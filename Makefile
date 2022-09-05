NAME=miniRT
CC=gcc
CFLAGS=
sources=main.c

USER=pvznuzda

sources_path = $(addprefix ./sources/, $(sources))

objs=$(sources:.c=.o)

objs_path=$(sources_path:.c=.o)

all: $(NAME)

$(NAME): $(objs_path)
	$(CC) $(CFLAGS) -o $(NAME) $(objs_path) libraries/mlx/libmlx42.a -I include -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"

clean:
	rm -rf $(objs_path)

fclean: clean
	rm -rf $(NAME)

re: fclean all