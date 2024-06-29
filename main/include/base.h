#ifndef _BASE_H
#define _BASE_H
/**
 * @file base.h
 * @brief  libreria de los callback que usa el lector rfid
 */
#include "esp_err.h"
#include <stddef.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include "esp_event.h"
#include <esp_log.h>
#include <inttypes.h>

/**
 * @brief callback que recibe el codigo rfid 
 * 
 */
typedef void (*callback_RFID_t)(uint64_t rfid);


/**
 * @brief callback que recibe datos y el topico 
 * 
 */
typedef void (*callback_data_t)(char* data, char* topic);

/**
 * @brief callback que no recibe parametros
 * 
 */

typedef void (*esp_callback_t)(void);


/**
 * @brief callback que recibe un char
 * 
 */
typedef void (*callback_get_key)(char key);

/**
 * @brief callback que recibe un buffer
 * 
 */

typedef void (*callback_get_buffer)(char* buffer);

/**
 * @brief callback que no recibe nada
 * 
 */

typedef void (*callback_clear)();

#define CHECK_RUN_F(f)            if(f)f()     // si f es distinta de NULL, llamar

// printf solo compila cuando se define EN_DEBUG_MESSAGE
#define EN_DEBUG_MESSAGE             

#ifdef EN_DEBUG_MESSAGE
    #define DEBUG_FORMAT                        "[DEBUG] %s"
    #define DEBUG_PRINT(message)                printf(DEBUG_FORMAT,message)
#else
    #define DEBUG_PRINT(message) 
#endif




#endif