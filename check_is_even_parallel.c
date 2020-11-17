#include <stdio.h>
#include <mpich/mpi.h>


void is_even(int id, int value){
    if(value % 2 == 0){
        printf("%d --> %d : is an even number\n", id, value);
    }
}

// no control over which process executes first
int main(int argc, char* argv[])
{
    // MPI_Init
    MPI_Init(&argc, &argv);


    // declare 3 params
    int id;
    int i;
    int p;

    // void is_even(int, int);

    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // 1 -> 100 even numbers
    for(i = id; i < 100; i+=p){
        is_even(id, i);
    }

    MPI_Finalize();


    // printf("Hello world");
}

// for each id must be 