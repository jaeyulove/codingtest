#include <stdio.h>
#include <stdlib.h>

int solution(int array[], size_t len, int n) {
    if (len == 0) {
        // 배열이 비어 있는 경우 적절한 값 반환
        return -1;
    }
    
    int closest = array[0];
    int minDiff = abs(array[0] - n);

    // 배열을 순회하면서 n과 가장 가까운 수를 찾는다.
    for (int i = 1; i < len; i++) {
        int currentDiff = abs(array[i] - n);
        if (currentDiff < minDiff) {
            // 더 작은 차이가 발견되면 정보 갱신
            minDiff = currentDiff;
            closest = array[i];
        } else if (currentDiff == minDiff) {
            // 같은 차이가 있을 경우 더 작은 수를 선택
            if (array[i] < closest) {
                closest = array[i];
            }
        }
    }
    return closest;
}

int main(void) {
    int array[] = {3, 10, 28, 20};
    size_t len = sizeof(array) / sizeof(array[0]);
    int n = 20;
    int result = solution(array, len, n);
    printf("The closest number to %d is %d\n", n, result);  // 결과 출력
    
    return 0;
}
