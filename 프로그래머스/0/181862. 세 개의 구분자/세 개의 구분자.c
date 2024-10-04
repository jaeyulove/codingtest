#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* myStr, int* result_len) {
    // 최대 문자열 길이만큼 동적 할당 (최대 나눠질 수 있는 문자열 수)
    char** answer = (char**)malloc(sizeof(char*) * (strlen(myStr) + 1));
    char* myStr_cpy = strdup(myStr); // 문자열 복사
    int count = 0;

    // "a", "b", "c"로 구분하여 문자열을 분할
    char* token = strtok(myStr_cpy, "abc");
    while (token != NULL) {
        // 토큰이 빈 문자열이 아닌 경우에만 배열에 추가
        if (strlen(token) > 0) {
            answer[count++] = strdup(token);
        }
        token = strtok(NULL, "abc");
    }

    // 구분자로 나눈 결과가 없으면 "EMPTY" 반환
    if (count == 0) {
        answer[count] = strdup("EMPTY");
        count++;
    }

    result_len = count; // 결과 길이 설정

    // 복사한 문자열 메모리 해제
    free(myStr_cpy);
    
    return answer;
}

int main(void) {
    const char* myStr = "baconlettucetomato";
    int result_len = 0;
    char** result = solution(myStr, &result_len);

    // 결과 출력
    for (int i = 0; i < result_len; i++) {
        printf("%s\n", result[i]);
        free(result[i]); // 각 문자열 메모리 해제
    }
    free(result); // 동적 배열 메모리 해제

    return 0;
}
