#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string) {
    char vowels[] = {'a', 'e', 'i', 'o', 'u'}; // 모음 배열
    size_t len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * (len + 1)); // 메모리 할당
    
    if(answer == NULL) {
        printf("메모리 할당 실패\n");
        return NULL;
    }
    
    int idx = 0; // answer에 추가할 위치를 가리키는 인덱스
    for(size_t i = 0; i < len; i++) {
        bool isVowel = false;
        for(int j = 0; j < 5; j++) { // 모음 판별
            if(my_string[i] == vowels[j]) {
                isVowel = true;
                break;
            }
        }
        if(!isVowel) {
            answer[idx++] = my_string[i]; // 모음이 아니면 answer에 추가
        }
    }
    answer[idx] = '\0'; // 문자열 종료
    
    return answer;
}

int main(void) {
    const char* my_string = "bus";
    char* result = solution(my_string);
    
    if(result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("메모리 할당 실패\n");
    }
    
    return 0;
}
