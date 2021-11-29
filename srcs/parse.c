/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:23:37 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/29 22:15:16 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	parse_map(int fd, t_data *data)
{
	size_t			rd_size;
	char			buf[101];
	t_parse_data	p_data;

	p_data.size = 100;
	p_data.length = 0;
	p_data.rear = 0;
	p_data.last_index = 0;
	ft_memset(buf, '\0', 101);
	data->map_data = (char *)malloc(sizeof(char) * p_data.size);
	if (data->map_data == NULL)
		error_handler(data);
	rd_size = read(fd, buf, 100);
	while (0 < rd_size)
	{
		if (data->max_row == 0)
			check_row_length(buf, &p_data, data);
		expand_map(data, &p_data, buf, rd_size);
		ft_memset(buf, '\0', 101);
		rd_size = read(fd, buf, 100);
	}
	check_format(data);
}

void	expand_map(t_data *data, t_parse_data *p_data,
	char *buf, size_t buf_size)
{
	char	*temp;

	if (p_data->size < p_data->length)
	{
		temp = (char *)malloc(sizeof(char) * (p_data->size) * 2);
		if (temp == NULL)
		{
			error_handler(data);
		}
		ft_memmove(temp, data->map_data, p_data->size);
		free(data->map_data);
		data->map_data = temp;
		p_data->size *= 2;
	}
	ft_memmove((data->map_data) + p_data->rear, buf, buf_size);
	p_data->rear += buf_size;
}

void	check_row_length(char *line, t_parse_data *p_data, t_data *data)
{
	int		index;
	int		end;

	index = -1;
	end = 0;
	while (line[++index])
	{
		if (line[index] != '1' && line[index] != '\n')
			error_handler(data);
		if (line[index] == '\n')
		{
			data->max_row = index + (int)(p_data->length);
			p_data->length += ft_strlen(line);
			if (data->max_row < 2)
				error_handler(data);
			return ;
		}
	}
}
