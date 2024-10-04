#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 문자열로 주어진 큰 수를 더하는 함수
char* solution(const char* a, const char* b) {
    // 두 문자열의 길이를 구함
    int len_a = strlen(a);
    int len_b = strlen(b);
    
    // 더 긴 길이 + 1 (올림 자리 처리) 만큼 동적 메모리 할당
    int max_len = len_a > len_b ? len_a : len_b;
    char* answer = (char*)malloc(sizeof(char) * (max_len + 2));  // +2는 자리 올림 처리
    
    int carry = 0;  // 자리 올림 처리
    int sum = 0;
    int idx = max_len;  // 인덱스는 큰 수 기준으로 맞춤
    answer[idx + 1] = '\0';  // 결과의 마지막에 NULL 문자 삽입

    // 문자열 끝에서부터 각 자리수를 더함
    len_a--;
    len_b--;
    
    while (len_a >= 0 || len_b >= 0 || carry) {
        int digit_a = (len_a >= 0) ? a[len_a--] - '0' : 0;  // 각 자리수 값 또는 0
        int digit_b = (len_b >= 0) ? b[len_b--] - '0' : 0;  // 각 자리수 값 또는 0

        sum = digit_a + digit_b + carry;  // 각 자리수 더하기 및 자리 올림 처리
        carry = sum / 10;  // 자리 올림 계산
        answer[idx--] = (sum % 10) + '0';  // 결과 배열에 한 자리수 저장
    }

    // 만약 가장 앞자리에 자리 올림이 발생했으면, idx는 0에 해당하는 위치로 이동
    if (carry) {
        answer[idx] = carry + '0';
        return answer;  // 전체 문자열 반환
    }
    
    // 앞자리에 불필요한 0이 없을 경우 answer + 1 반환
    return answer + idx + 1;
}

int main(void){
    const char* a = "18446744073709551615";
    const char* b = "287346502836570928366";
    
    char* result = solution(a, b);
    
    if(result != NULL) {
        printf("%s\n", result); 
        free(result - (result[0] == 'x' ? 1 : 0));  // 필요 시 원래 주소로 이동 후 메모리 해제
    }
    
    return 0;
}


