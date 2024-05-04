#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    return answer;
}

int main(void){
    int** dots[4][2] = {{1, 4}, {9, 2}, {3, 8}, {11, 6}};
    size_t dots_rows = sizeof(dots)/sizeof(dots[0]); 
    size_t dots_cols = sizeof(dots[0])/sizeof(dots[0][0]);
    
    int result= solution(dots, dots_rows, dots_cols); 
    printf("%d\n", result); 
    return 0; 
}
    