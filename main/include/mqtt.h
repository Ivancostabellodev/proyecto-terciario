/**
 * @file mqtt.h
 * @brief libreria para definir funciones del MQTT
 */
#ifndef _MQTT_H
#define _MQTT_H
#include "base.h"





/**
 * @brief                  Inicia el cliente MQTT con el URL especificado
 * 
 * @param uri              URL del broker MQTT
 * @param conn             Callback que se llama cuando se conecta al servidor 
 * @param disconn          Callback que se llama cuando se desconecta del servidor
 * @param data_received    Callback que se llama para manejar los datos recibidos
 * @return esp_err_t       Retorna a ESP_OK
 */
esp_err_t mqtt_init(const char* uri, esp_callback_t conn, esp_callback_t disconn,callback_data_t data_received);

/**
 * @brief              Publica un mensaje en un topico especifico
 * 
 * @param msg         Mensaje a publicar
 * @param topic       Topico en el que se publica el mensaje
 * @param qos         Nivel de la calidad del servicio (Quality of service) para el mensaje
 * @param retain      Retencion de mensaje
 */
esp_err_t mqtt_publish(const char* msg, const char* topic,int qos, int retain);

/**
 * @brief      Publica un mensaje en un topico especifico y deja el mensaje en una cola de manejo de mensajes
 *  
 */
esp_err_t mqtt_publish_on_queue(const char* msg, const char* topic,int qos, int retain);


/**
 * @brief    Se suscribe a un topico especifico para recibir mensajes
 * 
 */
esp_err_t mqtt_subcribe( char* topic, int qos);

#endif
