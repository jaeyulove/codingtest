#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* bin1, const char* bin2) {
    size_t bin1_len = strlen(bin1);
    size_t bin2_len = strlen(bin2);
    size_t max_len = bin1_len > bin2_len ? bin1_len : bin2_len;
    char bin1_copy[50], bin2_copy[50] = {0};

    // 초기화
    strcpy(bin1_copy, bin1);
    strcpy(bin2_copy, bin2);

    // 길이 맞추기
    if (bin1_len != bin2_len) {
        if (max_len == bin1_len) {
            memmove(bin2_copy + max_len - bin2_len, bin2_copy, bin2_len);
            memset(bin2_copy, '0', max_len - bin2_len);
        } else {
            memmove(bin1_copy + max_len - bin1_len, bin1_copy, bin1_len);
            memset(bin1_copy, '0', max_len - bin1_len);
        }
    }

    char* answer = (char*)malloc(sizeof(char) * (max_len + 2));
    if (!answer) return NULL;
    int carry = 0, index = 0;

    // 이진수 덧셈 수행
    for (int i = max_len - 1; i >= 0; i--) {
        int digit1 = bin1_copy[i] - '0';
        int digit2 = bin2_copy[i] - '0';
        int sum = digit1 + digit2 + carry;
        answer[index++] = (sum % 2) + '0';
        carry = sum / 2;
    }
    if (carry) answer[index++] = '1';

    // 결과 뒤집기
    answer[index] = '\0';
    for (int i = 0; i < index / 2; i++) {
        char temp = answer[i];
        answer[i] = answer[index - 1 - i];
        answer[index - 1 - i] = temp;
    }

    return answer;
}

int main(void) {
    const char* bin1 = "10";
    const char* bin2 = "11";

    char* result = solution(bin1, bin2);
    if (result != NULL) {
        printf("%s\n", result);
        free(result);
    } else {
        printf("Memory allocation failed\n");
    }

    return 0;
}
