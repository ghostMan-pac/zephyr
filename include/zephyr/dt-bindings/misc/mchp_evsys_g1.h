/*
 * Copyright (c) 2026 Muhammed Asif P
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_DT_BINDINGS_MISC_MCHP_EVSYS_G1_H_
#define ZEPHYR_INCLUDE_DT_BINDINGS_MISC_MCHP_EVSYS_G1_H_

#define EVSYS_MCHP_EVGEN_NONE                      0x00

#define EVSYS_MCHP_EVGEN_OSCCTRL_XOSC_FAIL0        0x01
#define EVSYS_MCHP_EVGEN_OSCCTRL_XOSC_FAIL1        0x02

#define EVSYS_MCHP_EVGEN_OSC32KCTRL_XOSC32K_FAIL   0x03

/* 0x04 – 0x0B : RTC Period x = 0..7 */
#define EVSYS_MCHP_EVGEN_RTC_PER0                  0x04
#define EVSYS_MCHP_EVGEN_RTC_PER1                  0x05
#define EVSYS_MCHP_EVGEN_RTC_PER2                  0x06
#define EVSYS_MCHP_EVGEN_RTC_PER3                  0x07
#define EVSYS_MCHP_EVGEN_RTC_PER4                  0x08
#define EVSYS_MCHP_EVGEN_RTC_PER5                  0x09
#define EVSYS_MCHP_EVGEN_RTC_PER6                  0x0A
#define EVSYS_MCHP_EVGEN_RTC_PER7                  0x0B

/* 0x0C – 0x0F : RTC Compare x = 0..3 */
#define EVSYS_MCHP_EVGEN_RTC_CMP0                  0x0C
#define EVSYS_MCHP_EVGEN_RTC_CMP1                  0x0D
#define EVSYS_MCHP_EVGEN_RTC_CMP2                  0x0E
#define EVSYS_MCHP_EVGEN_RTC_CMP3                  0x0F

#define EVSYS_MCHP_EVGEN_RTC_TAMPER                0x10
#define EVSYS_MCHP_EVGEN_RTC_OVF                   0x11

/* 0x12 – 0x21 : EIC External Interrupt x = 0..15 */
#define EVSYS_MCHP_EVGEN_EIC_EXTINT0               0x12
#define EVSYS_MCHP_EVGEN_EIC_EXTINT1               0x13
#define EVSYS_MCHP_EVGEN_EIC_EXTINT2               0x14
#define EVSYS_MCHP_EVGEN_EIC_EXTINT3               0x15
#define EVSYS_MCHP_EVGEN_EIC_EXTINT4               0x16
#define EVSYS_MCHP_EVGEN_EIC_EXTINT5               0x17
#define EVSYS_MCHP_EVGEN_EIC_EXTINT6               0x18
#define EVSYS_MCHP_EVGEN_EIC_EXTINT7               0x19
#define EVSYS_MCHP_EVGEN_EIC_EXTINT8               0x1A
#define EVSYS_MCHP_EVGEN_EIC_EXTINT9               0x1B
#define EVSYS_MCHP_EVGEN_EIC_EXTINT10              0x1C
#define EVSYS_MCHP_EVGEN_EIC_EXTINT11              0x1D
#define EVSYS_MCHP_EVGEN_EIC_EXTINT12              0x1E
#define EVSYS_MCHP_EVGEN_EIC_EXTINT13              0x1F
#define EVSYS_MCHP_EVGEN_EIC_EXTINT14              0x20
#define EVSYS_MCHP_EVGEN_EIC_EXTINT15              0x21

/* 0x22 – 0x25 : DMA Channel x = 0..3 */
#define EVSYS_MCHP_EVGEN_DMAC_CH0                  0x22
#define EVSYS_MCHP_EVGEN_DMAC_CH1                  0x23
#define EVSYS_MCHP_EVGEN_DMAC_CH2                  0x24
#define EVSYS_MCHP_EVGEN_DMAC_CH3                  0x25

/* 0x26 */
#define EVSYS_MCHP_EVGEN_PAC_ACCERR                0x26

/* 0x29 – 0x31 : TCC0 */
#define EVSYS_MCHP_EVGEN_TCC0_OVF                  0x29
#define EVSYS_MCHP_EVGEN_TCC0_TRG                  0x2A
#define EVSYS_MCHP_EVGEN_TCC0_CNT                  0x2B
#define EVSYS_MCHP_EVGEN_TCC0_MC0                  0x2C
#define EVSYS_MCHP_EVGEN_TCC0_MC1                  0x2D
#define EVSYS_MCHP_EVGEN_TCC0_MC2                  0x2E
#define EVSYS_MCHP_EVGEN_TCC0_MC3                  0x2F
#define EVSYS_MCHP_EVGEN_TCC0_MC4                  0x30
#define EVSYS_MCHP_EVGEN_TCC0_MC5                  0x31

/* 0x32 – 0x38 : TCC1 */
#define EVSYS_MCHP_EVGEN_TCC1_OVF                  0x32
#define EVSYS_MCHP_EVGEN_TCC1_TRG                  0x33
#define EVSYS_MCHP_EVGEN_TCC1_CNT                  0x34
#define EVSYS_MCHP_EVGEN_TCC1_MC0                  0x35
#define EVSYS_MCHP_EVGEN_TCC1_MC1                  0x36
#define EVSYS_MCHP_EVGEN_TCC1_MC2                  0x37
#define EVSYS_MCHP_EVGEN_TCC1_MC3                  0x38

/* 0x39 – 0x3E : TCC2 */
#define EVSYS_MCHP_EVGEN_TCC2_OVF                  0x39
#define EVSYS_MCHP_EVGEN_TCC2_TRG                  0x3A
#define EVSYS_MCHP_EVGEN_TCC2_CNT                  0x3B
#define EVSYS_MCHP_EVGEN_TCC2_MC0                  0x3C
#define EVSYS_MCHP_EVGEN_TCC2_MC1                  0x3D
#define EVSYS_MCHP_EVGEN_TCC2_MC2                  0x3E

/* 0x3F – 0x43 : TCC3 */
#define EVSYS_MCHP_EVGEN_TCC3_OVF                  0x3F
#define EVSYS_MCHP_EVGEN_TCC3_TRG                  0x40
#define EVSYS_MCHP_EVGEN_TCC3_CNT                  0x41
#define EVSYS_MCHP_EVGEN_TCC3_MC0                  0x42
#define EVSYS_MCHP_EVGEN_TCC3_MC1                  0x43

/* 0x44 – 0x48 : TCC4 */
#define EVSYS_MCHP_EVGEN_TCC4_OVF                  0x44
#define EVSYS_MCHP_EVGEN_TCC4_TRG                  0x45
#define EVSYS_MCHP_EVGEN_TCC4_CNT                  0x46
#define EVSYS_MCHP_EVGEN_TCC4_MC0                  0x47
#define EVSYS_MCHP_EVGEN_TCC4_MC1                  0x48

/* 0x49 – 0x4B : TC0 */
#define EVSYS_MCHP_EVGEN_TC0_OVF                   0x49
#define EVSYS_MCHP_EVGEN_TC0_MC0                   0x4A
#define EVSYS_MCHP_EVGEN_TC0_MC1                   0x4B

/* 0x4C – 0x4E : TC1 */
#define EVSYS_MCHP_EVGEN_TC1_OVF                   0x4C
#define EVSYS_MCHP_EVGEN_TC1_MC0                   0x4D
#define EVSYS_MCHP_EVGEN_TC1_MC1                   0x4E

/* 0x4F – 0x51 : TC2 */
#define EVSYS_MCHP_EVGEN_TC2_OVF                   0x4F
#define EVSYS_MCHP_EVGEN_TC2_MC0                   0x50
#define EVSYS_MCHP_EVGEN_TC2_MC1                   0x51

/* 0x52 – 0x54 : TC3 */
#define EVSYS_MCHP_EVGEN_TC3_OVF                   0x52
#define EVSYS_MCHP_EVGEN_TC3_MC0                   0x53
#define EVSYS_MCHP_EVGEN_TC3_MC1                   0x54

/* 0x55 - 0x57: TC4 */
#define EVSYS_MCHP_EVGEN_TC4_OVF                   0x55
#define EVSYS_MCHP_EVGEN_TC4_MC0                   0x56
#define EVSYS_MCHP_EVGEN_TC4_MC1                   0x57

/* 0x58 – 0x5A : TC5 */
#define EVSYS_MCHP_EVGEN_TC5_OVF                   0x58
#define EVSYS_MCHP_EVGEN_TC5_MC0                   0x59
#define EVSYS_MCHP_EVGEN_TC5_MC1                   0x5A

/* 0x5B – 0x5D : TC6 */
#define EVSYS_MCHP_EVGEN_TC6_OVF                   0x5B
#define EVSYS_MCHP_EVGEN_TC6_MC0                   0x5C
#define EVSYS_MCHP_EVGEN_TC6_MC1                   0x5D

/* 0x5E – 0x60 : TC7 */
#define EVSYS_MCHP_EVGEN_TC7_OVF                   0x5E
#define EVSYS_MCHP_EVGEN_TC7_MC0                   0x5F
#define EVSYS_MCHP_EVGEN_TC7_MC1                   0x60

/* 0x61 – 0x66 : PDEC */
#define EVSYS_MCHP_EVGEN_PDEC_OVF                  0x61
#define EVSYS_MCHP_EVGEN_PDEC_ERR                  0x62
#define EVSYS_MCHP_EVGEN_PDEC_DIR                  0x63
#define EVSYS_MCHP_EVGEN_PDEC_VLC                  0x64
#define EVSYS_MCHP_EVGEN_PDEC_MC0                  0x65
#define EVSYS_MCHP_EVGEN_PDEC_MC1                  0x66

/* 0x67 – 0x68 : ADC0 */
#define EVSYS_MCHP_EVGEN_ADC0_RESRDY               0x67
#define EVSYS_MCHP_EVGEN_ADC0_WINMON               0x68

/* 0x69 – 0x6A : ADC1 */
#define EVSYS_MCHP_EVGEN_ADC1_RESRDY               0x69
#define EVSYS_MCHP_EVGEN_ADC1_WINMON               0x6A

/* 0x6B – 0x6C : AC Comparator x = 0..1 */
#define EVSYS_MCHP_EVGEN_AC_COMP0                  0x6B
#define EVSYS_MCHP_EVGEN_AC_COMP1                  0x6C

/* 0x6D : AC Window */
#define EVSYS_MCHP_EVGEN_AC_WIN                    0x6D

/* 0x6E – 0x6F : DAC EMPTY x = 0..1 */
#define EVSYS_MCHP_EVGEN_DAC_EMPTY0                0x6E
#define EVSYS_MCHP_EVGEN_DAC_EMPTY1                0x6F

/* 0x70 – 0x71 : DAC RESRDY x = 0..1 */
#define EVSYS_MCHP_EVGEN_DAC_RESRDY0               0x70
#define EVSYS_MCHP_EVGEN_DAC_RESRDY1               0x71

/* 0x72 : GMAC */
#define EVSYS_MCHP_EVGEN_GMAC_TSU_CMP              0x72

/* 0x73 : TRNG */
#define EVSYS_MCHP_EVGEN_TRNG_READY                0x73

/* 0x74 – 0x77 : CCL LUTOUT x = 0..3 */
#define EVSYS_MCHP_EVGEN_CCL_LUTOUT0               0x74
#define EVSYS_MCHP_EVGEN_CCL_LUTOUT1               0x75
#define EVSYS_MCHP_EVGEN_CCL_LUTOUT2               0x76
#define EVSYS_MCHP_EVGEN_CCL_LUTOUT3               0x77

// the m is the register offset number in the user it is not the value which is to be written
// it is the actual register offset. check the evsys.h header file to find its offset writtern
/* These are the register offsets of each of the channel user registers.*/
/* USER 0 : RTC Tamper */
#define EVSYS_MCHP_EVUSER_RTC_TAMPER               EVSYS_USER0_REG_OFST

/* USER 1..4 : PORT Event 0..3 */
#define EVSYS_MCHP_EVUSER_PORT_EV0                 EVSYS_USER1_REG_OFST
#define EVSYS_MCHP_EVUSER_PORT_EV1                 EVSYS_USER2_REG_OFST
#define EVSYS_MCHP_EVUSER_PORT_EV2                 EVSYS_USER3_REG_OFST
#define EVSYS_MCHP_EVUSER_PORT_EV3                 EVSYS_USER4_REG_OFST

/* USER 5..12 : DMAC Channel 0..7 */
#define EVSYS_MCHP_EVUSER_DMAC_CH0                 EVSYS_USER5_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH1                 EVSYS_USER6_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH2                 EVSYS_USER7_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH3                 EVSYS_USER8_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH4                 EVSYS_USER9_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH5                 EVSYS_USER10_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH6                 EVSYS_USER11_REG_OFST
#define EVSYS_MCHP_EVUSER_DMAC_CH7                 EVSYS_USER12_REG_OFST

/* USER 13 : Reserved (skipped) */

/* USER 14..16 : CM4 Trace */
#define EVSYS_MCHP_EVUSER_CM4_TRACE_START          EVSYS_USER14_REG_OFST
#define EVSYS_MCHP_EVUSER_CM4_TRACE_STOP           EVSYS_USER15_REG_OFST
#define EVSYS_MCHP_EVUSER_CM4_TRACE_TRIG           EVSYS_USER16_REG_OFST

/* USER 17..24 : TCC0 */
#define EVSYS_MCHP_EVUSER_TCC0_EV0                 EVSYS_USER17_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_EV1                 EVSYS_USER18_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC0                 EVSYS_USER19_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC1                 EVSYS_USER20_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC2                 EVSYS_USER21_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC3                 EVSYS_USER22_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC4                 EVSYS_USER23_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC0_MC5                 EVSYS_USER24_REG_OFST

/* USER 25..30 : TCC1 */
#define EVSYS_MCHP_EVUSER_TCC1_EV0                 EVSYS_USER25_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC1_EV1                 EVSYS_USER26_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC1_MC0                 EVSYS_USER27_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC1_MC1                 EVSYS_USER28_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC1_MC2                 EVSYS_USER29_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC1_MC3                 EVSYS_USER30_REG_OFST

/* USER 31..35 : TCC2 */
#define EVSYS_MCHP_EVUSER_TCC2_EV0                 EVSYS_USER31_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC2_EV1                 EVSYS_USER32_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC2_MC0                 EVSYS_USER33_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC2_MC1                 EVSYS_USER34_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC2_MC2                 EVSYS_USER35_REG_OFST

/* USER 36..39 : TCC3 */
#define EVSYS_MCHP_EVUSER_TCC3_EV0                 EVSYS_USER36_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC3_EV1                 EVSYS_USER37_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC3_MC0                 EVSYS_USER38_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC3_MC1                 EVSYS_USER39_REG_OFST

/* USER 40..43 : TCC4 */
#define EVSYS_MCHP_EVUSER_TCC4_EV0                 EVSYS_USER40_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC4_EV1                 EVSYS_USER41_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC4_MC0                 EVSYS_USER42_REG_OFST
#define EVSYS_MCHP_EVUSER_TCC4_MC1                 EVSYS_USER43_REG_OFST

/* USER 44..51 : TC0..7 EVU */
#define EVSYS_MCHP_EVUSER_TC0_EVU                  EVSYS_USER44_REG_OFST
#define EVSYS_MCHP_EVUSER_TC1_EVU                  EVSYS_USER45_REG_OFST
#define EVSYS_MCHP_EVUSER_TC2_EVU                  EVSYS_USER46_REG_OFST
#define EVSYS_MCHP_EVUSER_TC3_EVU                  EVSYS_USER47_REG_OFST
#define EVSYS_MCHP_EVUSER_TC4_EVU                  EVSYS_USER48_REG_OFST
#define EVSYS_MCHP_EVUSER_TC5_EVU                  EVSYS_USER49_REG_OFST
#define EVSYS_MCHP_EVUSER_TC6_EVU                  EVSYS_USER50_REG_OFST
#define EVSYS_MCHP_EVUSER_TC7_EVU                  EVSYS_USER51_REG_OFST

/* USER 52..54 : PDEC EVU */
#define EVSYS_MCHP_EVUSER_PDEC_EVU0                EVSYS_USER52_REG_OFST
#define EVSYS_MCHP_EVUSER_PDEC_EVU1                EVSYS_USER53_REG_OFST
#define EVSYS_MCHP_EVUSER_PDEC_EVU2                EVSYS_USER54_REG_OFST

/* USER 55..56 : ADC0 */
#define EVSYS_MCHP_EVUSER_ADC0_START               EVSYS_USER55_REG_OFST
#define EVSYS_MCHP_EVUSER_ADC0_SYNC                EVSYS_USER56_REG_OFST
/* USER 57..58 : ADC1 */
#define EVSYS_MCHP_EVUSER_ADC1_START               EVSYS_USER57_REG_OFST
#define EVSYS_MCHP_EVUSER_ADC1_SYNC                EVSYS_USER58_REG_OFST

/* USER 59..60 : AC SOC x = 0..1 */
#define EVSYS_MCHP_EVUSER_AC_SOC0                  EVSYS_USER59_REG_OFST
#define EVSYS_MCHP_EVUSER_AC_SOC1                  EVSYS_USER60_REG_OFST

/* USER 61..62 : DAC START 0..1 */
#define EVSYS_MCHP_EVUSER_DAC_START0               EVSYS_USER61_REG_OFST
#define EVSYS_MCHP_EVUSER_DAC_START1               EVSYS_USER62_REG_OFST

/* USER 63..66 : CCL LUTIN 0..3 */
#define EVSYS_MCHP_EVUSER_CCL_LUTIN0               EVSYS_USER63_REG_OFST
#define EVSYS_MCHP_EVUSER_CCL_LUTIN1               EVSYS_USER64_REG_OFST
#define EVSYS_MCHP_EVUSER_CCL_LUTIN2               EVSYS_USER65_REG_OFST
#define EVSYS_MCHP_EVUSER_CCL_LUTIN3               EVSYS_USER66_REG_OFST

/* Remaining USER indices reserved */

#endif /* ZEPHYR_INCLUDE_DT_BINDINGS_MISC_MCHP_EVSYS_G1_H_ */
