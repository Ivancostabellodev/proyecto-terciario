#include "main.h"
#include "keypad.h"
#include <driver/gpio.h>

// Buffer para formatear las peticiones al servidor
char buffer[LEN_BUFFER]= {0};











static void get_rfid(uint64_t rfid){ 
    sprintf(buffer,REQUEST_FORMAT,PRODUCT_ID, rfid);
    //printf("Envió petición al servidor:\n");
    printf("\n%s\n",buffer);
    mqtt_publish(buffer,TOPIC_PUB_TAR,2,0);
 }








static void get_data( char* data,  char* topic){
    
  void get_data(char* data, char* topic) {
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == '1') {
            CHECK(topic, RES_NODE, action_ok);
        } else if (data[i] == '0') {
            CHECK(topic, RES_NODE, action_fail);
        } else {
            CHECK(topic, RES_NODE, action_unknown);
        }
    }
}






static void keypad_add_key(char key){ 
    //Aquí podría ir un LCD Gráfico.
	printf("[%c]",key);
    fflush(stdout);
}





static void keypad_send(char*b){
    sprintf(buffer,REQUEST_FORMAT_KEYPAD,PRODUCT_ID, b);
    //printf("Envió petición al servidor:\n");
    printf("\n%s\n",buffer);
    mqtt_publish(buffer,TOPIC_PUB_TEC,2,0);
    
}



int app_main()
{
    gpio_set_direction(GPIO_LED,GPIO_MODE_OUTPUT);
    gpio_set_level(GPIO_LED,0);
    wifi_connect(WIFI_CREDENTIALS_ID,WIFI_CREDENTIALS_PASS,callback_wifi_connected,NULL);

    while(1){
        vTaskDelay(1000/ portTICK_PERIOD_MS);
    }   
    return 0;
}







static void mqtt_connected(){
    printf("init mqtt\n");
    // Me conector a todos los tópicos necesarios.
    mqtt_subcribe(RES_NODE,2);

    
    // Lector de tarjetas
    rc522_init(&config,get_rfid);
    
    //Teclado
    keypad_init( keypad_add_key,keypad_send,NULL);


}

static void callback_wifi_connected(){
    printf("WIFI Ok\n");
    mqtt_init(MQTT_URL,mqtt_connected,NULL,get_data);

}


static void action_ok(){
    printf("\n Usuario autorizado\n");
   gpio_set_level(GPIO_LED,1);
}

static void action_fail(){
    printf("\n Usuario  NO autorizado\n");
   gpio_set_level(GPIO_LED,0);
}

static void action_unknown(){
    printf("Error inesperado\n");
}