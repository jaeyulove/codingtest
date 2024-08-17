#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr1_len은 배열 arr1의 길이입니다.
// arr2_len은 배열 arr2의 길이입니다.
int solution(int arr1[], size_t arr1_len, int arr2[], size_t arr2_len){
    int answer = 0;
    int arr1_sum = 0;
    int arr2_sum = 0; 
    
    if(arr1_len>arr2_len){
        answer = 1;
    }
    else if(arr1_len<arr2_len){
        answer = -1;
    }
    else if(arr1_len == arr2_len){
        for(size_t i=0; i<arr1_len; i++){
            arr1_sum += arr1[i];
        }
        
        for(size_t j=0; j<arr2_len; j++){
            arr2_sum += arr2[j];
        }
        if(arr1_sum>arr2_sum){
            answer = 1;
        }
        else if(arr1_sum<arr2_sum){
            answer = -1;
        }
    }
    return answer;
}

int main(void){
    int arr1[]={49,13};
    int arr2[]={70,11,2};
    size_t arr1_len=sizeof(arr1)/sizeof(arr1[0]); 
    size_t arr2_len=sizeof(arr2)/sizeof(arr2[0]);
    
    int result = solution(arr1,arr1_len,arr2,arr2_len);
    printf("%d\n", result);
    return 0; 
}