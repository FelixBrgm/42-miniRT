#include "../includes/miniRT.h"
# include "../includes/parser.h"
# include "../includes/render.h"
t_data	*data_create(void);

void	display_data_main(t_data data)
{
	int	i;

	t_obj **objs;
	objs = data.scene.objs;

	i = 0;
	printf("*** DATA ***\n");
	printf("AMBIENT\n");
	printf("ratio: %.2f\n", data.scene.ambient.ratio);
	printf("r = %.4f, g = %.4f, b = %.4f\n", data.scene.ambient.color.r, data.scene.ambient.color.g, data.scene.ambient.color.b);
	printf("======\n");
	printf("CAMERA\n");
	printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.camera.position.x, data.scene.camera.position.y, data.scene.camera.position.z);
	printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", data.scene.camera.rotation.x, data.scene.camera.rotation.y, data.scene.camera.rotation.z);
	printf("fov = %i\n", data.scene.camera.fov);
	printf("======\n");
	printf("LIGHT\n");
	printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", data.scene.light.position.x, data.scene.light.position.y, data.scene.light.position.z);
	printf("brightness: %.2f\n", data.scene.light.brightness);
	printf("seg\n");
	while (objs[i])
	{
		if (objs[i]->cylinder)
		{
			printf("CYLINDER\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", objs[i]->cylinder->position.x, objs[i]->cylinder->position.y, objs[i]->cylinder->position.z);
			printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", objs[i]->cylinder->rotation.x, objs[i]->cylinder->rotation.y, objs[i]->cylinder->rotation.z);
			printf("radius = %.2f\n", objs[i]->cylinder->radius);
			printf("height = %.2f\n", objs[i]->cylinder->height);
			printf("r = %.0f, g = %.0f, b = %.0f\n", objs[i]->cylinder->color.r, objs[i]->cylinder->color.g, objs[i]->cylinder->color.b);
			printf("======\n");
		}
		else if (objs[i]->plane)
		{
			printf("PLANE\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", objs[i]->plane->position.x, objs[i]->plane->position.y, objs[i]->plane->position.z);
			printf("rot_x = %.2f, rot_y = %.2f, rot_z = %.2f\n", objs[i]->plane->rotation.x, objs[i]->plane->rotation.y, objs[i]->plane->rotation.z);
			printf("r = %.0f, g = %.0f, b = %.0f\n", objs[i]->plane->color.r, objs[i]->plane->color.g, objs[i]->plane->color.b);
			printf("======\n");
		}
		else if (objs[i]->sphere)
		{
			printf("SPHERE\n");
			printf("pos_x = %.2f, pos_y = %.2f, pos_z = %.2f\n", objs[i]->sphere->position.x, objs[i]->sphere->position.y, objs[i]->sphere->position.z);
			printf("radius = %.2f\n", objs[i]->sphere->radius);
			printf("r = %.0f, g = %.0f, b = %.0f\n", objs[i]->sphere->color.r, objs[i]->sphere->color.g, objs[i]->sphere->color.b);
			printf("======\n");
		}
		i++;
	}
}

// definitely lost: 2,336 bytes in 81 blocks
// ==706==    indirectly lost: 1,454 bytes in 227 blocks

void	free_data(t_data *data)
{
	int	i;
	t_scene scene;

	i = 0;
	while (data->img[i])
	{
		free(data->img[i]);
		i++;
	}
	free(data->img);
	scene = data->scene;
	i = 0;
	while (scene.objs[i])
	{
		if (scene.objs[i]->cylinder)
		{
			free(scene.objs[i]->cylinder);
			scene.objs[i]->cylinder = NULL;
		}
		else if (scene.objs[i]->plane)
		{
			free(scene.objs[i]->plane);
			scene.objs[i]->plane = NULL;
		}
		else if (scene.objs[i]->sphere)
		{
			free(scene.objs[i]->sphere);
			scene.objs[i]->sphere = NULL;
		}
		free(scene.objs[i]);
		i++;
	}
	free(scene.objs);
	scene.objs = NULL;
	free(data);
}

int main(int argc, char **argv)
{
	// t_data	data;
	t_data	*data;

	data = data_create();
	if (!data)
		return (0); // data malloc failed
	if (parse_input(data, argc, argv) == -1)
	{
		printf("error in parser.\n");
		return (0);
	}
	//display_data_main(*data);
	if (!data)
		exit(EXIT_FAILURE); // ???
	// mlx_start(data);
	printf("done!\n");
	// FREE DATA
	free_data(data);
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
	data->pixel_samples = 0;
	srand(time(NULL));
	return (data);
}
