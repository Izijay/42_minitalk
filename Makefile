# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdupuis <mdupuis@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 22:15:15 by mdupuis           #+#    #+#              #
#    Updated: 2021/12/01 15:17:45 by mdupuis          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
BLUE = \033[0;34m
CYAN = \x1b[36m
GREEN = \x1b[32m
ORANGE = \033[93m
PURPLE = \033[0;95m
RED = \033[0;91m
END = \033[0m

SRCS_CLIENT				=	client_srcs/client.c\
							srcs/ft_atoi.c\
							srcs/ft_check_pid.c\
							srcs/ft_putstr_fd.c

SRCS_SERVER				=	server_srcs/server.c\
							srcs/ft_memset.c\
							srcs/ft_strlen.c\
							srcs/ft_putstr_fd.c\
							srcs/ft_putnbr_fd.c

DIR_HEAD				=	includes/

INCLUDES				=	${DIR_HEAD}minitalk.h

OBJS_CLIENT				=	${SRCS_CLIENT:.c=.o}
OBJS_SERVER				=	${SRCS_SERVER:.c=.o}

NAME_CLIENT				=	client
NAME_SERVER				=	server

CC						=	gcc
RM						=	rm -rf
FLAGS					=	-Wall -Werror -Wextra

.c.o:
						@${CC} ${FLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}
						@echo "\t\t${BOLD}${GREEN} [[ OK ]]${END} ${PURPLE}${<:.s=.o}${END}"

all:			${NAME_CLIENT}

${NAME_CLIENT}:		${NAME_SERVER} ${OBJS_CLIENT}
					@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_CLIENT} ${OBJS_CLIENT}
					@echo "\n\t${BOLD}${CYAN}[[ CLIENT ]]	${GREEN}OK!${END}${END}\n"

${NAME_SERVER}:		${OBJS_SERVER}
					@${CC} ${FLAGS} -I${DIR_HEAD} -o ${NAME_SERVER} ${OBJS_SERVER}
					@echo "\n\t${BOLD}${CYAN}[[ SERVER ]]	${GREEN}OK!${END}${END}\n"

clean:
				@${RM} ${OBJS_CLIENT} ${OBJS_SERVER}

fclean:			clean
				@${RM} ${NAME_CLIENT} ${NAME_SERVER}
				@echo "${GREEN}[[ OK ]]${END} ${RED} Bye bye Client and Server${END}"

re:				fclean all

.PHONY:		all clean fclean re
