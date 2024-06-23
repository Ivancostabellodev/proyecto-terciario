#include "base.h"



/**
 * @brief Teclado compatible con callbacks. 
 * Utiliza una tarea en segundo plano para el polling.
 * 
 * @param callback_key_pressed Callback cuando se presiona una tecla, recibe un char como parámetro
 * @param callback_get_buffer  Callback cuando se presiona la tecla, recibe el buffer como parámetro
 * @param fclear  Callback que se llama cuando se presiona tecla C, se borra el buffer
 */
void keypad_init( callback_get_key callback_key_pressed,
                  callback_get_buffer callback_get_buffer,
                  callback_clear  fclear);