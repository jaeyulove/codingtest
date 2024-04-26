#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots는 점들의 배열, dots_rows는 배열의 길이입니다.
int solution(int** dots, size_t dots_rows) {
    // 최소값과 최대값 초기화
    int max_rows = dots[0][0];
    int min_rows = dots[0][0];
    int max_cols = dots[0][1];
    int min_cols = dots[0][1];
    
    // 모든 점을 순회하며 최대값과 최소값 갱신
    for (int i = 0; i < dots_rows; i++) {
        if (dots[i][0] > max_rows) {
            max_rows = dots[i][0];
        }
        if (dots[i][0] < min_rows) {
            min_rows = dots[i][0];
        }
        if (dots[i][1] > max_cols) {
            max_cols = dots[i][1];
        }
        if (dots[i][1] < min_cols) {
            min_cols = dots[i][1];
        }
    }

    // 최대 가로와 최대 세로 차이를 계산하여 면적을 계산
    int square_rows = max_rows - min_rows;
    int square_cols = max_cols - min_cols;
    
    return square_rows * square_cols; // 면적 반환
}

int main(void) {
    int dots[4][2] = {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    size_t dots_rows = sizeof(dots) / sizeof(dots[0]);
    
    // 배열 포인터 변환
    int* dots_ptrs[4];
    for (int i = 0; i < 4; i++) {
        dots_ptrs[i] = dots[i];
    }
    
    int result = solution(dots_ptrs, dots_rows);
    printf("%d\n", result); // 결과 출력
    return 0; 
}
