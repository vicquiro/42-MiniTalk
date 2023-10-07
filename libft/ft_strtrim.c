/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:15:57 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/08 12:30:21 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_last_pos(char const *s1, char const *set)
{	
	int	i;
	int	j;
	int	k;

	i = ft_strlen(s1) - 1;
	while (i != 0)
	{	
		j = 0;
		k = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
				k++;
			j++;
		}
		if (k >= 1)
			i--;
		else
			return (i + 1);
	}
	return (i);
}

int	get_first_pos(char const *s1, char const *set)
{	
	int	i;
	int	j;
	int	k;

	i = 0;
	while (s1[i] != 0)
	{	
		j = 0;
		k = 0;
		while (set[j] != 0)
		{
			if (s1[i] == set[j])
				k++;
			j++;
		}
		if (k >= 1)
			i++;
		else
			return (i);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	if (!s1)
		return (0);
	i = get_last_pos(s1, set) - get_first_pos(s1, set);
	j = 0;
	k = get_first_pos(s1, set);
	s2 = (char *)malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (0);
	s2[i] = 0;
	while (i--)
		s2[j++] = s1[k++];
	return (s2);
}
