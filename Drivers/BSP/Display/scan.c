#include "display.h"
#include "hub75.h"

/**
 * @brief P15的扫描
 *
 */
void convert_pixelmap_p15(void)
{
    uint16_t ModuelGroup = 0;
    uint8_t row_cnt = 0, col_cnt = 0;

    for (uint16_t map_cnt = 0; map_cnt < DISRAM_SIZE; map_cnt++) {
        row_cnt     = map_cnt / SCREEN_PIXEL_ROW; // 屏幕的行标
        col_cnt     = map_cnt % SCREEN_PIXEL_ROW;
        ModuelGroup = col_cnt / 4 + (row_cnt / 4 * (MODULE_PER_ROW * 4)); // 组标

        switch (row_cnt % 4) {
            case 0:
                hub75_buff[2 * (3 - col_cnt % 4) + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
                break;

            case 1:
                hub75_buff[2 * (3 - col_cnt % 4) + 1 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
                break;

            case 2:
                hub75_buff[2 * (col_cnt % 4) + 9 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
                break;

            case 3:
                hub75_buff[2 * (col_cnt % 4) + 8 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
                break;

            default:
                break;
        }
    }
}

/**
 * @brief 新P5模组扫描
 *
 */
void convert_pixelmap_p5(void)
{
    uint16_t ModuelGroup = 0;
    uint8_t row_cnt = 0, col_cnt = 0;

    for (uint16_t src_cnt = 0; src_cnt < DISRAM_SIZE; src_cnt++) {
        row_cnt     = src_cnt / SCREEN_PIXEL_ROW; // 屏幕的行标
        col_cnt     = src_cnt % SCREEN_PIXEL_ROW;
        ModuelGroup = row_cnt / 16 * 8 + row_cnt % 8; // 组标

        if (1 == src_cnt / SCREEN_PIXEL_ROW / 8 % 2)
            hub75_buff[col_cnt * 2 + ModuelGroup * GROUP_SIZE] = pixel_map[src_cnt];
        else
            hub75_buff[col_cnt * 2 + 1 + ModuelGroup * GROUP_SIZE] = pixel_map[src_cnt];
    }
}

/**
 * @brief P6模组的扫描
 *
 */
void convert_pixelmap_p6(void)
{
    uint16_t ModuelGroup = 0;
    uint8_t row_cnt = 0, col_cnt = 0;

    for (uint16_t map_cnt = 0; map_cnt < DISRAM_SIZE; map_cnt++) {
        row_cnt     = map_cnt / SCREEN_PIXEL_ROW; // 屏幕的行标
        col_cnt     = map_cnt % SCREEN_PIXEL_ROW;
        ModuelGroup = row_cnt / 16 * 8 + row_cnt % 8; // 组标

        // 在单行扫描内判断是上半行还是下半行
        if ((row_cnt % 16) >= 8) // 上半行
            hub75_buff[col_cnt + (col_cnt / MODULE_PIXEL_ROW * MODULE_PIXEL_ROW) + (ModuelGroup * GROUP_SIZE)] = pixel_map[map_cnt];
        else // 下半行
            hub75_buff[col_cnt + ((col_cnt / MODULE_PIXEL_ROW + 1) * MODULE_PIXEL_ROW) + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
    }
}

/**
 * @brief P10模组的扫描
 *
 */
void convert_pixelmap_p10(void)
{
    uint16_t ModuelGroup = 0;
    uint8_t row_cnt = 0, col_cnt = 0;

    for (uint16_t map_cnt = 0; map_cnt < DISRAM_SIZE; map_cnt++) {
        // 点阵缓存的行标和列标计算
        row_cnt = map_cnt / SCREEN_PIXEL_ROW;
        col_cnt = map_cnt % SCREEN_PIXEL_ROW;
        // 点阵缓存的组标计算
        ModuelGroup = (row_cnt % 4 + row_cnt / 8 * 4) * (SCAN_LINE_PIXEL_NUM / GROUP_SIZE) + col_cnt / 8;

        // 在单行扫描内判断是上半行还是下半行
        if ((row_cnt % 8) >= 4) // 下半行的点逆序排列
            hub75_buff[15 - col_cnt % 8 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
        else // 上半行的点顺序排列
            hub75_buff[col_cnt % 8 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
    }
}

/**
 * @brief 更新点阵缓冲区到显存
 *
 */
void convert_pixelmap(void)
{
    uint16_t ModuelGroup = 0;
    uint8_t row_cnt = 0, col_cnt = 0;

    for (uint16_t map_cnt = 0; map_cnt < DISRAM_SIZE; map_cnt++) {
        // 点阵缓存的行标和列标计算
        row_cnt = map_cnt / SCREEN_PIXEL_ROW;
        col_cnt = map_cnt % SCREEN_PIXEL_ROW;
        // 点阵缓存的组标计算
        // ModuelGroup = (row_cnt % 4 + row_cnt / 8 * 4) * (SCAN_LINE_PIXEL_NUM / GROUP_SIZE) + col_cnt / 8;
        ModuelGroup = col_cnt / 32 * HUB75_PIXEL_NUM + row_cnt / 8 % 2 * HUB75_PIXEL_NUM / 2 + (row_cnt % 4 * 4 + row_cnt / 16 * 16) + col_cnt % 32 / 8;

        // 在单行扫描内判断是上半行还是下半行
        if ((row_cnt % 8) >= 4) // 下半行的点顺序排列
            hub75_buff[col_cnt % 8 + 8 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
        else // 上半行的点顺序排列
            hub75_buff[col_cnt % 8 + ModuelGroup * GROUP_SIZE] = pixel_map[map_cnt];
    }
}
