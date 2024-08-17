#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

char** solution(const char* my_string, size_t* my_string_len_result) {
    char* my_string_cpy = strdup(my_string);
    char* token = strtok(my_string_cpy, " ");
    size_t index = 0;
    char** answer = (char**)malloc(sizeof(char*) * 1000); // 넉넉하게 메모리 할당
    
    while (token != NULL) {
        answer[index++] = strdup(token); // 각 단어를 복사하여 answer에 저장
        token = strtok(NULL, " ");
    }
    
    free(my_string_cpy); // strdup으로 복사한 문자열을 해제
    my_string_len_result = index;
    return answer;
}

int main(void) {
    const char* my_string = " i    love  you"; 
    size_t my_string_len_result; 
    char** result = solution(my_string, &my_string_len_result);
    
    if (result != NULL) {
        for (size_t i = 0; i < my_string_len_result; i++) {
            printf("%s\n", result[i]);
            free(result[i]); // strdup으로 복사한 단어를 해제
        }
        free(result); // 동적으로 할당한 answer 배열을 해제
    }
    
    return 0; 
}
