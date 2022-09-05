CC := gcc
CFLAGS :=

NAME := miniRT

SRC := sources/
INPUT := input/
VECTOR := vector/
MLX := mlx/

CFILES_INPUT := 
CFILES_INPUT := $(addprefix $(INPUT), $(CFILES_INPUT))

CFILES_VECTOR := vector_operations.c vector_utils.c
CFILES_VECTOR := $(addprefix $(VECTOR), $(CFILES_VECTOR))

CFILES_MLX := mlx_start.c
CFILES_MLX := $(addprefix $(MLX), $(CFILES_MLX))


CFILES := main.c $(CFILES_INPUT) $(CFILES_VECTOR) $(CFILES_MLX)
CFILES := $(addprefix $(SRC), $(CFILES))
OFILES := $(CFILES:.c=.o)


all: $(NAME)

$(NAME): $(OFILES)
	make -C libraries/mlxlib
	make -C libraries/libs
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) libraries/libs/libs.a libraries/mlxlib/libmlx42.a -I include -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all