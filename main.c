#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 8
#define TXT 8
int value_of_char_geo(char c)
{
    char letters_alphapet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int j = 0; j < 52; j++)
    {
        if (j < 26)
        {
            if(letters_alphapet[j]==c)
            {
                 
                return j+1;
            }
        }
        else
        {
            if(letters_alphapet[j]==c)
            {
                return j-25;
            }
        }
    }
    return 0;
}
void print_text_from_i_to_j(char* print_text,int i, int j){
for (int from = i; from < j; from++)
{
    printf("%c",print_text[from]);
}
printf("\n");

}

int text_length_geo(char *str_new)
{
    int sum_for_word = 0;
    char ch;
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int j = 0;
    for (int i = j; str_new[i] != '\0'; i++)
    {
        for( j = 0; sum_for_word<=8; j++)
        {
          sum_for_word+=value_of_char_geo(str_new[j]);

        }
        print_text_from_i_to_j(str_new,i,j);
        i=j;
    }
    
}

int word_length_geo(char *str_new2)
{
    int sum_for_word = 0;
    char ch;
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 30; i++)
    {
        ch = *(str_new2 + i);
        if (!(ch))
            break;
        for (int j = 0; j < 52; j++)
        {
            if (j < 26)
            {
                if (ch == letters[j])
                {
                    sum_for_word += j + 1;
                    break;
                }
            }
            else
            {
                if (ch == letters[j])
                {
                    sum_for_word += j - 25;
                    break;
                }
            }
        }
    }
    return sum_for_word;
}
char *new_words(int newsize)
{

    char *str = (char *)malloc((newsize + 1) * sizeof(char));
    int i;
    char c;
    for (i = 0; i <= newsize; i++)
    {
        // scanf("");

        if (i == newsize)
        {
            break;
        }
        else
        {
            str[i] = c;
        }
    }
    str[newsize] = '\0'; /* terminate the string */

    return str;
}

int main(void)
{
    printf("Insert str: MAX 8 CHARS!\n\n");
    char string1[TXT];
    scanf("%8s", string1);
    // for (int i = 0; i < 8; ++i) {
    //      printf("%c, ",string1[i]);
    //  }

    printf("Insert word_input: MAX 8 CHARS!\n\n");
    char string2[WORD];
    scanf("%8s", string2);

    //  for (int i = 0; i < 8; ++i) {
    //      printf("%c, ",string2[i]);
    //  }
    // text_length_geo(string1);
    int x = word_length_geo(string2);
    printf("\n%d\n", x);
    text_length_geo(string1);
}
