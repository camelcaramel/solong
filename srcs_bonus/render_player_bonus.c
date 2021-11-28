/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 17:01:32 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/01 15:04:08 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong_bonus.h"

void	render_player(t_data *data, int direction, int x, int y)
{
	if (data->is_win == 1)
	{
		data->ani_x = x;
		data->ani_y = y;
		return ;
	}
	if (direction ==  1 || direction == 3)
		render_player_face(data, x, y);
	else if (direction == 2)
	{
		render_player_right(data, x, y);
		render_bg(data, x, y);
		render_player_face(data, x, y);
	}
	else if (direction == 4)
	{
		render_player_left(data, x, y);
		render_bg(data, x, y);
		render_player_face(data, x, y);
	}
}

void	render_player_face(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->player_img,
			x, y);
}

void	render_player_right(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->p_r_img,
			x, y);
}

void	render_player_left(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->p_l_img,
			x, y);
}