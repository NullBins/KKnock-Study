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
