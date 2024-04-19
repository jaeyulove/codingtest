#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    size_t len = strlen(my_string); 
    char* answer = (char*)malloc(sizeof(char) * len * n +1);
    if(answer == NULL){
        return NULL;
    }
    size_t k = 0; 
    for(size_t i = 0; i < len ; i++){
        for(size_t j=0; j<n; j++){
            answer[k++]=my_string[i];
        }
    }
    answer[k] = '\0';
    return answer;
}

int main(void){
    int n;
    const char* my_string = "hello";
    char* result = solution(my_string, n);

    printf("반복할 숫자를 입력하시오");
    scanf("%d", &n);

    if(result != NULL) {
        printf("%s\n", result);
        free(result);
    }
    
    return 0; 
}