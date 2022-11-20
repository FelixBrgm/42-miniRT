CC := gcc
# CFLAGS := -Wall -Werror -Wextra


sources_path = $(addprefix ./sources/, $(sources))
NAME := miniRT

SRC := sources/
INPUT := input/
VECTOR := vector/
MLX := mlx/
RENDER := render/

CFILES_INPUT := input_parser.c utils1.c utils2.c utils3.c utils4.c utils5.c	\
				utils6.c utils7.c utils8.c utils9.c utils10.c
CFILES_INPUT := $(addprefix $(INPUT), $(CFILES_INPUT))

CFILES_VECTOR := vector_operations.c vector_utils.c
CFILES_VECTOR := $(addprefix $(VECTOR), $(CFILES_VECTOR))

CFILES_MLX := mlx_start.c
CFILES_MLX := $(addprefix $(MLX), $(CFILES_MLX))

CFILES_RENDER := render.c calculate.c ray.c color.c hit.c color_calculate_light.c color_utils.c color_calculate_light_cylinder.c

CFILES_RENDER := $(addprefix $(RENDER), $(CFILES_RENDER))


CFILES := main.c $(CFILES_INPUT) $(CFILES_MLX) $(CFILES_VECTOR) $(CFILES_RENDER)
# CFILES := main.c $(CFILES_INPUT)

CFILES := $(addprefix $(SRC), $(CFILES))
OFILES := $(CFILES:.c=.o)

all: $(NAME)

parser: $(OPARSER)
	@$ make -C libraries/libs
	$(CC) $(CFLAGS) -g -o $(NAME) sources/main.c sources/input/input_parser.c libraries/libs/libs.a

clean_p: 
	make clean -C libraries/libs
	rm -rf sources/main.o sources/input/input_parser.o

fclean_p: clean_p
	make fclean -C libraries/libs
	rm -rf $(NAME)

$(NAME): $(OFILES)
	@$ make -C libraries/libs
	@$ make -C libraries/mlxlib
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) libraries/libs/libs.a libraries/mlxlib/libmlx42.a -I include -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"

clean:
	make clean -C libraries/libs
	rm -rf $(OFILES)

fclean: clean
	make fclean -C libraries/mlxlib
	make fclean -C libraries/libs
	rm -rf $(NAME)

test: 
	@$ make -C libraries/libs
	@$ make -C libraries/mlxlib
	$(CC) -o $(NAME) $(OFILES) libraries/libs/libs.a libraries/mlxlib/libmlx42.a -I include -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"
	./miniRT box.rt

re: fclean all