#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void bubblesort(int arr[], size_t n){
    int i,j,temp;
    
    for(i=0; i<n-1; i++){
        
        for(j=0; j<n-i-1; j++){
            
            if(arr[j]> arr[j+1]){
                temp = arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1] = temp;
            }
        }
    }
}
int solution(int array[], size_t array_len) {
 bubblesort(array, array_len);
 return array [array_len / 2];
}

int main() {
    int arr[] = {3, 1, 2, 5, 4};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    printf("중간값은 %d입니다.\n", solution(arr, n));
    return 0;
}