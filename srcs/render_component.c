/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_component.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:17:58 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/28 23:21:16 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	render_bg(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->bg_img,
		x, y);
}

void	render_enemy(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->enemy_img,
		x, y);	
}

void	render_coin(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->coin_img,
		x, y);
}

void	render_stone(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->fence_img,
		x, y);
}

void	render_exit(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->exit_img,
		x, y);
}
