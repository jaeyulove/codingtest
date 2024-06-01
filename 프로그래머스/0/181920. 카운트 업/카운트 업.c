#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int start_num, int end_num) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    size_t len = end_num - start_num; 
    int* answer = (int*)malloc(sizeof(int)* len+1);
    int index = 0;
    
    for(int i=start_num; i<end_num+1; i++){
        answer[index++] = i; 
    }
    return answer;
}

int main(void){
    int start_num = 3;
    int end_num = 10; 
    int result = solution(start_num, end_num); 
    
    printf("%d\n", result); 
}