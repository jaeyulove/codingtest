#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// numbers_len은 배열 numbers의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int numbers[], size_t numbers_len, const char* direction) {
    int* answer = (int*)malloc(sizeof(int)*numbers_len);
    if(answer == NULL){
        printf("메모리 할당 실패\n"); 
        return NULL;  
    }
    
    if(strcmp(direction,"right") == 0 ){
        answer[0] = numbers[numbers_len-1]; 
        for(int i=0; i<numbers_len-1; i++){
            answer[i+1] = numbers[i]; 
   }
    }
    
    else if (strcmp(direction,"left") == 0 ){
        answer[numbers_len-1] = numbers[0];
        for(int i=1; i<numbers_len; i++){
            answer[i-1] = numbers[i];
        }
    }
    
return answer;
} 

int main(void){
    int numbers[]={1,2,3}; 
    size_t numbers_len = sizeof(numbers)/sizeof(numbers[0]);
    const char* direction = "right"; 
    int* result = solution(numbers, numbers_len, direction);  
    
    if(result != NULL){
        for(int i = 0; i<numbers_len; i++){
        printf("%d", result[i]);
        free(result); 
      }
    }
    
    else{
        printf("메모리 할당 실패\n");
    }
    return 0; 
}