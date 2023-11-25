/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 14:29:28 by vquiroga          #+#    #+#             */
/*   Updated: 2023/11/25 15:54:37 by vquiroga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# define ROGER "\nMessage received!\n"
/// ADD HERE OTHER GLOBAL CONST

typedef struct s_buffer
{
	int		length;
	char	*message;

}	t_buffer;

#endif