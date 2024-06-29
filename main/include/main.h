/**
 * @file main.h
 * @brief libreria para configurar los pines del lector rfid y funciones del mqtt y del wifi
 */
#ifndef _MAIN_H
#define _MAIN_H



#include <stdio.h>
#include <stdlib.h>
#include "rc522.h"
#include "mqtt.h"
#include "wifi.h"
#include "wifi_credentials.h"
#include "config.h"








/**
 * @brief Nueva estructura de configuración del puerto SPI utilizado por el lector de tarjetas.
 * 
 */
rc522_config_t config = {
    .spi.host = VSPI_HOST,                          /*<! Host utilizado. El SPI0 y SP1 no están disables para el usuario */  
    .spi.miso_gpio = 21,                            /*<!  MISO */
    .spi.mosi_gpio = 23,                            /*<!  MOSI */
    .spi.sck_gpio = 19,                             /*<!  SCK */
    .spi.sda_gpio = 22,                             /*<!  SDA */
    .spi.device_flags= SPI_DEVICE_HALFDUPLEX        /*<!  Flags de configuración */
};




/**
 * @brief Esta función se encarga de obtener los datos desde el lector de tarjetas RFID y publicarlos en un tema específico de MQTT.
 * 
 * @param data  especifica el contenido de los datos
 * @param topic  especifica el topico de MQTT donde se publicarán.
 */
static void get_data( char* data,  char* topic);

/**
 * @brief Esta función se ejecuta cuando la conexión MQTT se establece correctamente. Puede incluir lógica para subscribirse a topicos, publicar mensajes iniciales, o simplemente indicar que la conexión es exitosa.
 * 
 */
static void mqtt_connected();

/**
 * @brief Esta función es un callback que se ejecuta cuando la conexión WiFi se establece exitosamente. Es posible que inicie la conexión MQTT o ejecute otras acciones necesarias una vez que el dispositivo esté conectado a la red.
 * 
 */
static void callback_wifi_connected();


/**
 * @brief Esta función se llama cuando una acción se completa con éxito. Puede ser usada para indicar visualmente (por ejemplo, con un LED) o registrar en logs que la acción fue exitosa.
 * 
 */
static void action_ok();

/**
 * @brief Similar a action_ok(), pero se llama cuando una acción falla. Probablemente indique un error, ya sea mediante un LED, un mensaje en el log, o una publicación MQTT.

 * 
 */
static void action_fail();

/**
 * @brief Esta función se llama cuando la acción realizada no se puede categorizar como éxito o fallo. Podría usarse para manejar estados indeterminados o errores no previstos.
 * 
 */
static void action_unknown();


#endif