#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int max_find(int sides, size_t sides_len){
    return sides;
}

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int max = max_find(sides, sides_len);
   
     for(int i=0; i<sides_len; i++){
        if(sides[i]>sides[i+1]){
            int temp = sides[i];
            sides[i] = sides[i+1];
            sides[i+1] = temp;
        }
    }
    
    if(sides[2]>= sides[0]+sides[1]){
        return 2;
    }
    else {
        return 1; 
    }
}

int main(void){
    int sider[]={1,2,3};
    size_t len = sizeof(sider)/sizeof(sider[0]);
    int result = solution(sider, len);
    
    printf("%d", result);
    return 0; 
}