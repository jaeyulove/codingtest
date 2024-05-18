#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int* solution(int num_list[], size_t num_list_len, int n, int answer_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int)*answer_len);
    int index = 0; 
    
    for(int i =0; i<num_list_len; i++){
        answer[index++] = num_list[i]; 
        i += n-1; 
    }
    return answer;
}

int main(void){
    int num_list[] = {4, 2, 6, 1, 7, 6};
    int num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int n = 2; 
    int answer_len = num_list_len/n;
    int* result = solution(num_list,num_list_len, n, answer_len); 
     
    
    if(result != NULL){
        for(int i=0; i<answer_len; i++){
            printf("%d", result[i]); 
        }
        free(result); 
    } else {
        printf("memory allocation failed");
    }
    return 0; 
}