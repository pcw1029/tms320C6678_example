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
    System_printf("Gpio14 �Ǵ� Gpio15 Ʈ���� �߻����� ���� �̺�Ʈ 88 �Ǵ� 89 �ڵ鸵\n");
    System_printf("GPIO14 Interrupt count : %d, GPIO15 Interrupt count : %d\n", g_Inter14, g_Inter15);
}

void interruptOccurrenceIdleFunc()
{
    System_flush();
    gpioSettings(14);
    System_printf("\nGPIO 14 ��۸�\n");

    gpioSettings(15);
    System_printf("\n GPIO 15 ��۸�\n");
    System_flush();
}

void interruptGpioPinSet()
{
    gpioOutputDirSet(14);
    gpioInterruptRisingSet(14);

    gpioOutputDirSet(15);
    gpioInterruptRisingSet(15);

    gpioInterruptEnable();
    System_printf("���ͷ�Ʈ GPIO 14, 15 �� ���� �Ϸ�\n");
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
