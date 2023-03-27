#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
#include <stdlib.h>
# include <stdio.h>

# define WIN_WIDTH  1280
# define WIN_HEIGHT 720

# define X          0
# define Y          1

# define SKY        0x87CEEB
# define GRASS      0x7CFC00

// TODO: read it from input file
# define MAP_WIDTH  24
# define MAP_HEIGHT 24

typedef struct
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *data_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    int     map_width;
    int     map_height;
    int     map_data[MAP_WIDTH][MAP_HEIGHT]; // TODO: use a point `int **map_data;` instead
    double  pos[2];
    double  dir[2];
    double  plane[2];
    double  moveSpeed;
    double  rotSpeed;
    void    *texture;
    int     tex_w;
    int     tex_h;
    char    *img_color;
}   t_data;

typedef struct
{
    double  ray_dir[2];
    int     map[2];
    double  side_dist[2];
    double  delta_dist[2];
    double  perp_wall_dist;
    int     step[2];
    int     side;
    int     line_height;
    int     draw_start;
    int     draw_end;
}   t_raycast;

void    draw_vertical_line(t_data *data, t_raycast *rc, int x, int wall_color);
void    raycast(t_data *data);
void img_pixel_put(t_data *data, int x, int y, int color);
void    load_texture(t_data *data);

#endif // CUB3D_H
