#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;
#define INF 1000
vector<vector<int>> adj_matrix(6, vector<int>(6, INF));

void init_adj_matrix()
{
    adj_matrix = {
        {0, 2, 5, INF, INF, INF},
        {INF, 0, 7, 1, INF, 8},
        {INF, INF, 0, 4, INF, INF},
        {INF, INF, INF, INF, 3, INF},
        {INF, INF, 2, INF, 0, 3},
        {INF, 5, INF, 2, 4, 0}};
}
int main()
{
    init_adj_matrix();

    // APPLY FLOYD WARSHALL ALGO
    for (int k = 0; k < 6; k++)
    {
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                adj_matrix[i][j] = min(adj_matrix[i][j], adj_matrix[i][k] + adj_matrix[k][j]);
            }
        }
    }

    for (auto row : adj_matrix)
    {
        for (auto value : row)
        {
            cout << setw(5) << value << " ";
        }
        cout << endl;
    }
}