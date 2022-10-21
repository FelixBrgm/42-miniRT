CC := gcc
CFLAGS :=


sources_path = $(addprefix ./sources/, $(sources))
NAME := miniRT

SRC := sources/
INPUT := input/
VECTOR := vector/
MLX := mlx/
RENDER := render/

CFILES_INPUT := input_parser.c
CFILES_INPUT := $(addprefix $(INPUT), $(CFILES_INPUT))

CFILES_VECTOR := vector_operations.c vector_utils.c
CFILES_VECTOR := $(addprefix $(VECTOR), $(CFILES_VECTOR))

CFILES_MLX := mlx_start.c
CFILES_MLX := $(addprefix $(MLX), $(CFILES_MLX))

CFILES_RENDER := render.c calculate.c ray.c color.c hit.c
CFILES_RENDER := $(addprefix $(RENDER), $(CFILES_RENDER))


CFILES := main.c $(CFILES_INPUT) $(CFILES_MLX) $(CFILES_VECTOR) $(CFILES_RENDER)
# CFILES := main.c $(CFILES_INPUT)

CFILES := $(addprefix $(SRC), $(CFILES))
OFILES := $(CFILES:.c=.o)


all: $(NAME)
  
# $(NAME): $(OFILES)
# 	@$ make -C libraries/libs
# 	$(CC) $(CFLAGS) -o $(NAME) $(OFILES) libraries/libs/libs.a

# $(CC) $(CFLAGS) -o $(NAME) $(objs_path) libraries/mlxlib/libmlx42.a -I include -lglfw -L "/Users/$(USER)/goinfre/.brew/opt/glfw/lib/"

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

re: fclean all