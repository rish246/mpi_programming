#include <mpich/mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_LOW(id, p, n) ((id) *(n) / (p))
#define BLOCK_HIGH(id, p, n) BLOCK_LOW((id) + 1, p, n)
#define BLOCK_SIZE(id, p, n) (BLOCK_HIGH(id, p, n) - BLOCK_LOW(id, p, n))
#define BLOCK_OWNER(index, p, n) (((p) * (index + 1)) - 1 / (n))



int main(int argc, char *argv[])
{
    // declare normal variables
    int i, p, id, index;

    int N, prime;

    int local_count, global_count;

    int lower_bound, upper_bound, size, proc0_size;

    int *is_prime;

    MPI_Init(&argc, &argv);

    if(argc != 2)
    {
        // not specified value of n
        printf("Value of N not specified....\n");
        MPI_Finalize();
        exit(1);
    }

    // calcuate id and rank
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);


    N = atoi(argv[1]);

   
    lower_bound = BLOCK_LOW(id, p, N+1);
    upper_bound = BLOCK_HIGH(id, p, N+1);
    size = upper_bound - lower_bound;

    // assign arr size
    is_prime = (int *)malloc(sizeof(int) * (size));
    for(i=0; i<size; i++) is_prime[i] = 1;

    if(id == 0) index = 2;

    prime = 2;

    int first;
    do
    {
        if(prime * prime >= upper_bound){
            // no element to mark
            first = size;
        }
        else if((prime * prime) > lower_bound){
            first = (prime * prime) - lower_bound;
        } 
        else {
            if((lower_bound % prime) == 0) first = 0;
            else{
                first = prime - (lower_bound % prime);
            }
        }

        // bug is here
        for(i = first; i<size; i+=prime) is_prime[i] = 0;

        // compute next prime
        if(id == 0)
        {
            while(!is_prime[++index]);
            prime = index;
        }
        
        MPI_Bcast(&prime, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } while (prime * prime <= N);
    

    local_count = 0;
    for(i=0; i<size; i++){
        if(is_prime[i] && (lower_bound + i >= 2)) {
            local_count++;
        }
    }

    MPI_Reduce(&local_count, &global_count, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(id == 0)
    {
        printf("Total prime numbers less than equal to %d : %d\n", N, (global_count));
    }


    MPI_Finalize();

    return 0;


    // resize with size

    
    // calculate the bounds of block of cur process




}

// 5 -> prime * prime > n (prime * prime - 5 --> 4)
