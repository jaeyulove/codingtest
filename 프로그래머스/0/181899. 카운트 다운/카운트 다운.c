#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int start, int end_num) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int result_len = (start-end_num)+1;
    int* answer = (int*)malloc(sizeof(int)*result_len);
    int index = 0;
    
    if(answer == NULL){
        printf("memory alloc failed");
        return NULL; 
    }
    
    for(int i=start; i>=end_num; i--){
        answer[index++] = i;  
    }
    return answer;
}

int main(void){
    int start = 10;
    int end_num = 3;
    int result = solution(start,end_num);
    int result_len = (start-end_num)+1;
    
    
    if(result != NULL){
        for(int i =0; i<result_len; i++){
            printf("%d", result);
        }
        free(result);
    } else {
        printf("memory alloc failed\n"); 
    }
    return 0;
}