/*******************************************************************************
 * [   Module  ]: AVR_REG_DEFS
 *
 * [ File Name ]: avr_reg_defs.h
 *
 * [Description]: registers definition File For ATmega16 micro-controller.
 *
 * [   Author  ]: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_UTILS_AVR_REG_DEFS_H_
#define SRC_UTILS_AVR_REG_DEFS_H_

/*------------------------------------------------------------------------------
 *                                  INCLUDES
 *------------------------------------------------------------------------------*/
#include "std_types.h"

/*------------------------------------------------------------------------------
 *                                  DEFINITIONS
 *------------------------------------------------------------------------------*/
#define __MMIO_RW_BYTE(__mem_address)    (*((volatile uint8 *)(__mem_address)))
#define __MMIO_R_BYTE(__mem_address)     (*((const volatile uint8 *)(__mem_address)))
#define __MMIO_RW_WORD(__mem_address)    (*((volatile uint16 *)(__mem_address)))

#define __IO_OFFSET        0x20

#define __SFR_IO8_R(__io_address)      __MMIO_R_BYTE((__io_address) + __IO_OFFSET)
#define __SFR_IO8_RW(__io_address)     __MMIO_RW_BYTE((__io_address) + __IO_OFFSET)
#define __SFR_IO16_RW(__io_address)    __MMIO_RW_WORD((__io_address) + __IO_OFFSET)

#endif /* SRC_UTILS_AVR_REG_DEFS_H_ */
