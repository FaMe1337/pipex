/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 23:21:42 by famendes          #+#    #+#             */
/*   Updated: 2024/10/21 23:22:10 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
