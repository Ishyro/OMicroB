//#ifndef OPT_SYSTEM_INTERNAL
#define OPT_SYSTEM_INTERNAL
//#endif

#include "cores/System_Defs.h"
#include "cores/Arduino.h"

//extern "C" { // nécessaire avec pic32-g++
extern void __use_isr_install(void);
__attribute__((section(".comment"))) void (*__use_force_isr_install)(void) = &__use_isr_install;
//}

int main(void) {
  init(); // important, au moins pour les timers
  pinMode(LED_BUILTIN, OUTPUT); // setup(), nécessaire pour raison ?
  int * addr = (int *) 0xBF88603C; // LATA10INV
  while(1) {
    _scheduleTask(); // nécessaire
    *addr = 0x0400; // INV bit 10
    delay(1000);;
        //if (serialEventRun) serialEventRun(); // on doit pouvoir s'en passer, nécessite pic32-g++
  }
  return 0;
}
