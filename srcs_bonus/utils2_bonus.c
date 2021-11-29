/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:58:44 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/29 22:34:53 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/solong_bonus.h"

static int	num_length(unsigned int n)
{
	int		len;

	len = 0;
	while ((n) > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	strrev(char *s)
{
	int			len;
	char		temp;

	len = ft_strlen(s);
	while (len > 0)
	{
		temp = *s;
		*s = *(s + len - 1);
		*(s + len - 1) = temp;
		len -= 2;
		s++;
	}
}

static void	fill_number(char *s, unsigned int n)
{
	char	*temp;

	temp = s;
	if (n == 0)
	{
		*s++ = '0';
		*s = '\0';
		return ;
	}
	while (n > 0)
	{
		*s++ = '0' + (n % 10);
		n /= 10;
	}
	*s = '\0';
	strrev(temp);
}

static void	itoa_helper(char *ret, int n, char *ment, int num)
{
	int	index;

	if (n < 0)
		*ret = '-';
	index = -1;
	while (ment[++index])
		ret[index] = ment[index];
	if (n < 0)
		fill_number(ret + 1 + 8, num);
	else
		fill_number(ret + 8, num);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				size;
	char			*ret;
	char			*ment;

	ment = "score = ";
	num = n;
	if (n < 0)
		num = (-1) * (n);
	else
		num = n;
	size = num_length(num);
	if (n < 0)
		size = size + 2;
	else
		size = size + 1;
	ret = (char *)malloc(sizeof(char) * (size + 8));
	if (ret == NULL)
		return (NULL);
	itoa_helper(ret, n, ment, num);
	return (ret);
}
