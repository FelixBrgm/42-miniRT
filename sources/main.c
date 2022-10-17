#include "../includes/miniRT.h"

t_data	*data_create(void);

int main(int argc, char **argv)
{
	t_data	*data;

	data = data_create();
	if (!data)
		exit(EXIT_FAILURE);
	// input_parser(data);
	mlx_start(data);
	printf("done!\n");
	return (0);
}

t_data	*data_create(void)
{
	t_data	*data;
	int		i;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (NULL);

	data->img = ft_calloc(PIXELS + 1, sizeof(t_color *));
	i = 0;
	while (i < PIXELS)
	{
		data->img[i] = ft_calloc(1, sizeof(t_color));
		i++;
	}
	data->img[PIXELS] = NULL;
	if (!data->img)
	{
		free(data);
		return (NULL);
	}
	data->mlx_img = NULL;
	return (data);
}