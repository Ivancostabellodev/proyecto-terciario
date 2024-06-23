#ifndef _CONFIG_H
#define _CONFIG_H
#include "base.h"
#include  <string.h>
/**
 * @brief Parámetros para configuración la conexión con servidor MQTT
 * 
 */
#define MQTT_URL            "mqtt://broker.hivemq.com:1883"
#define TOPIC_PUB_TAR           "/Tarjeta_de_esp"               // Tópico para enviar solicitudes del lector
#define TOPIC_PUB_TEC              "/Teclado_de_esp"            // Tópico para enviar solicitudes del teclado



#define RES_NODE              "RES/NODE"


#define LEN_BUFFER          100
#define GPIO_LED            2



#define MSG_OK          "USUARIO AUTORIZADO\n"
#define MSG_FAIL        "USUARIO NO AUTORIZADO\n"
#define MSG_UNKNOWN     "ERROR DESCONOCIDO"


// Si s1 y s2 son iguales, ejecuto f


#define EQUAL(s1,s2)                (strcmp(s1,s2) == 0)
#define CHECK(s1,s2,f)            if( EQUAL(s1,s2)) f()   



#define REQUEST_FORMAT           "%" PRIu64 
#define REQUEST_FORMAT_KEYPAD    "%s"

#endif
