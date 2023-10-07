/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:55:45 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/08 12:30:24 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_out;
	size_t	i;
	size_t	j;
	char	*str_out;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	len_out = ft_strlen(s1) + ft_strlen(s2);
	str_out = malloc(sizeof(char) * (len_out + 1));
	if (!str_out)
		return (0);
	while (s1[i] != '\0' && j < len_out)
		str_out[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0' && j < len_out)
		str_out[j++] = s2[i++];
	str_out[j] = '\0';
	return (str_out);
}
