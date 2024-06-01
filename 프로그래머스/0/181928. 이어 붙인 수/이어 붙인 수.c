#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h> 

int solution(int num_list[], size_t num_list_len) {
    
    int even = 0;
    int odd = 0;
    int digit_even = 1;
    int digit_odd = 1;

    // 짝수와 홀수를 각기 다른 수로 만들기
    for(int i = num_list_len - 1; i >= 0; i--){
        if(num_list[i] % 2 == 0){
            even += num_list[i] * digit_even;
            digit_even *= 10;
        }
        else {
            odd += num_list[i] * digit_odd;
            digit_odd *= 10;
        }
    }
    
    int answer = even + odd; 
    return answer;
}

int main(void){
    int num_list[] = {3, 4, 5, 2, 1}; 
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]); 
    int result = solution(num_list, num_list_len);
    
    printf("%d\n", result); 
    return 0;
}
