#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*num_list_len);
    int index = 0; 
    
    for(int i=n; i<num_list_len; i++){
        answer[index++] = num_list[i]; 
    }
    
    for(int i=0; i<n; i++){
        answer[index++] = num_list[i]; 
    }
    return answer;
}

int main(void){
    int num_list[] = {2,1,6};
    int n = 1;
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]);
    int* result = solution(num_list,n,num_list_len); 
    
    if(result != NULL){
        for(int i=0; i<num_list_len; i++){
            printf("%d", result[i]);
        }
        free(result);
    } else {
        printf("memory alloc failed"); 
    }
    return 0;
}