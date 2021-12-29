#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# define BUFFER_SIZE 4096
# define PLAYER_L1 "./img/witch_l1.xpm"
# define PLAYER_R1 "./img/witch_r1.xpm"
# define BOT "./img/grass.xpm"
# define WALL "./img/wall.xpm"
# define COIN "./img/coin.xpm"
# define EXIT "./img/boiler.xpm"
# define EXIT_WIN "./img/exit.xpm"

typedef struct	s_map {
	char	**arr;
	int		column;
	int		lines;
	int		coins;
	int 	coins_number;
	int		count_iter;
	int 	collect;
	int		exit;
	int		player;
}				t_map;

typedef struct	s_display {
	void	*mlx;
	void	*win;
	char 	*grass;
	void	*player_img[2];
	char	*coin;
	char	*wall;
	char	*exit;
}				t_display;

typedef struct  s_obj {
	int		x;
	int		y;
	int 	disabled;
	int 	isLeft;
}				t_player, t_coins;

typedef struct	s_render {
	t_display	*display;
	t_map		*map;
	t_player	*player;
	t_coins		*coins;
}				t_render;

size_t	ft_strlen(const char *s);
void	error(int num);
void	valid_map(char *argv, t_render *render);
void	read_to_arr(char *argv, t_map *map);
void	arr_to_struct(t_render *render);
void	display_init(t_render *render);
void	check_extension(char *argv);
void 	end_game(t_display *display);
int		expose_hook(void *param);
void	render_item(t_render *render);
int		render_next_frame(void *rend);
void	check_collision(t_render *render);

char	**ft_split(const char *str, char c, t_map *map);
void	*ft_memcpy(void *dest, const void *s, size_t n);
void	*ft_calloc(unsigned numelem, size_t sizelem);
void	ft_bzero(void *s, size_t n);
void	clear_all(t_render *render);

#endif
