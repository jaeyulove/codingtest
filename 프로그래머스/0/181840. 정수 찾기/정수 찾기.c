#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int num_list[], size_t num_list_len, int n) {
    for (int i=0; i<num_list_len; i++){
        if(num_list[i] == n){
            return 1;
        }
    }
    return 0;
}

int main(void){
    int num_list[] = {1,2,3,4,5};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int n = 3;
    int result = solution(num_list,num_list_len,n);
    
    printf("%d", result);
    return 0; 
}