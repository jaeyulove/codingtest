#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

int solution(const char* before, const char* after) {
    size_t b_len = strlen(before);
    size_t a_len = strlen(after);
    
    // 두 문자열의 길이가 다르면 재배열 불가
    if (b_len != a_len) {
        return 0;
    }
    
    // 각 문자의 빈도를 계산합니다.
    int frequency[26] = {0};  // 알파벳 소문자에 대한 빈도 수 배열

    for (int i = 0; i < b_len; i++) {
        frequency[before[i] - 'a']++;
        frequency[after[i] - 'a']--;
    }

    // 빈도 수가 모두 0인지 확인합니다.
    for (int i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            return 0;
        }
    }
    
    return 1;
}

int main(void){
    const char* before = "olleh";
    const char* after = "hello";
    
    int result = solution(before, after);
    printf("%d", result);  // 결과 1 출력 (olleh를 재배열하면 hello가 될 수 있습니다.)
    return 0;
}
