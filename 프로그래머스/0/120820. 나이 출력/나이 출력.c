#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int age) {
        return 2022-age+1;
}

int main(void) {
    int age;
    int result;

    // 예시 1
    age = 40;
    result = solution(age);
    printf("%d", result);

    // 예시 2
    age = 23;
    result = solution(age);
    printf("%d", result);

    return 0;
}
