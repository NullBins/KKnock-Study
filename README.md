# ⚔ KKnock-Study
> 📖 KKnock Study Practice Codes.

## KKnock Study 2 Assignments.
- [Homework-3] : *Rock Paper Scissors*
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define True 1

void get_line(int num);

int main(void) {
    /* --- [K.Knock] 난수 설정 (Seed Random) --- */
    srand(time(NULL)); // 
    int cond = 0;
    /* --- [K.Knock] While (1) --- */
    while (True) {
        /* --- [K.Knock] 기본 프로세스 --- */
        get_line(30);
        printf("> 뭐 낼래?\n1 가위 2 바위 3보\n");
        scanf("%d", &cond);
        /* --- [K.Knock] 1 ~ 3만 선택하도록 설정 --- */
        if (cond < 1 || cond > 3) { printf("\n*** 1,2,3 중에 골라줘! ***\n\n"); continue; }
        /* --- [K.Knock] 난수를 3으로 나눈 나머지(int) => ((0 ~ 2) + 1) --- */
        int rc = (rand() % 3) + 1;
        switch (cond) {
        case 1: {
            /* --- [K.Knock] 사용자 => 가위 --- */
            get_line(30);
            (rc == 1) ? printf("*** 비겼다! 다시! ***\n") : ((void)0); // 가위
            if (rc == 2) { printf("*** 졌다! 으아아앙 ***\n"); system("pause"); return 0; } // 바위
            if (rc == 3) { printf("*** 이겼다! 야호! ***\n"); system("pause"); return 0; } // 보
            break;
        }
        case 2: {
            /* --- [K.Knock] 사용자 => 바위 --- */
            get_line(30);
            if (rc == 1) { printf("*** 이겼다! 야호! ***\n"); system("pause"); return 0; } // 가위
            (rc == 2) ? printf("*** 비겼다! 다시! ***\n") : ((void)0); // 바위
            if (rc == 3) { printf("*** 졌다! 으아아앙 ***\n"); system("pause"); return 0; } // 보
            break;
        }
        case 3: {
            /* --- [K.Knock] 사용자 => 보 --- */
            get_line(30);
            if (rc == 1) { printf("*** 졌다! 으아아앙 ***\n"); system("pause"); return 0; } // 가위
            if (rc == 2) { printf("*** 이겼다! 야호! ***\n"); system("pause"); return 0; } // 바위
            (rc == 3) ? printf("*** 비겼다! 다시! ***\n") : ((void)0); // 보
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

void get_line(int num) {
    for(int i = 0; i <= num; i++)
        printf("-");
    printf("\n");
}
```

## KKnock Study 3 Assignments.
- [Homework-2] : *Addition and subtraction of matrices*
```c
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
```

## KKnock Study 4 Assignments.
- [Homework-3] : *User function SWAP*
```c
#include <stdio.h>

void swap(int *x, int *y, int *z) {
    int temp = *x;
    *x = *y;
    *y = temp;
    *z = *x + *y;
    return;
}

int main(void) {
    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    //
    swap(&a, &b, &c);
    printf("a = %d, b = %d, c = %d", a, b, c);
    //
    return 0;
}
```
