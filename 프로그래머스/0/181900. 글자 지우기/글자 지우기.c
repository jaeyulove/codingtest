#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

int compare(const void* a, const void* b) { //오름차 순으로 정렬 
return (*(int*)a - *(int*)b); 
} 

// indices_len은 배열 indices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int indices[], size_t indices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t my_string_len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char)*my_string_len+1);
    
    qsort(indices,indices_len,sizeof(int),compare);
    
    int index = 0;
    int skip_index = 0; 
    for(size_t i=0; i<my_string_len; i++){
        if(skip_index < indices_len && i == indices[skip_index]){
            skip_index++;
        }
        else {
            answer[index++] = my_string[i];
        }
    }
    answer[index] = '\0';
    return answer;
}

int main(void){
    const char* my_string = "apporoograpemmemprs";
    int indices[]={1, 16, 6, 15, 0, 10, 11, 3};
    size_t indices_len = sizeof(indices)/sizeof(indices[0]); 
    
    char* result = solution(my_string,indices,indices_len);
    
    if(result != NULL){
        printf("%s\n", result);
        free(result); 
    }
    return 0; 
}