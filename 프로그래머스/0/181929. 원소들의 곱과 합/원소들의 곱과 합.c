#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len){
    int multiply = 1;
    int sum = 0; 
    
    for(int i=0; i<num_list_len; i++){
        multiply *= num_list[i];
    }
    
    for(int j=0; j<num_list_len; j++){
        sum += num_list[j]; 
    }
    
    if(multiply < sum*sum){
        return 1; 
    }
    
    else if(multiply >= sum*sum) {
        return 0; 
    }
}

int main(void){
    int num_list[] = {3,4,5,2,1}; 
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int result = solution(num_list, num_list_len); 
    printf("%d\n", result); 
}