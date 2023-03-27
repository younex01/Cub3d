#include "cub3d.h"

void img_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->data_addr
            + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void    draw_vertical_line(t_data *data, t_raycast *rc, int x, int wall_color)
{
    int y;
	(void)wall_color;

    y = -1;
    while (++y < rc->draw_start)
        img_pixel_put(data, x, y, SKY);
    while (y < rc->draw_end)
		y++;
        // img_pixel_put(data, x, y, wall_color);
    while (++y < WIN_HEIGHT)
        img_pixel_put(data, x, y, GRASS);
}