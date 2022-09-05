#include "../includes/miniRT.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	// if (!data)
		//exit with code -1
	parse_input(data, argc, argv);
	return (0);
}
