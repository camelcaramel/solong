/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 21:43:45 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/01 15:41:28 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/solong.h"

void	find_path_enemy(t_data *data)
{
	int			x;
	int			y;
	static int	try;
	int			from;

	x = data->e_pos->x;
	y = data->e_pos->y;
	from = data->e_pos->x + data->e_pos->y *(data->max_row + 1);
	while (try++ < 4)
	{
		x = data->e_pos->x;
		y = data->e_pos->y;
		if (try == 4)
			y--;
		else if (try == 3)
			x++;
		else if (try == 2)
			y++;
		else if (try == 1)
			x--;
		if (is_possible2move(data->map_data[y * (data->max_row + 1) + x]) == 1)
			return (move_enemy(data, from, x, y));
	}
	try = 0;
}

void	move_enemy(t_data *data, int from, int x, int y)
{
	data->e_pos->x = x;
	data->e_pos->y = y;
	data->map_data[from] = '0';
	data->map_data[y * (data->max_row + 1) + x] = 'M';
}

int		is_possible2move(char c)
{
	return (c == '0' || c == 'P');
}

void	set_enemy(t_data *data)
{
	int		index;

	index = 0;
	while (data->map_data[index])
	{
		if (data->map_data[index] == '0')
		{
			data->map_data[index] = 'M';
			data->e_pos->x = index % data->max_row - 1;
			data->e_pos->y = index / data->max_row;
			return ;
		}
		index++;
	}
}