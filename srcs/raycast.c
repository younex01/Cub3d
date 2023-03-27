#include "cub3d.h"

static void compute_delta_dist(t_data *data, t_raycast *rc)
{
    rc->map[X] = data->pos[X];
    rc->map[Y] = data->pos[Y];
    rc->delta_dist[X] = 1e30;
    if (rc->ray_dir[X] != 0.0)
        rc->delta_dist[X] = fabs(1.0 / rc->ray_dir[X]);
    rc->delta_dist[Y] = 1e30;
    if (rc->ray_dir[Y] != 0.0)
        rc->delta_dist[Y] = fabs(1.0 / rc->ray_dir[Y]);
}

static void compute_side_dist(t_data *data, t_raycast *rc)
{
    if (rc->ray_dir[X] < 0)
    {
        rc->step[X] = -1;
        rc->side_dist[X] = (data->pos[X] - rc->map[X]) * rc->delta_dist[X];
    }
    else
    {
        rc->step[X] = 1;
        rc->side_dist[X] = (rc->map[X] + 1 - data->pos[X]) * rc->delta_dist[X];
    }
    if (rc->ray_dir[Y] < 0)
    {
        rc->step[Y] = -1;
        rc->side_dist[Y] = (data->pos[Y] - rc->map[Y]) * rc->delta_dist[Y];
    }
    else
    {
        rc->step[Y] = 1;
        rc->side_dist[Y] = (rc->map[Y] + 1 - data->pos[Y]) * rc->delta_dist[Y];
    }
}

static void perform_dda(t_data *data, t_raycast *rc)
{
    int hit;

    compute_delta_dist(data, rc);
    compute_side_dist(data, rc);
    hit = 0;
    while (hit == 0)
    {
        if (rc->side_dist[X] < rc->side_dist[Y])
        {
            rc->side_dist[X] += rc->delta_dist[X];
            rc->map[X] += rc->step[X];
            rc->side = X;
        }
        else
        {
            rc->side_dist[Y] += rc->delta_dist[Y];
            rc->map[Y] += rc->step[Y];
            rc->side = Y;
        }
        hit = data->map_data[rc->map[X]][rc->map[Y]] > 0;
    }
}

static int  get_wall_color(t_data *data, t_raycast *rc)
{
    int color;

    color = 0x00FFFF;
    if (data->map_data[rc->map[X]][rc->map[Y]] == 1)
        color = 0xFF0000;
    else if (data->map_data[rc->map[X]][rc->map[Y]] == 2)
        color = 0x00FF00;
    else if (data->map_data[rc->map[X]][rc->map[Y]] == 3)
        color = 0x0000FF;
    else if (data->map_data[rc->map[X]][rc->map[Y]] == 4)
        color = 0xFFFFFF;
    if (rc->side == Y)
        color /= 2;
    return (color);
}

static void draw_wall(t_data *data, t_raycast *rc, int x)
{
    rc->line_height = WIN_HEIGHT / rc->perp_wall_dist;
    rc->draw_start = -rc->line_height / 2  + WIN_HEIGHT / 2;
    if (rc->draw_start < 0)
        rc->draw_start = 0;
    // rc->draw_end = rc->draw_start + rc->line_height;
    // if (rc->draw_end > WIN_HEIGHT)
        rc->draw_end = rc->line_height / 2 + WIN_HEIGHT / 2; // rc->draw_end = WIN_HEIGHT - 1;
    if (rc->draw_end >= WIN_HEIGHT)
        rc->draw_end = WIN_HEIGHT - 1;
    load_texture(data);
    double wallX;
    if(rc->side == 0)
        wallX = data->pos[Y] + rc->perp_wall_dist * rc->ray_dir[Y];
    else
        wallX = data->pos[X] + rc->perp_wall_dist * rc->ray_dir[X];
    wallX -= floor(wallX);
    int texX = (int)(wallX + (double)(data->tex_w));
    if (rc->side == 0 && rc->ray_dir[X] > 0)
        texX = data->tex_w - texX - 1;
    if (rc->side == 1 && rc->ray_dir[Y] < 0)
        texX = data->tex_w - texX - 1;
    double step = (double)data->tex_h / rc->line_height;
    double texPos = (rc->draw_start - WIN_HEIGHT / 2 + rc->line_height / 2) * step;
    int y = rc->draw_start;
    int texY;
    int color;
    puts("||");
    while(y < rc->draw_end)
    {
        if ((int)fmod(texPos, (data->tex_h - 1)))
            texY = (int)fmod(texPos, (data->tex_h - 1)); // -1
        // if (texY == 0)
        //     break;
        texPos += step;
        printf("%d,%f,%f\n",texY, texPos, step);
        color = *(int *)(data->img_color + (texY * data->size_line + texX * (data->bits_per_pixel / 8)));
        puts("--");
        if (rc->side == 1)
            color = (color >> 1) & 0x7F7F7F;
        // printf("%d,%d\n",color,rc->side);
        // img_pixel_put(data, x, y, color);
        y++;
        puts("*");
    }
    draw_vertical_line(data, rc, x, get_wall_color(data, rc));
}

void    raycast(t_data *data)
{
    int         x;
    double      cameraX;
    t_raycast   rc;

    x = -1;
    while (++x < WIN_WIDTH)
    {
        cameraX = 2.0 * x / WIN_WIDTH - 1;
        rc.ray_dir[X] = data->dir[X] + data->plane[X] * cameraX;
        rc.ray_dir[Y] = data->dir[Y] + data->plane[Y] * cameraX;
        perform_dda(data, &rc);
        if (rc.side == X)
            rc.perp_wall_dist = rc.side_dist[X] - rc.delta_dist[X];
        else
            rc.perp_wall_dist = rc.side_dist[Y] - rc.delta_dist[Y];
        draw_wall(data, &rc, x);
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
