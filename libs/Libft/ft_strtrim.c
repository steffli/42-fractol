/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:04:13 by stliu             #+#    #+#             */
/*   Updated: 2025/03/16 15:09:51 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s1 string to be trimmed, remove the set of characters
*/

static int	ft_set(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	s1_len;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_set(set, s1[i]))
		i++;
	while (s1_len > i && ft_set(set, s1[s1_len - 1]))
		s1_len--;
	ptr = malloc(s1_len - i + 1 * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < s1_len)
	{
		ptr[j] = s1[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
