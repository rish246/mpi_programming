#include <mpich/mpi.h>
#include <stdio.h>

const int N = 100;

int is_even(int id, int value){
    
    if(value % 2 == 0){
        printf("%d --> %d is an even number\n", id,   value);
        return 1;
    }
    
    return 0;
}


int main(int argc, char* argv[])
{
    // declare vars
    int i, id, p;

    int solutions, global_solutions;

    // solutions -> local solns of cur process


    // merged solutions

    // is_even(int, int);

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    MPI_Comm_size(MPI_COMM_WORLD, &p);

    // construct local solutions
    solutions = 0;

    for(i=id; i<N; i+=p){
        solutions += is_even(id, i);

    }

    // reduce to global solutions
    MPI_Reduce(&solutions, &global_solutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    printf("Process having id : %d is done", id);


    fflush(stdout);

    MPI_Finalize();

    if(id == 0){
        printf("total even numbers between 0 to 100 are : %d\n", global_solutions);
    }

    return 0;





}