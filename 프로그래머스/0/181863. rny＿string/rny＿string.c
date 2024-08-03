#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rny_string){
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t rny_string_len = strlen(rny_string); 
    size_t max_len = (rny_string_len * 2) + 1 ;
    char rny_string_cpy[100]; 
    strcpy(rny_string_cpy, rny_string); 
    char* answer = (char*)malloc(sizeof(char)*(max_len));
                                 
    if(answer == NULL){
        printf("memory allocation failed!"); 
        return NULL; 
    }
    
    size_t j = 0; 
    for(size_t i=0; i<rny_string_len; i++){
        if(rny_string[i] =='m'){
        answer[j++] = 'r';
        answer[j++] = 'n';
        }
    else {
        answer[j++] = rny_string[i];
    }
    }
    answer[j] = '\0'; 
    
   /* char* ptr = strstr(rny_string_cpy, "m"); 
    
    if(ptr) {
        strncpy(ptr, "rn", 2); 
    }
    answer = rny_string_cpy; 
*/
    return answer;
}

int main(void){
    const char* rny_string = "masterpiece"; 
    const char* result = solution(rny_string);
    
    if(result != NULL){
        printf("%s\n", result); 
        free(result);
    } else {
        printf("memory allocation failed!"); 
    }
    
    return 0; 
}