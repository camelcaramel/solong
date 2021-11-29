/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:57:16 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/29 22:19:22 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_handler(t_data *data, int direction)
{
	int		index;
	int		row_count;
	int		col_count;
	t_pos	pos;

	index = 0;
	row_count = 0;
	col_count = 0;
	repaint(data);
	render_score(data);
	while (data->map_data[index])
	{
		if (data->map_data[index] == '\n')
		{
			row_count = 0;
			index = row_count + (data->max_row + 1) * (++col_count);
			continue ;
		}
		else
			row_count++;
		pos.x = (row_count - 1) * data->box_width;
		pos.y = col_count * data->box_height;
		render(data, direction, pos, data->map_data[index]);
		index = row_count + (data->max_row + 1) * col_count;
	}
}

void	render(t_data *data, int direction, t_pos pos, char target)
{
	if (target == '1')
		render_stone(data, pos.x, pos.y);
	else if (target == '0')
		render_bg(data, pos.x, pos.y);
	else if (target == 'P' || target == 'X')
		render_player(data, direction, pos.x, pos.y);
	else if (target == 'M')
		render_enemy(data, pos.x, pos.y);
	else if (target == 'E')
		render_exit(data, pos.x, pos.y);
	else if (target == 'C')
		render_coin(data, pos.x, pos.y);
	render_score(data);
}

void	render_score(t_data *data)
{
	int	x;
	int	y;

	x = data->box_width * (data->max_row / 2);
	y = data->box_height * data->max_col + 20;
	if (data->game_over == 1)
		mlx_string_put(data->mlx, data->win, x, y, 0x00bfff, "lose");
	else if (data->is_win == 0)
	{
		mlx_string_put(data->mlx, data->win, x, y, 0x00bfff, ft_itoa(data->step));
	}		
	else
		mlx_string_put(data->mlx, data->win, x, y, 0x00bfff, "Win!");
}

void	repaint(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->layer, 0, 0);
}
