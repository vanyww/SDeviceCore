/**
 * @file CoreGlobalSDevice/public.h
 * @brief Публичный интерфейс глобального модуля.
 * @details Глобальный модуль (`CoreGlobalSDevice`) создается статически в одном экземпляре.
 * Он используется для логирования состояний и выбрасывания паник фреймворка SDevice.
 */

#pragma once

#include "log.h"
#include "config.h"
#include "dependencies.h"

/**
 * @defgroup core_global Глобальный модуль
 * @{
 */

/**
 * @defgroup core_global_public Публичный интерфейс
 * @brief @copybrief CoreGlobalSDevice/public.h
 * @details @copydetails CoreGlobalSDevice/public.h
 * @{
 */

/* 78be0543-4a77-11ee-8689-93f017f8080a */

/**
 * @brief Старшая часть UUID глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_UUID_HIGH 0x78be05434a7711ee

/**
 * @brief Младшая часть UUID глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_UUID_LOW  0x868993f017f8080a

/**
 * @brief Старшая компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_MAJOR 2

/**
 * @brief Средняя компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_MINOR 0

/**
 * @brief Младшая компонента версии глобального модуля.
 */
#define CORE_GLOBAL_SDEVICE_VERSION_PATCH 0

/**
 * @brief Предварительное объявление типа данных дескриптора глобального модуля.
 */
SDEVICE_HANDLE_FORWARD_DECLARATION(CoreGlobal);

/**
 * @brief Паники глобального модуля.
 */
typedef enum
{
   CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY /**< Недостаток динамически выделяемой памяти. */
} CoreGlobalSDevicePanic;

/**
 * @brief Объявление переменной идентификационного блока модуля.
 */
SDEVICE_IDENTITY_BLOCK_DECLARATION(CoreGlobal);

/**
 * @brief Выбрасывает панику глобального модуля.
 * @details Использует #SDevicePanic.
 * @param panic Паника для выбрасывания.
 */
void CoreGlobalSDeviceThrowPanic(CoreGlobalSDevicePanic panic);

/**
 * @brief Логирует состояние глобального модуля.
 * @details Использует #SDeviceLogStatus.
 * @param status Состояние для логирования.
 */
void CoreGlobalSDeviceLogStatus(CoreGlobalSDeviceStatus status);

/** @} */

/** @} */
