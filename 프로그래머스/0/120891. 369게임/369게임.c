#include <stdio.h>
#include <stdlib.h>

int solution(int order) {
    int answer = 0;
    int currentNumber = order;

    // 각 자리수를 검사하며 3, 6, 9의 개수를 셈
    while (currentNumber > 0) {
        int digit = currentNumber % 10;  // 현재 자리수를 추출
        if (digit == 3 || digit == 6 || digit == 9) {
            answer++;  // 3, 6, 9 중 하나면 박수 치기
        }
        currentNumber /= 10;  // 다음 자리수로
    }

    return answer;
}

int main(void) {
    int order = 29423;
    int result = solution(order);
    printf("%d\n", result);  // 출력 결과: 박수 횟수

    return 0;
}

/*
29423 % 10 = 3 → 일의 자리수는 3
29423 / 10 = 2942 → 다음 숫자로 업데이트
2942 % 10 = 2 → 다음 자리수는 2
2942 / 10 = 294 → 계속해서 숫자 업데이트 
*/