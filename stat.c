#include "ft_ls.h"


int	main(int ac, char **av)
{
	/*struct stat buf;
    int x;

    x = stat (av[1], &buf);
    if (S_ISLNK(buf.st_mode)) printf (" stat says link\n");
    if (S_ISREG(buf.st_mode)) printf (" stat says file\n");

    x = lstat (av[1], &buf);
    if (S_ISLNK(buf.st_mode)) printf ("lstat says link\n");
    if (S_ISREG(buf.st_mode)) printf ("lstat says file\n");*/
	struct stat sb;
	int x;

	if (ac == 2)
	{
		
		if (stat(av[1], &sb) == -1)
			{
				printf( (errno & ENOENT) ? "y" : "n");
				exit(1);
			}
			printf("st_mode: %o\n", sb.st_mode);
			printf("st_ino: %llu\n", sb.st_ino);
			printf("st_dev: %d\n", sb.st_dev);
			printf("st_uid: %d\n", sb.st_uid);
			printf("st_gid: %d\n", sb.st_gid);
			printf("st_atime: %ld\n", sb.st_atime);
			printf("st_ctime: %ld\n", sb.st_ctime);
			printf("st_mtime: %ld\n", sb.st_mtime);
			printf("modified atime: %s", ctime(&sb.st_atime));
			printf("st_size: %lld\n", sb.st_size);
			printf("File Permissions: \t");
			printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
			printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
			printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
			printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
			printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
			printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
			printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
			printf( (sb.st_mode & S_IROTH) ? "r" : "-");
			printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
			printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
			printf( (S_ISDIR(sb.st_mode)) ? "Directory\n" : "");
			printf( (S_ISREG(sb.st_mode)) ? "Fichier regulier\n" : "");
			printf( (S_ISCHR(sb.st_mode)) ? "Charac device\n" : "");
			printf( (S_ISBLK(sb.st_mode)) ? "Block device\n" : "");
			printf( (S_ISFIFO(sb.st_mode)) ? "FIFO\n" : "");
			printf( (S_ISLNK(sb.st_mode)) ? "Lien symbolique\n" : "");
			printf( (S_ISSOCK(sb.st_mode)) ? "Socket\n" : "\n");
			printf("\n\n");

		if (lstat(av[1], &sb) == -1)
		{
			printf("1000\n");
			exit(1);
		}
		printf("st_mode: %o\n", sb.st_mode);
		printf("st_ino: %llu\n", sb.st_ino);
		printf("st_dev: %d\n", sb.st_dev);
		printf("st_uid: %d\n", sb.st_uid);
		printf("st_gid: %d\n", sb.st_gid);
		printf("st_atime: %ld\n", sb.st_atime);
		printf("st_ctime: %ld\n", sb.st_ctime);
		printf("st_mtime: %ld\n", sb.st_mtime);
		printf("modified atime: %s", ctime(&sb.st_atime));
		printf("st_size: %lld\n", sb.st_size);
		printf("File Permissions: \t");
		printf( (S_ISDIR(sb.st_mode)) ? "d" : "-");
		printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
		printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
		printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
		printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
		printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
		printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
		printf( (sb.st_mode & S_IROTH) ? "r" : "-");
		printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
		printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
		printf("\n");
		printf( (S_ISDIR(sb.st_mode)) ? "Directory\n" : "");
		printf( (S_ISREG(sb.st_mode)) ? "Fichier regulier\n" : "");
		printf( (S_ISCHR(sb.st_mode)) ? "Charac device\n" : "");
		printf( (S_ISBLK(sb.st_mode)) ? "Block device\n" : "");
		printf( (S_ISFIFO(sb.st_mode)) ? "FIFO\n" : "");
		printf( (S_ISLNK(sb.st_mode)) ? "Lien symbolique\n" : "");
		printf( (S_ISSOCK(sb.st_mode)) ? "Socket\n" : "\n");
		printf("\n\n");
	}
	return (0);
}
