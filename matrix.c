#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matrix(int** matrix, int r, int c) //행렬 출력
{
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
}

void add_matrix(int** array_A, int** array_B, int** result_array, int rows, int c) //행렬 A+B
{
    //result_array 행렬에 array_A와 array_B의 [i][j]번째 원소 값 합한 값을 넣기
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < c; j++) {
            result_array[i][j] = array_A[i][j] + array_B[i][j];
        }
    }
}

void subtract_matrix(int** array_A, int** array_B, int** result_array, int r, int c) //행렬 A-B
{
    //result_array 행렬에 array_A와 array_B의 [i][j]번째 원소 값을 뺀 값을 넣기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result_array[i][j] = array_A[i][j] - array_B[i][j];
        }
    }
}

void transpose_matrix(int** array, int** result_array, int r, int c) //행렬 A의 전치행렬
{
    //행렬 A의 [i][j]번째 원소와 [j][i]번째 원소들의 위치를 변환하여 주대각 원소는 같은 행렬 A의 전치행렬 T를 result_array에 넣기
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            result_array[j][i] = array[i][j];
        }
    }
}
void multiply_matrix(int** array_A, int** array_B, int** result_array, int rows_A, int cols_A, int cols_B) //행렬 A*B
{
    //행렬 A의 행과 행렬 B의 열들을 곱하여 행렬의 곱셈을 표현
    for (int i = 0; i < rows_A; i++) {
        for (int j = 0; j < cols_B; j++) {
            result_array[i][j] = 0;
            for (int k = 0; k < cols_A; k++) {
                result_array[i][j] += array_A[i][k] * array_B[k][j];
            }
        }
    }
}

void free_matrix(int** array, int r) //행렬 메모리 해제
{
    //free함수로 동적 할당한 메모리 해제
    for (int i = 0; i < r; i++) {
        free(array[i]);
    }
    free(array);
}


int main() 
{
    printf("[----- [LeeSeungHun] [2023041045] -----]\n"); //second commit

    int rows, cols; //변수 행과 열 선언

    printf("Matrix size : ");
    scanf("%d %d", &rows, &cols); // 행렬 A,B의 크기 입력 받기


    // 메모리 할당
    int** array_A = (int**)malloc(rows * sizeof(int*)); //2차원 배열 array_A에 malloc 함수로 메모리 동적할당
    int** array_B = (int**)malloc(rows * sizeof(int*)); //2차원 배열 array_B에 malloc 함수로 메모리 동적할당
    int** result_array = (int**)malloc(rows * sizeof(int*)); //2차원 배열 result_array에 malloc 함수로 메모리 동적할당

    for (int i = 0; i < rows; i++) 
    {
        array_A[i] = (int*)malloc(cols * sizeof(int)); //array_A의 배열 안에 배열을 동적할당하여 2차원 배열 구현
        for (int j = 0; j < cols; j++) {
            array_A[i][j] = rand() % 100; //rand함수로 행렬 A 할당 및 랜덤 값으로 초기화
        }
    }

    for (int i = 0; i < rows; i++) 
    {
        array_B[i] = (int*)malloc(cols * sizeof(int)); //array_B의 배열 안에 배열을 동적할당하여 2차원 배열 구현
        for (int j = 0; j < cols; j++) {
            array_B[i][j] = rand() % 100; //rand함수로 행렬 B 할당 및 랜덤 값으로 초기화
        }
    }

    printf("Matrix A:\n");
    print_matrix(array_A, rows, cols); //행렬 출력 함수 호출로 

    printf("Matrix B:\n");
    print_matrix(array_B, rows, cols);

        result_array = (int**)malloc(rows * sizeof(int*)); // 결과 행렬에 메모리 할당
        for (int i = 0; i < rows; i++) 
        {
            result_array[i] = (int*)malloc(cols * sizeof(int));
        }
        add_matrix(array_A, array_B, result_array, rows, cols);
        printf("Matrix A+B:\n");
        print_matrix(result_array, rows, cols);
        free_matrix(result_array, rows); //할당된 메모리 해제

        result_array = (int**)malloc(rows * sizeof(int*)); // 결과 행렬에 메모리 할당
        for (int i = 0; i < rows; i++) 
        {
            result_array[i] = (int*)malloc(cols * sizeof(int));
        }
        subtract_matrix(array_A, array_B, result_array, rows, cols);
        printf("Matrix A-B:\n");
        print_matrix(result_array, rows, cols);
        free_matrix(result_array, rows); // 할당된 메모리 해제
  

    result_array = (int**)malloc(cols * sizeof(int*)); // 결과 행렬에 메모리 할당
    for (int i = 0; i < cols; i++) 
    {
        result_array[i] = (int*)malloc(rows * sizeof(int));
    }
    printf("Transpose_matrix of A, T\n");
    transpose_matrix(array_A, result_array, rows, cols);
    print_matrix(result_array, cols, rows); // 행과 열이 바뀜
    free_matrix(result_array, cols); // 할당된 메모리 해제

        result_array = (int**)malloc(rows * sizeof(int*)); // 결과 행렬에 메모리 할당
        for (int i = 0; i < rows; i++) 
        {
            result_array[i] = (int*)malloc(cols * sizeof(int));
        }
        multiply_matrix(array_A, array_B, result_array, rows, cols, cols);
        printf("Matrix A*B\n");
        print_matrix(result_array, rows, cols);
        free_matrix(result_array, rows); // 할당된 메모리 해제

    free_matrix(array_A, rows); //행렬 A에 할당된 메모리 해제
    free_matrix(array_B, rows); //행렬 B에 할당된 메모리 해제

    return 0;
}