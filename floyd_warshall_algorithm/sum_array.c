#include <mpich/mpi.h>
#include <stdio.h>

#define BLOCK_LOW(id, n, p) ((id) * (n / p))
#define BLOCK_HIGH(id, n, p) BLOCK_LOW(id+1, n, p)
int array[] = {1, 3, 2, 5, 6, 6};

/* TODO :-> implement program to calculate the sum of the array */
int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int i, id, p;

    int local_sum = 0, global_sum;

    // get id
    MPI_Comm_rank(MPI_COMM_WORLD, &id);

    MPI_Comm_size(MPI_COMM_WORLD, &p);

    int block_start = BLOCK_LOW(id, 6, p);

    int block_end = BLOCK_HIGH(id, 6, p);

    int block_size = block_end - block_start;
    // printf("%d) Block start : %d\tBlock size: %d\tBlock high: %d\n", id, block_start, block_size, block_high);


    for(i=0; i<block_size; i++) {
        local_sum += array[i + block_start];
    }

    // after this 
    // reduce the result

    MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Finalize();

    if(!id) {
        printf("Sum of the numbers of the array = %d\n",global_sum);
    }





    // calculate sum of portion 


    // merge the portion to main answer
}