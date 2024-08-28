#include <stdio.h>
#include <string.h>

// 문자열 내에서 패턴이 몇 번 나타나는지 세는 함수
int solution(const char* myString, const char* pat) {
    int answer = 0;
    size_t myString_len = strlen(myString);
    size_t pat_len = strlen(pat);

    for (size_t i = 0; i < myString_len; i++) {
        // 부분 문자열이 패턴과 일치하는지 확인
        if (strncmp(&myString[i], pat, pat_len) == 0) {
            answer++;
        }
    }

    return answer;
}

int main(void) {
    const char* myString = "bananaanaana";
    const char* pat = "ana";
    int result = solution(myString, pat);
    
    printf("%d\n", result);  // 예상 출력: 3
    return 0;
}
