#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* my_string, const char* letter) {
	int len = strlen(my_string); 
	char* answer = (char*)malloc(len + 1);

	if (answer == NULL) {
		return NULL;
	}

	int index = 0;
	for (int i = 0; i< len; i++){
		if (my_string[i] != letter[0]) {
			answer[index++] = my_string[i]; 
		}
	}
    answer[index] = '\0'; 
	return answer;
}

int main(void) {
	const char* my_string = "abcdef";
	const char* letter = 'f'; 
	char* result = solution(my_string, letter); 

	if (result != NULL) {
		printf("%s\n", result);
	}

	else {
		printf("failed"); 
	}

	free(result);
	return 0; 
}