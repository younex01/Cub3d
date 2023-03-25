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
    data->rotSpeed = 0.08; // 0.1
    data->moveSpeed = 0.9; //0.08
    // 	data->player.rot_speed = 1.5 * (M_PI / 180);
	// data->player.move_speed = 50;
}

int	keypress(int keycode,t_data *data)
{
    double oldDir;
    double oldPlan;

	if (keycode == 53 && data)
		exit(0);
	if (keycode == 13)
	{
        if(!(data->map_data[(int)(data->pos[X] + data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] += data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] + data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] += data->dir[Y] * data->moveSpeed;
    }
	if (keycode == 1)
	{
        if(!(data->map_data[(int)(data->pos[X] - data->dir[X] * data->moveSpeed)][(int)data->pos[Y]]))
            data->pos[X] -= data->dir[X] * data->moveSpeed;
        if(!(data->map_data[(int)data->pos[X]][(int)(data->pos[Y] - data->dir[Y] * data->moveSpeed)]))
            data->pos[Y] -= data->dir[Y] * data->moveSpeed;
    }
    if (keycode == 2)
    {
        if (fabs(data->dir[X]) > fabs(data->dir[Y]) 
            && !(data->map_data[(int)(data->pos[X] - data->dir[Y] * data->moveSpeed)][(int)(data->pos[Y] - data->dir[X] * data->moveSpeed)]))
        {
            data->pos[X] -= data->dir[Y] * data->moveSpeed;
            data->pos[Y] -= data->dir[X] * data->moveSpeed;
        }
        else if (fabs(data->dir[X]) < fabs(data->dir[Y]) 
            && !(data->map_data[(int)(data->pos[X] + data->dir[Y] * data->moveSpeed)][(int)(data->pos[Y] + data->dir[X] * data->moveSpeed)]))
        {
            data->pos[Y] += data->dir[X] * data->moveSpeed;
            data->pos[X] += data->dir[Y] * data->moveSpeed;
        }
    }
    if (keycode == 0)
    {
        if (fabs(data->dir[X]) < fabs(data->dir[Y]) && !(data->map_data[(int)(data->pos[X] - data->dir[Y] * data->moveSpeed)][(int)(data->pos[Y] - data->dir[X] * data->moveSpeed)]))
        {
            data->pos[X] -= data->dir[Y] * data->moveSpeed;
            data->pos[Y] -= data->dir[X] * data->moveSpeed;
        }
        else if (fabs(data->dir[X]) > fabs(data->dir[Y]) 
            && !(data->map_data[(int)(data->pos[X] + data->dir[Y] * data->moveSpeed)][(int)(data->pos[Y] + data->dir[X] * data->moveSpeed)]))
        {
            data->pos[Y] += data->dir[X] * data->moveSpeed;
            data->pos[X] += data->dir[Y] * data->moveSpeed;
        }
    }
    if(keycode == 124)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(-(data->rotSpeed)) - data->dir[Y] * sin(-(data->rotSpeed));
        data->dir[Y] = oldDir * sin(-(data->rotSpeed)) + data->dir[Y] * cos(-(data->rotSpeed));
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(-(data->rotSpeed)) - data->plane[Y] * sin(-(data->rotSpeed));
        data->plane[Y] = oldPlan * sin(-(data->rotSpeed)) + data->plane[Y] * cos(-(data->rotSpeed));
    }
    if(keycode == 123)
    {
        oldDir = data->dir[X];
        data->dir[X] = data->dir[X] * cos(data->rotSpeed) - data->dir[Y] * sin(data->rotSpeed);
        data->dir[Y] = oldDir * sin(data->rotSpeed) + data->dir[Y] * cos(data->rotSpeed);
        oldPlan = data->plane[X];
        data->plane[X] = data->plane[X] * cos(data->rotSpeed) - data->plane[Y] * sin(data->rotSpeed);
        data->plane[Y] = oldPlan * sin(data->rotSpeed) + data->plane[Y] * cos(data->rotSpeed);
    }
    // if (keycode == 13)
    // 	data->moveSpeed = 1;
    // if (keycode == 1)
    // 	data->moveSpeed = -1;
    // if (keycode == 2)
    // 	data->rotSpeed *= 1;
    // if (keycode == 0)
    //     data->rotSpeed *= -1;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
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
