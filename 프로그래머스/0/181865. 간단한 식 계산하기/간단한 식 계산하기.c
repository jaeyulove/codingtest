#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* binomial) {
    // 문자열 복사
    char binomial_cpy[100];
    strcpy(binomial_cpy, binomial);
    
    // 문자열 분할
    char *tokens[3];
    char *ptr = strtok(binomial_cpy, " ");
    
    int i = 0;
    while(ptr != NULL && i < 3) {
        tokens[i++] = ptr;
        ptr = strtok(NULL, " ");
    }
    
    // a, b 및 op 추출
    int a = atoi(tokens[0]);
    char op = tokens[1][0];  // 문자열의 첫 번째 문자를 사용
    int b = atoi(tokens[2]);
    
    // 연산 수행
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '*') {
        return a * b;
    }
    
    return 0; // 기본 반환 값 (이 경우는 발생하지 않음)
}

int main(void) {
    const char* binomial = "43 + 12"; 
    int result = solution(binomial); 
    printf("%d\n", result); // 55 출력
    return 0; 
}
