#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t myString_len = strlen(myString); 
    char* answer = (char*)malloc(sizeof(int)*(myString_len+1));
    char myString_cpy[myString_len];
    strcpy(myString_cpy,myString); 
    
    for(size_t i=0; i<myString_len; i++){
        if(myString_cpy[i] < 'l'){
            answer[i] = 'l'; 
        }
        else{
         answer[i]=myString_cpy[i];   
        }
    }
    answer[myString_len] = '\0';    
    return answer;
}

int main(void){
    const char* myString = "abcdevwxyz";
    char* result = solution(myString);
    
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}