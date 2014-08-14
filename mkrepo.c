#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int usage(const char *p_name)
{
	fprintf(stderr, "usage: %s [-v] <repo1, repo2, ...>\n", p_name);
	return 1;
}

int _mkdir(char *path)
{
	return mkdir(path, 0755);
}

void mkrepo(char *path, int v)
{
	/* Make new directory */
	_mkdir(path);
	
	/* Switch to directory */
	chdir(path);

	/* Create git repository */
	
	if (v == 0) {
		system("git init --bare > /dev/null");
	} else {
		system("git init --bare");
	}

	/* Move back parent directory */
	chdir("..");
}

int main (int argc, char **argv)
{
	if (argc <= 1) {
		return usage(argv[0]);
	}

	int opt_verbose = 0;
	int index;
	int c;

	opterr = 0;

	while ((c = getopt(argc, argv, "v")) != -1) {
		switch (c) {
			case 'v':
				opt_verbose = 1;
			break;
		}
	}

	for (index = optind; index < argc; ++index) {
		mkrepo(argv[index], opt_verbose);
	}

	return 0;
}
