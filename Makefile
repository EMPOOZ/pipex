NAME = pipex
 
CFILES =	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strjoin.c ft_strnstr.c path_search.c pip.c ft_strlen.c\
			ft_substr.c


OBJECTS = $(CFILES:.c=.o)

PIPEX = pip.h

CC = gcc
 
CFLAGS = -Wall -Wextra -Werror
 
all: $(NAME)

 
$(NAME): $(OBJECTS) $(PIPEX) $(CFILES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)
 
fclean: clean
	rm -f $(NAME)
 
re: fclean all
 
call: all clean