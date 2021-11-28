/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 18:55:58 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/28 18:36:52 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/solong.h"

void	check_format(t_data *data)
{
	int				row_count;
	int				col_count;
	unsigned int	index;

	row_count = 0;
	col_count = 0;
	index = 0;
	while (data->map_data[index])
	{
		check_char(data, &row_count, &col_count, &index);
	}
	index -= data->max_row + 1;
	while (data->map_data[++index])
		if (data->map_data[index] != '1')
			error_handler(data);
	data->max_col = col_count + 1;
	if (data->position->x == 0 && data->position->y == 0)
		error_handler(data);
}

void	check_char(t_data *data, int *row_count, int *col_count, unsigned int *index)
{
	if (data->map_data[*index] == '\n')
	{
		if (*row_count != data->max_row)
			error_handler(data);
		*row_count = 0;
		*(col_count) += 1;
		*(index) += 1;
	}
	else (*row_count) += 1;
	line_error_checker(*row_count, *col_count, *index, data);
	*index = *row_count + (data->max_row + 1) * (*(col_count));
}

void	line_error_checker(int row_count, int col_count, int index, t_data *data)
{
	char	cur;

	cur = data->map_data[index];
	if (cur == 'P' && data->position->x == 0 && data->position->y == 0)
	{
		data->position->x = row_count - 1;
		data->position->y = col_count;
	}
	else if (cur == 'P' && data->position->x != 0 && data->position->y != 0)
		data->map_data[index] = '0';
	if (cur == 'C')
		data->coin_n = data->coin_n + 1;
	if (cur == 'E' && data->is_exit == 0)
		data->is_exit = 1;
	if (cur == 'E' && data->is_exit == 0)
		error_handler(data);
	if (cur != 'P' && cur != 'E' && cur != 'C' && cur != '1' && cur != '0')
		error_handler(data);
	if (col_count == 0 && cur != '1')
		error_handler(data);
	if ((row_count == 0 || row_count == data->max_row)
		&& cur != '1')
		error_handler(data);
}