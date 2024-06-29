/**
 * @file wifi.h
 * @brief libreria de funciones que usa el wifi
 */
#ifndef _WIFI_H
#define _WIFI_H
#include  "base.h"








/**
 * @brief Esta función se encarga de conectar el dispositivo a una red WiFi utilizando las credenciales proporcionadas
 * 
 * @param WIFI_ID         red wifi
 * @param PASS            contraseña de la red
 * @param callback_conn    puntero a una función de tipo esp_callback_t que se llamará cuando la conexión WiFi se establezca correctamente.
 * @param callback_desconn     puntero a una función de tipo esp_callback_t que se llamará cuando la conexión WiFi se desconecte.
 * @return esp_err_t 
 */
 esp_err_t wifi_connect(const char* WIFI_ID, const char * PASS,
                        esp_callback_t callback_conn, esp_callback_t callback_desconn);

/**
 * @brief Esta función se utiliza para desconectar el dispositivo de la red WiFi actual.
 * 
 * @return esp_err_t 
 */
esp_err_t wifi_desconnect(void);

#endif