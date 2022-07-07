# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 16:39:52 by aniouar           #+#    #+#              #
#    Updated: 2022/07/07 09:14:15 by aniouar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MANC = libft/libft.c libft/more_libft.c libft/mmore_libft.c libft/str_func.c \
	   fhandle/parser.c fhandle/file_handle.c fhandle/more_file_handle.c \
	    common/regular_pipe.c proc/process_func.c error_handle/cmd_error.c pipex.c   \
		
BONUSC = libft/libft.c libft/more_libft.c libft/mmore_libft.c libft/str_func.c \
	   fhandle/parser.c fhandle/file_handle.c fhandle/more_file_handle.c fhandle/fd_bonus.c \
	   proc/process_func.c  proc/multi_proc_bonus.c proc/extra_proc_bonus.c common/regular_pipe.c \
	   bonus_func/pipex_func_bonus.c \
	   bonus_func/pipex_utils_bonus.c herdoc/her_doc_bonus.c\
	   gnl/get_next_line.c gnl/get_next_line_utils.c error_handle/cmd_error.c \
	   pipex_bonus.c \
 
EXEC = pipex
EXEB = pipex_bonus
OBJM =  $(MANC:.c=.o)
OBJC =  $(BONUSC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
all : $(EXEC)
$(EXEC): $(OBJM) 
	gcc $(CFLAGS) -o $(EXEC) $(OBJM)
bonus:  $(EXEB)
$(EXEB): $(OBJC)
	gcc $(CFLAGS) -o $(EXEB) $(OBJC)	
clean :
	rm -f $(OBJM) $(OBJC)
fclean : clean
	rm -f $(EXEC) $(EXEB) 
re : fclean all bonus

