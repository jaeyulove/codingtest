#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* strArr[], size_t strArr_len) {
    int length_count[31] = {0};  
    
    // 각 문자열의 길이를 카운트
    for (size_t i = 0; i < strArr_len; i++) {
        int len = strlen(strArr[i]);  // 문자열의 길이
        length_count[len]++;  // 해당 길이의 카운트를 증가
    }
    
    // 가장 큰 그룹의 크기 찾기
    int max_count = 0;
    for (int i = 1; i <= 30; i++) {
        if (length_count[i] > max_count) {
            max_count = length_count[i];  
        }
    }
    return max_count;  // 가장 큰 그룹의 크기를 반환
}

int main(void) {
    const char* strArr[] = {"a","bc","d","efg","hi"};
    size_t strArr_len = sizeof(strArr) / sizeof(strArr[0]);
    
    int result = solution(strArr, strArr_len);
    printf("%d\n", result);  // 결과 출력
    return 0;
}
