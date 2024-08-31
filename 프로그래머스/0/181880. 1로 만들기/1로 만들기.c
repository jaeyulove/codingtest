#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    
    for(size_t i=0; i<num_list_len; i++){
        while(num_list[i] != 1){
            if(num_list[i] % 2 != 0){
                num_list[i] = (num_list[i]-1)/2; 
            }
                else if(num_list[i] % 2 == 0){
                    num_list[i] = num_list[i]/2; 
                }
            answer++;
            }
        }
        return answer;
    }

int main(void){
    int num_list[] = {12, 4, 15, 1, 14};
    size_t num_list_len = sizeof(num_list)/sizeof(num_list[0]);
    int result = solution(num_list, num_list_len);
    printf("%d", result);
    return 0;
}