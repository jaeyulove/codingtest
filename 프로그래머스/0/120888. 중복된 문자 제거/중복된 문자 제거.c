#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* solution(const char* my_string) {
    size_t len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * (len + 1)); // 널 문자 공간을 포함한 충분한 공간 할당
    if (answer == NULL) return NULL; // 메모리 할당 실패 검사

    bool seen[256] = {0}; // ASCII 문자를 위한 빈도 배열 초기화
    int index = 0;

    for (int i = 0; i < len; i++) {
        unsigned char ch = my_string[i]; 
        if (!seen[ch]) { // 현재 문자가 처음 나타난 경우에만 추가
            seen[ch] = true;
            answer[index++] = my_string[i];
        }
    }
    answer[index] = '\0'; // 널 문자로 문자열 종료
    return answer;
}

int main() {
    const char* my_string = "abacabad";
    char* result = solution(my_string);
    printf("Result: %s\n", result); // "abcd" 출력 예상
    free(result); // 동적 할당된 메모리 해제
    return 0;
}
