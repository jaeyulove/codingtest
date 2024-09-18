#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 

int solution(const char* ineq, const char* eq, int n, int m) {
    int answer = 0;
    
    if (strcmp(ineq, ">") == 0 && strcmp(eq, "=") == 0) {
        if (n >= m) {
            answer = 1;
        }
    } else if (strcmp(ineq, "<") == 0 && strcmp(eq, "=") == 0) {
        if (n <= m) {
            answer = 1;
        }
    } else if (strcmp(ineq, ">") == 0 && strcmp(eq, "!") == 0) {
        if (n > m) {
            answer = 1;
        }
    } else if (strcmp(ineq, "<") == 0 && strcmp(eq, "!") == 0) {
        if (n < m) {
            answer = 1;
        }
    }
    
    return answer;
}
    
int main(void) {
    const char* ineq = "<";
    const char* eq = "=";
    int n = 20;
    int m = 50;
    
    int result = solution(ineq, eq, n, m);
    printf("%d\n", result);
    return 0;
}
