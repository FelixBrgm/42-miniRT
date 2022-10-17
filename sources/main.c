#include "../includes/miniRT.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	// mlx_start(data);
	// if (!data)
		//exit with code -1
	if (parse_input(data, argc, argv) == -1)
	{
		printf("Error in parser.\n"); // CLEAN EXIT (free mlx)
		return (0);
	}
	return (0);
}
