/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:05:10 by stliu             #+#    #+#             */
/*   Updated: 2025/03/17 12:19:39 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c && *s != '\0')
			s++;
		else
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
	}
	return (count);
}

static char	*get_word(const char *s, int str_start, int str_len)
{
	char	*str;
	int		j;

	j = 0;
	if (s == NULL)
		return (NULL);
	str = malloc((str_len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (j < str_len)
	{
		str[j] = s[str_start + j];
		j++;
	}
	str[str_len] = '\0';
	return (str);
}

static	char	**free_matrix(char **arr, int arr_index)
{
	while (arr_index > 0)
	{
		arr_index--;
		free(arr[arr_index]);
	}
	free(arr);
	return (NULL);
}

char	**get_matrix(char **arr, const char *s, char c, int count_word)
{
	int	i;
	int	str_start;
	int	str_len;
	int	arr_index;

	i = 0;
	arr_index = 0;
	while (s[i] != '\0' && arr_index < count_word)
	{
		while (s[i] == c)
			i++;
		str_start = i--;
		str_len = 0;
		while (s[++i] != c && s[i] != '\0')
			str_len++;
		if (str_len)
		{
			arr[arr_index] = get_word(s, str_start, str_len);
			if (arr[arr_index] == NULL)
				return (free_matrix(arr, arr_index));
			arr_index++;
		}
	}
	arr[arr_index] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		count_word;
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_word = ft_count_word(s, c);
	arr = (char **)malloc((count_word + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	arr = get_matrix(arr, s, c, count_word);
	return (arr);
}
