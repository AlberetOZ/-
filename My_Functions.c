#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#define MAX_String 1024


int My_strlen (const char* str)
{ 
	int size = sizeof(*str);
	const char* temp = str; 

	while ((*str != '\0') && (*str != '\n')) {
		str++;
	} 
	return ((str - temp)/size);
}

char*  My_strncpy(char* dest, const char* str, int size)
{
	int i = 0;
	for (i = 0; i < size && str[i] != '\0'; i++)
		dest[i] = str[i];
	for (;i <= size; i++)
		dest[i] = '\0';
	return dest;
}



char* My_strncat(char *dest, const char *src, int n)
{       
        int dest_len = My_strlen(dest);
        int i = 0;


        for (i = 0 ; i < n && src[i] != '\0' ; i++)
                dest[dest_len + i] = src[i];
        dest[dest_len + i] = '\0'; 
        

        return dest;
}

const char* My_strstr(const char* str, const char* find)
{
	const char* f = &(*str);
	int i = 0, j = 0, n = My_strlen(find);
		

	for(; str[i] != '\0'; i++)
	{
		for(j = 0; str[i+j] == find[j] && j < n; j++)
		{
		}
		
		if (j == n)
			return f + i;

	} 




	return 0;
}


char* My_strtok_NULL_pointer = NULL;


char* My_strtok(char* str, const char* del)
{
	int i = 0;
	if(*str != NULL)
	{
		for (; My_strstr(del, &str[i]) == 0; i++)
		{
		}
		str[i] = '\0';
		My_strtok_NULL_pointer = &str[i+1];
		return str;
	}
	else
	{
		assert(My_strtok_NULL_pointer != NULL);
	
		str = My_strtok_NULL_pointer;
		for (; My_strstr(del, &str[i]) == 0; i++)
		{
		}
		str[i] = '\0';
		My_strtok_NULL_pointer = &str[i+1];
		return str;

	}




}




int main()
{
	char str1[MAX_String], str2[MAX_String];
	int size = 0;
	fgets (str1, sizeof(str1)-1, stdin);

	printf("strlen = %d\n",size = My_strlen(str1));

	My_strncpy(str2, str1, size);
	printf("strncpy = %s\n", str2);

	My_strncat(str2, str1, size);
	printf("strncat = %s\n",str2);

	printf("strstr = %p\n", My_strstr(str2, str1));

	printf("strtok = %s     %s       %s\n", My_strtok(str2, " ,.!"), My_strtok(NULL, " ,.!"),  My_strtok(NULL, " ,.!") );

    
 return 0;   
}
