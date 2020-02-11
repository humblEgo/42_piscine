#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

bool	check_valid_arg(char *str);
char	*new_parse_dict(char *dict);

int main(int argc, char *argv[])
{
	int	fd;

	if (argc != 2 && argc != 3)
		write(1, "Error\n", 6);
	else
	{
		if (argc == 2)
		{
			if (!check_valid_arg(argv[argc - 1]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			else
			{
				// debug
				printf("OK : %s\n", argv[argc - 1]);
				fd = open("numbers.dict.txt", O_RDONLY);
				if (fd == -1)
				{
					write(1, "Error\n", 6);
					close(fd);
				}
//				create_dict_buf(fd);
			}
		}
		else if (argc == 3)
		{
			if (!check_valid_arg(argv[argc - 1]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			else
			{
				// debug
				printf("OK : %s\n", argv[argc - 1]);
				fd = open(argv[argc - 1], O_RDONLY);
				if (fd == -1)
				{
					write(1, "Error\n", 6);
					close(fd);
				}
//				create_dict_buf(fd);
			}
		}
	}
	return 0;
}

// ----------- 12 lines ------------
bool	check_valid_arg(char *str)
{
	if (*str == '0')
		return (false);
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
			return (false);
		str++;
	}
	return (true);
}

char	*new_parse_dict(char *dict)
{
	char	*temp;
	int		len;

	len = 42;
	temp = (char *)malloc(sizeof(char) * len);
	
	while (*dict)
	{
		while (*dict != ' ' && *dict != ':')
		{
			*temp = *dict;
			temp++;
			dict++;
		}
		if (*dict == ':')
		{
			*temp = *dict;
			dict++;
			temp++;
		}
		if (*dict == ' ')
		{
			while (*dict != ' ')
				*dict++;
			while (*dict != '\n' && *dict != '\0')
			{
				*temp = *dict;
				temp++;
				dict++;
			}
			dict++;
		}
		else
		{
			while (*dict != '\n' && *dict != '\0')
			{
				*temp = *dict;
				temp++;
				dict++;
			}
			dict++;
		}
	}
}
