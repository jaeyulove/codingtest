#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dot_len은 배열 dot의 길이입니다.
int solution(int dot[], size_t dot_len) {
    
int answer; 
    
if(dot[0]<0 && dot[1]>0){
    answer = 2;
}
    
if(dot[0]>0 && dot[1]>0){
    answer = 1;
}
    
if(dot[0]<0 && dot[1]<0){
    answer = 3;
}
    
if(dot[0]>0 && dot[1]<0){
    answer = 4;
}
    
return answer; 
}

int main(void){
int dot[]={2,4};
size_t dot_len = sizeof(dot) / sizeof(dot[0]); 
int result = solution(dot, dot_len);
       
    printf("%d", result); 

    return 0; 
}