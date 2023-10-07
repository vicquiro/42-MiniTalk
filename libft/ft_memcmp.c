/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:54:19 by vquiroga          #+#    #+#             */
/*   Updated: 2022/09/16 16:14:12 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			i;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (aux1[i] > aux2[i])
		{
			return (aux1[i] - aux2[i]);
		}
		if (aux1[i] < aux2[i])
		{
			return (aux1[i] - aux2[i]);
		}
		i++;
	}
	return (0);
}
