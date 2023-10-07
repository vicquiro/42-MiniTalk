/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:33:04 by vquiroga          #+#    #+#             */
/*   Updated: 2022/09/23 18:49:10 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_len;
	void	*dst;

	total_len = count * size;
	if (total_len && (total_len / size != count))
		return (0);
	dst = malloc(total_len);
	if (!dst)
		return (0);
	ft_bzero(dst, total_len);
	return (dst);
}
