#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
  int num1 =1; 
  for(int i=1; i<=10; i++){
      num1 *= i;
      if(num1>n){
          return i-1;
      }
      
      else if(num1 == n){
          return i;
      }
  }
}

int main(void){
    int n = 7;
    int result = solution(n);
    
    printf("%d", result); 
    return 0; 
}