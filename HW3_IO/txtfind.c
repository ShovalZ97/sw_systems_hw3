#include <stdio.h>
#include <string.h>

//Max char per line
#define LINE 256
//Max char per word
#define WORD 30

//read one line from the input
//return total char (count)
int get_line(char s[])
{
	int i = 0;
	int count = 0;
	for (i = 0; i < LINE; ++i)
	{
		if (scanf("%c", &(*(s + i))) == EOF)
		{
			*(s + i) = '\0';
			break;
		}

		if (*(s + i) == '\n' || *(s + i) == '\0')
		{
			break;
		}


		count++;
	}

	return count;
}

//read one word from the input
//return total char (count)
int getword(char w[])
{
	int count = 0;
	for (int i = 0; i < WORD; ++i)
	{
		if (scanf("%c", &(*(w + i))) == EOF)
		{
			*(w + i) = '\0';
			break;
		}
		if (*(w + i) == '\n' || *(w + i) == '\t' || *(w + i) == ' ')
		{

			*(w + i) = '\0';
			break;
		}
		count++;
	}
	return count;
}

//Checks if the string is a substring of another string.
int substring(char* str1, char* str2)
{
    int i,j;
    for (i = 0; i <= strlen(str1)-strlen(str2) ; i++)
    {
       	int count = 0;
        for (j = 0; j <= strlen(str2); ++j)
        {
            if (str1[i+j] == str2[j])
                count++;
        }

        if (count >= strlen(str2))
            return 1;
    }
	return 0;
}

// Checks if the string is similar to other string
int similar (char *s, char *t, int n)
{
   	if (strlen(s)- strlen(t) != n)
        return 0;
	int i;
    for(i=0 ; i<=n; i++)
	{
        while (*s && *t && *s == *t)
		{
        	s++;
            t++;
        }
        if(*s==0&&*t==0)
		{
            return 1;
        }
        s++;

    }
    return 0;
}

//Prints all the lines that contains a substring of the word.
void print_lines(char* str)
{
	char line[LINE] = { 0 };

	while (get_line(line) != 0)
	{
		if (substring(line, str))
			printf("%s", line);
	}
}

// Prints all the words that are similar to the word
void print_similar_words(char* str)
{
	char word[WORD] = { 0 };

	while (getword(word) != 0)
	{
		if (similar(word, str, 0) || similar(word, str, 1))
		{
			printf("%s\n", word);
		}
	}

}

int main()
{
	char word[WORD];
	char choose;
   
	getword(word);
	scanf(" %c\n", &choose);

	if (choose == 'a')
	{
		print_lines(word);
	}

	else if (choose == 'b')
	{
		print_similar_words(word);
	}

	return 0;
}