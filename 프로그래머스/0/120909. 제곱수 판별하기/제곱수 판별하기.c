#include <stdio.h>
#include <math.h>

int solution(int n) {
    int root = (int)sqrt(n);  // sqrt 함수로 n의 제곱근을 계산하고 정수형으로 변환
    if (root * root == n) {  // 제곱근의 제곱이 n과 같고, 제곱근이 짝수인지 확인
        return 1;
    } else {
        return 2;
    }
}

int main(void) {
    int n = 144;  
    int result = solution(n);  
    
    printf("%d\n", result);  // 결과 출력
    return 0;
}
