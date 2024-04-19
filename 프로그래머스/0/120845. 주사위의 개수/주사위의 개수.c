#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// box_len은 배열 box의 길이입니다.
int solution(int box[], size_t box_len, int n) {
    
    int answer = 1; 
    for(int i = 0; i<box_len; i++){
        answer *= box[i]/n;
    }
    return answer; 
}

int main(void){
    int box[] = {10,8,6}; 
    size_t box_len = sizeof(box)/sizeof(box[0]); 
    int n = 3;
    
    int result = solution(box, box_len, n); 
    printf("%d", result); 
    
    return 0; 
}