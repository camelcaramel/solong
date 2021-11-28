/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 19:00:20 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/28 23:13:27 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

/*
direction 
1 : up
2 : right
3 : down
4 : left
*/

int	monitor(int keycode, t_data *data)
{
	if (data->game_over == 0 && data->is_win == 0)
	{
		if (keycode == 13)
			move_player(1, data);
		else if (keycode == 0)
			move_player(4, data);
		else if (keycode == 1)
			move_player(3, data);
		else if (keycode == 2)
			move_player(2, data);
		else if (keycode == 53)
			exit(1);
	}
	else if (keycode == 53)
		 exit(1);
	return (0);
}

void	move_player(int direction, t_data *data)
{
	int				x;
	int				y;
	int				index;
	int				cur;

	x = data->position->x;
	y = data->position->y;
	cur = data->position->y * (data->max_row + 1) + data->position->x;
	find_path_enemy(data);
	consider_dir(&x, &y, direction);
	index = y * (data->max_row + 1) + x;
	if (index < 0)
		return ;
	if (data->map_data[index] == '1')
		return ;
	movement(data, index, cur);
	data->position->y = y;
	data->position->x = x;
	data->step = data->step + 1;
	printf("%d\n", data->step);
	render_handler(data, direction);
}

void	consider_dir(int *x, int *y, int direction)
{
	if (direction == 1)
		(*y)--;
	else if (direction == 2)
		(*x)++;
	else if (direction == 3)
		(*y)++;
	else
		(*x)--;
}

void	movement(t_data *data, int index, int cur)
{
	if (data->map_data[index] == 'C')
		data->coin_get += 1;
	else if (data->map_data[index] == 'E')
		game_over(data);
	else if (data->map_data[index] == 'M')
		killed(data);
	if (data->map_data[cur] == 'X')
		data->map_data[cur] = 'E';
	else
		data->map_data[cur] = '0';
	if (data->map_data[index] == 'E' && data->is_win == 0)
		data->map_data[index] = 'X';
	else
		data->map_data[index] = 'P';
}
