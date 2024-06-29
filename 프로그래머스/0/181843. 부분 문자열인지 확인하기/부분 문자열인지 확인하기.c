#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* my_string, const char* target) {
    char answer; 
    answer = strstr(my_string, target); 
    if(answer == NULL){
        return 0;
    }
    else {
        return 1; 
    }
}

int main(void){
    const char* my_string = "banana";
    const char* target = "ana";
    int result = solution(my_string, target);
    printf("%d", result);
    return 0; 
}