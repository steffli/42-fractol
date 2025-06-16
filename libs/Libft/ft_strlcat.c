/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stliu <stliu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:24:28 by stliu             #+#    #+#             */
/*   Updated: 2025/03/11 16:19:11 by stliu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;
	size_t	j;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	i = 0;
	j = dstlen;
	if (dstlen >= dstsize)
		dstlen = dstsize;
	if (dstsize > 0 && dstlen < dstsize - 1)
	{
		while (src[i] && (dstlen + i) < dstsize - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	}
	dst[j] = '\0';
	return (dstlen + srclen);
}

// int main()
// {
// 	char dest[] = "hallo";
// 	char src[] = "mini";
// 	//ft_strlcat(dest,src, 4);
// 	strlcat(dest,src,8);
// 	puts(dest);
// }