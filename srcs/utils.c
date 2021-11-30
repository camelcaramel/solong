/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:37:23 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/30 14:27:55 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ret;

	ret = b;
	while (len--)
		*ret++ = (unsigned char)c;
	return ((void *)b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!d && !s)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (!d && !s)
		return (NULL);
	if (!len)
		return (dst);
	if (d <= s)
		return (ft_memcpy(dst, src, len));
	s += len;
	d += len;
	while (len--)
		*--d = *--s;
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	const char	*temp;

	temp = s;
	while (*temp)
		temp++;
	return (temp - s);
}

void	error_handler(t_data *data)
{
	printf("Error.\n");
	if (data->input_str != NULL)
		free(data->input_str);
	if (data == NULL || data->map_data != NULL)
		free(data->map_data);
	exit(1);
}
