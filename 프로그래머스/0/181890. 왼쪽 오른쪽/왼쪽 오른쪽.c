#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// str_list_len은 배열 str_list의 길이입니다.
// result_len은 포인터로 전달하여 값이 반영되도록 설정
char** solution(const char* str_list[], size_t str_list_len, int* result_len) {
    // 각 문자열을 저장할 공간 할당 (문자열 포인터의 크기 * 길이)
    char** answer = (char**)malloc(sizeof(char*) * str_list_len);
    int index = 0;
    bool is_l = false;
    int is_l_index = 0;
    int is_r_index = 0;

    // 'l' 또는 'r'의 위치를 찾기 위한 반복문
    for (int i = 0; i < str_list_len; i++) {
        if (strcmp(str_list[i], "l") == 0) {
            is_l = true;
            is_l_index = i;
            break;
        } else if (strcmp(str_list[i], "r") == 0) {
            is_l = false;
            is_r_index = i;
            break;
        }
    }

    // 'l'이 발견된 경우: 'l' 이전의 문자열을 저장
    if (is_l) {
        for (int i = 0; i < is_l_index; i++) {
            answer[index] = (char*)malloc(strlen(str_list[i]) + 1);
            strcpy(answer[index++], str_list[i]);
        }
    }
    // 'r'이 발견된 경우: 'r' 이후의 문자열을 저장
    else {
        for (int i = is_r_index + 1; i < str_list_len; i++) {
            answer[index] = (char*)malloc(strlen(str_list[i]) + 1);
            strcpy(answer[index++], str_list[i]);
        }
    }

    // 반환할 문자열의 개수를 설정
    result_len = index;

    return answer;
}

int main(void) {
    const char* str_list[] = {"u", "u", "l", "r"};
    size_t str_list_len = sizeof(str_list) / sizeof(str_list[0]);
    int result_len = 0;

    // solution 함수 호출
    char** result = solution(str_list, str_list_len, &result_len);

    // 결과 출력
    if (result != NULL) {
        for (int i = 0; i < result_len; i++) {
            printf("%s\n", result[i]);  // 문자열 출력
            free(result[i]);  // 동적으로 할당된 메모리 해제
        }
        free(result);  // 배열 자체 해제
    }

    return 0;
}
