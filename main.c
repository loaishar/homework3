#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 30
#define TXT 1024
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

int text_length_geo(char *str_new,int word_length)
{
    int sum_for_word = 0;
    char ch;
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int j = 0;
    for (int i = j; str_new[i] != '\0'; i++)
    {
        for( j = i; sum_for_word<word_length; j++)
        {
          sum_for_word+=value_of_char_geo(str_new[j]);

        }
        print_text_from_i_to_j(str_new,i,j);
        i=j-1;
        sum_for_word=0;
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
   

 //   printf("Insert word_input: MAX 8 CHARS!\n\n");
    
    

/*********** thhe word input ***********************************************/
    
    char string2[30];
    printf("\n\n enter text\n");
        scanf("%30s", string2);
    // str will be modified by strtok
    const char deli1[] = " ";
    const char deli2[] = "\n";
    const char deli3[] = "\t";   // deli could also be declared as [2] or as const char *. Take your pick...
    char *token;

    token = strtok(string2, deli1);
    token = strtok(string2, deli2);
    token = strtok(string2, deli3);
    int i=0;
   // while(token[i]!='\0') {
     //     printf("%c, ",token[i]);
     //     i++;
     // }
      
/****************** end word input ************************************************/
while ((getchar()) != '\n');
 printf("Insert str: MAX 8 CHARS!\n\n");
    char string1[1024];
  //  char string1[TXT];
    scanf("%[^~]s", string1);
     i=0;
     //while(string1[i]!='\0') {
     //     printf("%c, ",string1[i]);
     //     i++;
      //}





    //  for (int i = 0; i < 8; ++i) {
    //      printf("%c, ",string2[i]);
    //  }
    int x = word_length_geo(token);
    text_length_geo(string1,x);
}
