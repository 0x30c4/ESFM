#include<file.h>

bool create_file(char *file_name, char *exe_name){

	int fd = open(file_name, O_CREAT, 0755);

	char str[32];

	long int str_len = strlen(str);

	sprintf(str, "/usr/bin/env %s", exe_name);

	printf("%s | %ld\n", str, str_len);

	for (int i = 0; i < str_len; i++)
		write(1, str, 1);
	/* write(fd, str, str_len); */
	close(fd);

	return true;
}
