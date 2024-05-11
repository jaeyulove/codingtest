#include <stdio.h>
#include <string.h>

int solution(const char* A, const char* B) {
    int n = strlen(A);
    
    if (strcmp(A, B) == 0) {
        return 0;
    }
    
    char shifted[101]; // A와 같은 길이로 배열을 할당, null 문자를 위해 1 길이 추가
    for (int i = 1; i < n; i++) {
        // 오른쪽으로 i 칸 이동한 문자열 생성
        for (int j = 0; j < n; j++) {
            shifted[j] = A[(j + n - i) % n];
        }
        shifted[n] = '\0'; // 문자열의 끝을 나타내는 null 문자 추가

        if (strcmp(shifted, B) == 0) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    printf("%d\n", solution("hello", "ohell")); // 출력: 1
    printf("%d\n", solution("apple", "elppa")); // 출력: -1
    printf("%d\n", solution("atat", "tata"));   // 출력: 1
    printf("%d\n", solution("abc", "abc"));     // 출력: 0
    return 0;
}
