#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int fd;
	char *line;

	fd = open("test_file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linha lida: %s\n", line);
		free(line);
	}

	close(fd);
	return (0);
}