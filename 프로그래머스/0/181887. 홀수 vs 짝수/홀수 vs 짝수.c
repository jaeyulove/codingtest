#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    
    int answer = 0;
    int odd = 0;
    int even = 0; 
    
    for(int i =0; i<num_list_len; i++){
       if(i % 2 == 0){
           odd += num_list[i]; 
       }
        
        else if( i % 2 != 0){
            even += num_list[i];  
        }
    }
    
    if(odd>even){
        answer = odd;
    }
    
    else {
        answer = even; 
    }

    return answer;
}

int main(void){
    int num_list[] = {4, 2, 6, 1, 7, 6};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int result = solution(num_list, num_list_len);
    
    printf("%d", result); 
    return 0; 
}