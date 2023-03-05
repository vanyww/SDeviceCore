#pragma once

/**
 * @file core.h
 * @brief Определения и объявления для создания модулей и взаимодействия с ними.
 */

/**
 * @defgroup Core Ядро фреймворка SDevice
 * @copydoc core.h
 * @details Модули состоят из трех частей:
 * - публичная часть интерфейса
 * - приватная часть интерфейса
 * - реализация интерфейса
 *
 * Пример публичной части интерфейса:
 * @include core/public.h
 * Пример приватной части интерфейса:
 * @include core/private.h
 * Пример реализации интерфейса:
 * @include core/core.c
 * @{
 */

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Версия модуля.
 */
typedef struct
{
   uint16_t Major; /**< Старшая компонента версии. */
   uint8_t Minor; /**< Средняя компонента версии. */
   uint8_t Patch; /**< Младшая компонента версии. */
} SDeviceVersion;

/**
 * @brief Старшая компонента версии ядра фреймворка SDevice.
 */
#define SDEVICE_CORE_VERSION_MAJOR 6

/**
 * @brief Средняя компонента версии ядра фреймворка SDevice.
 */
#define SDEVICE_CORE_VERSION_MINOR 0

/**
 * @brief Младшая компонента версии ядра фреймворка SDevice.
 */
#define SDEVICE_CORE_VERSION_PATCH 0

/**
 * @brief Версия ядра фреймворка SDevice в виде составного литерала структуры SDeviceVersion.
 */
#define SDEVICE_CORE_VERSION ((SDeviceVersion)                                                                         \
{                                                                                                                      \
   .Major = SDEVICE_CORE_VERSION_MAJOR,                                                                                \
   .Minor = SDEVICE_CORE_VERSION_MINOR,                                                                                \
   .Patch = SDEVICE_CORE_VERSION_PATCH                                                                                 \
})

/**
 * @defgroup Handles Дескрипторы
 * @brief Макросы для объявления и взаимодействия с дескрипторами.
 * @details Структура данных дескриптора состоит из следующих членов:
 * - SDeviceHandleHeader Header
 * - SDEVICE_INIT_DATA() Init
 * - SDEVICE_RUNTIME_DATA() Runtime
 *
 * @n В @b публичной части интерфейса используется предварительное объявление SDEVICE_HANDLE_FORWARD_DECLARATION().
 * В @b приватной части интерфейса используется обычное (полное) объявление SDEVICE_HANDLE_DECLARATION().
 * @n Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup HandleInitData Параметры инициализации
 * @brief Макросы для объявления и взаимодействия со структурами данных параметров инициализации дескрипторов.
 * @details Параметры инициализации - это структура данных, определяемая разработчиком модуля.
 * Пользователь создает экземпляр этой структуры и передает его @link HandleCreation функции создания модуля @endlink.
 * Это позволяет настроить конкретный дескриптор под нужды пользователя в рамках, заданных разработчиком модуля.
 * Часть @b публичного интерфейса модуля.
 * @n Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) структуры данных параметров инициализации дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_INIT_DATA(device_name) _##device_name##SDeviceInitData

/**
 * @brief Начинает объявление структуры данных параметров инициализации дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_INIT_DATA_DECLARATION(device_name) struct SDEVICE_INIT_DATA(device_name)

/**
 * @brief Создает предварительное объявление структуры данных параметров инициализации дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_INIT_DATA_FORWARD_DECLARATION(device_name)                                                             \
   typedef SDEVICE_INIT_DATA_DECLARATION(device_name) SDEVICE_INIT_DATA(device_name)

/** @} */

/**
 * @defgroup HandleRuntimeData Параметры времени выполнения
 * @brief Макросы для объявления и взаимодействия со структурами данных параметров времени выполнения дескрипторов.
 * @details Параметры времени выполнения - это структура данных, определяемая разработчиком модуля.
 * Она хранит внутреннее состояние конкретного дескриптора в процессе его использования пользователем.
 * Часть @b приватного интерфейса модуля.
 * @n Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) структуры данных параметров времени выполнения дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_RUNTIME_DATA(device_name) _##device_name##SDeviceRuntimeData

/**
 * @brief Начинает объявление структуры данных параметров времени выполнения дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_RUNTIME_DATA_DECLARATION(device_name) struct SDEVICE_RUNTIME_DATA(device_name)

/**
 * @brief Создает предварительное объявление структуры данных параметров времени выполнения дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(device_name)                                                          \
   typedef SDEVICE_RUNTIME_DATA_DECLARATION(device_name) SDEVICE_RUNTIME_DATA(device_name)

/** @} */

/** @} */

/**
 * @defgroup HandleCreation Процедура создания дескриптора
 * @brief Макросы для объявления, определения и использования процедуры создания дескриптора модуля.
 * @details Данная процедура создает и инициализирует новый дескриптор модуля.
 * @n Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) процедуры создания дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_CREATE_HANDLE(device_name) _##device_name##SDeviceCreateHandle

/**
 * @brief Тип возвращаемого процедурой создания дескриптора значения.
 */
#define SDEVICE_CREATE_HANDLE_RETURN_VALUE void *

/**
 * @brief Список формальных параметров процедуры создания дескриптора.
 * @param init_data_name Имя формального параметра параметров инициализации дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name)                                                  \
   (const void *init_data_name, void *context_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на процедуру создания дескриптора.
 * @param pointer_name Имя создаваемой переменной.
 */
#define SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                    \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_CREATE_HANDLE_ARGUMENTS(,,)

/**
 * @brief Создает прототип (объявление) процедуры создания дескриптора.
 * @param device_name Название модуля.
 * @param init_data_name Имя формального параметра данных инициализации дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_DECLARATION(device_name, init_data_name, context_name)                                   \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                  \
   SDEVICE_CREATE_HANDLE(device_name)                                                                                  \
   SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, context_name)

/** @} */

/**
 * @defgroup HandleDisposal Процедура удаления дескриптора
 * @brief Макросы для объявления, определения и использования процедуры удаления дескриптора модуля.
 * @details Параметры времени выполнения - это структура данных, определяемая разработчиком модуля.
 * Она хранит внутреннее состояние конкретного дескриптора в процессе его использования пользователем.
 * Часть @b приватного интерфейса модуля.
 * @n Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Тип возвращаемого функцией удаления дескриптора значения.
 */
#define SDEVICE_DISPOSE_HANDLE_RETURN_VALUE void

/**
 * @brief Список формальных параметров функции удаления дескриптора.
 * @param handle_pointer_name Имя формального параметра указателя на дескриптор.
 */
#define SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name) (void *handle_pointer_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию удаления дескриптора.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_DISPOSE_HANDLE_POINTER(pointer_name)                                                                   \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_DISPOSE_HANDLE_ARGUMENTS()

/**
 * @brief Мета-определение символа (имени) функции удаления дескриптора.
 * @param device_name Пользовательское имя модуля.
 */
#define SDEVICE_DISPOSE_HANDLE(device_name) _##device_name##SDeviceDisposeHandle

/**
 * @brief Создает прототип (объявление) функции удаления дескриптора.
 * @param device_name Название модуля.
 * @param handle_pointer_name Имя формального параметра указателя на дескриптор.
 */
#define SDEVICE_DISPOSE_HANDLE_DECLARATION(device_name, handle_pointer_name)                                           \
   SDEVICE_DISPOSE_HANDLE_RETURN_VALUE                                                                                 \
   SDEVICE_DISPOSE_HANDLE(device_name)                                                                                 \
   SDEVICE_DISPOSE_HANDLE_ARGUMENTS(handle_pointer_name)

/** @} */

/**
 * @brief Заголовок дескриптора, общие для всех дескрипторов данные.
 */
typedef struct
{
   void *Context; /**< Указатель на пользовательский контекст дескриптора. */
   int32_t LatestStatus; /**< Последнее состояние дескриптора (последняя ошибка или исключение). */
} SDeviceHandleHeader;

/**
 * @brief Мета-определение символа (идентификатора) структуры дескриптора.
 * @param device_name Пользовательское имя модуля.
 */
#define SDEVICE_HANDLE(device_name) _##device_name##SDeviceHandle

/**
 * @brief Создает предварительное объявление структуры дескриптора.
 * @param device_name Пользовательское имя модуля.
 */
#define SDEVICE_HANDLE_FORWARD_DECLARATION(device_name)                                                                \
   typedef struct SDEVICE_HANDLE(device_name) SDEVICE_HANDLE(device_name)

/**
 * @brief Создает объявление структуры дескриптора.
 * @param device_name Пользовательское имя модуля.
 * @details Структура дескриптора включает в себя следующие члены:
 * - SDeviceHandleHeader Header
 * - SDEVICE_INIT_DATA(device_name) Init
 * - SDEVICE_RUNTIME_DATA(device_name) Runtime
 */
#define SDEVICE_HANDLE_DECLARATION(device_name) struct SDEVICE_HANDLE(device_name)                                     \
{                                                                                                                      \
   SDeviceHandleHeader Header;                                                                                         \
   SDEVICE_INIT_DATA(device_name) Init;                                                                                \
   SDEVICE_RUNTIME_DATA(device_name) Runtime;                                                                          \
}

/**
 * @brief Создает объявления псевдонимов для типов данных, ассоциированных с модулем.
 * @details Предназначен для использования в объявлении приватного интерфейса модуля.
 * Упрощает написание и чтение кода модуля.
 * @n Создает следующие объявления:
 * - typedef SDEVICE_INIT_DATA(device_name) ThisInitData
 * - typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData
 * - typedef SDEVICE_HANDLE(device_name) ThisHandle
 *
 * @param device_name Пользовательское имя модуля.
 */
#define SDEVICE_INTERNAL_ALIASES_DECLARATION(device_name)                                                              \
   typedef SDEVICE_INIT_DATA(device_name) ThisInitData;                                                                \
   typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData;                                                          \
   typedef SDEVICE_HANDLE(device_name) ThisHandle

/**
 * @brief Возвращает пользовательский контекст дескриптора.
 * @param[in] _handle Дескриптор.
 * @return Пользовательский контекст дескриптора @p _handle.
 */
static inline void * SDeviceGetHandleContext(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->Context;
}

/**
 * @brief Возвращает последнее состояние дескриптора.
 * @param[in] _handle Дескриптор.
 * @return Последнее состояние дескриптора @p _handle.
 */
static inline int32_t SDeviceGetHandleLatestStatus(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->LatestStatus;
}

/** @} */

/**
 * @defgroup Properties Свойства
 * @brief Объявления, предназначенные для создания и взаимодействия со свойствами.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Результат операции чтения или записи свойства.
 */
typedef enum
{
    SDEVICE_PROPERTY_OPERATION_STATUS_OK,               /**< Операция выполнена успешно. */
    SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR, /**< Ошибка валидации значения. */
    SDEVICE_PROPERTY_OPERATION_STATUS_PROCESSING_ERROR  /**< Ошибка во время записи или чтения значения. */
} SDevicePropertyOperationStatus;

/**
 * @brief Мета-определение символа (имени) типа данных свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_PROPERTY_TYPE(device_name, property_name) _##device_name##SDevice##property_name##PropertyType

/**
 * @brief Создает объявление типа данных свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param type Тип данных свойства.
 */
#define SDEVICE_PROPERTY_TYPE_DECLARATION(device_name, property_name, type)                                            \
   typedef type SDEVICE_PROPERTY_TYPE(device_name, property_name)

/**
 * @defgroup CommonProperties Обыкновенные свойства
 * @brief Объявления, предназначенные для создания и взаимодействия с частичными свойствами модулей.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup CommonPropertySet Запись
 * @brief Объявления, предназначенные для создания и взаимодействия с функцией записи обыкновенного свойства.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Тип возвращаемого функцией записи обыкновенного свойства значения.
 */
#define SDEVICE_SET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus

/**
 * @brief Список формальных параметров функции записи обыкновенного свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на записываемое значение.
 */
#define SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию записи обыкновенного свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_SET_PROPERTY_POINTER(pointer_name)                                                                     \
   SDEVICE_SET_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции записи обыкновенного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_SET_PROPERTY(device_name, property_name) _##device_name##SDevice##property_name##SetProperty

/**
 * @brief Создает прототип (объявление) функции записи обыкновенного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на записываемое значение.
 */
#define SDEVICE_SET_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                          \
   SDEVICE_SET_PROPERTY_RETURN_VALUE                                                                                   \
   SDEVICE_SET_PROPERTY(device_name, property_name)                                                                    \
   SDEVICE_SET_PROPERTY_ARGUMENTS(handle_name, value_name)

/** @} */

/**
 * @defgroup CommonPropertyGet Чтение
 * @brief Объявления, предназначенные для создания и взаимодействия с функцией чтения обыкновенного свойства.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Тип возвращаемого функцией чтения обыкновенного свойства значения.
 */
#define SDEVICE_GET_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus

/**
 * @brief Список формальных параметров функции чтения обыкновенного свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на буфер для читаемого значения.
 */
#define SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию чтения обыкновенного свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_GET_PROPERTY_POINTER(pointer_name)                                                                     \
   SDEVICE_GET_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции чтения обыкновенного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_GET_PROPERTY(device_name, property_name) device_name##SDevice##property_name##GetProperty

/**
 * @brief Создает прототип (объявление) функции чтения обыкновенного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на буфер для читаемого значения.
 */
#define SDEVICE_GET_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                          \
   SDEVICE_GET_PROPERTY_RETURN_VALUE                                                                                   \
   SDEVICE_GET_PROPERTY(device_name, property_name)                                                                    \
   SDEVICE_GET_PROPERTY_ARGUMENTS(handle_name, value_name)

/** @} */

/** @} */

/**
 * @defgroup PartialProperties Частичные свойства
 * @brief Объявления, предназначенные для создания и взаимодействия с частичными свойствами модулей.
 * @details Интерфейс частичных свойств, в отличие от обыкновенных, обеспечивает доступ к произвольному срезу значения.
 * Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup PartialPropertySet Запись
 * @brief Объявления, предназначенные для создания и взаимодействия с функцией записи частичного свойства.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров записываемого значения.
 */
typedef struct
{
   const void *Data; /**< Указатель на записываемую часть значения. */
   size_t Offset; /**< Смещение (в байтах) относительно начала полного значения, с которого начнется запись. */
   size_t Size; /**< Размер (в байтах) записываемой части полного значения. */
} SDeviceSetPartialPropertyParameters;

/**
 * @brief Тип возвращаемого функцией записи частичного свойства значения.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus

/**
 * @brief Список формальных параметров функции записи частичного свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров записываемого значения.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceSetPartialPropertyParameters *parameters_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию записи частичного свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции записи частичного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   _##device_name##SDevice##property_name##SetPartialProperty

/**
 * @brief Создает прототип (объявление) функции записи частичного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров записываемого значения.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/**
 * @defgroup PartialPropertyGet Чтение
 * @brief Объявления, предназначенные для создания и взаимодействия с функцией чтения частичного свойства.
 * @details Пример применения соответствующих макросов приведен в @link Core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров читаемого значения.
 */
typedef struct
{
   void *Data; /**< Указатель на буфер для читаемой части значения. */
   size_t Offset; /**< Смещение (в байтах) относительно начала полного значения, с которого начнется чтение. */
   size_t Size; /**< Размер (в байтах) читаемой части полного значения. */
} SDeviceGetPartialPropertyParameters;

/**
 * @brief Тип возвращаемого функцией частичного обыкновенного свойства значения.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus

/**
 * @brief Список формальных параметров функции чтения частичного свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров читаемого значения.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceGetPartialPropertyParameters *parameters_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию чтения частичного свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции чтения частичного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                       \
   _##device_name##SDevice##property_name##GetPartialProperty

/**
 * @brief Создает прототип (объявление) функции чтения частичного свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров читаемого значения.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/** @} */

/** @} */
