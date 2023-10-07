/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:53:44 by vquiroga          #+#    #+#             */
/*   Updated: 2022/09/21 16:18:28 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		last_index;
	char	*ret;

	ret = 0;
	last_index = ft_strlen(s);
	while (last_index >= 0)
	{
		if (s[last_index] == (unsigned char) c)
		{
			ret = ((char *)s + last_index);
			return (ret);
		}
		last_index--;
	}
	return (ret);
}
