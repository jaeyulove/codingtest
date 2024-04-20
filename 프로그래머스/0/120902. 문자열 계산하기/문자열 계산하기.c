#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* my_string) {
    char buffer[101];  // 문자열 길이 제한 +1 (null-terminator)
    strcpy(buffer, my_string);  // 문자열 복사

    char* token = strtok(buffer, " ");
    int answer = atoi(token);

    while ((token = strtok(NULL, " ")) != NULL) {
        char op = token[0];  // 연산자 읽기
        token = strtok(NULL, " ");
        int num = atoi(token);  // 다음 숫자 읽기

        if (op == '+') {
            answer += num;
        } else if (op == '-') {
            answer -= num;
        }
    }

    return answer;
}

int main() {
    const char* my_string = "3 + 4 - 5 + 6";
    int result = solution(my_string);
    printf("Result: %d\n", result);
    return 0;
}
