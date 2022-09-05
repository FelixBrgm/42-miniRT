#include "../libraries/mlxlib/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	t_scene scene;
}			t_data;

int main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	// if (!data)
		//exit with code -1
	input_parser(data);
	printf("done!\n");
	return (0);
}
