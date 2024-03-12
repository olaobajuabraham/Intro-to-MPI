#include <mpi.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char host[80];
	int p, id;

	MPI_Init(&argc, &argv);
	if(gethostname(host, 80) != 0)
		host[0] = '\0';
	MPI_Comm_size(MPI_COMM_WORLD, &p);
	MPI_Comm_rank(MPI_COMM_WORLD, &id);
	
	printf("Hello World from %s! I am %d of %d.\n",
		host, id, p);
	MPI_Finalize();
	return 0;
}
