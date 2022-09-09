#include "../../includes/miniRT.h"

/*
A 0.2 255,255,255
C -50,0,20 0,0,0 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
sp 0,0,20 20 255,0,0
sp 0,0,20 20 255,0,0
*/

int	check_arguments(int argc, char **argv)
{
	int	arg_len;
	int	fd;

	if (argc > 2)
	{
		printf("Wrong amount of arguments.\n");
		return (-1);
	}
	arg_len = ft_strlen(argv[1]);
	if (arg_len < 4)
	{
		printf("Wrong filename.\n");
		return (-1);
	}
	if (ft_strncmp((argv[1] + arg_len - 3), ".rt", 4))
	{
		printf("Wrong file format.\n");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Cannot open file.\n");
		return (-1);
	}
	return (fd);
}

int	read_into_list(int fd, t_list **line_list)
{
	t_list	*new_item;
	char	*line;
	int		eof;

	eof = 0;
	while (!eof)
	{
		line = get_next_line(fd);
		if (!line)
			eof = 1;
		else if (ft_strncmp(line, "\n", 2))
		{
			
			new_item = ft_lstnew((void *)(ft_strdup(line)));
			if (!new_item->content)
				return (1); // MALLOC Error
			ft_lstadd_back(line_list, new_item);
		}
		free(line);
	}
	return (0);
}

void display_list(t_list *list)
{
	while (list)
	{
		printf("%s", list->content);
		list = list->next;
	}
}

char *get_identifier(char *line)
{
	char	*identifier;
	int		i;

	i = 0;
	while (line[i] != ' ')
	{
		if (line[i] == '\0')
		{
			printf("No spaces\n");
			return (NULL);
		}
		i++;
	}
	identifier = ft_substr(line, 0, i);
	if (!identifier)
		return (NULL); // malloc failed
	return (identifier);
}

int	check_identifier(char *identifier, int identifier_count[4])
{
	if (!ft_strncmp(identifier, "A", 2))
	{
		identifier_count[0] = identifier_count[0] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "C", 2))
	{
		identifier_count[1] = identifier_count[1] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "L", 2))
	{
		identifier_count[2] = identifier_count[2] + 1;
		return (0);
	}
	else if (!ft_strncmp(identifier, "pl", 3) ||
		!ft_strncmp(identifier, "sp", 3) ||
		!ft_strncmp(identifier, "cy", 3))
	{
		identifier_count[3] = identifier_count[3] + 1;
		return (0);
	}
	return (1);
}

/*
	Return:
		-1: if wrong identifier or identifier count.
		amount of objects(sp, pl, cy): if identifiers meet all the rules
*/
int	check_identifiers(t_list *line_list)
{
	char	*identifier;
	int		check_res;
	int		identifier_count[4]; // 0 - A; 1 - C; 2 - L; 3 - objects(pl, sp, cy);

	identifier_count[0] = 0;
	identifier_count[1] = 0;
	identifier_count[2] = 0;
	identifier_count[3] = 0;
	while (line_list)
	{
		identifier = get_identifier(line_list->content); // might be NULL
		check_res = check_identifier(identifier, identifier_count);
		free(identifier);
		if (check_res)
			return (-1);
		line_list = line_list->next;
	}
	if (identifier_count[0] > 1 || identifier_count[1] > 1 ||
		identifier_count[2] > 1)
	{
		printf("Wrong amount of identifiers.\n");
		return (-1);
	}
	return (identifier_count[3]);
}

int	get_split_len(char **split)
{
	int	len;

	len = 0;
	while (split[len])
		len++;
	return (len);
}

int	check_float(char *line)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (line[i] == '-')
		i++;
	if (line[i] == '.')
		return (-1);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]))
		{
			if (line[i] == '.' && !dot && ft_isdigit(line[i + 1]))
				dot = 1;
			else
				return (-1);
		}
		i++;
	}
	return (0);
}

int	check_coords(char *coords_line)
{
	char	**coords_split;
	int		i;
	int		dot;

	coords_split = ft_split(coords_line, ',');
	if (get_split_len(coords_split) != 3)
	{
		printf("Wrong amount of elements for coordinates.\n");
		return (-1);
	}
	i = 0;
	while (coords_split[i])
	{
		if (check_float(coords_split[i]) == -1)
		{
			printf("Wrong coordinate format.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

// A 0.2 255,255,255
int check_ambient(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 3)
	{
		printf("Wrong amount of elements for light.\n");
		return (-1);
	}
	if (check_float(line_split[1]) == -1)
	{
		printf("Wrong lighting ratio format.\n");
		return (-1);
	}
	check_coords(line_split[2]);
	return (0);
}

// C -50,0,20 0,0,0 70
int	check_camera(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 4)
	{
		printf("Wrong amount of elements for camera.\n");
		return (-1);
	}
	check_coords(line_split[1]);
	check_coords(line_split[2]);
	if (check_float(line_split[3]) == -1)
	{
		printf("Wrong FOV format.\n");
		return (-1);
	}
	return (0);
}

// L -40,0,30 0.7 255,255,255
int check_light(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 4)
	{
		printf("Wrong amount of elements for light.\n");
		return (-1);
	}
	check_coords(line_split[1]);
	if (check_float(line_split[2]) == -1)
	{
		printf("Wrong brightness format.\n");
		return (-1);
	}
	check_coords(line_split[3]);
	return (0);
}

// sp 0,0,20 20 255,0,0
int check_sphere(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 4)
	{
		printf("Wrong amount of elements for light.\n");
		return (-1);
	}
	check_coords(line_split[1]);
	if (check_float(line_split[2]) == -1)
	{
		printf("Wrong diameter format.\n");
		return (-1);
	}
	check_coords(line_split[3]);
	return (0);
}

// pl 0,0,0 0,1.0,0 255,0,225
int check_plane(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 4)
	{
		printf("Wrong amount of elements for light.\n");
		return (-1);
	}
	check_coords(line_split[1]);
	check_coords(line_split[2]); // should be normalized to values from 0.0 to 1.0!
	check_coords(line_split[3]);
	return (0);
}

// cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
int check_cylinder(char *line)
{
	char	**line_split;

	line_split = ft_split(line, ' '); // PROTECT SPLIT!
	if (get_split_len(line_split) != 6)
	{
		printf("Wrong amount of elements for light.\n");
		return (-1);
	}
	check_coords(line_split[1]);
	check_coords(line_split[2]); // should be normalized to values from 0.0 to 1.0!
	if (check_float(line_split[3]) == -1)
	{
		printf("Wrong diameter format.\n");
		return (-1);
	}
	if (check_float(line_split[4]) == -1)
	{
		printf("Wrong height format.\n");
		return (-1);
	}
	check_coords(line_split[5]);
	return (0);
}

int	check_lines(t_list *line_list)
{
	char	*identifier;
	int		check_res;

	while (line_list)
	{
		identifier = get_identifier(line_list->content); //might be NULL
		if (!ft_strncmp(identifier, "A", 2))
			check_res = check_ambient(line_list->content);
		else if (!ft_strncmp(identifier, "C", 2))
			check_res = check_camera(line_list->content);
		else if (!ft_strncmp(identifier, "L", 2))
			check_res = check_light(line_list->content);
		else if (!ft_strncmp(identifier, "sp", 3))
			check_res = check_sphere(line_list->content);
		else if (!ft_strncmp(identifier, "pl", 3))
			check_res = check_plane(line_list->content);
		else if (!ft_strncmp(identifier, "cy", 3))
			check_res = check_cylinder(line_list->content);
		if (check_res == -1)
			return (-1);
		line_list = line_list->next;
	}
	return (0);
}

float     ft_atof(const char *str)
{
	int		i;
	float	divider;
	float	negative;
	float	result;

	i = 0;
	negative = 0;
	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
			result = result * 10 + (str[i] - '0');
			i++;
	}
	if (str[i] == '.')
	{
		i++;
		divider = 10;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') / divider;
			divider *= 10;
			i++;
		}
	}
	if (negative)
			return (-result);
	return (result);
}

int	parse_ambient(t_data *data, char *line)
{
	//parse line and assign data to data->scene.ambient
}

int	parse_camera(t_data *data, char *line)
{
	//parse line and assign data to data->scene.camera
}

int	parse_light(t_data *data, char *line)
{
	//parse line and assign data to data->scene.light
}

int	parse_sphere(t_data *data, char *line, int *obj_i)
{
	//parse line and assign data to data->scene.objs
}

int	parse_plane(t_data *data, char *line, int *obj_i)
{
	//parse line and assign data to data->scene.objs
}

int	parse_cylinder(t_data *data, char *line, int *obj_i)
{
	//parse line and assign data to data->scene.objs
}

// int	parse_lines(t_data *data, t_list *line_list)
// {
// 	char	*identifier;
// 	int		parse_res;
// 	int		obj_i;

// 	obj_i = 0;
// 	while (line_list)
// 	{
// 		identifier = get_identifier(line_list->content); //might be NULL
// 		if (!ft_strncmp(identifier, "A", 2))
// 			parse_res = parse_ambient(data, line_list->content);
// 		else if (!ft_strncmp(identifier, "C", 2))
// 			parse_res = parse_camera(data, line_list->content);
// 		else if (!ft_strncmp(identifier, "L", 2))
// 			parse_res = parse_light(data, line_list->content);
// 		else if (!ft_strncmp(identifier, "sp", 3))
// 			parse_res = parse_sphere(data, line_list->content, &obj_i);
// 		else if (!ft_strncmp(identifier, "pl", 3))
// 			parse_res = parse_plane(data, line_list->content, &obj_i);
// 		else if (!ft_strncmp(identifier, "cy", 3))
// 			parse_res = parse_cylinder(data, line_list->content, &obj_i);
// 		line_list = line_list->next;
// 	}
// 	return (0);
// }


void	parse_input(t_data *data, int argc, char **argv)
{
	int 	fd;
	int		obj_count;
	t_list	*line_list;


	printf("float: %f\n", ft_atof("12.354"));

	fd = check_arguments(argc, argv);
	if (fd == -1)
		return ;
	line_list = NULL;
	if (read_into_list(fd, &line_list))
		return ;
	display_list(line_list);
	obj_count = check_identifiers(line_list);
	if (obj_count == -1)
	{
		printf("Wrong identifiers.\n");
		return ;
	}
	if (check_lines(line_list) == -1)
	{
		printf("Check error.\n");
		// return (-1);
	}
	if (obj_count > 0)
	{
		data->scene.objs = malloc(sizeof(t_obj) * (obj_count + 1));
		if (!data->scene.objs)
			; // MALLOC FAILED, CLEAN EXIT.
	}
	//parse_lines(data, line_list);
}