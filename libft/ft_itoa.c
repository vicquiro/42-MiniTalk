/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:07:41 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/08 12:30:27 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_lenght_number(int n)
{
	int	i;
	int	j;

	i = n;
	j = 0;
	if (n == 0)
		return (1);
	while (i != 0)
	{	
		i = i / 10;
		j++;
	}
	return (j);
}

static unsigned int	sign_change(int n, int *sign)
{
	unsigned int	i;

	i = n;
	if (n < 0)
	{
		i = n * (-1);
		*sign = -1;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				j;
	char			*num;
	int				sign;
	unsigned int	i;

	sign = 1;
	j = get_lenght_number(n);
	i = sign_change(n, &sign);
	if (sign == 1)
		num = (char *) malloc(sizeof(char) * ((j) + 1));
	else
		num = (char *) malloc(sizeof(char) * ((j++) + 2));
	if (!num)
		return (0);
	num[j] = 0;
	while (j--)
	{	
		num[j] = (i % 10) + '0';
		i = i / 10;
	}
	if (sign == -1)
		num[0] = '-';
	return (num);
}
