#include "../includes/miniRT.h"

// t_data	*data_create(void);

void	display_data_main(t_data data)
{
	int	i;

	i = 0;
	printf("*** DATA ***\n");
	printf("AMBIENT\n");
	printf("ratio: %.2f\n", data.scene.ambient.ratio);
	printf("r = %.0f, g = %.0f, b = %.0f\n", data.scene.ambient.color.r, data.scene.ambient.color.g, data.scene.ambient.color.b);
	printf("======\n");
	printf("CAMERA\n");
	printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.camera.position.x, data.scene.camera.position.y, data.scene.camera.position.z);
	printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", data.scene.camera.rotation.x, data.scene.camera.rotation.y, data.scene.camera.rotation.z);
	printf("fov = %i\n", data.scene.camera.fov);
	printf("======\n");
	printf("LIGHT\n");
	printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.light.position.x, data.scene.light.position.y, data.scene.light.position.z);
	printf("brightness: %.2f\n", data.scene.light.brightness);
	while (data.scene.objs[i].cylinder || data.scene.objs[i].plane || data.scene.objs[i].sphere)
	{
		if (data.scene.objs[i].cylinder)
		{
			printf("CYLINDER\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.objs[i].cylinder->position.x, data.scene.objs[i].cylinder->position.y, data.scene.objs[i].cylinder->position.z);
			printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", data.scene.objs[i].cylinder->rotation.x, data.scene.objs[i].cylinder->rotation.y, data.scene.objs[i].cylinder->rotation.z);
			printf("radius = %.2f\n", data.scene.objs[i].cylinder->radius);
			printf("height = %.2f\n", data.scene.objs[i].cylinder->height);
			printf("r = %.0f, g = %.0f, b = %.0f\n", data.scene.objs[i].cylinder->color.r, data.scene.objs[i].cylinder->color.g, data.scene.objs[i].cylinder->color.b);
			printf("======\n");
		}
		else if (data.scene.objs[i].plane)
		{
			printf("PLANE\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.objs[i].plane->position.x, data.scene.objs[i].plane->position.y, data.scene.objs[i].plane->position.z);
			printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", data.scene.objs[i].plane->rotation.x, data.scene.objs[i].plane->rotation.y, data.scene.objs[i].plane->rotation.z);
			printf("r = %.0f, g = %.0f, b = %.0f\n", data.scene.objs[i].plane->color.r, data.scene.objs[i].plane->color.g, data.scene.objs[i].plane->color.b);
			printf("======\n");
		}
		else if (data.scene.objs[i].sphere)
		{
			printf("SPHERE\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.objs[i].sphere->position.x, data.scene.objs[i].sphere->position.y, data.scene.objs[i].sphere->position.z);
			printf("radius = %.2f\n", data.scene.objs[i].sphere->radius);
			printf("r = %.0f, g = %.0f, b = %.0f\n", data.scene.objs[i].sphere->color.r, data.scene.objs[i].sphere->color.g, data.scene.objs[i].sphere->color.b);
			printf("======\n");
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	t_data	data;

	// data = data_create();
	if (parse_input(&data, argc, argv) == -1)
		printf("error in parser.\n");
	display_data_main(data);
	// if (!data)
		// exit(EXIT_FAILURE);
	// mlx_start(data);
	printf("done!\n");
	return (0);
}

// t_data	*data_create(void)
// {
// 	t_data	*data;
// 	int		i;

// 	data = ft_calloc(sizeof(t_data), 1);
// 	if (!data)
// 		return (NULL);

// 	data->img = ft_calloc(PIXELS + 1, sizeof(t_color *));
// 	i = 0;
// 	while (i < PIXELS)
// 	{
// 		data->img[i] = ft_calloc(1, sizeof(t_color));
// 		i++;
// 	}
// 	data->img[PIXELS] = NULL;
// 	if (!data->img)
// 	{
// 		free(data);
// 		return (NULL);
// 	}
// 	data->mlx_img = NULL;
// 	return (data);
// }