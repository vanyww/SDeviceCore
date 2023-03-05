#pragma once

/**
 * @file heap.h
 * @brief Операции динамического выделения памяти.
 * @details Реализация механизма динамического выделения для использования при разработке модулей.
 */

/**
 * @defgroup dynamic_allocation Динамическое выделение памяти
 * @brief @copybrief heap.h
 * @details @copydetails heap.h
 * @{
 */

#include <stddef.h>

/**
 * @brief Динамически выделяет непрерывную область памяти с выравниванием, подходящим для доступа к любому типу.
 * @details
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `malloc`.
 * @param[in] size Размер выделяемой области.
 * @return Указатель на выделенную область памяти размера @p size.
 * @throws #CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY
 */
void * SDeviceMalloc(size_t size);

/**
 * @brief Освобождает динамически выделенную (при помощи функции #SDeviceMalloc) область памяти.
 * @details
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `free`.
 * @param[in] memory Указатель на область памяти, которую требуется освободить.
 */
void SDeviceFree(void *memory);

/** @} */
