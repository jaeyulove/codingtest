#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    
    for(int i=0; i<num_list_len; i++){
        if(num_list[i] < 0){
             return i; 
        } else {
            answer = -1;
        }
        }
    return answer;
}

int main(void){
    int num_list[] = {12, 4, 15, 46, 38, -2, 15};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    
    int result = solution(num_list,num_list_len);
    printf("%d", result); 
    return 0;
}