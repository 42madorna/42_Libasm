/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:25:43 by madorna-          #+#    #+#             */
/*   Updated: 2021/03/16 10:58:18 by madorna-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "libasm.h"
#include <errno.h>
extern int ___error;

void		test_ft_strdup()
{
	char *str;

	printf("\x1b[32mft_strdup :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	str = strdup("");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", str);
	free(str);
	str = ft_strdup("");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", str);
	free(str);
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa'\x1b[0m\n");
	str = strdup("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", str);
	free(str);
	str = ft_strdup("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", str);
	free(str);
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	str = strdup("0123456789");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", str);
	free(str);
	str = ft_strdup("0123456789");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", str);
	free(str);
}

// void		test_ft_read()
// {
// 	int			fd;
// 	char		buffer[100];
// 	char		show[100];
// 	ssize_t		ret;

// 	printf("\x1b[32mft_read:\x1b[0m\n");
// 	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'open(\"main.c\", O_RDONLY)' '' '0'\x1b[0m\n");
// 	fd = open("testlib.c", O_RDONLY);
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	fd = open("testlib.c", O_RDONLY);
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'open(\"Makefile\", O_RDONLY)' '' '50'\x1b[0m\n");
// 	fd = open("Makefile", O_RDONLY);
// 	ret = read(fd, buffer, 50);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
// 	close(fd);
// 	fd = open("Makefile", O_RDONLY);
// 	ret = read(fd, buffer, 50);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 50));
// 	close(fd);
// 	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"dontexist\", O_RDONLY)' '' '10'\x1b[0m\n");
// 	fd = open("dontexist", O_RDONLY);
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	fd = open("dontexist", O_RDONLY);
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'open(\"testlib.c\", O_RDONLY)' 'NULL' '10'\x1b[0m\n");
// 	fd = open("testlib.c", O_RDONLY);
// 	ret = read(fd, NULL, 10);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", ret);
// 	close(fd);
// 	fd = open("testlib.c", O_RDONLY);
// 	ret = read(fd, NULL, 10);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ret);
// 	close(fd);
// 	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'42' '' '10'\x1b[0m\n");
// 	ret = read(42, buffer, 10);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	ret = read(42, buffer, 10);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	fd = open("empty_file", O_RDONLY | O_TRUNC | O_CREAT, 0777);
// 	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'open(\"empty_file\", O_RDONLY | O_TRUNC | O_CREAT, 0777)' '' '10'\x1b[0m\n");
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	ret = read(fd, buffer, 10);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd - %s\n", ret, strncpy(show, buffer, 10));
// 	close(fd);
// 	remove("empty_file");
// }

void
	test_ft_read(void)
{

	int		ret;
	int		num;
	int		fd;
	char	dest[500];
	char	*file = "src/linux/ft_strlen.s";
	fd = open(file, O_RDONLY);
	printf("\033[1;36m\n\n\nSYSTEM READ(%d, dest, 80) %s\n\033[0m", fd, file);
	errno = 0;
	do
	{
		ret = read(fd, dest, 80);
		num = errno;
		printf("%s\n\033[1;36mSYS--> ret=%d\terrno=%d %s <--\033[0m\n",dest, ret, num, strerror(num));

	} while(ret == 80);
	close(fd);

	fd = open(file, O_RDONLY);
	printf("\033[1;36m\n\nFT_READ(%d, dest, 80) %s\n\033[0m", fd, file);
	errno = 0;
	do
	{
		ret = ft_read(fd, dest, 80);
		num = errno;
		printf("%s\n\033[1;36mFT--> ret=%d\terrno=%d %s <--\033[0m\n",dest, ret, num, strerror(num));

	} while(ret == 80);
	close(fd);
}

void
	test_read_errors()
{
	int ret;
	int num;
	char	dest[50];

	printf("\n--== ERRORES ==--\nread(int fd, char *buf, int size)\n");

	printf("\033[1;36m\nread(0, NULL, 50);\033[0m\t\tbuffer NULL, el tamaño no importa xD\n");
	errno = 0;
	ret = read(0, NULL, 50);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));

	errno = 0;
	ret = ft_read(0, NULL, 50);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	

	printf("\033[1;36m\nread(42, dest, 6);\033[0m\t\tfd=42 bonito, pero incorrecto\n");
	errno = 0;
	ret = read(42, dest, 6);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	
	errno = 0;
	ret = ft_read(42, dest, 6);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	printf("\033[1;36m\nread(0, dest, -42);\033[0m\tSi es negativo... el tamaño SI importa\n");
	errno = 0;
	ret = read(0, dest, -42);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	errno = 0;
	ret = ft_read(0, dest, -42);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
}

// void		test_ft_write()
// {
// 	int			fd;
// 	char		buffer[100];

// 	printf("\x1b[32mft_write :\x1b[0m\n");
// 	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'1' '' '0'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "", 0));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "", 0));
// 	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'1' 'toto' '4'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 4));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 4));
// 	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'1' 'toto' '2'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, "toto", 2));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, "toto", 2));
// 	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'1' 'NULL' '6'\x1b[0m\n");
// 	// printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(1, NULL, 6));
// 	// printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(1, NULL, 6));
// 	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'0' 'toto' '4'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(0, "toto", 4));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(0, "toto", 4));
// 	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'42' 'toto' '4'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(42, "toto", 4));
// 	// printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(42, "toto", 4));
// 	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'-1' 'toto' '4'\x1b[0m\n");
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %zd\n", write(-1, "toto", 4));
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %zd\n", ft_write(-1, "toto", 4));
// 	fd = open("ft_write_test", O_WRONLY | O_TRUNC | O_CREAT, 0777);
// 	printf("	\x1b[34m[8]\x1b[0m \x1b[36m'open(\"ft_write_test\", O_WRONLY | O_TRUNC | O_CREAT)' '<whichlib.h> toto' '15'\x1b[0m\n");
// 	write(fd, "<unistd.h> toto", 15);
// 	ft_write(fd, "<libasm.h> toto", 15);
// 	close(fd);
// 	fd = open("ft_write_test", O_RDONLY);
// 	read(fd, buffer, 15);
// 	printf("		\x1b[33m<unistd.h>\x1b[0m  %s\n", buffer);
// 	read(fd, buffer, 15);
// 	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", buffer);
// 	close(fd);
// 	remove("ft_write_test");
// }

void
	test_ft_write(void)
{
	int i;
	int ret;
	int num;
	int		ntest = 4;
	char	*test[4] =	{"",
						"(҂◡_◡)",
						"Hello World",
						"¯\\_(ツ)_/¯"};

	printf("\nWRITE\n");
	for (i = 0; i < ntest; i++)
	{
		printf("\033[1;36m\"%s\"\033[0m\n", test[i]);
		ret = write(1, test[i], strlen(test[i]));
		num = errno;
		printf("\tret=%d\terrno=%d %s <--SYS\n",ret, num, strerror(num));

		ret = ft_write(1, test[i], strlen(test[i]));
		num = errno;
		printf("\tret=%d\terrno=%d %s <-- FT\n\n",ret, num, strerror(num));
	}
}

void
	test_write_errors()
{
	int ret;
	int num;

	printf("\n--== ERRORES ==--\nwrite(int fd, char *buf, int size)\n");
	printf("\033[1;36m\nwrite(1, NULL, 50);\033[0m\t\tbuffer NULL, el tamaño no importa xD\n");
	errno = 0;
	ret = write(1, NULL, 50);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));

	errno = 0;
	ret = ft_write(1, NULL, 50);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	printf("\033[1;36m\nwrite(42, \"buffer\", 6);\033[0m\t\tfd=42 bonito, pero incorrecto\n");
	errno = 0;
	ret = write(42, "buffer", 6);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	
	errno = 0;
	ret = ft_write(42, "buffer", 6);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	printf("\033[1;36m\nwrite(1, \"buffer\", -42);\033[0m\tSi es negativo... el tamaño SI importa\n");
	errno = 0;
	ret = write(1, "buffer", -42);
	num = errno;
	printf("SYS\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
	errno = 0;
	ret = ft_write(1, "buffer", -42);
	num = errno;
	printf("FT\tret=%d\terrno=%d %s\n",ret, num, strerror(num));
}

void		test_ft_strcmp()
{
	printf("\x1b[32mft_strcmp :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m'' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("", ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'toto' ''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("toto", ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("toto", ""));
	printf("	\x1b[34m[4]\x1b[0m \x1b[36m'' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("", "toto"));
	printf("	\x1b[34m[5]\x1b[0m \x1b[36m'tototest' 'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("tototest", "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("tototest", "toto"));
	printf("	\x1b[34m[6]\x1b[0m \x1b[36m'bbbonjour' 'bbonjour'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m %d\n", strcmp("bbbonjour", "bbonjour"));
	printf("		\x1b[33m<libasm.h>\x1b[0m %d\n", ft_strcmp("bbbonjour", "bbonjour"));
}

void		test_ft_strcpy()
{
	char	dst[100];

	printf("\x1b[32mft_strcpy :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, ""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, ""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'toto'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "toto"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "toto"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
}

void		test_ft_strlen()
{
	printf("\x1b[32mft_strlen :\x1b[0m\n");
	printf("	\x1b[34m[1]\x1b[0m \x1b[36m''\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen(""));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen(""));
	printf("	\x1b[34m[2]\x1b[0m \x1b[36m'    '\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("    "));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("    "));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'0123456789'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %lu\n", strlen("0123456789"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %lu\n", ft_strlen("0123456789"));
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'NULL'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", "SEGMENTATION FAULT");
}

int			main(int argc, char *argv[])
{
	if (argc == 1 || !strcmp(argv[1], "ft_strlen"))
		test_ft_strlen();
	if (argc == 1 || !strcmp(argv[1], "ft_strcpy"))
		test_ft_strcpy();
	if (argc == 1 || !strcmp(argv[1], "ft_strcmp"))
		test_ft_strcmp();
	if (argc == 1 || !strcmp(argv[1], "ft_write"))
	{
		test_ft_write();
		test_write_errors();
	}
	if (argc == 1 || !strcmp(argv[1], "ft_read"))
	{
		test_ft_read();
		test_read_errors();
	}
	if (argc == 1 || !strcmp(argv[1], "ft_strdup"))
		test_ft_strdup();
}
