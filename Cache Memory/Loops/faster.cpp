#include <bits/stdc++.h>


void execute(int length)
{
    const int MAX = length;
    int i, j;
    // time_t start, end;

    // double A[MAX][MAX], x[MAX], y[MAX];
    double **A, *x, *y;
    A = new double*[MAX];
    x = new double[MAX];
    y = new double[MAX];
    // . . .
    /* Initialize A and x, assign y = 0 */
    for (i = 0; i < MAX; i++)
    {
        A[i] = new double[MAX];
        for (j = 0; j < MAX; j++)
            A[i][j] = std::rand() % 100;
    }
    for (i = 0; i < MAX; i++)
        x[i] = std::rand() % 100;
    for (i = 0; i < MAX; i++)
        y[i] = 0;
    // . . .
    /* First pair of loops */
    // time(&start);
    auto begin = std::chrono::high_resolution_clock::now();
    for (i = 0; i < MAX; i++)
        for (j = 0; j < MAX; j++)
            y[i] += A[i][j]*x[j];
    // time(&end);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << " microseconds" << std::endl;
    // std::cout << "Time taken by first pair of loops: " << std::fixed << double(end - start) << std::setprecision(5) << " sec" << std::endl;

    for (i = 0; i < MAX; i++)
        delete[] A[i];
    delete[] A;
    delete[] x;
    delete[] y;
}




int main()
{

    for (int i = 1000; i <= 16000; i += 1000)
    {
        std::cout << "Length: " << i << "/t";
        execute(i);
    }
    return 0;
}