#include "../includes/miniRT.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	mlx_start(data);
	// if (!data)
		//exit with code -1
	// input_parser(data);
	printf("done!\n");
	return (0);
}
