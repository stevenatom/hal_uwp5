/*
 * Copyright (c) 2018, UNISOC Incorporated
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MARLIN3_HAL_SFC_CFG_H
#define __MARLIN3_HAL_SFC_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "uwp_hal.h"
#include "hal_sfc.h"
#include "hal_sfc_hal.h"

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#endif

#ifdef FLASH_SIZE_16MBIT
#define MAX_HW_FLASH_SIZE			0x00200000
#elif defined(FLASH_SIZE_32MBIT)
#define MAX_HW_FLASH_SIZE			0x00400000
#elif defined(FLASH_SIZE_48MBIT)
#define MAX_HW_FLASH_SIZE			0x00600000
#elif defined(FLASH_SIZE_64MBIT)
#define MAX_HW_FLASH_SIZE			0x00800000
#elif defined(FLASH_SIZE_80MBIT)
#define MAX_HW_FLASH_SIZE			0x00A00000
#elif defined(FLASH_SIZE_128MBIT)
#define MAX_HW_FLASH_SIZE			0x01000000
#elif defined(FLASH_SIZE_144MBIT)
#define MAX_HW_FLASH_SIZE			0x01200000
#elif defined(FLASH_SIZE_160MBIT)
#define MAX_HW_FLASH_SIZE			0x01400000
#elif defined(FLASH_SIZE_192MBIT)
#define MAX_HW_FLASH_SIZE			0x01800000
#elif defined(FLASH_SIZE_256MBIT)
#define MAX_HW_FLASH_SIZE			0x02000000
#else
#define MAX_HW_FLASH_SIZE			0x01000000
#endif

#define PHY_FLASH_SIZE					MAX_HW_FLASH_SIZE
#define FLASH_SECTOR_SIZE				0x00008000

#define MAX_FLASH_SIZE					PHY_FLASH_SIZE

#ifdef NV_PRTITION_TINY
#define	RUNNIN_NV_SECTOR_NUM		4	//160KB
#elif defined(NV_PRTITION_SMALL)
#define	RUNNIN_NV_SECTOR_NUM		7	//224KB
#elif defined(NV_PRTITION_NORMAL)
#define	RUNNIN_NV_SECTOR_NUM		10	//320KB
#elif defined(NV_PRTITION_LARGE)
#define	RUNNIN_NV_SECTOR_NUM		15	//480KB
#else
#define	RUNNIN_NV_SECTOR_NUM		10	//320KB
#endif

#ifdef UMEM_PRTITION_TINY
#define	UMEM_SECTOR_NUM		4	//128KB
#elif defined(UMEM_PRTITION_SMALL)
#define	UMEM_SECTOR_NUM		5	//160KB
#elif defined(UMEM_PRTITION_NORMAL)
#define	UMEM_SECTOR_NUM		6	//192KB
#elif defined(UMEM_PRTITION_LARGE)
#define	UMEM_SECTOR_NUM		7	//224KB
#else
#define	UMEM_SECTOR_NUM		4	//128KB
#endif

#define RUNNIN_NV_SIZE			(RUNNIN_NV_SECTOR_NUM * FLASH_SECTOR_SIZE)
#define FIXED_NV_SIZE			0x6C00	//72KB

#define RUNNIN_NV_BASE_ADDR	(MAX_FLASH_SIZE - RUNNIN_NV_SIZE)
#define FIXED_NV_BASE_ADDR		(RUNNIN_NV_BASE_ADDR - FLASH_SECTOR_SIZE)
#define PRODUCT_NV_BASE_ADDR	(FIXED_NV_BASE_ADDR + FIXED_NV_SIZE)

#ifdef UMEM_SUPPORT
#define UDISK_SIZE				(UMEM_SECTOR_NUM * FLASH_SECTOR_SIZE)
#define UDISK_BASE_ADDR			(FIXED_NV_BASE_ADDR - UDISK_SIZE)
#else
#define UDISK_SIZE				-1
#define UDISK_BASE_ADDR			-1
#endif

#ifdef MMI_RES_PRTITION_TINY
#define MMI_RES_SECTOR_NUM		50
#elif defined(MMI_RES_PRTITION_SMALL)
#define	MMI_RES_SECTOR_NUM		100
#elif defined(MMI_RES_PRTITION_NORMAL)
#define	MMI_RES_SECTOR_NUM		150
#elif defined(MMI_RES_PRTITION_LARGE)
#define	MMI_RES_SECTOR_NUM		200
#else
#define	MMI_RES_SECTOR_NUM		0
#endif

#ifdef STONE_IMAGE_SUPPORT
#define MMI_RES_BASE_ADDR			-1
#else
#define MMI_RES_SIZE				(MMI_RES_SECTOR_NUM * FLASH_SECTOR_SIZE)
#ifdef  UMEM_SUPPORT
#define MMI_RES_BASE_ADDR		(UDISK_BASE_ADDR - MMI_RES_SIZE)
#else
#define MMI_RES_BASE_ADDR		(FIXED_NV_BASE_ADDR - MMI_RES_SIZE)
#endif
#endif

#define SPIFLASH_VOLTAGE_3V			1
#define SPIFLASH_VOLTAGE_1V8		0

	static const struct spi_flash_lock_pattern sf_lock_pattern[] = {
		{SFXXM_L0X00000000_0X001000, 0x00000000, 0x001000},
		{SFXXM_L0X00000000_0X002000, 0x00000000, 0x002000},
		{SFXXM_L0X00000000_0X004000, 0x00000000, 0x004000},
		{SFXXM_L0X00000000_0X008000, 0x00000000, 0x008000},
		{SFXXM_L0X00000000_0X010000, 0x00000000, 0x010000},
		{SFXXM_L0X00000000_0X020000, 0x00000000, 0x020000},
		{SFXXM_L0X00000000_0X040000, 0x00000000, 0x040000},
		{SFXXM_L0X00000000_0X080000, 0x00000000, 0x080000},
		{SFXXM_L0X00000000_0X100000, 0x00000000, 0x100000},
		{SFXXM_L0X00000000_0X200000, 0x00000000, 0x200000},
		{SFXXM_L0X00000000_0X400000, 0x00000000, 0x400000},
		{SFXXM_L0X00000000_0X800000, 0x00000000, 0x800000},
		{SFXXM_L0X00000000_0X1000000, 0x00000000, 0x1000000},
		{SFXXM_L0X00000000_0X2000000, 0x00000000, 0x2000000},
		{SFXXM_L0X00000000_0X4000000, 0x00000000, 0x4000000},
		{SFXXM_L0X00000000_0X8000000, 0x00000000, 0x8000000},

		{SFXXM_L0X00000000_0X300000, 0x00000000, 0X300000},
		{SFXXM_L0X00000000_0X380000, 0x00000000, 0X380000},
		{SFXXM_L0X00000000_0X3C0000, 0x00000000, 0X3C0000},
		{SFXXM_L0X00000000_0X3E0000, 0x00000000, 0X3E0000},
		{SFXXM_L0X00000000_0X3F0000, 0x00000000, 0X3F0000},
		{SFXXM_L0X00000000_0X600000, 0x00000000, 0X600000},
		{SFXXM_L0X00000000_0X700000, 0x00000000, 0X700000},
		{SFXXM_L0X00000000_0X780000, 0x00000000, 0X780000},
		{SFXXM_L0X00000000_0X7C0000, 0x00000000, 0X7C0000},
		{SFXXM_L0X00000000_0X7E0000, 0x00000000, 0X7E0000},
		{SFXXM_L0X00000000_0X7F0000, 0x00000000, 0X7F0000},

		{SF32M_L0X003FF000_0X001000, 0X003FF000, 0X001000},
		{SF32M_L0X003FE000_0X002000, 0X003FE000, 0X002000},
		{SF32M_L0X003FC000_0X004000, 0X003FC000, 0X004000},
		{SF32M_L0X003F8000_0X008000, 0X003F8000, 0X008000},
		{SF32M_L0X003F0000_0X010000, 0X003F0000, 0X010000},
		{SF32M_L0X003E0000_0X020000, 0X003E0000, 0X020000},
		{SF32M_L0X003C0000_0X040000, 0X003C0000, 0X040000},
		{SF32M_L0X00380000_0X080000, 0X00380000, 0X080000},
		{SF32M_L0X00300000_0X100000, 0X00300000, 0X100000},
		{SF32M_L0X00200000_0X200000, 0X00200000, 0X200000},
		{SF32M_L0X00000000_0X400000, 0X00000000, 0X400000},

		{SF64M_L0X007FF000_0X001000, 0X007FF000, 0X001000},
		{SF64M_L0X007FE000_0X002000, 0X007FE000, 0X002000},
		{SF64M_L0X007FC000_0X004000, 0X007FC000, 0X004000},
		{SF64M_L0X007F8000_0X008000, 0X007F8000, 0X008000},
		{SF64M_L0X007F0000_0X010000, 0X007F0000, 0X010000},
		{SF64M_L0X007E0000_0X020000, 0X007E0000, 0X020000},
		{SF64M_L0X007C0000_0X040000, 0X007C0000, 0X040000},
		{SF64M_L0X00780000_0X080000, 0X00780000, 0X080000},
		{SF64M_L0X00700000_0X100000, 0X00700000, 0X100000},
		{SF64M_L0X00600000_0X200000, 0X00600000, 0X200000},
		{SF64M_L0X00400000_0X400000, 0X00400000, 0X400000},
		{SF64M_L0X00000000_0X800000, 0X00000000, 0X800000},

		{SF128M_L0X00FFF000_0X001000, 0X00FFF000, 0X001000},
		{SF128M_L0X00FFE000_0X002000, 0X00FFE000, 0X002000},
		{SF128M_L0X00FFC000_0X004000, 0X00FFC000, 0X004000},
		{SF128M_L0X00FF8000_0X008000, 0X00FF8000, 0X008000},
		{SF128M_L0X00FF0000_0X010000, 0X00FF0000, 0X010000},
		{SF128M_L0X00FE0000_0X020000, 0X00FE0000, 0X020000},
		{SF128M_L0X00FC0000_0X040000, 0X00FC0000, 0X040000},
		{SF128M_L0X00F80000_0X080000, 0X00F80000, 0X080000},
		{SF128M_L0X00F00000_0X100000, 0X00F00000, 0X100000},
		{SF128M_L0X00E00000_0X200000, 0X00E00000, 0X200000},
		{SF128M_L0X00C00000_0X400000, 0X00C00000, 0X400000},
		{SF128M_L0X00800000_0X800000, 0X00800000, 0X800000},
		{SF128M_L0X00000000_0X1000000, 0X00000000, 0X1000000},

		{SF256M_L0X01FF0000_0X010000, 0X01FF0000, 0X010000},
		{SF256M_L0X01FE0000_0X020000, 0X01FE0000, 0X020000},
		{SF256M_L0X01FC0000_0X040000, 0X01FC0000, 0X040000},
		{SF256M_L0X01F80000_0X080000, 0X01F80000, 0X080000},
		{SF256M_L0X01F00000_0X100000, 0X01F00000, 0X100000},
		{SF256M_L0X01E00000_0X200000, 0X01E00000, 0X200000},
		{SF256M_L0X01C00000_0X400000, 0X01C00000, 0X400000},
		{SF256M_L0X01800000_0X800000, 0X01800000, 0X800000},
		{SF256M_L0X01000000_0X1000000, 0X01000000, 0X1000000},
		{SF256M_L0X00000000_0X2000000, 0X00000000, 0X2000000},

		{SFXXM_L0X00000000_0X02000000, 0X00000000, 0X02000000},
		{SFXXM_L0X00000000_0X01FF0000, 0X00000000, 0X01FF0000},
		{SFXXM_L0X00000000_0X01FE0000, 0X00000000, 0X01FE0000},
		{SFXXM_L0X00000000_0X01FC0000, 0X00000000, 0X01FC0000},
		{SFXXM_L0X00000000_0X01F80000, 0X00000000, 0X01F80000},
		{SFXXM_L0X00000000_0X01F00000, 0X00000000, 0X01F00000},
		{SFXXM_L0X00000000_0X01E00000, 0X00000000, 0X01E00000},
		{SFXXM_L0X00000000_0X01C00000, 0X00000000, 0X01C00000},
		{SFXXM_L0X00000000_0X01800000, 0X00000000, 0X01800000},
		{SFXXM_L0X00000000_0X01000000, 0X00000000, 0X01000000},

		{SF256M_L0X00010000_0X01FF0000, 0X00010000, 0X01FF0000},
		{SF256M_L0X00020000_0X01FE0000, 0X00020000, 0X01FE0000},
		{SF256M_L0X00040000_0X01FC0000, 0X00040000, 0X01FC0000},
		{SF256M_L0X00080000_0X01F80000, 0X00080000, 0X01F80000},
		{SF256M_L0X00100000_0X01F00000, 0X00100000, 0X01F00000},
		{SF256M_L0X00200000_0X01E00000, 0X00200000, 0X01E00000},
		{SF256M_L0X00400000_0X01C00000, 0X00400000, 0X01C00000},
		{SF256M_L0X00800000_0X01800000, 0X00800000, 0X01800000},
		{SF256M_L0X01000000_0X01000000, 0X01000000, 0X01000000},

	};

#define DUMMYCLK_2_FREQ_50MHZ		(0x0)
#define DUMMYCLK_4_FREQ_80MHZ		(0x10)
#define DUMMYCLK_6_FREQ_104MHZ		(0x20)
#define DUMMYCLK_8_FREQ_104MHZ		(0x30)

#define GIGA_MFID					0XC8
#define WINBOND_MFID				0XEF

#define GIGA_ID_25LQ16					0x6015
#define GIGA_ID_25LQ32B					0X6016
#define GIGA_ID_25LQ64B					0X6017
#define GIGA_ID_25LQ128					0X6018
#define GIGA_ID_25Q64B					0X4017
#define GIGA_ID_25Q32B					0X4016
static struct spi_flash_params giga_flash_table[] = {
	{
		GIGA_ID_25LQ16,
		0,
		256,
		16,
		16,
		32,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25LQ16",
	},
	{
		GIGA_ID_25LQ32B,
		0,
		256,
		16,
		16,
		64,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25LQ32B",
	},
	{
		GIGA_ID_25LQ64B,
		0,
		256,
		16,
		16,
		128,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25LQ64B",
	},
	{
		GIGA_ID_25LQ128,
		0,
		256,
		16,
		16,
		256,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25LQ128",
	},
	{
		GIGA_ID_25Q64B,
		0,
		256,
		16,
		16,
		128,
		SPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25Q64B",
	},
	{
		GIGA_ID_25Q32B,
		0,
		256,
		16,
		16,
		64,
		SPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25Q32B",
	},
	{
		GIGA_ID_25Q32B,
		0,
		256,
		16,
		16,
		64,
		SPI_MODE,
		READ_FREQ_104M,
		DUMMY_2CLOCKS,
		"25Q32B",
	},
};

#define WINBOND_ID_W25X16			0x3015
#define WINBOND_ID_W25X32			0x3016
#define WINBOND_ID_W25X64			0x3017
#define WINBOND_ID_W25Q32DW			0x6016
#define WINBOND_ID_W25Q64FW			0x6017
#define WINBOND_ID_W25Q128FW		0x6018
#define WINBOND_ID_W25Q16			0x4015
#define WINBOND_ID_W25Q32FV			0x4016
#define WINBOND_ID_W25Q64FV			0x4017
#define WINBOND_ID_W25Q128FV		0x4018
#define WINBOND_ID_W25Q256FV		0x4019
static struct spi_flash_params winbond_flash_table[] = {
	{
		WINBOND_ID_W25X16,
		0,
		256,
		16,
		16,
		32,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25X16",
	},
	{
		WINBOND_ID_W25X32,
		0,
		256,
		16,
		16,
		64,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25X32",
	},
	{
		WINBOND_ID_W25X64,
		0,
		256,
		16,
		16,
		128,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25X64",
	},
	{
		WINBOND_ID_W25Q32DW,
		0,
		256,
		16,
		16,
		64,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q32DW",
	},
	{
		WINBOND_ID_W25Q64FW,
		0,
		256,
		16,
		16,
		128,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q64FW",
	},
	{
		WINBOND_ID_W25Q128FW,
		0,
		256,
		16,
		16,
		256,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q128FW",
	},
	{
		WINBOND_ID_W25Q16,
		0,
		256,
		16,
		16,
		32,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q16",
	},
	{
		WINBOND_ID_W25Q32FV,
		0,
		256,
		16,
		16,
		64,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q32FV",
	},
	{
		WINBOND_ID_W25Q64FV,
		0,
		256,
		16,
		16,
		128,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q64FV",
	},
	{
		WINBOND_ID_W25Q128FV,
		0,
		256,
		16,
		16,
		256,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q128FV",
	},
	{
		WINBOND_ID_W25Q256FV,
		0,
		256,
		16,
		16,
		512,
		QPI_MODE,
		READ_FREQ_104M,
		DUMMY_4CLOCKS,
		"W25Q256FV",
	},
};


static struct spi_flash_spec_s spi_flash_spec_table[] = {
	{
		GIGA_MFID,
		ARRAY_SIZE(giga_flash_table),
		giga_flash_table,
	},
	{
		WINBOND_MFID,
		ARRAY_SIZE(winbond_flash_table),
		winbond_flash_table,
	},
};


#ifdef __cplusplus
}
#endif

#endif
