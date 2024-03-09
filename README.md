# Intro-to-MPI
message passing model is a type of parallel programming model. 

### recommended resources 
1. https://curc.readthedocs.io/en/latest/programming/MPI-C.html#setup-and-hello-world
2. https://manual.cs50.io/

To run any of the scripts in this project you need to have the MPI compiler installed.

```shell
sudo apt-get install mpich
```
### Functions under the MPI headers 
Functions under the `<mpi.h>` include:
1. MPI_Init(&argc, &argv) - Startsup a Virtual Machine.
2. MPI_Comm_size(MPI_COMM_WORLD, &p) - Gets the Virtual Machine Size 
3. MPI_Comm_rank(MPI_COMM_WORLD, &id) - Gets the Process Id / rank in Virtual Machine
4. MPI_Finalize() - Shutsdown Virtual Machine.

## Guides.
To build `src/hello-simple.c` and run it. you can change the number of processes by change the number 4 in the command.
```shell
mpicc -Wall -O -o bin/hello-simple src/hello-simple.c && mpirun -np 4 bin/hello-simple 
```
 
To build `src/hello-advanced.c` and run it. you can change the number of processes by change the number 4 in the command.
`NOTE: The paylaod has been change in this implementation.`
```shell
mpicc -Wall -O -o bin/hello-advanced src/hello-advanced.c && mpirun -np 4 bin/hello-advanced 
```
You can also specify a machinefile to run the logic of the get the new paylaod.
```shell
mpirun -machinefile resources/mpi04 -np 4 bin/hello-advanced
``


