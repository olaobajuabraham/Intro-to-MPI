#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char host[80];

	if(gethostname(host, 80) != 0)
		host[0] = '\0';
	printf("Hello World from %s!\n",
		host);
	return 0;
}

