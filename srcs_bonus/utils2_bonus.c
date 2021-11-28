/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 20:58:44 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/28 18:36:31 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong_bonus.h"

static int		num_length(unsigned int n)
{
	int		len;

	len = 1;
	while ((n /= 10) > 0)
		len++;
	return (len);
}

static void		strrev(char *s)
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

static void		fill_number(char *s, unsigned int n)
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

char			*ft_itoa(int n)
{
	unsigned int	num;
	int				size;
	char			*ret;
	char			*ment;
	int				index;

	ment = "score = ";
	num = (n < 0) ? (-1) * (n) : (n);
	size = num_length(num);
	size = (n < 0) ? (size + 2) : (size + 1);
	if ((ret = (char *)malloc(sizeof(char) * (size + 8))) == NULL)
		return (NULL);
	if (n < 0)
		*ret = '-';
	index = 0;
	while (ment[index])
	{
		ret[index] = ment[index];
		index++;
	}
	fill_number((n < 0) ? (ret + 1 + 8) : (ret + 8), num);
	return (ret);
}