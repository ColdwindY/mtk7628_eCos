#ifndef CPUID_H
#define CPUID_H

enum ralink_soc_type {
	SOC_UNKNOWN = 0,
	SOC_RT3050,
	SOC_RT3052,
	SOC_RT3350,
	SOC_RT3352,
	SOC_RT5350,
	SOC_RT3662,
	SOC_RT3883,
	SOC_MT7620,
	SOC_MT7621,
	SOC_MT7628,
};

#define RT305X_SYSC_BASE		0xB0000000
/* SYSC registers */
#define SYSC_REG_CHIP_NAME0		0x000	/* Chip Name 0 */
#define SYSC_REG_CHIP_NAME1		0x004	/* Chip Name 1 */
#define SYSC_REG_CHIP_ID			0x00c	/* Chip Identification */
#define SYSC_REG_SYSTEM_CONFIG	0x010	/* System Configuration */

#define CHIP_ID_ID_MASK		0xff
#define CHIP_ID_ID_SHIFT		8
#define CHIP_ID_REV_MASK		0xff

#define SYS_TYPE_LEN	64



#define RT3052_CHIP_NAME0	0x30335452
#define RT3052_CHIP_NAME1	0x20203235

#define RT3350_CHIP_NAME0	0x33335452
#define RT3350_CHIP_NAME1	0x20203035

#define RT3352_CHIP_NAME0	0x33335452
#define RT3352_CHIP_NAME1	0x20203235

#define RT5350_CHIP_NAME0	0x33355452
#define RT5350_CHIP_NAME1	0x20203035

#define RT3883_CHIP_NAME0	0x33355452
#define RT3883_CHIP_NAME1	0x20203035

#define MT7620_CHIP_NAME0	0x3637544d
#define MT7620_CHIP_NAME1	0x20203032

#define MT7621_CHIP_NAME0   0x3637544d
#define MT7621_CHIP_NAME1   0x20203132

#define MT7628_CHIP_NAME0   0x3637544d
#define MT7628_CHIP_NAME1   0x20203832


int cpu_info(void);

#endif /* CPUID_H */
