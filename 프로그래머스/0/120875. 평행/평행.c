
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

double findSlope(int* dot1, int* dot2) {
    return (double) (dot2[1] - dot1[1]) / (dot2[0] - dot1[0]);
}
// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    if (findSlope(dots[0], dots[1]) == findSlope(dots[2], dots[3])) {
        return 1;
    }

        // (0, 2), (1, 3)
    if (findSlope(dots[0], dots[2]) == findSlope(dots[1], dots[3])) {
        return 1;
    }
        // (0, 3), (1, 2)
    if (findSlope(dots[0], dots[3]) == findSlope(dots[1], dots[2])) {
        return 1;
    }

    return answer;
}

int main(void) {
    int** dots = {{1, 4}, {9, 2}, {3, 8}, {11, 6}};
    size_t dots_rows = sizeof(dots)/sizeof(dots[0]);
    size_t dots_cols = sizeof(dots[0])/sizeof(dots[0][0]);
    int result = solution(dots, dots_rows, dots_cols); 
}