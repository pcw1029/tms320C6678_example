/*
 *  ======== main.c ========
 */

#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

#include "gpioCtrl.h"

int g_Inter14;
int g_Inter15;

void gpio14Interrupt(UArg arg)
{
    g_Inter14++;
    if(g_Inter14 >= 1000)
        g_Inter14 = 0;
}

void gpio15Interrupt(UArg arg)
{
    g_Inter15++;
    if(g_Inter15 >= 1000)
        g_Inter15 = 0;
}

void hwiCombinGpio14Gpio15(UArg arg)
{
    System_printf("Gpio14 또는 Gpio15 트리거 발생으로 인해 이베트 88 또는 89 핸들링\n");
    System_printf("GPIO14 Interrupt count : %d, GPIO15 Interrupt count : %d\n", g_Inter14, g_Inter15);
}

void interruptOccurrenceIdleFunc()
{
    System_flush();
    gpioSettings(14);
    System_printf("\nGPIO 14 토글링\n");

    gpioSettings(15);
    System_printf("\n GPIO 15 토글링\n");
    System_flush();
}

void interruptGpioPinSet()
{
    gpioOutputDirSet(14);
    gpioInterruptRisingSet(14);

    gpioOutputDirSet(15);
    gpioInterruptRisingSet(15);

    gpioInterruptEnable();
    System_printf("인터럽트 GPIO 14, 15 핀 설정 완료\n");
}

/*
 *  ======== main ========
 */
Int main()
{ 
    g_Inter14 = 0;
    g_Inter15 = 0;
    interruptGpioPinSet();
    System_flush(); // print the buffer that was set in the hwi functions
    BIOS_start();    /* does not return */
    return(0);
}
