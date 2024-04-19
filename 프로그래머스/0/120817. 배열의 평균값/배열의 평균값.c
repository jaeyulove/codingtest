#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
double solution(int num[], size_t num_len){
    int i;
    double temp=0;
    
 for(i=0; i<num_len; i++){
     temp += num[i];
 }
    return temp/num_len;
}

int main(void){

    int num[]={1,2,3,4,5,6,7,8,9,10}; //첫번째 입출력 
    size_t num_len=sizeof(num)/sizeof(num[0]);
    double result; 
     
    result = solution(num, num_len);
    printf("%.2f", result); 
    
    int num2[]={89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99}; //두번째 입출력 
    size_t num_len2=sizeof(num2)/sizeof(num2[0]);
    
    result = solution(num2, num_len2);
    printf("%.2f", result);
    
return 0; 
}