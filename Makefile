DIRLIB		= ./ft_printf/ \

SRCS	=	parser/main.c

OBJS	= ${SRCS:.c=.o}

LIBFT   = ./ft_printf/libft/libft.a

PRINTF	= ./ft_printf/libftprintf.a

NAME	= minishell.a

CC		= gcc

AR		= ar rcs

RM		= rm -rf

CFLAGS	= -fsanitize=address -g

NAMELFT		= libft.a

NAMEPRINT	= libftprintf.a

all:	minishell

# %.o: %.c
# 	${CC} -c $< -o $@ ''

minishell: ${NAME} ${PRINTF}
	gcc ${NAME} ${PRINTF} ${CFLAGS} -o minishell


$(NAME):	$(OBJS) $(PRINTF)
	ar rcs ${NAME} ${OBJS}

$(PRINTF):
	make -C ./ft_printf
	cp ./ft_printf/libftprintf.a $(NAME)

clean:
	make clean -C ./ft_printf/libft
	make clean -C ./ft_printf
		$(RM) $(OBJS) $(BOBJ) 

fclean: 
	make fclean -C ./ft_printf/libft
	make fclean -C ./ft_printf
	$(RM) $(NAME) $(OBJS) push_swap 

re:
	${MAKE} fclean		
	cd ${DIRLIB} && ${MAKE} fclean
	cd ${DIRLIB}/libft && ${MAKE} fclean
	${MAKE}

.PHONY:		all clean fclean re