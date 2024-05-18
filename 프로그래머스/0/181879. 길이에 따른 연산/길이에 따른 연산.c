#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    
    if(num_list_len>=11){
        for(int i=0; i<num_list_len; i++){
        answer += num_list[i]; 
    }
    }
    
    else if(num_list_len<=10){
        answer = 1; 
            for(int i=0; i<num_list_len; i++){
                answer *= num_list[i]; 
            }
        }
    return answer;
}

int main(void){
    int num_list[] = {3, 4, 5, 2, 5, 4, 6, 7, 3, 7, 2, 2, 1};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int result = solution(num_list, num_list_len); 
    printf("%d", result);
    return 0; 
}