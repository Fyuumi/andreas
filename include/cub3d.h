#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <error.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define HD
# define MINIMAP_BLOCK_SIZE 10
# define MOVEMENT_SPEED 2.5
# define ROTATION_SPEED 1.8

# ifdef HD
#  define HEIGHT 1080 // y
#  define WIDTH 1920  // x
# endif              // HD

# ifdef FK
#  define HEIGHT 2160 // y
#  define WIDTH 3840  // x
# endif              // FK

typedef enum e_hit_dir
{
			NO_wall,
			EA_wall,
			SO_wall,
			WE_wall
}			t_hit_dir;

typedef struct s_keys
{
	int		key_w;
	int		key_a;
	int		key_s;
	int		key_d;
	int		key_left;
	int		key_right;
}			t_keys;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		floor_color;
	int		ceiling_color;
	char	*path_no_texture;
	char	*path_so_texture;
	char	*path_we_texture;
	char	*path_ea_texture;
	char	*cubfile;
}			t_map;

typedef struct s_vect
{
	double	x;
	double	y;
}			t_vect;

typedef struct s_state
{
	t_vect	pos;
	t_vect	dir;
	t_vect	plane;
	double	mv_speed;
	double	rot_speed;
	double	delta_time;
	long	last_time;
}			t_state;

typedef struct s_ray
{
	char	**map_ptr;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;

	int		mapx;
	int		mapy;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_x;
	double	delta_y;
	double	per_wall_dist;

	int		stepx;
	int		stepy;
	int		side;
}			t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	t_map	map;
	t_keys	keys;

	t_state	state;
	// ptrs_to_textures.

}			t_game;

/* check_color */
int			color_check(t_game *game);

/* check_input.c */
int			check_input(t_game *game, char **argv);

/* check_map.c */
int			map_check(t_game *game);

/* debug_utils.c */
void		print2d(char **str);

/* raycasting.c*/
void		cast_rays(t_game *g, t_state *state);

/* raycasting_utils.c */
t_hit_dir	hit_direction(t_ray *r);
double		wall_hit_x(t_game *g, t_ray *r);

/* drawing.c */
void		clear_image(t_game *game);
void		ft_pixel_put(t_game *game, int x, int y, int color);
void		draw_square(t_game *game, int x, int y, int size, int color);

/* get_infos.c */
void		nswe_infos(t_game *game);
void		get_infos_map(t_game *game);

/* init_map.c */
void		init_map(t_game *game);

/* init_vectors.c */
void		init_vectors(char c, t_game *game);

/* events.c */
int			handle_key_press(int keysym, t_game *game);
int			handle_key_release(int keysym, t_game *game);
int			handle_close(t_game *game);

/* init.c */
void		init_dispay(t_game *game);
void		init_game(t_game *game);

/* closing.c */
void		cleanup(t_game *game);
void		exit_game(t_game *game, const char *msg);

/* minimap.c */
void		draw_map(t_game *game, int start_x, int start_y, int size);
void		draw_position(t_game *g, int tile_size);

/* movement.c */
int			try_move(t_game *g, double new_x, double new_y);
void		move_point(t_game *game);

/*set_null*/
void		set_null(t_game *game);

#endif
