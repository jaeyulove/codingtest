#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) { // 오름차 순으로 정렬
    return strcmp(*(const char**)a,*(const char**)b);
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t my_string_len= strlen(my_string); 
    char** answer = (char**)malloc(sizeof(int*)*my_string_len+1);
 
    if(answer == NULL){
        printf("memory allocation failed");
        return NULL; 
    }
    
    char my_string_cpy[my_string_len];
    strcpy(my_string_cpy,my_string); 
    
    for(size_t i=0; i<my_string_len; i++){
        answer[i] = strdup(my_string_cpy+i);
    }
    qsort(answer,my_string_len, sizeof(char*), compare);
    return answer;
}

int main(void) {
    const char* my_string = "banana";
    size_t result_len = strlen(my_string);
    
    char** result = solution(my_string);
    
    if (result != NULL) {
        for (int i = 0; i < result_len; i++) {
            printf("%s\n", result[i]);
            free(result[i]); // 할당된 메모리 해제
        }
        free(result); // 배열 포인터 해제
    }
    
    return 0;
}