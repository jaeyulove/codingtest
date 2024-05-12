#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int num, int total) {
    int* answer = (int*)malloc(sizeof(int)*num);
    int mid = total/num; 
    
    if(num % 2 !=0){
    for(int i=0; i<num; i++){
        answer[i] = mid+i-(num/2);
     }
    }
    else if(num % 2 == 0){
    for(int i=0; i<num; i++){
        answer[i] = mid+i-(num/2-1);
     }
    }
    return answer;
}

int main(void){
    int num = 3;
    int total = 12;
    int* result = solution(num,total); 
    
    if(result == NULL){
        printf("memory alloc faield");
    }
    
    for(int i=0; i<num; i++){
    printf("%d", result[i]);
    free(result);
    }
    return 0; 
}