#include <stdio.h>

int contains_three(int num) {
    while (num > 0) {
        if (num % 10 == 3) { //num의 1의 자리가 3인지 확인 
            return 1;
        }
        num /= 10; // 그 다음 자리수로 이동 
    }
    return 0;
}

int solution(int n) {
    int count = 0;
    int num = 1;

    while (count < n) {
        if (contains_three(num) || num % 3 == 0) {
            num++;
            continue;
        }

        count++;
        if (count == n) { //3의 배수와 숫자 3을 제외시킨 n번째 값을 만나면 num을 반환 
            return num;
        }
        num++;
    }
    return -1; 
}

int main() {
    printf("%d\n", solution(15));  
    return 0;
}
