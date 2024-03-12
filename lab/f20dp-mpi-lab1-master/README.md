Log into the robotarium cluster and experiment with the three MPI programs.

First load the MPI module with the command:

    module load intel/mpi/64

Compile your programs using "mpicc" on the `robotarium` head node.

    mpicc hello3.c

Learn how to start MPI programs on the cluster i.e. `gpu01` .. `gpu08`, NOT on the `robotarium` head node.

Get started by using SLURM to launch your compiled programs:

    srun --partition=amd-longq -N 4 --mpi=pmi2 ./a.out

Learn how to use slurm batch scripts that you can start with `sbatch`.

Use `squeue` to find out what is going on on the system.