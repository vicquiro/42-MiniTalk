/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:51:21 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/08 12:30:22 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str_out;
	unsigned int		i;

	if (!s || !f)
		return (0);
	str_out = malloc((size_t)ft_strlen((char *)s) + 1);
	if (!str_out)
		return (0);
	i = 0;
	while (s[i])
	{
		str_out[i] = f(i, s[i]);
		i++;
	}
	str_out[i] = '\0';
	return (str_out);
}
