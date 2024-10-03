#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 문자열을 "x"로 나누고, 사전순으로 정렬한 결과를 반환하는 함수
char** solution(const char* myString, int* result_len) {
    char* temp = strdup(myString);
    size_t myString_len = strlen(myString);
    
    // 최대 토큰 개수는 myString의 길이만큼일 수 있음
    char** answer = (char**)malloc(sizeof(char*) * (myString_len + 1));
    char* token = strtok(temp, "x"); 
    int index = 0;

    // "x" 기준으로 나누고, 빈 문자열은 제외
    while (token != NULL) {
        if (strlen(token) > 0) {  
            answer[index] = strdup(token);  
            index++;
        }
        token = strtok(NULL, "x");
    }

    // 버블 정렬을 사용하여 사전순으로 정렬
    for (int i = 0; i < index - 1; i++) {
        for (int j = i + 1; j < index; j++) {
            if (strcmp(answer[i], answer[j]) > 0) {
                // 문자열 포인터를 스왑
                char* temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }

    result_len = index;  
    free(temp);  

    return answer;
}

int main(void) {
    const char* myString = "axbxcxdx";
    int result_len = 0;
    char** result = solution(myString, &result_len);

    if (result != NULL) {
        for (int i = 0; i < result_len; i++) {
            printf("%s\n", result[i]);  
            free(result[i]);  
        }
        free(result);  
    }

    return 0;
}
