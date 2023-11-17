DIRLIB		= ./libft/

SRCS	=	ft_printf.c \
			ft_putnbr_fd_mod.c \
			printconvfromdec.c \
			uIntPutnbr.c		\
			convertX.c	\
			cases.c	\

OBJ	= ${SRCS:.c=.o}

LIBFT   = ./libft/libft.a

NAME	= libftprintf.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -Wall -Wextra -Werror

NAMELFT		= libft.a

all:		${NAME}

# %.o: %.c 
# 	${CC} ${CFLAGS} -c -I. -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	$(OBJ) $(LIBFT)
				ar rcs $(NAME) $(OBJ)

$(LIBFT):
	make -C ./libft
	cp ./libft/libft.a $(NAME)

clean:
	make clean -C ./libft
		$(RM) $(OBJ) $(BOBJ)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:			fclean all
				cd ${DIRLIB} && ${MAKE} clean

.PHONY:		all clean fclean re


# NAME    =               libftprintf.a
# LIBFT   =               ./libft/libft.a
# CC              =               cc
# CFLAGS  =               -Wall -Wextra -Werror
# RM              =               rm -f
# SRC     =               srcs/ft_printf.c srcs/ft_printf_utils.c
# OBJ             =               $(SRC:.c=.o)

# all:                    $(NAME)

# $(NAME):	$(OBJ) $(LIBFT)
# 				ar rcs  $(NAME) $(OBJ)
# $(LIBFT):
#                                 make -C ./libft
#                                 cp ./libft/libft.a $(NAME)
# clean:
#                                 make clean -C ./libft
#                                 $(RM) $(OBJ) $(BOBJ)
# fclean: clean
#                                 make fclean -C ./libft
#                                 $(RM) $(NAME)
# re:             fclean  $(NAME)
