#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// order_len은 배열 order의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* order[], size_t order_len) {
    int answer = 0;
    
    const char* americano[] = {"americano","iceamericano", "americanohot", "hotamericano", "americanoice", "anything"}; 
    const char* latte[] = {"cafelatte", "icecafelatte", "cafelatteice", "hotcafelatte", "cafelattehot"}; 
    size_t americano_len = sizeof(americano)/sizeof(americano[0]);
    size_t latte_len = sizeof(latte)/sizeof(latte[0]); 
    
    for(size_t i=0; i<order_len; i++) {
        for(size_t j=0; j<americano_len; j++) {
            if(strcmp(order[i] ,americano[j]) == 0) {
                answer += 4500;
            }
        }
        
        for(size_t k=0; k<latte_len; k++) {
            if(strcmp(order[i] ,latte[k]) == 0) {
                answer += 5000; 
            }
           }
        }
    return answer;
}

int main(void) {
    const char* order[] = {"cafelatte", "americanoice", "hotcafelatte", "anything"};
    size_t order_len = sizeof(order)/sizeof(order[0]); 
    
    int result = solution(order,order_len); 
    printf("%d", result);
    return 0; 
}