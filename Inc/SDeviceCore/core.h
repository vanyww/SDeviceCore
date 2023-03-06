#pragma once

/**
 * @file core.h
 * @brief Инструменты создания модулей и взаимодействия с ними.
 * @details Модуль - единица разработки в рамках фреймворка SDevice.
 * Представляет собой набор объявлений и определений, описывающих структуры данных и алгоритмы взаимодействия с ними.
 * Модули состоят из трех частей:
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
 * Публичная часть интерфейса предназначена для использования в конечном ПО.
 * Приватная часть интерфейса используется в реализации самого модуля.
 */

/**
 * @defgroup sdevice_core Ядро фреймворка SDevice
 * @brief @copybrief core.h
 * @details @copydetails core.h
 * @{
 */

#include <stdint.h>
#include <stddef.h>

/**
 * @brief Версия модуля.
 * @details Тип данных, используемый для хранения версии модулей.
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
#define SDEVICE_CORE_VERSION_MAJOR 7

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
 * @defgroup handles Дескрипторы модулей
 * @brief Инструменты описания дескрипторов и взаимодействия с ними.
 * @details Дескриптор - часть интерфейса модуля, структура данных,
 * храненящая его параметры и внутреннее состояние между вызовами.
 * Дескриптор состоит из следующих членов:
 * - @code SDeviceHandleHeader Header @endcode
 * - @code SDEVICE_INIT_DATA(device_name) Init @endcode
 * - @code SDEVICE_RUNTIME_DATA(device_name) Runtime @endcode
 *
 * @note В публичной части интерфейса используется предварительное объявление - #SDEVICE_HANDLE_FORWARD_DECLARATION.
 * @note В приватной части интерфейса используется обыкновенное (полное) объявление - #SDEVICE_HANDLE_DECLARATION.
 *
 * Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup handle_init_data Параметры инициализации дескриптора
 * @brief Инструменты описания параметров инициализации дескриптора и взаимодействия с ними.
 * @details Параметры инициализации дескриптора - часть интерфейса модуля, структура данных,
 * используемая для пользовательской настройки конкретного его дескриптора в момент создания.
 * @note Может принадлежать как к публичной, так и к приватной части интерфейса в зависимости от особенностей модуля.
 *
 * Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
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
 * @defgroup handle_runtime_data Параметры времени выполнения дескриптора
 * @brief Инструменты описания параметров времени выполнения дескриптора и взаимодействия с ними.
 * @details Параметры времени выполнения дескриптора - часть интерфейса модуля, структура данных,
 * хранящая внутреннее состояние его дескриптора.
 * @note Часть приватного интерфейса модуля.
 *
 * Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
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

/**
 * @defgroup handle_creation Функция создания дескриптора
 * @brief Инструменты описания функции создания дескриптора и взаимодействия с ней.
 * @details Данная функция создает и инициализирует дескриптор, используя параметры, переданные пользователем.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) функции создания дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_CREATE_HANDLE(device_name) _##device_name##SDeviceCreateHandle

/**
 * @brief Тип возвращаемого функцией создания дескриптора значения.
 */
#define SDEVICE_CREATE_HANDLE_RETURN_VALUE void *

/**
 * @brief Список формальных параметров функции создания дескриптора.
 * @param init_data_name Имя формального параметра параметров инициализации дескриптора.
 * @param parent_name Имя формального параметра указателя на внешний дескриптор.
 * @param identifier_name Имя формального параметра идентификатора дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, parent_name, identifier_name, context_name)                    \
   (const void *init_data_name, const void *parent_name, SDeviceHandleIdentifier identifier_name, void *context_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию создания дескриптора.
 * @param pointer_name Имя создаваемой переменной.
 */
#define SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                    \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_CREATE_HANDLE_ARGUMENTS(,,)

/**
 * @brief Создает прототип (объявление) функции создания дескриптора.
 * @param device_name Название модуля.
 * @param init_data_name Имя формального параметра данных инициализации дескриптора.
 * @param parent_name Имя формального параметра указателя на внешний дескриптор.
 * @param identifier_name Имя формального параметра идентификатора дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_DECLARATION(device_name, init_data_name, parent_name, identifier_name, context_name)     \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                  \
   SDEVICE_CREATE_HANDLE(device_name)                                                                                  \
   SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, parent_name, identifier_name, context_name)

/** @} */

/**
 * @defgroup handle_disposal Функция удаления дескриптора
 * @brief Инструменты описания функции удаления дескриптора и взаимодействия с ней.
 * @details Данная функция деинициализирует и удаляет переданный дескриптор.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
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
 * @param device_name Название модуля.
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
 * @brief Тип данных идентификатора дескриптора.
 */
typedef uint16_t SDeviceHandleIdentifier;

/**
 * @brief Тип данных последнего состояния дескриптора.
 */
typedef int16_t SDeviceHandleLatestStatus;

/**
 * @brief Заголовок дескриптора.
 * @details Структура данных, общая для всех дескрипторов.
 */
typedef struct
{
   void *Context; /**< Указатель на пользовательский контекст дескриптора. */
   const void *ParentHandle; /**< Внешний ("родительский") дескриптор. */
   SDeviceHandleLatestStatus LatestStatus; /**< Последнее состояние дескриптора (последняя ошибка или исключение). */
   SDeviceHandleIdentifier Identifier; /**< Идентификатор дескриптора. */
} SDeviceHandleHeader;

/**
 * @brief Мета-определение символа (идентификатора) структуры дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_HANDLE(device_name) _##device_name##SDeviceHandle

/**
 * @brief Создает предварительное объявление структуры дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_HANDLE_FORWARD_DECLARATION(device_name)                                                                \
   typedef struct SDEVICE_HANDLE(device_name) SDEVICE_HANDLE(device_name)

/**
 * @brief Создает объявление структуры данных дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_HANDLE_DECLARATION(device_name) struct SDEVICE_HANDLE(device_name)                                     \
{                                                                                                                      \
   SDeviceHandleHeader Header;                                                                                         \
   SDEVICE_INIT_DATA(device_name) Init;                                                                                \
   SDEVICE_RUNTIME_DATA(device_name) Runtime;                                                                          \
}

/**
 * @brief Создает объявления псевдонимов для типов данных, ассоциированных с модулем.
 * @details Упрощает написание и чтение кода модуля.
 * @n Создает следующие объявления:
 * - @code typedef SDEVICE_INIT_DATA(device_name) ThisInitData @endcode
 * - @code typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData @endcode
 * - @code typedef SDEVICE_HANDLE(device_name) ThisHandle @endcode
 *
 * @note Опциональная часть приватного интерфейса модуля.
 * @param device_name Название модуля.
 */
#define SDEVICE_INTERNAL_ALIASES_DECLARATION(device_name)                                                              \
   typedef SDEVICE_INIT_DATA(device_name) ThisInitData;                                                                \
   typedef SDEVICE_RUNTIME_DATA(device_name) ThisRuntimeData;                                                          \
   typedef SDEVICE_HANDLE(device_name) ThisHandle

/**
 * @brief Возвращает пользовательский контекст дескриптора @ref SDeviceHandleHeader::Context.
 * @param[in] handle Дескриптор.
 * @return Пользовательский контекст дескриптора @p handle.
 */
static inline void * SDeviceGetHandleContext(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->Context;
}

/**
 * @brief Возвращает последнее состояние дескриптора @ref SDeviceHandleHeader::LatestStatus.
 * @param[in] handle Дескриптор.
 * @return Последнее состояние дескриптора @p handle.
 */
static inline SDeviceHandleLatestStatus SDeviceGetHandleLatestStatus(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->LatestStatus;
}
/**
 * @brief Возвращает внешний дескриптор @ref SDeviceHandleHeader::ParentHandle.
 * @param[in] handle Дескриптор.
 * @return Внешний дескриптор дескриптора @p handle.
 */
static inline const void * SDeviceGetHandleParent(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->ParentHandle;
}

/**
 * @brief Возвращает идентификатор дескриптора @ref SDeviceHandleHeader::Identifier.
 * @param[in] handle Дескриптор.
 * @return Идентификатор дескриптора @p handle.
 */
static inline SDeviceHandleIdentifier SDeviceGetHandleIdentifier(const void *handle)
{
   const SDeviceHandleHeader *header = handle;
   return header->Identifier;
}

/** @} */

/**
 * @defgroup properties Свойства
 * @brief Инструменты описания свойств и взаимодействия с ними.
 * @details Свойства - универсальный интерфейс доступа к значению для записи и/или чтения.
 * Используются в модулях для доступа к внутренним данным модуля, а также вычисляемым значениям.
 * Делятся на:
 * - @ref common_properties
 * - @ref partial_properties
 * @{
 */

/**
 * @brief Результат операции чтения или записи свойства.
 */
typedef enum
{
    SDEVICE_PROPERTY_OPERATION_STATUS_OK,               /**< Операция выполнена успешно. */
    SDEVICE_PROPERTY_OPERATION_STATUS_VALIDATION_ERROR, /**< Ошибка проверки значения. */
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
 * @defgroup common_properties Обыкновенные свойства
 * @brief Инструменты описания обыкновенных свойств и взаимодействия с ними.
 * @details Интерфейс обыкновенных свойств обеспечивает доступ для записи и\или чтения к цельному значению.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup common_property_set Запись
 * @brief Инструменты описания функции записи обыкновенного свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
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
#define SDEVICE_SET_PROPERTY(device_name, property_name)                                                               \
   _##device_name##SDevice##property_name##SetProperty

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
 * @defgroup common_property_get Чтение
 * @brief Инструменты описания функции чтения обыкновенного свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
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
#define SDEVICE_GET_PROPERTY(device_name, property_name)                                                               \
   _##device_name##SDevice##property_name##GetProperty

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
 * @defgroup partial_properties Частичные свойства
 * @brief Инструменты описания частичных свойств и взаимодействия с ними.
 * @details Интерфейс частичных свойств обеспечивает доступ для записи и\или чтения к произвольному срезу значения.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup partial_property_set Запись
 * @brief Инструменты описания функции записи частичного свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров записываемого значения частичного свойства.
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
 * @param parameters_name Имя формального параметра параметров записываемого значения частичного свойства.
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
 * @param parameters_name Имя формального параметра параметров записываемого значения частичного свойства.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_SET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_SET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/**
 * @defgroup partial_property_get Чтение
 * @brief Инструменты описания функции чтения частичного свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров читаемого значения частичного свойства.
 */
typedef struct
{
   void *Data; /**< Указатель на буфер для читаемой части значения. */
   size_t Offset; /**< Смещение (в байтах) относительно начала полного значения, с которого начнется чтение. */
   size_t Size; /**< Размер (в байтах) читаемой части полного значения. */
} SDeviceGetPartialPropertyParameters;

/**
 * @brief Тип возвращаемого функцией чтения частичного обыкновенного свойства значения.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyOperationStatus

/**
 * @brief Список формальных параметров функции чтения частичного свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров читаемого значения частичного свойства.
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
 * @param parameters_name Имя формального параметра параметров читаемого значения частичного свойства.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_GET_PARTIAL_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_GET_PARTIAL_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/** @} */

/** @} */

/** @} */
