#include "../include/so_long.h"

int	key_hook(int keycode, t_map *map)
{
	printf("key: %d!\n", keycode);
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 124 || keycode == 2)
	{

	}
	else if (keycode == 126 || keycode == 13)
	{

	}
	else if (keycode == 123 || keycode == 0)
	{

	}
	else if (keycode == 125 || keycode == 1)
	{

	}
	return 0;
}

int	render_next_frame(void *t_display);

int	main(int argc, char **argv)
{
	//init
	t_display	display;
	t_map		map;
	t_render	*render;
	t_player	player;
	t_coins		coins;
	char	*path_player = "./img/witch.xpm";
	char	*path_grass = "./img/grass.xpm";
	char	*path_wall = "./img/wall.xpm";
	char	*path_coin = "./img/coin.xpm";
	char	*path_exit = "./img/boiler.xpm";
	int		img_width;
	int		img_height;
	void 	*struc;

	// map = (t_map *)malloc(sizeof(t_map));
	// if (!map)
	// 	perror("Map: ");
	render = malloc(sizeof(t_render));
	init_map_struct(&map);
	open_map(argv[1], &map);
	map_to_arr(argv[1], &map);

	display.mlx = mlx_init();
	display.win = mlx_new_window(display.mlx, map.column * 50, map.lines * 50, "So Long");
	display.grass = mlx_xpm_file_to_image(display.mlx, path_grass, &img_width, &img_height);
	display.player_img = mlx_xpm_file_to_image(display.mlx, path_player, &img_width, &img_height);
	display.coin = mlx_xpm_file_to_image(display.mlx, path_coin, &img_width, &img_height);
	display.wall = mlx_xpm_file_to_image(display.mlx, path_wall, &img_width, &img_height);
	display.exit = mlx_xpm_file_to_image(display.mlx, path_exit, &img_width, &img_height);

	render->display = &display;
	render->map = &map;
	render->player = &player;
	render->coins = &coins;

	mlx_key_hook(display.win, key_hook, &map);
	mlx_loop_hook(display.mlx, render_next_frame, render);
	mlx_loop(display.mlx);
}

int	render_next_frame(void *rend)
{
	t_render *render;
	render = (t_render*)rend;

	for (int i = 0; i < render->map->lines; i++)
	{
			for (int j = 0; j < render->map->column; j++)
		{
			//printf("i = %d j = %d arr = %c\n", i, j, render->map->arr[i][j]);
			if(render->map->arr[i][j] == '1')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->wall, j * 51, i * 51);
			else if(render->map->arr[i][j] == '0')
			 	mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->grass, j * 51, i * 51);
			else if(render->map->arr[i][j] == 'P')
			{
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->player_img, j * 51, i * 51);
				// printf("player[%d][%d]\n", i, j);
			}
			else if(render->map->arr[i][j] == 'C')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->coin, j * 51, i * 51);
			else if(render->map->arr[i][j] == 'E')
				mlx_put_image_to_window(render->display->mlx, render->display->win, render->display->exit, j * 51, i * 51);
		}
	}
	//mlx_put_image_to_window(display->mlx, display->win, display->player, var->x, var->y);
	return 0;
}
