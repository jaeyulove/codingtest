#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* order = "abcdefghijklmnopqrstuvwxyz"; 
    size_t order_len = strlen(order);
    size_t len = strlen(s);
    char* answer = (char*)malloc(sizeof(char)* (len+1));
    
    int index = 0; 
    
    for(size_t i=0; i<len; i++){
        int count = 0;
        for(size_t j=0; j<len; j++){
            if(s[i] == s[j]){
                count++; 
            }   
        } 
          if (count == 1){
            answer[index++] = s[i];
            }  
    }
    
    char* resized = realloc(answer, sizeof(char)* index); 
    
    if(resized != NULL){
        answer = resized; 
    }
      for (size_t i = 0; i < index - 1; i++) {
        for (size_t j = 0; j < index - i - 1; j++) {
            if (answer[j] > answer[j + 1]) {
                char temp = answer[j];
                answer[j] = answer[j + 1];
                answer[j + 1] = temp;
            }
        }
    }
    answer[index] = '\0';
    return answer;
}

int main(void){
    const char* s = "abcabcadc";
    char* result = solution(s);
    
    if(result == NULL){
        printf("memory alloc failed");
    }
    else {
        printf("%s", result);
        free(result);
    }
    return 0;
}