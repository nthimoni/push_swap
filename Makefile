SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
######################################################################
SRCS = main.c\
		parse.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
#####################################################################
CC = clang -g
CFLAGS = -Wall -Wextra -Werror
LINK = -lft 
INCPATH = -I$(INCDIR) -I$(FTINC)
LIBPATH = -L$(FTPATH) 
NAME = push_swap
######################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

clean:
	rm -rf $(OBJS)

fclean: clean
	#make fclean -C $(FTPATH)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
