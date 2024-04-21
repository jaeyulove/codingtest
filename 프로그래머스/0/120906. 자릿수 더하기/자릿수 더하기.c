#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int* array = (int*)malloc(sizeof(int)*100);
    int index = 0;
    
    while(n != 0){
        array[index++] = n % 10; 
        n = n/10;
    }
    
    int answer = realloc(array,sizeof(int)*index);
    
    int final_answer = 0; 
    for(int i =0; i<index; i++){
        final_answer += array[i]; 
    }
    
    return final_answer; 
}

int main(void){
    int n = 1234;
    int result = solution(n);
    
    printf("%d", result);
    return 0; 
}