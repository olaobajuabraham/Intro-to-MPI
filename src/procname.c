#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    // int size;
    int rank;
    int namelen;
    char procname[MPI_MAX_PROCESSOR_NAME];

    MPI_Init(&argc, &argv);

    MPI_Get_processor_name(procname, &namelen);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("rank %d is processor %s \n", rank, procname);

    MPI_Finalize();

    return 0;
}