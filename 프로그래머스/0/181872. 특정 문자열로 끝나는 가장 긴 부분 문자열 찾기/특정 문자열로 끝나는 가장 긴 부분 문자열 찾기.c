#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* myString, const char* pat) {
    size_t myString_len = strlen(myString); 
    char* answer = (char*)malloc(sizeof(char) * (myString_len + 1));
    char* pos = strstr(myString, pat);
    char* last_occurrence = NULL;

    while (pos != NULL) {
        last_occurrence = pos;  
        pos = strstr(pos + 1, pat); // 다음 위치에서 pat가 있는지 찾기 위해 
    }
    
    if (last_occurrence != NULL) {
        size_t result_len = last_occurrence - myString + strlen(pat); //4+2 = 6
        strncpy(answer, myString, result_len);
        answer[result_len] = '\0';
    } else {
        strcpy(answer, myString);
    }

    return answer;
}

int main(void) {
    const char* myString1 = "AbCdEFG";
    const char* pat1 = "dE";
    char* result1 = solution(myString1, pat1);
    printf("%s\n", result1); 
    free(result1);

    return 0;
}
