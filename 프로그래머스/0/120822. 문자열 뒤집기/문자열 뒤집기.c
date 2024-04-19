#include<stdio.h>
#include<string.h>

char* solution(const char* my_string){
	size_t len = strlen(my_string); 
	char* reversed = (char*)malloc(len + 1);

	if (reversed == NULL) {
		return NULL; 
	}

	for (size_t i = 0; i < len; i++) {
		reversed[i] = my_string[len - i - 1];
	}
	
	reversed[len] = '\0';

	return reversed; 
}


int main(void) {
	const char* my_string = "jaron";
	char* reversed_string = solution(my_string);

	if (reversed_string != NULL) {
		printf("Original: %s\n", my_string);
		printf("Reversed: %s\n", reversed_string);

		free(reversed_string);
	}
	else {
		printf("Memory allocation failed.\n");
	}	
	return 0; 
}
