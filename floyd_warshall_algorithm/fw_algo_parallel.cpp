#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int main()
{
    // initialize a 2d array in c
    int n_rows = 6, n_cols = 6;

    // declare a large array of size (n_rows * n_cols)
    int *Bstorage;

    Bstorage = (int *)malloc((n_cols * n_rows) * sizeof(int));

    // divide the array into n_rows different arrays
    int **B; // final matrix

    // divide the Bstorage into n_rows different arrays
    B = (int **)malloc(n_rows * sizeof(int *));

    // store pointers of 1st element of each row
    for (int i_row = 0; i_row < n_rows; i_row++)
    {
        B[i_row] = Bstorage + (n_cols * i_row);
    }

    for (int i_row = 0; i_row < n_rows; i_row++)
    {
        for (int i_col = 0; i_col < n_cols; i_col++)
        {
            B[i_row][i_col] = 1;
            cout << B[i_row][i_col] << " ";
        }
        cout << endl;
    }
}