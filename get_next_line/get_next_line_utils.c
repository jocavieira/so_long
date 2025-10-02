/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@sudent.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:33:45 by jocarlo2          #+#    #+#             */
/*   Updated: 2025/10/02 08:15:20 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlengnl(const char *s)
{
	size_t i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_strdupgnl(const char *s)
{
	size_t	len;
	char	*copy;
	size_t	i;

	len = ft_strlengnl(s);
	copy = malloc(len +1);
	i = 0;
	if (!copy)
		return (NULL);
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
char	*ft_substrgnl(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*sub;

	slen = 0;
	i = 0;
	slen = ft_strlengnl(s);
	if (start >= slen)
		return (ft_strdupgnl(""));
	if (len > slen - start)
		len = slen - start;
	sub = (char *)malloc(len + 1);
	if (!sub)
		return (NULL);
	while (s[start + i] && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t j;

	if (!s1)
		s1 = ft_strdupgnl("");
	new = malloc(ft_strlengnl(s1) + ft_strlengnl(s2) + 1);
	if (!new)
    return (free(s1), NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];

	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (free (s1), new);
}
char *ft_strchr_gnl(char *s, char c)
{
    if (!s)
        return (NULL);
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    if ((char)c == '\0')
        return (s);
    return (NULL);
}

