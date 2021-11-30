/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:19:09 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/30 14:46:31 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "../mlx/mlx.h"

typedef	struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_data
{
	void	*mlx;
	void	*win;
	void	*player_img;
	void	*p_r_img;
	void	*p_l_img;
	void	*enemy_img;
	void	*fence_img;
	void	*coin_img;
	void	*exit_img;
	void	*bg_img;
	int		max_row;
	int		max_col;
	int		step;
	int		coin_n;
	int		coin_get;
	char	*map_data;
	int		game_over;
	int		box_width;
	int		box_height;
	void	*layer;
	int		is_win;
	int		is_exit;
	char	*input_str;
	t_pos	*position;
	t_pos	*e_pos;
	int		ani_x;
	int		ani_y;
}			t_data;

typedef	struct	s_parse_data
{
	int	size;
	int	length;
	int	rear;
	int	last_index;
}				t_parse_data;

typedef	struct	s_hoop_data
{
	int			x;
	int			y;
	t_data		*data;
}				t_hoop_data;

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	error_handler(t_data *data);

void	parse_map(int fd, t_data *data);
void	line_error_checker(int row_count,
	int col_count, int index, t_data *data);
void	check_format(t_data *data);
void	check_row_length(char *line, t_parse_data *p_data, t_data *data);
void	expand_map(t_data *data, t_parse_data *p_data,
	char *buf, size_t buf_size);

void	render_handler(t_data *data, int direction);
void	render(t_data *data, int direction, t_pos pos, char target);
void	calculate_size(t_data *data);
void	render_score(t_data *data);
void	repaint(t_data *data);

void	render_player(t_data *data, int direction, int x, int y);
void	render_player_face(t_data *data, int x, int y);
void	render_player_right(t_data *data, int x, int y);
void	render_player_left(t_data *data, int x, int y);

void	render_bg(t_data *data, int x, int y);
void	render_enemy(t_data *data, int x, int y);
void	render_coin(t_data *data, int x, int y);
void	render_stone(t_data *data, int x, int y);
void	render_exit(t_data *data, int x, int y);

int		monitor(int keycode, t_data *data);
void	move_player(int direction, t_data *data);
void	killed(t_data *data);
void	game_over(t_data *data);

char	*ft_itoa(int n);

void	set_enemy(t_data *data);
int		is_possible2move(char c);
void	move_enemy(t_data *data, int from, int x, int y);
void	find_path_enemy(t_data *data);

void	render_win_animation(t_data *data, int x, int y);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);

void	init_data(t_data *data);
void	calculate_size(t_data *data);

void	start(t_data *data, int fd);
void	init_image(t_data *data);

void	consider_dir(int *x, int *y, int direction);
void	movement(t_data *data, int index, int cur);

void	check_char(t_data *data, int *row_count,
	int *col_count, unsigned int *index);
int		check_input_str(char *str, t_data *data);

int		exit_btn_handler(t_data *data);

void	init_pointer_data(t_data *data);

# endif