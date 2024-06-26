#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    
    for(int i=0; i<array_len; i++){
        while(array[i] != 0){
            if(array[i] % 10 == 7){
                answer++;
            }
            array[i] /= 10;
        }
    }
    return answer;
}

int main(void){
    int array[] = {7,77,17};
    size_t array_len = sizeof(array)/sizeof(array[0]);
    
    int result = solution(array, array_len);
    return 0; 
}