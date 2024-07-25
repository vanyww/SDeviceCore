/**
 * @file SDeviceCore/core.h
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

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * @defgroup sdevice_core Ядро фреймворка SDevice
 * @brief @copybrief SDeviceCore/core.h
 * @details @copydetails SDeviceCore/core.h
 * @{
 */

/**
 * @brief Версия модуля.
 * @details Тип данных, используемый для хранения версии модулей.
 */
typedef struct
{
   uint16_t Major; /**< Старшая компонента версии. */
   uint8_t  Minor; /**< Средняя компонента версии. */
   uint8_t  Patch; /**< Младшая компонента версии. */
} SDeviceVersion;

/**
 * @brief Старшая компонента версии ядра фреймворка SDevice.
 */
#define SDEVICE_CORE_VERSION_MAJOR 9

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
#define SDEVICE_CORE_VERSION (                                                                                         \
   (SDeviceVersion)                                                                                                    \
   {                                                                                                                   \
      .Major = SDEVICE_CORE_VERSION_MAJOR,                                                                             \
      .Minor = SDEVICE_CORE_VERSION_MINOR,                                                                             \
      .Patch = SDEVICE_CORE_VERSION_PATCH                                                                              \
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
#define SDEVICE_INIT_DATA(device_name) $##device_name##SDeviceInitData

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
#define SDEVICE_RUNTIME_DATA(device_name) $##device_name##SDeviceRuntimeData

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
#define SDEVICE_CREATE_HANDLE(device_name) $##device_name##SDeviceCreateHandle

/**
 * @brief Тип возвращаемого функцией создания дескриптора значения.
 */
#define SDEVICE_CREATE_HANDLE_RETURN_VALUE void *

/**
 * @brief Список формальных параметров функции создания дескриптора.
 * @param init_data_name Имя формального параметра параметров инициализации дескриптора.
 * @param owner_name Имя формального параметра указателя на владельца (внешний дескриптор).
 * @param identifier_name Имя формального параметра идентификатора дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, owner_name, identifier_name, context_name)                     \
   (const void *init_data_name, void *owner_name, SDeviceHandleIdentifier identifier_name, void *context_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию создания дескриптора.
 * @param pointer_name Имя создаваемой переменной.
 */
#define SDEVICE_CREATE_HANDLE_POINTER(pointer_name)                                                                    \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE (* pointer_name) SDEVICE_CREATE_HANDLE_ARGUMENTS(,,,)

/**
 * @brief Создает прототип (объявление) функции создания дескриптора.
 * @param device_name Название модуля.
 * @param init_data_name Имя формального параметра данных инициализации дескриптора.
 * @param owner_name Имя формального параметра указателя на внешний дескриптор.
 * @param identifier_name Имя формального параметра идентификатора дескриптора.
 * @param context_name Имя формального параметра пользовательского контекста дескриптора.
 */
#define SDEVICE_CREATE_HANDLE_DECLARATION(device_name, init_data_name, owner_name, identifier_name, context_name)      \
   SDEVICE_CREATE_HANDLE_RETURN_VALUE                                                                                  \
   SDEVICE_CREATE_HANDLE(device_name)                                                                                  \
   SDEVICE_CREATE_HANDLE_ARGUMENTS(init_data_name, owner_name, identifier_name, context_name)

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
#define SDEVICE_DISPOSE_HANDLE(device_name) $##device_name##SDeviceDisposeHandle

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
 * @brief Тип данных состояния дескриптора.
 */
typedef int16_t SDeviceHandleStatus;

/**
 * @brief Тип данных UUID.
 */
typedef struct
{
   uint64_t High; /**< Старшая часть UUID. */
   uint64_t Low;  /**< Младшая часть UUID. */
} SDeviceUuid;

/**
 * @brief Тип данных идентификационного блока модуля дескриптора.
 */
typedef struct
{
   SDeviceUuid    Uuid;    /**< UUID модуля. */
   SDeviceVersion Version; /**< Версия модуля. */
} SDeviceIdentityBlock;

/**
 * @brief Заголовок дескриптора.
 * @details Структура данных, общая для всех дескрипторов.
 */
typedef struct
{
   void                       *Context;       /**< Указатель на пользовательский контекст дескриптора. */
   void                       *OwnerHandle;   /**< Указатель на владельца дескриптора (внешний дескриптор). */
   const SDeviceIdentityBlock *IdentityBlock; /**< Идентификационный блок модуля дескриптора. */
   SDeviceHandleStatus         LatestStatus;  /**< Последнее состояние дескриптора (ошибка или исключение). */
   SDeviceHandleIdentifier     Identifier;    /**< Идентификатор дескриптора. */
} SDeviceHandleHeader;

/**
 * @brief Обобщенный дескриптор.
 * @details Структура данных, используемая для доступа к общим данных дескрипторов.
 */
typedef struct
{
   SDeviceHandleHeader Header;  /**< Заголовок дескриптора. */
   void      *restrict Init;    /**< @ref handle_init_data "Параметры инициализации" дескриптора. */
   void      *restrict Runtime; /**< @ref handle_runtime_data "Параметры времени выполнения" дескриптора. */
} __attribute__((may_alias)) SDeviceCommonHandle;

/**
 * @brief Сравнивает идентификаторы @ref SDeviceUuid.
 * @param[in] uuid$0 Первый UUID.
 * @param[in] uuid$1 Второй UUID.
 * @return `true`, если @p uuid$0 равен @p uuid$1, иначе - `false`.
 */
bool SDeviceCompareUuids(const SDeviceUuid *uuid$0, const SDeviceUuid *uuid$1);

/**
 * @brief Сравнивает версии @ref SDeviceVersion.
 * @param[in] version$0 Первая версия.
 * @param[in] version$1 Вторая версия.
 * @return `true`, если @p version$0 равна @p version$1, иначе - `false`.
 */
bool SDeviceCompareVersions(const SDeviceVersion *version$0, const SDeviceVersion *version$1);

/**
 * @brief Сравнивает идентификационные блоки @ref SDeviceIdentityBlock.
 * @param[in] identity$0 Первый идентификационный блок.
 * @param[in] identity$1 Второй идентификационный блок.
 * @return `true`, если @p identity$0 равен @p identity$1, иначе - `false`.
 */
bool SDeviceCompareIdentityBlocks(const SDeviceIdentityBlock *identity$0, const SDeviceIdentityBlock *identity$1);

/**
 * @brief Мета-определение символа (идентификатора) структуры дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_HANDLE(device_name) $##device_name##SDeviceHandle

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
#define SDEVICE_HANDLE_DECLARATION(device_name)                                                                        \
   struct SDEVICE_HANDLE(device_name)                                                                                  \
   {                                                                                                                   \
      SDeviceHandleHeader                Header;                                                                       \
      SDEVICE_INIT_DATA(device_name)    *Init;                                                                         \
      SDEVICE_RUNTIME_DATA(device_name) *Runtime;                                                                      \
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
 * @defgroup identity_block Идентификационный блок модуля дескриптора
 * @brief Инструменты описания идентификационного блока модуля дескриптора и взаимодействия с ним.
 * @details Идентификационный блок используется для определения модуля по его дескриптору.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) переменной идентификационного блока модуля дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_IDENTITY_BLOCK(device_name) $##device_name##SDeviceIdentityBlock

/**
 * @brief Создает объявление переменной идентификационного блока модуля дескриптора.
 * @param device_name Название модуля.
 */
#define SDEVICE_IDENTITY_BLOCK_DECLARATION(device_name)                                                                \
   extern const SDeviceIdentityBlock SDEVICE_IDENTITY_BLOCK(device_name)

/**
 * @brief Создает определение переменной идентификационного блока модуля дескриптора.
 * @param uuid UUID модуля типа @ref SDeviceUuid.
 * @param version Версия модуля типа @ref SDeviceVersion.
 */
#define SDEVICE_IDENTITY_BLOCK_DEFINITION(device_name, uuid, version)                                                  \
   const SDeviceIdentityBlock SDEVICE_IDENTITY_BLOCK(device_name) =                                                    \
   {                                                                                                                   \
      .Uuid    = (uuid),                                                                                               \
      .Version = (version)                                                                                             \
   }

#define SDEVICE_IS_VALID_HANDLE(device_name, handle) (                                                                 \
   {                                                                                                                   \
      void *$$handle = (handle);                                                                                       \
                                                                                                                       \
      $$handle &&                                                                                                      \
      SDeviceCompareIdentityBlocks(                                                                                    \
            &SDEVICE_IDENTITY_BLOCK(device_name),                                                                      \
            SDeviceGetHandleIdentityBlock($$handle));                                                                  \
   })

/** @} */

/**
 * @brief Возвращает указатель на пользовательский контекст дескриптора @ref SDeviceHandleHeader::Context.
 * @param[in] handle Дескриптор.
 * @return Указатель на пользовательский контекст дескриптора @p handle.
 */
__attribute__((always_inline))
static inline void * SDeviceGetHandleContext(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Header.Context;
}

/**
 * @brief Возвращает указатель на владельца дескриптора (внешний дескриптор) @ref SDeviceHandleHeader::OwnerHandle.
 * @param[in] handle Дескриптор.
 * @return Указатель на владельца дескриптора @p handle.
 */
__attribute__((always_inline))
static inline void * SDeviceGetHandleOwnerHandle(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Header.OwnerHandle;
}

/**
 * @brief Возвращает идентификационный блок модуля дескриптора @ref SDeviceHandleHeader::IdentityBlock.
 * @param[in] handle Дескриптор.
 * @return Идентификационный блок модуля дескриптор @p handle.
 */
__attribute__((always_inline))
static inline const SDeviceIdentityBlock * SDeviceGetHandleIdentityBlock(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Header.IdentityBlock;
}

/**
 * @brief Возвращает последнее состояние дескриптора @ref SDeviceHandleHeader::LatestStatus.
 * @param[in] handle Дескриптор.
 * @return Последнее состояние дескриптора @p handle.
 */
__attribute__((always_inline))
static inline SDeviceHandleStatus SDeviceGetHandleLatestStatus(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Header.LatestStatus;
}

/**
 * @brief Возвращает идентификатор дескриптора @ref SDeviceHandleHeader::Identifier.
 * @param[in] handle Дескриптор.
 * @return Идентификатор дескриптора @p handle.
 */
__attribute__((always_inline))
static inline SDeviceHandleIdentifier SDeviceGetHandleIdentifier(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Header.Identifier;
}

/**
 * @brief Возвращает "параметры инициализации" дескриптора @ref SDeviceCommonHandle::Init.
 * @param[in] handle Дескриптор.
 * @return "Параметры инициализации" дескриптора @p handle.
 */
__attribute__((always_inline))
static inline const void * SDeviceGetHandleInitData(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Init;
}

/**
 * @brief Возвращает "параметры времени выполнения" дескриптора @ref SDeviceCommonHandle::Runtime.
 * @param[in] handle Дескриптор.
 * @return "Параметры времени выполнения" дескриптора @p handle.
 */
__attribute__((always_inline))
static inline void * SDeviceGetHandleRuntimeData(const void *handle)
{
   const SDeviceCommonHandle *_handle = handle;
   return _handle->Runtime;
}

/** @} */

/**
 * @defgroup properties Свойства
 * @brief Инструменты описания свойств и взаимодействия с ними.
 * @details Свойства - универсальный интерфейс доступа к значению для записи и/или чтения.
 * Используются в модулях для доступа к внутренним данным модуля, а также вычисляемым значениям.
 * Делятся на:
 * - @ref simple_properties
 * - @ref partial_properties
 * - @ref indexer_properties
 * @{
 */

/**
 * @brief Результат операции чтения или записи свойства.
 */
typedef enum
{
   SDEVICE_PROPERTY_STATUS_OK,               /**< Операция выполнена успешно. */
   SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR, /**< Ошибка проверки значения. */
   SDEVICE_PROPERTY_STATUS_PROCESSING_ERROR  /**< Ошибка во время записи или чтения значения. */
} SDevicePropertyStatus;

/**
 * @brief Проверяет значение на соответствие членам перечисления @ref SDevicePropertyStatus.
 * @param[in] value Значение, соответствие которого необходимо проверить.
 * @return `true`, если @p value является членом перечисления @ref SDevicePropertyStatus, иначе - `false`.
 */
#define SDEVICE_IS_VALID_PROPERTY_OPERATION_STATUS(value) (                                                            \
   {                                                                                                                   \
      __auto_type $$value = (value);                                                                                   \
      $$value == SDEVICE_PROPERTY_STATUS_OK               ||                                                           \
      $$value == SDEVICE_PROPERTY_STATUS_VALIDATION_ERROR ||                                                           \
      $$value == SDEVICE_PROPERTY_STATUS_PROCESSING_ERROR;                                                             \
   })

/**
 * @brief Мета-определение символа (имени) типа данных свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_PROPERTY_TYPE(device_name, property_name)                                                              \
   $##device_name##SDevice##property_name##PropertyType

/**
 * @brief Создает объявление типа данных свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param type Тип данных свойства.
 */
#define SDEVICE_PROPERTY_TYPE_DECLARATION(device_name, property_name, type)                                            \
   typedef type SDEVICE_PROPERTY_TYPE(device_name, property_name)

/**
 * @defgroup simple_properties Простые свойства
 * @brief Инструменты описания простых свойств и взаимодействия с ними.
 * @details Интерфейс простых свойств обеспечивает доступ к целому значению.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @defgroup simple_property_set Запись
 * @brief Инструменты описания функции записи простого свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Тип возвращаемого функцией записи простого свойства значения.
 */
#define SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE SDevicePropertyStatus

/**
 * @brief Список формальных параметров функции записи простого свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на записываемое значение.
 */
#define SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, const void *value_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию записи простого свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_SET_SIMPLE_PROPERTY_POINTER(pointer_name)                                                              \
   SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции записи простого свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_SET_SIMPLE_PROPERTY(device_name, property_name)                                                        \
   $##device_name##SDevice##property_name##SetSimpleProperty

/**
 * @brief Создает прототип (объявление) функции записи простого свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на записываемое значение.
 */
#define SDEVICE_SET_SIMPLE_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                   \
   SDEVICE_SET_SIMPLE_PROPERTY_RETURN_VALUE                                                                            \
   SDEVICE_SET_SIMPLE_PROPERTY(device_name, property_name)                                                             \
   SDEVICE_SET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name)

/** @} */

/**
 * @defgroup simple_property_get Чтение
 * @brief Инструменты описания функции чтения простого свойства и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Тип возвращаемого функцией чтения простого свойства значения.
 */
#define SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE SDevicePropertyStatus

/**
 * @brief Список формальных параметров функции чтения простого свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на буфер для читаемого значения.
 */
#define SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name) (void *handle_name, void *value_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию чтения простого свойства.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_GET_SIMPLE_PROPERTY_POINTER(pointer_name)                                                              \
   SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции чтения простого свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_GET_SIMPLE_PROPERTY(device_name, property_name)                                                        \
   $##device_name##SDevice##property_name##GetSimpleProperty

/**
 * @brief Создает прототип (объявление) функции чтения простого свойства.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param value_name Имя формального параметра указателя на буфер для читаемого значения.
 */
#define SDEVICE_GET_SIMPLE_PROPERTY_DECLARATION(device_name, property_name, handle_name, value_name)                   \
   SDEVICE_GET_SIMPLE_PROPERTY_RETURN_VALUE                                                                            \
   SDEVICE_GET_SIMPLE_PROPERTY(device_name, property_name)                                                             \
   SDEVICE_GET_SIMPLE_PROPERTY_ARGUMENTS(handle_name, value_name)

/** @} */

/** @} */

/**
 * @defgroup partial_properties Частичные свойства
 * @brief Инструменты описания частичных свойств и взаимодействия с ними.
 * @details Интерфейс частичных свойств обеспечивает доступ к произвольному срезу значения.
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
   const void *Data;   /**< Указатель на записываемую часть значения. */
   size_t      Offset; /**< Смещение (в байтах) относительно начала полного значения, с которого начнется запись. */
   size_t      Size;   /**< Размер (в байтах) записываемой части полного значения. */
} SDeviceSetPartialPropertyParameters;

/**
 * @brief Тип возвращаемого функцией записи частичного свойства значения.
 */
#define SDEVICE_SET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyStatus

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
   $##device_name##SDevice##property_name##SetPartialProperty

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
   void  *Data;   /**< Указатель на буфер для читаемой части значения. */
   size_t Offset; /**< Смещение (в байтах) относительно начала полного значения, с которого начнется чтение. */
   size_t Size;   /**< Размер (в байтах) читаемой части полного значения. */
} SDeviceGetPartialPropertyParameters;

/**
 * @brief Тип возвращаемого функцией чтения частичного обыкновенного свойства значения.
 */
#define SDEVICE_GET_PARTIAL_PROPERTY_RETURN_VALUE SDevicePropertyStatus

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
   $##device_name##SDevice##property_name##GetPartialProperty

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

/**
 * @defgroup indexer_properties Свойства-индексаторы
 * @brief Инструменты описания свойств-индексаторов и взаимодействия с ними.
 * @details Интерфейс свойств-индексаторов обеспечивает доступ к произвольным элементам значения.
 * @n Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Мета-определение символа (имени) длины свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_INDEXER_PROPERTY_LENGTH(device_name, property_name)                                                    \
   $##device_name##SDevice##property_name##IndexerPropertyLength

/**
 * @brief Определение длины свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param length Длина свойства.
 */
#define SDEVICE_INDEXER_PROPERTY_LENGTH_DEFINITION(device_name, property_name, length)                                 \
   enum { SDEVICE_INDEXER_PROPERTY_LENGTH(device_name, property_name) = length };

/**
 * @defgroup indexer_property_set Запись
 * @brief Инструменты описания функции записи свойства-индексатора и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров записываемого значения свойства-индексатора.
 */
typedef struct
{
   const void *const *Items;    /**< Указатель на записываемую коллекцию элементов. */
   size_t             StartIdx; /**< Индекс элемента, с которого начнется запись. */
   size_t             Length;   /**< Количество записываемых элементов. */
} SDeviceSetIndexerPropertyParameters;

/**
 * @brief Тип возвращаемого функцией записи свойства-индексатора значения.
 */
#define SDEVICE_SET_INDEXER_PROPERTY_RETURN_VALUE SDevicePropertyStatus

/**
 * @brief Список формальных параметров функции записи свойства-индексатора.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров записываемого значения свойства-индексатора.
 */
#define SDEVICE_SET_INDEXER_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceSetIndexerPropertyParameters *parameters_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию записи свойства-индексатора.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_SET_INDEXER_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_SET_INDEXER_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_SET_INDEXER_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции записи свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_SET_INDEXER_PROPERTY(device_name, property_name)                                                       \
   $##device_name##SDevice##property_name##SetIndexerProperty

/**
 * @brief Создает прототип (объявление) функции записи свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров записываемого значения свойства-индексатора.
 */
#define SDEVICE_SET_INDEXER_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_SET_INDEXER_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_SET_INDEXER_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_SET_INDEXER_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/**
 * @defgroup indexer_property_get Чтение
 * @brief Инструменты описания функции чтения свойства-индексатора и взаимодействия с ней.
 * @details Пример применения приведен в @link sdevice_core описании ядра фреймворка @endlink.
 * @{
 */

/**
 * @brief Структура данных параметров читаемого значения свойства-индексатора.
 */
typedef struct
{
   void *const *Items;    /**< Указатель на буфер для читаемой коллекции элементов. */
   size_t       StartIdx; /**< Индекс элемента, с которого начнется чтение. */
   size_t       Length;   /**< Количество читаемых элементов. */
} SDeviceGetIndexerPropertyParameters;

/**
 * @brief Тип возвращаемого функцией чтения свойства-индексатора значения.
 */
#define SDEVICE_GET_INDEXER_PROPERTY_RETURN_VALUE SDevicePropertyStatus

/**
 * @brief Список формальных параметров функции чтения свойства-индексатора.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров читаемого значения свойства-индексатора.
 */
#define SDEVICE_GET_INDEXER_PROPERTY_ARGUMENTS(handle_name, parameters_name)                                           \
   (void *handle_name, const SDeviceGetIndexerPropertyParameters *parameters_name)

/**
 * @brief Создает переменную (или член структуры) типа указателя на функцию чтения свойства-индексатора.
 * @param pointer_name Имя указателя.
 */
#define SDEVICE_GET_INDEXER_PROPERTY_POINTER(pointer_name)                                                             \
   SDEVICE_GET_INDEXER_PROPERTY_RETURN_VALUE (* pointer_name) SDEVICE_GET_INDEXER_PROPERTY_ARGUMENTS(,)

/**
 * @brief Мета-определение символа (имени) функции чтения свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 */
#define SDEVICE_GET_INDEXER_PROPERTY(device_name, property_name)                                                       \
   $##device_name##SDevice##property_name##GetIndexerProperty

/**
 * @brief Создает прототип (объявление) функции чтения свойства-индексатора.
 * @param device_name Название модуля.
 * @param property_name Название свойства.
 * @param handle_name Имя формального параметра дескриптора.
 * @param parameters_name Имя формального параметра параметров читаемого значения свойства-индексатора.
 */
#define SDEVICE_GET_INDEXER_PROPERTY_DECLARATION(device_name, property_name, handle_name, parameters_name)             \
   SDEVICE_GET_INDEXER_PROPERTY_RETURN_VALUE                                                                           \
   SDEVICE_GET_INDEXER_PROPERTY(device_name, property_name)                                                            \
   SDEVICE_GET_INDEXER_PROPERTY_ARGUMENTS(handle_name, parameters_name)

/** @} */

/** @} */

/** @} */

/** @} */
