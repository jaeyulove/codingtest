#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int s, int e) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t my_string_len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char)*my_string_len+1);
    int index = 0;
    
    if(s != 0){
    for(int i=0; i<s; i++){
        answer[index++] = my_string[i]; 
     }
   }
    
    for(int j=e; j>=s; j--){
        answer[index++] = my_string[j];
    }
    
    if(my_string_len>e){
        for(int k=e+1; k<my_string_len; k++){
            answer[index++] = my_string[k]; 
        }
    }
    answer[my_string_len] = '\0';
    return answer;
}

int main(void){
    const char* my_string = "Progra21Sremm3";
    int s = 6;
    int e = 12; 
    
    char* result = solution(my_string,s,e);
    if(result != NULL){
        printf("%s\n", result);
        free(result);
    }
    return 0; 
}