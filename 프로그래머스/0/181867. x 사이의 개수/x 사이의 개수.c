#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* myString, int* myString_len_result) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    size_t myString_len=strlen(myString); 
    int* answer = (int*)malloc(sizeof(int)*myString_len);
    size_t index = 0;
    int count = 0; 
    
    for(size_t i=0;i<myString_len; i++){
        if(myString[i] != 'x'){
            count++;  
        }
        else if(myString[i] == 'x') {
            answer[index++] = count;
            count=0;
        }
    }
     answer[index++] = count;
     //myString_len_result = index;
    return answer;
}

/*int main(void){
    const char* myString = "oxooxoxxox";
    size_t myString_len_result; 
    int* result = solution(myString, &myString_len_result);
    
    if(result != NULL){
        for(size_t i=0; i<myString_len_result; i++){
            printf("%d", result[i]);
        }
        free(result);
    }
    return 0; 
  }*/ 