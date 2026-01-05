#ifndef DRIVERS_BSP_DISPLAY_RENDER_H
#define DRIVERS_BSP_DISPLAY_RENDER_H

#include "main.h"
#include "display.h"

#define ST_ASCII_16_ADDRESS  0
#define FS_ASCII_16_ADDRESS  2080 / 4096
#define KT_ASCII_16_ADDRESS  4160 / 4096
#define HT_ASCII_16_ADDRESS  6240 / 4096

#define ST_GB2312_16_ADDRESS 8320 / 4096
#define FS_GB2312_16_ADDRESS 291104 / 4096
#define KT_GB2312_16_ADDRESS 573888 / 4096
#define HT_GB2312_16_ADDRESS 856672 / 4096

#define ST_ASCII_24_ADDRESS  1139456 / 4096
#define FS_ASCII_24_ADDRESS  1145632 / 4096
#define KT_ASCII_24_ADDRESS  1151808 / 4096
#define HT_ASCII_24_ADDRESS  1157984 / 4096

#define ST_GB2312_24_ADDRESS 1164160 / 4096
#define FS_GB2312_24_ADDRESS 1800384 / 4096
#define KT_GB2312_24_ADDRESS 2436608 / 4096
#define HT_GB2312_24_ADDRESS 3072832 / 4096

#define ST_ASCII_32_ADDRESS  3709056 / 4096
#define FS_ASCII_32_ADDRESS  3717280 / 4096
#define KT_ASCII_32_ADDRESS  3725504 / 4096
#define HT_ASCII_32_ADDRESS  3733728 / 4096

#define ST_GB2312_32_ADDRESS 3741952 / 4096
#define FS_GB2312_32_ADDRESS 4872992 / 4096
#define KT_GB2312_32_ADDRESS 6004032 / 4096
#define HT_GB2312_32_ADDRESS 7135072 / 4096

#define ASCII_16_STEP        (8320U)
#define GB2312_16_STEP       (282784U)
#define ASCII_24_STEP        (6176U)
#define GB2312_24_STEP       (636224U)
#define ASCII_32_STEP        (8224U)
#define GB2312_32_STEP       (1131040U)

#define ASCII_16_OFFSET      (0U)
#define GB2312_16_OFFSET     (ASCII_16_OFFSET + 4 * ASCII_16_STEP)
#define ASCII_24_OFFSET      (GB2312_16_OFFSET + 4 * GB2312_16_STEP)
#define GB2312_24_OFFSET     (ASCII_24_OFFSET + 4 * ASCII_24_STEP)
#define ASCII_32_OFFSET      (GB2312_24_OFFSET + 4 * GB2312_24_STEP)
#define GB2312_32_OFFSET     (ASCII_32_OFFSET + 4 * ASCII_32_STEP)

// 字号定义
typedef enum {
    font_16,
    font_24,
    font_32,
    font_48,
} FontSize_t;

// 字高定义
typedef enum {
    font16 = 16,
    font24 = 24,
    font32 = 32,
    font48 = 48,
} FontHigh_t;

// 字型定义
typedef enum {
    font_st,
    font_fs,
    font_kt,
    font_ht,
} FontType_t;

extern bool newData;
extern uint16_t max_display_len;

void Disp_Fill(uint8_t color);

void Disp_DrawString(uint32_t start_x, uint32_t start_y, const uint8_t *p_text, uint32_t text_len, hub75_color color, FontSize_t font_size, FontType_t font_type);

void Render_Text(const uint8_t *p_text, uint16_t *x, uint16_t *y, FontSize_t font_size, FontType_t font_type, bool mode, bool line_break, hub75_color color);

uint8_t auto_font_size(uint16_t len, uint8_t size);
uint16_t auto_line(uint8_t line, uint8_t font_size);
uint16_t set_align(uint16_t len, uint8_t font_size, uint8_t align);

#endif // DRIVERS_BSP_DISPLAY_RENDER_H
