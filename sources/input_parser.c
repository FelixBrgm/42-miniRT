#include "../includes/miniRT.h"

/*
A 0.2 255,255,255
C -50,0,20 0,0,0 70
L -40,0,30 0.7 255,255,255
pl 0,0,0 0,1.0,0 255,0,225
sp 0,0,20 20 255,0,0
cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255
*/

// void	get_specifier(t_data *data, char *spec)
// {
// 	if (ft_strncmp(spec, ));
// }

void	parse_line(t_data *data, char *line)
{
	char	**line_split;


}

void	parse_input(t_data *data, char argc, char **argv)
{
	int 	file;
	char	*line;
	int		eof;
	if (argc > 2)
	{
		printf("wrong amount of arguments!\n");
		return ;
	}
	file = open(argv[1], O_RDONLY);
	// if (file == -1)
	//	invalid file
	eof = 0;
	while (!eof)
	{
		line = get_next_line(file);
		if (!line)
			eof = 1;
		parse_line(data, line);
	}

}