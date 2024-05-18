#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*n);
    
    if(answer == NULL){
        printf("memory allocation failed \n");
        return NULL; 
    }
    
    for(int i=0; i<n; i++){
        answer[i] = num_list[i];
    }
    return answer;
}

int main(void){
    int num_list[] = {2,1,6};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]);
    int n =1;
    
    int result = solution(num_list,num_list_len, n); 
    if(result != NULL){
        printf("%d", result);
        free(result);
    } else {
        printf("memory allocation failed");
    }
    return 0;     
}