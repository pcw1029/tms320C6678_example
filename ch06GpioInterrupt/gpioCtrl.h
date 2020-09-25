/*
 * gpioCtrl.h
 *
 *  Created on: 2020. 9. 25.
 *      Author: pcw10
 */

#ifndef GPIOCTRL_H_
#define GPIOCTRL_H_

#define GPIO_CFG_BASE               (0x02320000)
#define GPIO_REG_BINTEN             (0x8)
#define GPIO_REG_DIR                (0x10)
#define GPIO_REG_OUT_DATA           (0x14)
#define GPIO_REG_SET_DATA           (0x18)
#define GPIO_REG_CLR_DATA           (0x1C)
#define GPIO_REG_IN_DATA            (0x20)
#define GPIO_REG_SET_RIS_TRIG       (0x24)
#define GPIO_REG_CLR_RIS_TRIG       (0x28)
#define GPIO_REG_SET_FAL_TRIG       (0x2C)
#define GPIO_REG_CLR_FAL_TRIG       (0x30)

void gpioSettings(int i_iGpioNumber);
void gpioOutputDirSet(int i_iGpioNumber);
void gpioInputDirSet(int i_iGpioNumber);
void gpioInterruptRisingSet(int i_iGpioNumber);
void gpioInterruptFallingSet(int i_iGpioNumber);
void gpioInterruptEnable();

#endif /* GPIOCTRL_H_ */
