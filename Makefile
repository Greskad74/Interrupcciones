DEVICE = STM32F103x8
FLASH  = 0x08000000

USE_ST_CMSIS = true

# Agrega tus archivos fuente aquí
SRC += src/main.c
SRC += src/librerias/timers.c
SRC += src/librerias/gpio.c
SRC += src/librerias/systickdelay.c
SRC += src/librerias/interupcciones.c
SRC += src/librerias/garra.c


# Incluye las rutas de tus headers
INC_DIRS += src/librerias  # Agrega esta línea

# Include the main makefile
include ./STM32-base/make/common.mk