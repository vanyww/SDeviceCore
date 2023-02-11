# SDeviceCore - ядро интерфейса модулей SDevice

Библиотека определяет макросы, функции и значения, позволяющие создавать универсальные модули (SDevice'ы) с единым расширяемым интерфейсом. Библиотека также предоставляет способ логирования, проверки утверждений (assertions) двух типов, а также обработки исключений на основе библиотеки [CExceptions](https://github.com/ThrowTheSwitch/CException), включенной в нее в качестве подмодуля.

## Зависимости

* [CExceptions](https://gitlab.dnouglublenie.ru/nonius/embeddedfirmware/embeddedcommon/forks/cexception.git)

## Создание нового модуля

### Публичный интерфейс

Для определения публичного интерфейса используется заголовочный файл библиотеки `core.h`.

1. Модуль *может* определить свою версию, используя предопределенную структуру `SDeviceVersion`.
2. Модуль **обязан** определить неполный тип данных (handle), хранящий внутреннее состояние экземпляра модуля, его параметры и служебную информацию, используя макрос `SDEVICE_HANDLE_FORWARD_DECLARATION`.
3. Модуль *может* определить тип-перечисление, описывающий исключения, которые могут возникнуть в ходе его работы.
4. Модуль **обязан** определить тип-перечисление, описывающий состояния для логирования, которые могут возникнуть в ходе его работы.
5. Модуль **обязан** определить полный тип данных, передаваемый ему в момент создания нового экземпляра модуля `SDEVICE_INIT_DATA_FORWARD_DECLARATION` и `SDEVICE_INIT_DATA`.
6. Модуль **обязан** объявить внешний символ для обращения к текстовому имени модуля, используя макрос `SDEVICE_STRING_NAME_DECLARATION`.
7. Модуль **обязан** объявить функции создания и удаления экземпляра модуля, используя макросы `SDEVICE_CREATE_HANDLE_DECLARATION` и `SDEVICE_DISPOSE_HANDLE_DECLARATION`.
8. Модуль *может* объявить обычные свойства для чтения и\или записи, используя макросы `SDEVICE_PROPERTY_TYPE_DECLARATION`, `SDEVICE_GET_PROPERTY_DECLARATION` и `SDEVICE_SET_PROPERTY_DECLARATION`.
9. Модуль *может* объявить частичные свойства для чтения и\или записи, используя макросы `SDEVICE_PROPERTY_TYPE_DECLARATION`, `SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION` и `SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION`.
10. Модуль *может* объявить обычные функции для взаимодействия с экземплярами модуля.

Результирующий публичный интерфейс модуля `Example` может выглядеть следующим образом (заголовочный файл):

```c
#include "SDeviceCore/core.h"

/* -1- */
#define EXAMPLE_SDEVICE_VERSION_MAJOR 1
#define EXAMPLE_SDEVICE_VERSION_MINOR 0
#define EXAMPLE_SDEVICE_VERSION_PATCH 0
#define EXAMPLE_SDEVICE_CORE_VERSION ((SDeviceVersion) \
{                                                      \
   .Major = EXAMPLE_SDEVICE_VERSION_MAJOR,             \
   .Minor = EXAMPLE_SDEVICE_VERSION_MINOR,             \
   .Patch = EXAMPLE_SDEVICE_VERSION_PATCH              \
})

/* -2- */
SDEVICE_HANDLE_FORWARD_DECLARATION(Example);
SDEVICE_INIT_DATA_FORWARD_DECLARATION(Example);.

/* -3- */
typedef enum
{
   EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_0,
   EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_1,
   /* any other exceptions to throw */
} ExampleSDeviceException;

/* -4- */
typedef enum
{
   EXAMPLE_SDEVICE_STATUS_OK,
   EXAMPLE_SDEVICE_STATUS_ERROR_1,
   EXAMPLE_SDEVICE_STATUS_ERROR_2,
   EXAMPLE_SDEVICE_STATUS_ERROR_3
   /* any other status entries to log */
} ExampleSDeviceStatus;

/* -5- */
struct SDEVICE_INIT_DATA(Example)
{
    /* any init data: callbacks, constants */
}

/* -6- */
SDEVICE_STRING_NAME_DECLARATION(Example);

/* -7- */
SDEVICE_CREATE_HANDLE_DECLARATION(Example, _init, _context, _outerNameNode);
SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, _handlePointer);

/* -8- */
SDEVICE_PROPERTY_TYPE_DECLARATION(Example, Property, int);
SDEVICE_GET_PROPERTY_DECLARATION(Example, Property, handle, value);
SDEVICE_SET_PROPERTY_DECLARATION(Example, Property, handle, value);

/* -9- */
SDEVICE_PROPERTY_TYPE_DECLARATION(Example, PartialProperty, char[64]);
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, PartialProperty, handle, value);
SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, PartialProperty, handle, value);

/* -10- */
void CommonInterfaceFunction(SDEVICE_HANDLE(Example) *handle);

```

### Приватный интерфейс

Для определения приватного интерфейса используется заголовочный файл публичного интерфейса (предположим, что он называется `core.h` и находится в папке `Example`).

1. Модуль **обязан** определить полный тип данных, используемый для хранения приватного динамического внутреннего состояния объекта, используя макросы `SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION` и `SDEVICE_RUNTIME_DATA`.
2. Модуль **обязан** определить полный тип данных представляющий собой экземпляр модуля, используя макрос `SDEVICE_HANDLE_DECLARATION`.
3. Модуль *может* объявить ряд приватных псевдонимов для типов данных, используя макрос `SDEVICE_INTERNAL_ALIASES_DECLARATION`.

Результирующий приватный интерфейс модуля `Example` может выглядеть следующим образом (заголовочный файл):

```c
#include "Example/core.h"

/* -1- */
SDEVICE_RUNTIME_DATA_FORWARD_DECLARATION(Example);

struct SDEVICE_RUNTIME_DATA(Example)
{
    /* any dynamic runtime data */
};

/* -2- */
SDEVICE_HANDLE_DECLARATION(Example);

/* -3- */
SDEVICE_INTERNAL_ALIASES_DECLARATION(Example);
```

### Реализация интерфейса

При реализации интерфейса используется его приватная часть, т.к. она уже включает в себя публичную. Предположим, что приватный интерфейс описан в файле `private.h`, который находится в одной папке с файлом, в котором планируется этот интерфейс реализовать.

1. Модуль **обязан** определить текстовое имя модуля, используя макрос `SDEVICE_STRING_NAME_DEFINITION`.
2. Модуль **обязан** определить функции создания и удаления экземпляра модуля, используя макросы `SDEVICE_CREATE_HANDLE_DECLARATION` и `SDEVICE_DISPOSE_HANDLE_DECLARATION`.
3. Модуль *может* определить обычные свойства для чтения и\или записи, используя макросы `SDEVICE_GET_PROPERTY_DECLARATION` и `SDEVICE_SET_PROPERTY_DECLARATION`.
4. Модуль *может* определить частичные свойства для чтения и\или записи, используя макросы `SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION` и `SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION`.
5. Модуль *может* определить обычные функции для взаимодействия с экземплярами модуля.

Результирующая реализация интерфейса модуля `Example` может выглядеть следующим образом (файл исходного кода):

```c
#include "private.h"

#include "SDeviceCore/heap.h"
#include "SDeviceCore/errors.h"

/* -1- */
SDEVICE_STRING_NAME_DEFINITION(Example);

/* -2- */
SDEVICE_CREATE_HANDLE_DECLARATION(Example, _init, _context, _outerNameNode)
{
    SDeviceAssert(_init != NULL);

    ThisHandle *handle = SDeviceMalloc(sizeof(ThisHandle));
    handle->Header = (SDeviceHandleHeader)
    {
        .Context = _context,
        .NameNode = { .Name = SDEVICE_STRING_NAME(Example), .OuterNode = _outerNameNode },
        .LatestStatus = EXAMPLE_SDEVICE_STATUS_OK
    };
    const ThisInitData *init = _init;
    handle->Init = *init;
    handle->Runtime = (ThisRuntimeData){ };

    return handle;
}

SDEVICE_DISPOSE_HANDLE_DECLARATION(Example, _handlePointer)
{
    SDeviceAssert(_handlePointer != NULL);

    ThisHandle **handlePointer = _handlePointer;
    ThisHandle *handle = *handlePointer;

    SDeviceAssert(handle != NULL);

    SDeviceFree(*handlePointer);
    *handlePointer = NULL;
}

/* -3- */
SDEVICE_GET_PROPERTY_DECLARATION(Example, Property, handle, value)
{
    /* read value to "value" parameter */
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PROPERTY_DECLARATION(Example, Property, handle, value)
{
    /* write value from "value" parameter */
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

/* -4- */
SDEVICE_GET_PARTIAL_PROPERTY_DECLARATION(Example, PartialProperty, handle, value)
{
    /* read value part to "value" parameter */
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

SDEVICE_SET_PARTIAL_PROPERTY_DECLARATION(Example, PartialProperty, handle, value)
{
    /* write value part from "value" parameter */
    return SDEVICE_PROPERTY_OPERATION_STATUS_OK;
}

/* -5- */
void CommonInterfaceFunction(SDEVICE_HANDLE(Example) *handle)
{
    /* perform any actions */
    return;
}
```

## Обработка ошибок и логирование

Средства, используемые для обработки ошибок и логирования содержатся в заголовочном файле `errors.h`.

### Проверка утверждений (assertions)

Для проверки утверждений используются два макроса: `SDeviceAssert` и `SDeviceDebugAssert`. Предлагается использовать первый для проверки фактических параметров при вызове процедур модуля, в то время, как второй - для проверки утверждений внутри модуля. Такое разделение позволит сократить объем кода в отладочной версии конечного приложения, отключив проверку утверждений, переданных в `SDeviceDebugAssert`. В оптимизированной же версии конечного приложения имеет смысл полностью отключить проверку утверждений.

```c
SDeviceAssert(1 == 1);
SDeviceDebugAssert(2 == 2);
```

В случае, если утверждение при проверке оказывается ложным, происходит вызов соответствующей процедуры - `SDeviceProcessAssertFail`. Данная процедура имеет определение по умолчанию в виде слабого символа, что позволяет ее переопределить.

```c
void SDeviceProcessAssertFail(char *file, int line)
{
    for(;;) { }
}
```

Флаги настройки проверки утверждений:

* `SDEVICE_USE_ASSERT` - включает проверку утверждений при помощи макроса `SDeviceAssert`.
* `SDEVICE_USE_DEBUG_ASSERT` - включает проверку утверждений при помощи макроса `SDeviceDebugAssert`.
* `SDEVICE_USE_SIMPLE_ASSERT` - изменяет прототип процедуры `SDeviceProcessAssertFail`, убирая из него формальные параметры имени файла и номера строки.

### Логирование

Логирование состояний происходит с помощью макроса `SDeviceLogStatus`. Данный макрос вызывает процедуру `SDeviceProcessLogStatus`, которая определена по умолчанию в виде слабого символа, что позволяет ее переопределить.

```c
SDeviceLogStatus(handle, EXAMPLE_SDEVICE_STATUS_ERROR_1);
```

Для идентификации экземпляра модуля, переданного в качестве фактического параметра может использоваться его именной узел, содержащий указатель на текстовое имя модуля, а также указатель на именной узел внешнего экземпляра модуля, в который входит переданный, в качестве зависимости.

```c
SDeviceProcessLogStatus(const void *_handle)
{
    int32_t status = SDeviceGetHandleLatestStatus(_handle);
    const SDeviceNameNode *nameNode = SDeviceGetHandleNameNodePointer(_handle);

    for(;;) { }
}
```

Флаги настройки проверки утверждений:

* `SDEVICE_USE_STATUS_LOG` - включает логирование с помощью макроса `SDeviceLogStatus`.

### Обработка исключений

Для обработки исключений используются средства библиотеки `CExceptions`, а также макрос `SDeviceThrow`.

```c

try
{
    SDeviceThrow(handle, EXAMPLE_SDEVICE_EXCEPTION_SOME_EXCEPTION_0);
}
catch(e)
{
    /* e - const void *handle */
    /* process exception */
}

```

Также, в случае, если исключение не было обработано, произойдет вызов процедуры `SDeviceProcessUnhandledThrow`, которая определена по умолчанию в виде слабого символа, что позволяет ее переопределить.

```c
void SDeviceProcessUnhandledThrow(CEXCEPTION_T _handle)
{
    int32_t status = SDeviceGetHandleLatestStatus(_handle);
    const SDeviceNameNode *nameNode = SDeviceGetHandleNameNodePointer(_handle);

    for(;;) { }
}
```

## Динамическое выделение памяти

При создании (и удалении) экземпляров модулей используются механизм динамического выделения памяти, реализованный процедурами `SDeviceMalloc` и `SDeviceFree`. Обе процедуры определены в виде слабых символов, что позволяет из переопределить. Реализация по умолчанию использует вызовы `malloc` и `free` стандартной библиотеки.

```c
void * SDeviceMalloc(size_t size)
{
   void *memory = malloc(size);

   if(memory == NULL)
      SDeviceThrow(CoreGlobalSDeviceHandle, CORE_GLOBAL_SDEVICE_EXCEPTION_OUT_OF_MEMORY);

   return memory;
}

void SDeviceFree(void *_handle)
{
   free(_handle);
}
```
