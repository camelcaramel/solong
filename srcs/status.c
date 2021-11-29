/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:57:22 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/29 22:56:30 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	game_over(t_data *data)
{
	if (data->coin_get == data->coin_n)
		data->is_win = 1;
}

void	killed(t_data *data)
{
	data->game_over = 1;
	render_score(data);
}
