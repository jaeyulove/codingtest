#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int* answer = (int*)malloc(sizeof(int)*100);
    if(!answer) {
        printf("memory alloc failed"); 
        free(answer);
        return -1; 
    }
    int index = 0;
    
    while(n != 0){
        answer[index++] = n % 10; 
        n = n/10;
    }
    
    int* temp = realloc(answer,sizeof(int)*index);
    if(!temp){
        printf("memory alloc failed");
        free(answer);
        return -1; 
    }
    answer = temp; 
    
    int final_answer = 0; 
    for(int i =0; i<index; i++){
        final_answer += answer[i]; 
    }
    
    return final_answer; 
}

int main(void){
    int n = 1234;
    int result = solution(n);
    
    printf("%d", result);
    return 0; 
}
