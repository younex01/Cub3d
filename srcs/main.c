#include "cub3d.h"

int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 2, 2, 0, 2, 2, 0, 0, 0, 0, 3, 0, 3, 0, 3, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 0, 0, 0, 5, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 4, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static void game_init(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (++i < MAP_WIDTH)
    {
        j = -1;
        while (++j < MAP_HEIGHT)
            data->map_data[i][j] = worldMap[i][j];
    }
    data->pos[X] = 22;
    data->pos[Y] = 12;
    data->dir[X] = -1;
    data->dir[Y] = 0;
    data->plane[X] = 0;
    data->plane[Y] = 0.66;
    data->rotSpeed = 2; // 0.1
    data->moveSpeed = 2; //0.08

    // 	data->player.rot_speed = 1.5 * (M_PI / 180);
	// data->player.move_speed = 50;
}

int	keypress(int keycode,t_data *data)
{
	if (keycode == 53 && data)
		exit(0);
	if (keycode == 126)
	{
        if(!(data->map_data[(int)(data->pos[X] + data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] += data->dir[Y] * data->moveSpeed;
    }
	if (keycode == 125)
	{
        if(!(data->map_data[(int)(data->pos[X] - data->dir[X] * 2)][(int)data->pos[Y]]))
            data->pos[X] -= data->dir[X] * 2;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->dir[Y] * 2)]))
            data->pos[Y] -= data->dir[Y] * 2;
    }
    if(keycode == 124)
    {
        double oldDir[2];
        double oldPlan[2];
        oldDir[X] = data->dir[X];
        data->dir[X] = data->dir[X] * cos(-data->rotSpeed) - data->dir[Y] * sin(-data->rotSpeed);
        data->dir[X] = oldDir[X] * sin(-data->rotSpeed) + data->dir[Y] * cos(-data->rotSpeed);
        data->plane[X] = data->plane[X] * cos(-data->rotSpeed) - data->plane[Y] * sin(-data->rotSpeed);
        data->plane[Y] = oldPlan[X] * sin(-data->rotSpeed) + data->plane[Y] * cos(-data->rotSpeed);
    }
    if(keycode == 123)
    {
        double oldDir[2];
        double oldPlan[2];
        oldDir[X] = data->dir[X];
        data->dir[X] = data->dir[X] * cos(data->rotSpeed) - data->dir[Y] * sin(data->rotSpeed);
        data->dir[X] = oldDir[X] * sin(data->rotSpeed) + data->dir[Y] * cos(data->rotSpeed);
        data->plane[X] = data->plane[X] * cos(data->rotSpeed) - data->plane[Y] * sin(data->rotSpeed);
        data->plane[Y] = oldPlan[X] * sin(data->rotSpeed) + data->plane[Y] * cos(data->rotSpeed);
    }
	// if (keycode == 124)
	// 	p->posX = p->posX + 5;
	// if (keycode == 125)
	// 	p->posY = p->posY + 5;
	// if (keycode == 126)
	// 	p->posY = p->posY - 5;
	// ft_draw(p->image, p->mlx, p->mlx_win, &(p->posX), &(p->posY));
    raycast(data);
	return (0);
}

int main(void)
{
    t_data  data;

    game_init(&data); // TODO: This is the parsing part
    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT,  "cub3d");
    data.img_ptr = mlx_new_image(data.mlx_ptr,  WIN_WIDTH,  WIN_HEIGHT);
    data.data_addr = mlx_get_data_addr(data.img_ptr, 
            &data.bits_per_pixel,  &data.size_line,  &data.endian);
    raycast(&data);
	mlx_hook(data.win_ptr, 2, 0, keypress, (void *)&data);
    mlx_loop(data.mlx_ptr);
}
