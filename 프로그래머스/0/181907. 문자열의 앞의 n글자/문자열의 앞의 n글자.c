#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int n) {
    // n개의 문자를 저장할 공간 + null 문자 공간 할당
    char* answer = (char*)malloc((n + 1) * sizeof(char));
    if (answer == NULL) {
        return NULL;
    }
    
    for(int i = 0; i < n; i++) {
        answer[i] = my_string[i];
    }
    answer[n] = '\0'; 

    return answer;
}

int main(void) {
    const char* my_string = "ProgrammerS123"; 
    int n = 11;
    char* result = solution(my_string, n);
    
    if(result != NULL) {
        printf("%s\n", result);
        free(result); 
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
