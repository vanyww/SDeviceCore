#include "SDeviceCore/common.h"

typedef struct
{
   int A;
   short B;
} ExampleStructure;

static int sizeOfA = SIZEOF_MEMBER(ExampleStructure, A); /* <- sizeof(int) */
static int sizeOfB = SIZEOF_MEMBER(ExampleStructure, B); /* <- sizeof(short) */
