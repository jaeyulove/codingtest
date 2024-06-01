#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*num_list_len+1);
    
    if(answer == NULL){
        printf("memory allocation failed"); 
        return -1; 
    }
    
    for(int i=0; i<num_list_len; i++){
        answer[i] = num_list[i]; 
    }
    
    if(num_list[num_list_len-1] > num_list[num_list_len-2]){
        answer[num_list_len] = num_list[num_list_len-1] - num_list[num_list_len-2]; 
    }
    
    else if(num_list[num_list_len-1] <= num_list[num_list_len-2]){
        answer[num_list_len] = num_list[num_list_len-1]*2; 
    }
    
    return answer;
}

int main(void){
    int num_list[] = {2,1,6}; 
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    
    int result = solution(num_list, num_list_len); 
    
    if(result != NULL){
        for(int i =0; i<num_list+1; i++){
          printf("%4d", result);
        }
        free(result); 
    }
    return 0; 
}