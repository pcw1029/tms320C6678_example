/*
 * gpioCtrl.c
 *
 *  Created on: 2020. 9. 25.
 *      Author: pcw10
 */


#include "gpioCtrl.h"

//GPIO관련 문서 참고 : https://www.ti.com/lit/ug/sprugv1/sprugv1.pdf

void gpioOutputDirSet(int i_iGpioNumber)
{
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_DIR) &= 0xFFFFFFFF ^ (1  << i_iGpioNumber);
}

void gpioInputDirSet(int i_iGpioNumber)
{
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_DIR) |= (1  << i_iGpioNumber);
}

void gpioInterruptRisingSet(int i_iGpioNumber)
{
    // Rising Edge 설정
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_SET_RIS_TRIG) |= (1 << i_iGpioNumber);
    // Falling Edge Clear
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_SET_FAL_TRIG) &= 0xFFFFFFFF ^ (1  << i_iGpioNumber);
}

void gpioInterruptFallingSet(int i_iGpioNumber)
{
    // Falling Edge 설정
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_SET_FAL_TRIG) |= (1 << i_iGpioNumber);
    // Rising Edge Clear
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_SET_RIS_TRIG) &= 0xFFFFFFFF ^ (1  << i_iGpioNumber);
}

void gpioSettings(int i_iGpioNumber)
{
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_OUT_DATA) &= 0xFFFFFFFF ^ (1 << i_iGpioNumber); //GPIO Law설정(0)
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_OUT_DATA) |= (1 << i_iGpioNumber);              //GPIO High 설정(1)
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_OUT_DATA) &= 0xFFFFFFFF ^ (1 << i_iGpioNumber); //GPIO Law설정(0)
}

void gpioInterruptEnable()
{
    *(unsigned int*)(GPIO_CFG_BASE+GPIO_REG_BINTEN) |= 0x1;
}

