#include "SDeviceCore/common.h"

void main(int value)
{
   if(likely(value > 10))
   {
      /* оптимизированный путь */
   }
   else
   {
      /* неоптимизированный путь */
   }
}
