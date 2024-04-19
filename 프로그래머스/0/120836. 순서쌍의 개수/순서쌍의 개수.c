#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h> // sqrt 함수 사용을 위해 추가

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){ // n이 i로 나누어떨어지면, 순서쌍이 존재함
            if(i * i == n){ // 순서쌍이 (i, i)인 경우, 즉 i가 sqrt(n)일 때
                answer += 1;
            } else {
                answer += 2; // (i, n/i)와 (n/i, i) 두 순서쌍이 가능
            }
        }
    }
    return answer;
}

int main(void){
    int n = 20; 
    int result = solution(n);
    
    printf("%d", result); // 6 출력 예상
    return 0; 
}
