/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:25:47 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/28 23:23:04 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/solong.h"

void	init_image(t_data *data)
{
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "./images/coin.xpm",
		&data->box_width, &data->box_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./images/player.xpm",
		&data->box_width, &data->box_height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "./images/enemy.xpm",
		&data->box_width, &data->box_height);
	data->bg_img = mlx_xpm_file_to_image(data->mlx, "./images/bg.xpm",
		&data->box_width, &data->box_height);
	data->fence_img = mlx_xpm_file_to_image(data->mlx, "./images/stone.xpm",
		&data->box_width, &data->box_height);
	data->p_r_img = mlx_xpm_file_to_image(data->mlx, "./images/p_right.xpm",
		&data->box_width, &data->box_height);
	data->p_l_img = mlx_xpm_file_to_image(data->mlx, "./images/p_left.xpm",
		&data->box_width, &data->box_height);
	data->exit_img = mlx_xpm_file_to_image(data->mlx, "./images/exit.xpm",
		&data->box_width, &data->box_height);
}

int	exit_btn_handler(t_data *data)
{
	if (data->map_data != NULL)
		free(data->map_data);
	if (data->input_str != NULL)
		free(data->input_str);
	exit(1);
}

void	start(t_data *data, int fd)
{
	data->mlx = mlx_init();
	parse_map(fd, data);
	data->win = mlx_new_window(data->mlx, 22 * data->max_row, 22 * data->max_col + 50, "solong");
	data->layer = mlx_new_image(data->mlx, 22 * data->max_row, 22 * data->max_col + 50);
	set_enemy(data);
	calculate_size(data);
	init_image(data);
	mlx_key_hook(data->win, monitor, data);
	mlx_hook(data->win, 17, 0, exit_btn_handler, data);
	render_handler(data, 1);
	mlx_loop(data->mlx);
}
