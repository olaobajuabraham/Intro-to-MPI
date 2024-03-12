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
3. MPI_Comm_rank(MPI_COMM_WORLD, &id) - Gets the Process Id / rank in Virtual Machine.
4. MPI_Get_processor_name(MPI_COMM_WORLD, &namelen) - get the name of the processor.
5. MPI_Comm_split() - split the MPI_COMM_WORLD communicator into sub-communicators.
5. MPI_Finalize() - Shutsdown Virtual Machine.

## Guides.
To build `src/hello-simple.c` and run it. you can change the number of processes by change the number 4 in the command.
```shell
mpicc -Wall -O -o bin/hello-simple src/hello-simple.c && mpirun -np 4 bin/hello-simple 
```
 
To build `src/hello-advanced.c` and run it use the command below. 
you can change the number of processes by changing the number 4 in the command.
`NOTE: The paylaod has been change in this implementation.`
```shell
mpicc -Wall -O -o bin/hello-advanced src/hello-advanced.c && mpirun -np 4 bin/hello-advanced 
```
You can also specify a machinefile to run the logic of the get the new paylaod.
```shell
mpirun -machinefile resources/mpi04 -np 4 bin/hello-advanced
```

MPI organises processors into groups called connectors.
MPI_COMM_WORLD is the top level communicator consisting of all processors allocated by `mpirun -np` 

### Basic POINT to POINT Communication in MPI
MPI offers two basic point to point communication functions: 
1. MPI_Send(message, count, datatype, dest, tag, comm)
2. MPI_Recv(message, count, datatype, source, tag, comm, status)
3. MPI_Ssend(message, count, datatype, dest, tag, comm)
4. MPI_Bsend(message, count, datatype, dest, tag, comm)

Many parallel programs can be written using just the basic
MPI_Send and MPI_Recv and the other functions we used in hello-simple and hello-advanced programs.

### Send and Recieve [Detailed]
pass `MPI_ANY_SOURCE` to `MPI_Recv` if the source is irrelevant.
pass `MPI_ANY_TAG` to `MPI_Recv` if the tag is also irrelevant. 


### MPI DATETYPES
MPI_CHAR : char
MPI_DOUBLE : double
MPI_FLOAT : float
MPI_INT : int
MPI_LONG : long
MPI_LONG_DOUBLE : long double
MPI_UNSIGNED_CHAR : unsigned char
MPI_UNSIGNED_INT : unsigned int - ?????
MPI_UNSIGNED_LONG : unsigned long
MPI_UNSIGNED_SHORT : unsigned short

### Example programs
The Number guessing Game is a 2 player game with two actors: thinker and guesser
1. Thinker - thinks of a number between 1 and 100
2. Guesser - guesses the number the thinker has chosen.
3. Thinker - replies whether the guess is low,high or correct.
4. idf not correct, the guesser trys again and so on.

### Task 1
Implement this program as an MPI Program running on two processors
Thinker is on processor 0
    1. Recieves Integer guesses.
    2. Sends replies as characters h, l or c.
Guesser is on processor 1
    1. Sends integer guesses
    2. Recieves characters.

NOTE: This is a distributed, non-parallel program, because the game is turn-based and thus inherently sequential.










