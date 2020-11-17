#include <stdio.h>
#include <mpich/mpi.h>

const int N = 5;
int my_array[] = {32, 43, 5, 67, 9};

int main(int argc, char *argv[])
{
    int i, p, id, solutions, global_solutions;

    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_asize(MPI_COMM_WORLD, &p);

    solutions = 0;
    // add 1 number
    for(int i=id; i<N; i+=p){
        solutions = my_array[i];
    }

    // Reduce
    MPI_Reduce(&solutions, &global_solutions, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);

    printf("Process havind id : %d completed\n", id);

    fflush(stdout);

    MPI_Finalize();
    // finali

    if(id == 0){
        printf("Maximum element of the array = %d\n", global_solutions);
    }

    return 0;
}