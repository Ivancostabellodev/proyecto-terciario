/**
 * @file rc522.h
 * @brief libreria de configuraciones del lector rfid
 */
#pragma once

#ifdef __cplusplus
extern "C" {
#endif


#include <driver/spi_master.h>
#include "base.h"

//#define RC522_I2C_ADDRESS (0x28)

#define RC522_DEFAULT_SCAN_INTERVAL_MS (125)
#define RC522_DEFAULT_TASK_STACK_SIZE (4 * 1024)
#define RC522_DEFAULT_TASK_STACK_PRIORITY (4)
#define RC522_DEFAULT_SPI_CLOCK_SPEED_HZ (5000000)
#define RC522_DEFAULT_I2C_RW_TIMEOUT_MS (1000)
#define RC522_DEFAULT_I2C_CLOCK_SPEED_HZ (100000)

ESP_EVENT_DECLARE_BASE(RC522_EVENTS);

typedef struct rc522* rc522_handle_t;

typedef struct {
    uint16_t scan_interval_ms;         /*<! Qué tan rápido escaneará ESP32 para etiquetas cercanas, en milisegundos */
    size_t task_stack_size;            /*<! Tamaño de la pila de la tarea rc522 */
    uint8_t task_priority;             /*<! Prioridad de la tarea rc522 */
    union {
        struct {
            spi_host_device_t host;
            int miso_gpio;
            int mosi_gpio;
            int sck_gpio;
            int sda_gpio;
            int clock_speed_hz;
            uint32_t device_flags;     /*<! Combinación bitwise de los indicadores SPI_DEVICE_* */
            /**
             * @brief Establecido en verdadero si el bus ya está inicializado.
             *        NOTA: Esta propiedad se eliminará en el futuro,
             *        una vez que se resuelva https://github.com/espressif/esp-idf/issues/8745
             * 
             */
            bool bus_is_initialized;
        } spi;
 
    };
} rc522_config_t;

typedef enum {
    RC522_EVENT_ANY = ESP_EVENT_ANY_ID,
    RC522_EVENT_NONE,
    RC522_EVENT_TAG_SCANNED,             /*<! Etiqueta escaneada */
} rc522_event_t;

typedef struct {
    rc522_handle_t rc522;
    void* ptr;
} rc522_event_data_t;

typedef struct {
    uint64_t serial_number;
} rc522_tag_t;

/**
 * @brief Crea un manejador de escáner RC522.
 *        Para comenzar a escanear etiquetas, llame a la función rc522_start.
 * @param config Configuración
 * @param out_rc522 Puntero al nuevo manejador resultante
 * @return ESP_OK en caso de éxito
 */
esp_err_t rc522_create(rc522_config_t* config, rc522_handle_t* out_rc522);

esp_err_t rc522_register_events(rc522_handle_t rc522, rc522_event_t event, esp_event_handler_t event_handler, void* event_handler_arg);

esp_err_t rc522_unregister_events(rc522_handle_t rc522, rc522_event_t event, esp_event_handler_t event_handler);

/**
 * @brief Comienza a escanear etiquetas. Si ya está iniciado, ESP_OK simplemente se devolverá. La función de inicialización debe haber sido
 *        llamada antes que esta.
 * @param rc522 Manejador
 * @return ESP_OK en caso de éxito
 */
esp_err_t rc522_start(rc522_handle_t rc522);

/**
 * @brief Reanuda el escaneo de etiquetas. Si ya está en pausa, ESP_OK simplemente se devolverá.
 * @param rc522 Manejador
 * @return ESP_OK en caso de éxito
 */
#define rc522_resume(rc522) rc522_start(rc522)

/**
 * @brief Pausa el escaneo de etiquetas. Si ya está pausado, ESP_OK simplemente se devolverá.
 * @param rc522 Manejador
 * @return ESP_OK en caso de éxito
 */
esp_err_t rc522_pause(rc522_handle_t rc522);

/**
 * @brief Destruye RC522 y libera todos los recursos. No se puede llamar desde el manejador de eventos.
 * @param rc522 Manejador
 */
esp_err_t rc522_destroy(rc522_handle_t rc522);

/**
 * @brief Inicializa el módulo RC522 con una configuración rápida, usando un callback cuando se recibe un RFID (uint64_t) para ocultar la implementación.
 * 
 * @param config Puntero a la configuración del módulo.
 * @param get_rfid Función de callback que recibe como parámetro el RFID (uint64_t).
 * @return esp_err_t 
 */
esp_err_t rc522_init(rc522_config_t* config, callback_RFID_t get_rfid);

#ifdef __cplusplus
}
#endif