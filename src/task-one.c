
/*
mpicc -Wall -O -o game game.c
mpirun -np 2 ./game
*/
#include <stdio.h>
#include <math.h>
#include <mpi.h>

void thinker() 
{

}

void guesser()
{

}

int main(int argc, char** argv) {

    int p; // size
    int id; // rank

    MPI_Init(&argc, &argv); // Start up VM
    MPI_Comm_size(MPI_COMM_WORLD, &p); // get size of VM
    MPI_Comm_rank(MPI_COMM_WORLD, &id); // getr rank/ processor id in VM
    
    if(id == 1) 
    {
        guesser();
    } else {
        thinker();
    }//payload

    //Shutdown VM
    MPI_Finalize();

    return 0;
}