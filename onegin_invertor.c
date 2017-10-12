#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<assert.h>
#define MAX_STRINGS 1024
#define MAX_SYMBOLS 128

int main() {
	int i = 0;
	char str[MAX_STRINGS][MAX_SYMBOLS];
	FILE *input, *output;
        input = fopen ("input","r");
        output = fopen ("output","w");
        
	assert(input);
	assert(output);
	assert(!ferror(input));
	assert(!ferror(output));


	for(;fgets(str[i], sizeof(str) - 1, input);i++)
	{

	}

	for(; i >= 0;i--)
	{
		fprintf(output, "%s", str[i]);

	}




	fclose (output);
	fclose (input);

	return 0;
}
