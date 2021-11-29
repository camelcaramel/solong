/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:24:01 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/29 22:15:00 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

int	check_input_str(char *str, t_data *data)
{
	int		index;
	int		i;
	char	*pat;

	index = 1;
	i = 0;
	pat = ".ber";
	str = ft_strtrim(str, " ");
	if (str == NULL)
		return (0);
	while (*(str + i))
		i++;
	while (*(str + i - index) && index < 5)
	{
		if (*(str + i - index) != pat[4 - index])
			return (0);
		index++;
	}
	data->input_str = str;
	return (1);
}

void	init_data(t_data *data)
{
	data->coin_n = 0;
	data->coin_get = 0;
	data->step = 0;
	data->is_win = 0;
	data->max_row = 0;
	data->max_col = 0;
	data->game_over = 0;
	data->is_exit = 0;
	data->ani_x = 0;
	data->ani_y = 0;
	data->map_data = NULL;
	data->input_str = NULL;
}

void	calculate_size(t_data *data)
{
	data->box_height = 22 * data->max_row;
	data->box_width = 22 * data->max_col;
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_data	data;
	t_pos	pos;
	t_pos	e_pos;

	init_data(&data);
	if (argc != 2 || !check_input_str(argv[1], &data))
		error_handler(&data);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_handler(&data);
	else
	{
		data.position = &pos;
		data.position->x = 0;
		data.position->y = 0;
		data.e_pos = &e_pos;
		data.e_pos->x = 0;
		data.e_pos->y = 0;
		start(&data, fd);
	}
	return (0);
}
