/**
 * @file SDeviceCore/heap.h
 * @brief Операции динамического выделения памяти.
 * @details Реализация механизма динамического выделения для использования при разработке модулей.
 */

#pragma once

#include <stddef.h>

/**
 * @defgroup sdevice_core_malloc Динамическое выделение памяти
 * @brief @copybrief SDeviceCore/heap.h
 * @details @copydetails SDeviceCore/heap.h
 * @{
 */

/**
 * @brief Динамически выделяет непрерывную область памяти с выравниванием, подходящим для доступа к любому типу.
 * @details
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `malloc`.
 * @param[in] size Размер выделяемой области.
 * @return Указатель на выделенную область памяти размера @p size.
 * @throws #CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY
 */
void * SDeviceAllocateMemory(size_t size);

/**
 * @brief Освобождает динамически выделенную (при помощи функции @ref SDeviceAllocateMemory) область памяти.
 * @details
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `free`.
 * @param[in] pointer Указатель на область памяти, которую требуется освободить.
 */
void SDeviceFreeMemory(void *pointer);

/**
 * @brief Динамически выделяет память для дескриптора.
 * @note Имеет определение в виде слабого символа.
 * @param[in] initSize Размер @ref handle_init_data "параметров инициализации" дескриптора модуля.
 * @param[in] runtimeSize Размер @ref handle_runtime_data "параметров времени выполнения" дескриптора модуля.
 * @return Указатель на выделенный дескприптор.
 * @throws #CORE_GLOBAL_SDEVICE_PANIC_OUT_OF_MEMORY
 */
void * SDeviceAllocateHandle(size_t initSize, size_t runtimeSize);

/**
 * @brief Освобождает динамически выделенную (при помощи функции @ref SDeviceAllocateHandle) память дескриптора.
 * @note Имеет определение в виде слабого символа.
 * @param[in] handle Дескриптор, память которого требуется освободить.
 */
void SDeviceFreeHandle(void *handle);

/** @} */
