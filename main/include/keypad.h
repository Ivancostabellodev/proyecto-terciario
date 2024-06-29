/**
 * @file keypad.h
 * @brief libreria para definir callbacks que usa el teclado amtricial
 */
#include "base.h"

/**
 * @brief Funcion para iniciar el teclado que usa callbacks como parametros y tareas en 
 * segundo plano para el polling
 * 
 * @param callback_key_pressed    callback que se llama cuando se presiona una tecla y devuelve esa tecla
 * @param callback_get_buffer     callback que se llama cuando se obtiene un buffer
 * @param fclear                 callback para limpiar/resetar el teclado se usa cuando se presiona la tecla C
 */

void keypad_init( callback_get_key callback_key_pressed,
                  callback_get_buffer callback_get_buffer,
                  callback_clear  fclear);