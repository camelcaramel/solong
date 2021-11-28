/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:06:47 by donghwik          #+#    #+#             */
/*   Updated: 2021/11/01 15:01:38 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "solong_bonus.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	char			*temp;
	unsigned int	s_len;

	s_len = (unsigned int)ft_strlen(s);
	len = (s_len < len) ? s_len : len;
	if (s_len < start)
		len = 0;
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	temp = ret;
	s += start;
	while (len--)
		*ret++ = *s++;
	*ret = '\0';
	return (temp);
}

static int	s_search(char const *set, char target)
{
	while (*set)
		if (target == *set++)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;

	start = s1;
	end = s1 + ft_strlen(s1) - 1;
	while (s_search(set, *start) && *start)
		start++;
	while (end > start && s_search(set, *end))
		end--;
	return (ft_substr(start, 0, end - start + 1));
}