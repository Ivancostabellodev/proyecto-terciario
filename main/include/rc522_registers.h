#pragma once

// Inicia y detiene la ejecución de comandos
#define RC522_COMMAND_REG 0x01

// Registro de habilitación de interrupción de comunicación.
// Bits de control para habilitar y deshabilitar el paso de solicitudes de interrupción
#define RC522_COMM_INT_EN_REG 0x02

// Registro de habilitación de interrupción desviada.
// Bits de control para habilitar y deshabilitar el paso de solicitudes de interrupción
#define RC522_DIV_INT_EN_REG 0x03

// Bits de solicitud de interrupción de comunicación
#define RC522_COMM_INT_REQ_REG 0x04

// Bits de solicitud de interrupción desviada
#define RC522_DIV_INT_REQ_REG 0x05

// Bits de error que muestran el estado de error del último comando ejecutado
#define RC522_ERROR_REG 0x06

// Contiene bits de estado del receptor, transmisor y detector de modo de datos
#define RC522_STATUS_2_REG 0x08

// Muestra la versión del software MFRC522
#define RC522_VERSION_REG 0x37

// Controla el comportamiento lógico de los pines del driver de antena TX1 y TX2
#define RC522_TX_CONTROL_REG 0x14

// Configura la ganancia del receptor
#define RC522_RF_CFG_REG 0x26

// Entrada y salida del búfer FIFO de 64 bytes
#define RC522_FIFO_DATA_REG 0x09

// Número de bytes almacenados en el búfer FIFO
#define RC522_FIFO_LEVEL_REG 0x0A

// Registro de control misceláneo
#define RC522_CONTROL_REG 0x0C

// Ajustes para tramas orientadas a bits
#define RC522_BIT_FRAMING_REG 0x0D

// Valores MSB (bits superiores) de la calculadora CRC
#define RC522_CRC_RESULT_MSB_REG 0x21

// Valores LSB (bits inferiores) de la calculadora CRC
#define RC522_CRC_RESULT_LSB_REG 0x22

// Establece el ancho de modulación
#define RC522_MOD_WIDTH_REG 0x24

// Define el modo del temporizador
#define RC522_TIMER_MODE_REG 0x2A

// Define la configuración del preescalador del temporizador
#define RC522_TIMER_PRESCALER_REG 0x2B

// Valor MSB (bits superiores) del valor de recarga del temporizador de 16 bits
#define RC522_TIMER_RELOAD_MSB_REG 0x2C

// Valor LSB (bits inferiores) del valor de recarga del temporizador de 16 bits
#define RC522_TIMER_RELOAD_LSB_REG 0x2D

// Define modos generales para transmitir y recibir
#define RC522_MODE_REG 0x11

// Controla la configuración de la modulación de transmisión
#define RC522_TX_ASK_REG 0x15