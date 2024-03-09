#include <stdio.h>
#include <unistd.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int p; //size
    int id; // rank
    char name[80];
    int z;

    MPI_Init(&argc, &argv); // startsup a VM.
    MPI_Comm_size(MPI_COMM_WORLD, &p); // gets VM size.
    MPI_Comm_rank(MPI_COMM_WORLD, &id ); // get rank in VM.

    z = gethostname(name,80);
    if (z==0) { 
        printf("Hello, I am %d of %d (hostname is %s)\n", id, p, name);  // payload
    } else {
        printf("Hello, I am %d of %d (hostname UNKNOWN)\n", id, p);     // payload
    }

    MPI_Finalize(); // shutddwn VM.

    return 0;
}