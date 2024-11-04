/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:32:27 by famendes          #+#    #+#             */
/*   Updated: 2024/10/21 23:21:25 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char*dst, const char*src, size_t size)
{
	unsigned int	j;
	unsigned int	lenght;

	j = 0;
	lenght = ft_strlen(dst);
	if (size <= lenght)
		return (size + ft_strlen(src));
	while (src[j] && lenght < size - 1)
	{
		dst[lenght] = src[j];
		lenght++;
		j++;
	}
	dst[lenght] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[j]));
}
char	*ft_strcat(char*dst, const char*src)
{
	unsigned int	j;
	unsigned int	lenght;

	j = 0;
	lenght = ft_strlen(dst);
	while (src[j])
		dst[lenght++] = src[j++];
	dst[lenght] = '\0';
	return (dst);
}
