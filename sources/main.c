#include "../includes/miniRT.h"

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
