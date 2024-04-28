#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int** board, int n) {
    int safe = n * n;  // 전체 칸 수로 시작합니다.
    int** marked = malloc(n * sizeof(int*));  // 위험지역 표시 배열 할당

    for (int i = 0; i < n; i++) {
        marked[i] = malloc(n * sizeof(int));
        memset(marked[i], 0, n * sizeof(int));  // 위험지역 배열 초기화
    }

    // 지뢰 주변을 위험 지역으로 표시
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int ni = i + di;
                        int nj = j + dj;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && marked[ni][nj] == 0) {
                            marked[ni][nj] = 1;
                            safe--;  // 안전지역 수 감소
                        }
                    }
                }
            }
        }
    }

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(marked[i]);
    }
    free(marked);

    return safe;
}

int main() {
    int n = 5;
    int** board = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        board[i] = malloc(n * sizeof(int));
        memset(board[i], 0, n * sizeof(int));
    }

    // 지뢰 위치 설정
    board[3][2] = 1;
    board[3][3] = 1;

    int result = solution(board, n);
    printf("%d\n", result); // 기대값: 13

    // 메모리 해제
    for (int i = 0; i < n; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}
