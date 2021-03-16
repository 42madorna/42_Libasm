/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madorna- <madorna-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 23:25:43 by madorna-          #+#    #+#             */
/*   Updated: 2021/03/16 16:49:28 by madorna-         ###   ########.fr       */
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
	printf("	\x1b[34m[7]\x1b[0m \x1b[36m'iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa' 'iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsah'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %d\n", strcmp("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa", "iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsah"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %d\n", ft_strcmp("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa", "iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsah"));
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
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %s\n", strcpy(dst, "iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %s\n", ft_strcpy(dst, "iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa"));
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
	printf("	\x1b[34m[3]\x1b[0m \x1b[36m'iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa'\x1b[0m\n");
	printf("		\x1b[33m<string.h>\x1b[0m  %zu\n", strlen("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa"));
	printf("		\x1b[33m<libasm.h>\x1b[0m  %zu\n", ft_strlen("iJLFNWDJKSLFNADSM-LKFSANDKFjkadnladsfjlkhdsjjkdsfasdfasdkjlfsadllkfhjasfalldskfhjaslkdfjsa"));
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
	system ("leaks exec");
}
