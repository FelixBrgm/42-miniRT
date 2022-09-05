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

/*
	1. init list of lines
	2. count objs
	3. make sure there is only 1 camera, light, amb_light
	4. 
*/

// int	count_split(char **split)
// {
// 	int	counter;

// 	counter = 0;
// 	while (split[counter])
// 		counter++;
// 	return (counter);
// }

// int	parse_ambient(t_data *data, char **line_split)
// {
// 	return (0);
// }

// /*
// RETURNS: -1 if malloc failed, 1 if arguments are wrong
// */
// int	parse_camera(t_data *data, char **line_split)
// {
// 	char	**coords;

// 	coords = ft_split(line_split[1], ',');
// 	if (!line_split)
// 		return -1;
// 	if (count_split(coords) != 3)
// 		return 1;
	
// }
// // parse_light
// // parse_sphere
// // parse_plane
// // parse_cylinder

// void	parse_specifier(t_data *data, char **line_split)
// {
// 	char	*spec;

// 	spec = line_split[0];
// 	if (!ft_strncmp(spec, "A", 1))
// 		; //parse_ambient(data, line);
// 	else if (!ft_strncmp(spec, "C", 2))
// 		; //parse_camera(data, line);
// 	else if (!ft_strncmp(spec, "L", 2))
// 		; //parse_light(data, line);
// 	else if (!ft_strncmp(spec, "sp", 3))
// 		; //parse_sphere(data, line);
// 	else if (!ft_strncmp(spec, "pl", 3))
// 		; //parse_plane(data, line);
// 	else if (!ft_strncmp(spec, "cy", 3))
// 		; //parse_cylinder(data, line);
// 	else
// 		; // wrong specifier
// }

// void	parse_line(t_data *data, char *line)
// {
// 	char	**line_split;

// 	line_split = ft_split(line, ' ');
// 	if (!line_split)
// 		return;
// 	parse_specifier(data, line_split);


// }

void	parse_input(t_data *data, char argc, char **argv)
{
	int 	file;
	char	*line;
	int		eof;
	t_list	*input;
	t_list	*new_item;

	if (argc > 2)
	{
		printf("wrong amount of arguments!\n");
		return ;
	}
	file = open(argv[1], O_RDONLY);
	// if (file == -1)
	//	invalid file
	eof = 0;
	input = NULL;
	while (!eof)
	{
		line = get_next_line(file);
		if (!line)
			eof = 1;
		else if (ft_strncmp(line, "\n", 2))
		{
			
			new_item = ft_lstnew((void *)(ft_strdup(line)));
			if (!new_item->content)
				return ; // MALLOC Error
			ft_lstadd_back(&input, new_item);
		}
		free(line);
	}

}