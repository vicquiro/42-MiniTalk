# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vquiroga <vquiroga@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 15:45:09 by vquiroga          #+#    #+#              #
#    Updated: 2022/10/06 18:18:15 by vquiroga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar 
ARFLAGS = -rcs
NAME = libft.a
RM = rm -rf
HDRS = libft.h


################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #

################################################################################
##									BONUS									  ##
################################################################################
CBONUS = \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
BOBJS = $(CBONUS:.c=.o)
################################################################################

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS) $(BOBJS)
else
	TOTAL_OBJS = $(OBJS)
endif

################################################################################
.PHONY: all re fclean clean bonus bclean
################################################################################

all:        $(NAME)
$(NAME):		$(TOTAL_OBJS)
				@$(AR) $(ARFLAGS) $@ $^
bonus:		
			@make WITH_BONUS=1
			
.c.o:
		 ${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)

clean:		bclean
			@$(RM) $(OBJS)

bclean:
			@$(RM) $(BOBJS)

