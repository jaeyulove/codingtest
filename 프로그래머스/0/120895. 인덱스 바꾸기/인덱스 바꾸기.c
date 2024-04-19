#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int num1, int num2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char)* len+1);
    char array[len+1];
    strcpy(answer,my_string); 
    
    char temp1 = answer[num1];
    char temp2 = answer[num2];
    
    answer[num1] = temp2;
    answer[num2] = temp1; 
 
    return answer;
}

int main(void){
    const char* my_string = "hello";
    int num1 = 1;
    int num2 = 2; 
    char result = solution(my_string, num1, num2); 
    
    if(result == NULL){
        printf("memory alloc failed");
    }
    else {
        printf("%s\n", result); 
        free(result);
    }
    return 0; 
}