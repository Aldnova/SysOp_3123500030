#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 4

// Fungsi untuk menghitung elemen matriks hasil
void multiplyRowByColumn(int mat1[N][N], int mat2[N][N], int hasil[N][N], int row, int col) {
    for (int k = 0; k < N; k++) {
        result[row][col] += mat1[row][k] * mat2[k][col];
    }
}

int main() {
    int mat1[N][N] = {
        {2, 0, 1, 3},
        {3, 0, 0, 5},
        {5, 1, 1, 2},
        {1, 3, 2, 2}
    };
    int mat2[N][N] = {
        {1, 0, 2, 1},
        {1, 2, 1, 0},
        {0, 1, 0, 2},
        {2, 1, 3, 1}
    };
    int hasil[N][N] = {0};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            pid_t pid = fork();
            if (pid == 0) {
                // Proses anak menghitung satu elemen dari hasil
                multiplyRowByColumn(mat1, mat2, result, i, j);
                printf("Child process for element [%d][%d] completed\n", i, j);
                _exit(0); // Keluar dari proses anak
            }
        }
    }

    // Menunggu semua proses anak selesai
    while (wait(NULL) > 0);

    // Mencetak hasil matriks
    printf("Result of matrix multiplication:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}


