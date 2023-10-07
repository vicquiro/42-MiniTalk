/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:08:46 by vquiroga          #+#    #+#             */
/*   Updated: 2022/09/29 14:39:59 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	c;

	if (!dest && !dstsize)
		return (0);
	i = 0;
	k = ft_strlen(dest);
	c = ft_strlen(src);
	if (dstsize <= k)
		return (dstsize + c);
	while (src[i] != '\0' && (k + i) < (dstsize - 1))
	{
		dest[k + i] = src[i];
		i++;
	}
	dest[k + i] = '\0';
	return (k + c);
}
