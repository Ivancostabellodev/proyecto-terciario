#pragma once
/**
 * @file guards.h
 * @brief  libreria para manejar errores del esp32
 */
#include <esp_err.h>

/**
 * @brief Etiqueta para la puerta de guardia de éxito en macros.
 *        Usada como una etiqueta de salto para manejar rutas de ejecución exitosas en macros.
 */
#define SUCCESS_GUARD_GATE __success_guard_gate

/**
 * @brief Etiqueta para la puerta de guardia de error en macros.
 *        Usada como una etiqueta de salto para manejar rutas de error en macros.
 */
#define ERROR_GUARD_GATE __error_guard_gate

/**
 * @brief Etiqueta para la puerta de guardia de salida en macros.
 *        Usada como una etiqueta de salto para marcar el final de las rutas de ejecución en macros.
 */
#define EXIT_GUARD_GATE __exit_guard_gate

/**
 * @brief Macro para crear puntos de salto para el manejo de éxito y error.
 *        Esta macro define etiquetas para el manejo de éxito y error, y un punto de salida común.
 * @param on_error Código a ejecutar en caso de error.
 * @param on_success Código a ejecutar en caso de éxito.
 */
#define JMP_GUARD_GATES(on_error, on_success) \
    goto SUCCESS_GUARD_GATE; \
        ERROR_GUARD_GATE: { on_error; goto EXIT_GUARD_GATE; };  \
        SUCCESS_GUARD_GATE: { on_success; goto EXIT_GUARD_GATE; };  \
        EXIT_GUARD_GATE: {};

/**
 * @brief Macro de guardia para saltar a un manejador de errores en caso de error de ESP.
 *        Verifica el resultado de EXP y si no es ESP_OK, salta a ERROR_GUARD_GATE.
 * @param EXP Expresión que devuelve un valor esp_err_t.
 */
#define ESP_ERR_JMP_GUARD(EXP) \
    if((err = (EXP)) != ESP_OK) { goto ERROR_GUARD_GATE; }

/**
 * @brief Macro para registrar un mensaje de error y saltar a un manejador de errores en caso de error de ESP.
 *        Si EXP no es ESP_OK, registra el mensaje proporcionado y salta a ERROR_GUARD_GATE.
 * @param EXP Expresión que devuelve un valor esp_err_t.
 * @param message El mensaje a registrar en caso de error.
 */
#define ESP_ERR_LOG_AND_JMP_GUARD(EXP, message) \
    if((err = (EXP)) != ESP_OK) { ESP_LOGE(TAG, message); goto ERROR_GUARD_GATE; }

/**
 * @brief Macro para registrar condicionalmente un mensaje de error y saltar a un manejador de errores.
 *        Si EXP evalúa como verdadero, registra el mensaje proporcionado y salta a ERROR_GUARD_GATE.
 * @param EXP Expresión booleana a evaluar.
 * @param message El mensaje a registrar si EXP es verdadero.
 */
#define CONDITION_LOG_AND_JMP_GUARD(EXP, message) \
    if(EXP) { ESP_LOGE(TAG, message); goto ERROR_GUARD_GATE; }

/**
 * @brief Macro de guardia para la asignación de memoria con salto al manejo de errores.
 *        Esta macro verifica si una expresión de asignación de memoria (EXP) falla (es decir, devuelve NULL).
 *        Si la asignación falla, salta a la etiqueta ERROR_GUARD_GATE.
 *        Esto se usa típicamente en funciones donde el manejo de errores está centralizado
 *        en una etiqueta específica (ERROR_GUARD_GATE) para un código más limpio y manejable.
 *        Ayuda a evitar la anidación profunda de verificaciones de errores después de cada asignación.
 * @param EXP Expresión de asignación de memoria (por ejemplo, una llamada a malloc).
 */
#define ALLOC_JMP_GUARD(EXP) \
    if((EXP) == NULL) { err = ESP_ERR_NO_MEM; goto ERROR_GUARD_GATE; }

/**
 * @brief Macro de guardia para funciones de asignación de memoria.
 *        Esta macro asegura que si una expresión de asignación de memoria falla (devuelve NULL),
 *        la función en la que se usa esta macro retornará inmediatamente con ESP_ERR_NO_MEM.
 *        Es útil para manejar fallas de asignación de memoria de manera elegante en funciones.
 * @param EXP Expresión de asignación de memoria (por ejemplo, una llamada a malloc).
 * @return Sale de la función que lo llama con ESP_ERR_NO_MEM si EXP evalúa a NULL.
 */
#define ALLOC_RET_GUARD(EXP) \
    if((EXP) == NULL) { return ESP_ERR_NO_MEM; }

/**
 * @brief Macro de guardia para el manejo de errores de ESP.
 *        Esta macro verifica si el resultado de EXP no es ESP_OK y, de ser así, retorna el código de error.
 * @param EXP Expresión que devuelve un valor esp_err_t.
 * @return Retorna el código de error si EXP no es ESP_OK.
 */
#define ESP_ERR_RET_GUARD(EXP) \
    if((err = (EXP)) != ESP_OK) { return err; }