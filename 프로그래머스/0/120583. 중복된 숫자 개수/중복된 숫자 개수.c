#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
   int answer = 0;
    
    for(int i =0; i<array_len; i++){
       if(array[i] == n){
           answer ++;
       }
   }
    return answer;
}

int main(void){
    int array[] = {1,1,2,3,4,5}; 
    size_t array_len = sizeof(array)/sizeof(array[0]); 
    int n = 1; 
    int result = solution(array,array_len,n);

    return 0; 
}