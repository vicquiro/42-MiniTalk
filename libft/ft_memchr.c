/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:32 by vquiroga          #+#    #+#             */
/*   Updated: 2022/09/21 16:30:23 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*aux;
	int				i;

	i = 0;
	aux = (unsigned char *)s;
	while (n > (size_t) i)
	{
		if (aux[i] == (unsigned char) c)
			return ((void *)aux + i);
		i++;
	}
	return (NULL);
}
