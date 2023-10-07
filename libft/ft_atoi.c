/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:27:14 by vquiroga          #+#    #+#             */
/*   Updated: 2022/10/08 12:28:53 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

static int	check_spaces(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' \
	|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	return (i);
}

static unsigned long	get_number(const char *str, int index)
{
	unsigned long	number;

	number = 0;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number = number * 10 + (str[index] - '0');
		index++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				i;
	int				neg;

	neg = ((res = 0));
	i = check_spaces(str);
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (0);
	res = get_number(str, i);
	if (res > LONG_MAX && neg == 1)
		return (0);
	if (res > LONG_MAX && neg == 0)
		return (-1);
	if (neg == 1)
		return (-res);
	return (res);
}
