/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom_editor.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/27 15:51:24 by Polcito           #+#    #+#             */
/*   Updated: 2020/06/27 20:22:38 by user42           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

 #ifndef DOOM_EDITOR_H
 # define DOOM_EDITOR_H

# include "../../libft/include/libft.h"
# include "../../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/time.h>

# define WIDTH 1280
# define HEIGHT 900
# define HUD_W 1000
# define HUD_H 800

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
	int					start;
	int					current;
	int					end;
}						t_color;

typedef struct			s_ray
{
	int					xi;
	int					xf;
	int					yi;
	int					yf;
}						t_ray;

typedef struct			s_xyz
{
	float				x;
	float				y;
	float				z;
}						t_xyz;

typedef struct			s_dot
{
	int					x;
	int					y;
}						t_dot;

typedef struct			s_tab
{
	int					pos_x;
	int					pos_y;
	int					pos_z;
	int					rot_x;
	int					rot_y;
	int					rot_z;
	int					tab_state;
	int					floor_state;
	int					spawn;
	int					direction;
}						t_tab;

typedef struct			s_coord
{
	t_xyz				tab[4];
	struct s_coord		*next;
}						t_coord;

typedef	struct			s_point
{
	int x;
	int y;
	struct s_point 		*next;
	struct s_point		*prev;
}						t_point;

typedef struct			s_image
{
	void				*wall_stone;
	char				*str_image;
	int					width;
	int					height;
	int					bpp;
	int					s_l;
	int					endian;
}						t_image;

typedef struct			s_select
{
	int					mouse_state;
	int					skybox;
}						t_select;

typedef struct			s_mouse
{
	int					x;
	int					y;
}						t_mouse;


typedef struct          s_file
{
    void				*mlx_ptr;
	void				*win_ptr;
	void				*ptr_img;
	char        		*my_str_img;
	int					bpp;
	int					s_l;
	int					endian;
	double				z;
	double				z_bis;
	t_mouse				mouse;
	t_select			state;
	t_ray				point;
	t_color				color;
	t_image				image[50];
	char*				name_texture[50];
	t_tab				tab[43][49];
	t_dot				position_texture[50];
	int					resetspawn;
}                       t_file;

typedef struct			s_bresenham
{
	double				dx;
	double				dy;
	double				i;
	double				xinc;
	double				yinc;
	double				cumul;
	double				x;
	double				y;
	double				c;
}						t_bresenham;

void		edit_z_2(t_file *file);
int	        deal_key(int key, t_file *file);
int			mouse_press(int key, int x, int y, t_file *file);
int			mouse_move(int x, int y, t_file *file);
int			display_window(t_file *file);
void		color_pixel(t_file *file, int x, int y);
void		bresenham(t_file *file, t_dot a, t_dot b);
int			get_color(t_file *file, t_bresenham brese, int start, int end);
void    	draw_circle(t_file *file, int x0, int y0);
void        list_point(t_point **point, int x, int y);
void		init_hud(t_file *file);
void		init_hud_bis(t_file *file);
int	        texture_images_init(t_file *file);
int			init_tab_texture(t_file *file);
void		init_tab_texture_2(t_file *file);
void		init_tab_texture_3(t_file *file);
void        clear_tab(t_file *file);
int			green_case(int x, int y, t_file *file);
int			blue_case(int x, int y, t_file *file);
int 		white_case(int x, int y, t_file *file);
int         wall_stone_texture(int x, int y, t_file *file);
int         wall_stone2_texture(int x, int y, t_file *file);
int         wall_square_texture(int x, int y, t_file *file);
int         wall_chair_texture(int x, int y, t_file *file);
int         wall_blue_texture(int x, int y, t_file *file);
int         wall_window_texture(int x, int y, t_file *file);
int         wall_wood_texture(int x, int y, t_file *file);
int         wall_green_texture(int x, int y, t_file *file);
int         wall_bluecomp_texture(int x, int y, t_file *file);
int         wall_quartz_texture(int x, int y, t_file *file);
int         wall_brick_texture(int x, int y, t_file *file);
int         wall_greencomp_texture(int x, int y, t_file *file);
void        init_tab(t_file *file);
void        check_state_int(t_file *file, int i, int j);
void        check_state_int_2(t_file *file, int i, int j);
void        check_state_int_3(t_file *file, int i, int j);
void        check_state_int_4(t_file *file, int i, int j);
void        check_state_int_5(t_file *file, int i, int j);
void        check_state_int_6(t_file *file, int i, int j);
void		check_state_int_7(t_file *file, int i, int j);
void    	select_visual_textures(int x, int y, t_file *file);
void		select_visual_textures_2(int x, int y, t_file *file);
void		select_visual_textures_3(int x, int y, t_file *file);
void		select_visual_textures_4(int x, int y, t_file *file);
void		select_visual_textures_5(int x, int y, t_file *file);
void		select_visual_textures_6(int x, int y, t_file *file);
void    	select_visual_skybox(int x, int y, t_file *file);
void    	print_white_visual_textures(int x, int y, t_file *file, int i);
void    	print_blue_visual_textures(int x, int y, t_file *file, int i);
void		print_white_visual_skybox(int x, int y, t_file *file, int i);
void		print_red_visual_skybox(int x, int y, t_file *file, int i);
int         spawn_green_start(int x, int y, t_file *file);
int         spawn_red_end(int x, int y, t_file *file);
int         potion_heal(int x, int y, t_file *file);
int         potion_mana(int x, int y, t_file *file);
int         bullet_doom(int x, int y, t_file *file);
int         key_doom(int x, int y, t_file *file);
int         doom_monster_1(int x, int y, t_file *file);
int         doom_monster_2(int x, int y, t_file *file);
int         doom_monster_3(int x, int y, t_file *file);
int         doom_monster_4(int x, int y, t_file *file);
void		button_clear_save(t_file *file);
void		hud_dark_theme(t_file *file);
void        check_floor(t_file *file, int floor, int i, int j);
void		edit_z(t_file *file);
void		sorting_parse(t_file *file);
void        draw_mob_and_object(int x, int y, t_file *file, int fd);
void        draw_mob(int x, int y, t_file *file, int fd);
void        draw_wall(int x, int y, t_file *file, int fd);
void		draw_wall_2(int x, int y, t_file *file, int fd);
void        draw_floor(int x, int y, t_file *file, int fd);
void    	parse_skybox(t_file *file, int fd);
void        reset_spawn(t_file *file);
void		mouse_press_2(int x, int y, t_file *file);
void		mouse_press_3(int x, int y, t_file *file);
void		mouse_press_4(int x, int y, t_file *file);
void		mouse_press_5(int x, int y, t_file *file);
void		mouse_press_6(int x, int y, t_file *file);
void		mouse_press_7(int x, int y, t_file *file);
void		mouse_press_8(int x, int y, t_file *file);
void		hud_white_case_2(t_file *file);
void		hud_white_case_3(t_file *file, int i, int j);
void		choose_textures_floor(t_file *file, int fd, int x, int y);
void		choose_textures_wall(t_file *file, int fd, int x, int y);
void		choose_objects_file(t_file *file, int fd, int x, int y);
void		first_dot_wall(int x, int y, t_file *file, int fd);
void		first_dot_wall_bis(int x, int y, t_file *file, int fd);
void		second_dot_wall(int x, int y, t_file *file, int fd);
void		third_dot_wall(int x, int y, t_file *file, int fd);
void		first_dot_wall_2(int x, int y, t_file *file, int fd);
void		first_dot_wall_bis_2(int x, int y, t_file *file, int fd);
void		second_dot_wall_2(int x, int y, t_file *file, int fd);
void		third_dot_wall_2(int x, int y, t_file *file, int fd);
void		first_dot_floor(int x, int y, t_file *file, int fd);
void		second_dot_floor(int x, int y, t_file *file, int fd);
void		third_dot_floor(int x, int y, t_file *file, int fd);
void        draw_base_floor(int fd);
void		draw_base_floor_1(int fd);
void		draw_base_floor_2(int fd);
void		draw_base_floor_3(int fd);

#endif