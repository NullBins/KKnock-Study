#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void get_line(int num);
void input_matrix(int arr[SIZE][SIZE], int x, int y);
void print_matrix(int arr[SIZE][SIZE], int x, int y);
void sum_matrix(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int result[SIZE][SIZE], int x, int y);
void sub_matrix(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int result[SIZE][SIZE], int x, int y);

int main(void) {
    int rows, cols;
    int matrix1[SIZE][SIZE], matrix2[SIZE][SIZE], sum[SIZE][SIZE], sub[SIZE][SIZE];
    //
    get_line(50);
    printf("행렬의 행과 열 크기를 입력하세요 (최대 10): ");
    scanf("%d %d", &rows, &cols);
    //
    get_line(50);
    printf("\n첫 번째 행렬 입력:\n");
    input_matrix(matrix1, rows, cols);
    printf("\n두 번째 행렬 입력:\n");
    input_matrix(matrix2, rows, cols);
    //
    get_line(50);
    printf("\n첫 번째 행렬:\n");
    print_matrix(matrix1, rows, cols);
    printf("\n두 번째 행렬:\n");
    print_matrix(matrix2, rows, cols);
    //
    get_line(50);
    printf("\n행렬 덧셈 결과:\n행렬:\n");
    sum_matrix(matrix1, matrix2, sum, rows, cols);
    print_matrix(sum, rows, cols);
    //
    printf("\n행렬 뺄셈 결과:\n행렬:\n");
    sub_matrix(matrix1, matrix2, sub, rows, cols);
    print_matrix(sub, rows, cols);
    get_line(50);
    //
    return 0;
}

void input_matrix(int arr[SIZE][SIZE], int x, int y) {
    printf("행렬의 요소를 입력하세요:\n");
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void print_matrix(int arr[SIZE][SIZE], int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

void sum_matrix(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int result[SIZE][SIZE], int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
}

void sub_matrix(int arr1[SIZE][SIZE], int arr2[SIZE][SIZE], int result[SIZE][SIZE], int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            result[i][j] = arr1[i][j] - arr2[i][j];
        }
    }
}

void get_line(int num) {
    for(int i = 1; i <= num; i++)
        printf("-");
    printf("\n");
}
