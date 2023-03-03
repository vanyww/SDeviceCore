#pragma once

/**
 * @file heap.h
 * @brief Операции динамического выделения памяти.
 */

/**
 * @defgroup Heap Динамическое выделение памяти
 * @copydoc heap.h
 * @{
 */

#include <stddef.h>

/**
 * @brief Динамически выделяет непрерывную область памяти.
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `malloc`.
 * @param size Размер выделяемой области.
 * @return Указатель на область памяти размера @p size.
 * @throws #CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY
 */
void * SDeviceMalloc(size_t size);

/**
 * @brief Освобождает динамически выделенную (при помощи функции SDeviceMalloc) область памяти.
 * @note Имеет определение в виде слабого символа, реализация по-умолчанию использует стандартную функцию `free`.
 * @param memory Указатель на область памяти для освобождения.
 */
void SDeviceFree(void *memory);

/** @} */
