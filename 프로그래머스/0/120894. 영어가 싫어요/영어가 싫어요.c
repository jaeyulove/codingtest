#include <stdio.h>
#include <string.h>

// 숫자 문자열을 숫자로 변환하는 함수
int solution(const char *numbers) {
    // 숫자에 대응하는 영어 단어를 정수로 매핑하는 배열
    const char *words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int values[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int numWords = sizeof(words) / sizeof(words[0]); // 단어의 개수

    char result[51] = {0}; // 결과를 저장할 문자열
    int resultIndex = 0;
    
    while (*numbers) {
        for (int i = 0; i < numWords; i++) {
            size_t len = strlen(words[i]);
            if (strncmp(numbers, words[i], len) == 0) { // 현재 위치에서 단어와 일치하는지 확인
                result[resultIndex++] = '0' + values[i]; // 숫자를 문자로 변환하여 결과에 추가
                numbers += len; // 검색된 단어 길이만큼 포인터 이동
                break;
            }
        }
    }

    return atoi(result); // 문자열을 정수로 변환하여 반환
}

int main() {
    char input1[] = "onetwothreefourfivesixseveneightnine";
    char input2[] = "onefourzerosixseven";

    printf("%d\n", solution(input1)); // 123456789
    printf("%d\n", solution(input2)); // 14067

    return 0;
}
