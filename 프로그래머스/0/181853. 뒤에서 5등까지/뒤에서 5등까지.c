#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare(const void* a, const void* b){
   return(*(int*)a - *(int*)b) ;
}

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*5); 
    
    qsort(num_list, num_list_len, sizeof(int), compare); 
    
    for(size_t i=0; i<5; i++){
        answer[i] = num_list[i]; 
    }
    return answer;
}

int main(void){
    int num_list[] = {12, 4, 15, 46, 38, 1, 14}; 
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int* result = solution(num_list, num_list_len);  
    // 동적할당으로 포인터 타입으로 반환하니까 int* 처리해줘야함 
    
    if(result != NULL){
        for(size_t i=0; i<5; i++){
            printf("%d", result[i]);
        }
    }
    free(result);
    return 0; 
}