/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icarboni <icarboni@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:03:14 by icarboni          #+#    #+#             */
/*   Updated: 2022/10/04 12:03:24 by icarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(const char *str)
{
	int					c;
	unsigned char		*str2;

	if (str == NULL)
		return (0);
	str2 = (unsigned char *) str;
	c = 0;
	while (str2[c] != '\0')
		c++;
	return (c);
}

char	*ft_joinaux(char *s1, char const *s2, int s1_len, int len_sum)
{
	int		i;
	char	*s;
	int		d;

	i = 0;
	d = 0;
	s = (char *)malloc((len_sum + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);
	while ((i + d) < len_sum)
	{
		if (i < s1_len)
		{
			s[i] = s1[i];
			i++;
		}
		else
		{
			s[i + d] = s2[d];
			d++;
		}
	}
	s[i + d] = '\0';
	free(s1);
	return (s);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		len_sum;
	int		s1_len;

	s1_len = ft_strlen(s1);
	len_sum = (s1_len + ft_strlen(s2));
	return (ft_joinaux(s1, s2, s1_len, len_sum));
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*d;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return (NULL);
	d = (unsigned char *) s;
	while (*d != '\0')
	{
		if (*d == (unsigned char) c)
			return ((char *)d);
		d++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)d);
	else
		return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;
	size_t	i;
	size_t	size_use;

	i = -1;
	len_s = ft_strlen(s);
	if (start > len_s || len_s == 0)
		size_use = 0;
	else if ((len_s - start) < len)
		size_use = len_s - start;
	else
		size_use = len;
	sub = (char *)malloc(sizeof(char) * (size_use + 1));
	if (sub == NULL)
		return (NULL);
	while (++i < (size_use))
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
