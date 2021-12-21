#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD 30
#define TXT 1024
int check_if_char_alphapet(char c);
int value_of_char_geo(char c)
{
    char letters_alphapet[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int j = 0; j < 52; j++)
    {
        if (j < 26)
        {
            if (letters_alphapet[j] == c)
            {

                return j + 1;
            }
        }
        else
        {
            if (letters_alphapet[j] == c)
            {
                return j - 25;
            }
        }
    }
    return 0;
}
// void print_text_from_i_to_j(char *print_text, int i, int j)
void print_text_from_i_to_j(char print_text[], int i, int j)
{
    for (int from = i; from < j; from++)
    {
        printf("%c", print_text[from]);
    }
    printf("~");
}

void text_length_geo(char *str_new, int word_length)
{
    int sum_for_word = 0;
    char ch;
    char letters[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int j = 0;
    for (int i = 0; str_new[i] != '\0'; i++)
    {
        //   if ((i > strlen(str_new)))
        //       exit;
        while ((!(check_if_char_alphapet(str_new[i]))) && (i < strlen(str_new)))
            i++;
        if ((i > strlen(str_new)))
            exit;

        for (j = i; (sum_for_word < word_length) && (str_new[j] != '\0'); j++)
        {
            sum_for_word += value_of_char_geo(str_new[j]);
        }
        if (sum_for_word == word_length)
        {
            print_text_from_i_to_j(str_new, i, j);
        }
        // i=j-1;
        sum_for_word = 0;
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
int check_if_char_alphapet(char c)
{
    char letters6[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 52; i++)

    {
        if (letters6[i] == c)
        {
            return 1;
        }
    }
    return 0;
}
// void hatbash(char *str_new2, char *word)
void hatbash(char str_new2[], char word[])
{
    int c = 0, p1, p2;
    for (int i = 0, j = 0; j < strlen(str_new2); i++, j++)
    {
        if (str_new2[j] != '~')
        {
            if (check_if_char_alphapet(str_new2[j]))
            {
                if (word[i] != str_new2[j])
                {
                    i = -1;
                }
                else
                {
                    c++;
                    if ((str_new2[j + 1] != '\0') && (word[i + 1] != '\0'))

                    {
                        if (check_if_char_alphapet(str_new2[j + 1]))
                        {
                            if (str_new2[j + 1] != word[i + 1])
                            {
                                c = 0;
                            }
                        }
                    }
                }
                if (c == 1)
                {
                    p1 = j;
                }
                if (c == strlen(word))
                {
                    p2 = j;
                    print_text_from_i_to_j(str_new2, p1, p2 + 1);
                    c = 0;
                }
            }
            else
            {
                i--;
            }
        }
        else
            break;
    }
}
char *word_for_atbash_generate(char *token_convert)
{
    char letters4[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int length_of_string2 = strlen(token_convert);
    char *word_for_atbash = malloc(sizeof length_of_string2);
    strcpy(word_for_atbash, token_convert);
    int i = 0;
    while (i < length_of_string2)
    {
        for (int j = 0; j < 52; j++)
        {
            if (word_for_atbash[i] == letters4[j])
            {
                if (j < 26)
                {
                    word_for_atbash[i] = letters4[26 - j - 1];
                    i++;
                    j = 0;
                }
                else
                {
                    word_for_atbash[i] = letters4[52 - j - 1];
                    i++;
                    j = 0;
                }
            }
        }
    }
    return word_for_atbash;
}

int check_if_char_alphapet_and_space(char c)
{
    char letters_and_space[53] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for (int i = 0; i < 53; i++)

    {
        if (letters_and_space[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

void func3(char str_new4[], char wor7[])
{
    if (str_new4)
        ;
}

/********** function to be reviewed****/
int is_included(int begin, int end, char *word6, char *str6)
{
    int c = 0;
    for (int i = 0; i < strlen(word6); i++)
    {
        for (int j = begin; j < end; j++)
        {
            if (word6[i] == str6[j])
            {
                c++;
            }
        }
    }
    for (int j = begin; j < end; j++)
    {
        for (int i = 0; i < strlen(word6); i++)
        {
            if (word6[i] == str6[j])
            {
                c++;
            }
        }
    }
    if (c / 2 == strlen(word6))
    {
        return 1;
    }

    return 0;
}
int get_spaces(int from, int to, char *str)
{
    int c = 0;
    for (int i = from; i < to; i++)
    {
        if (str[i] == ' ')
        {
            c++;
        }
    }
    return c;
}

void findAnagrams(char *str, char *word)
{
    int foll_spaces = 0;
    int number = strlen(str);
    int str_0[number];
    memset(str_0, 0, number * sizeof(str_0[0]));
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if (word[j] == str[i])
            {
                if(str_0[i]==0){
                str_0[i]++;
                // i = 0;
                }
            }
            if (foll_spaces == 0)
            {
                if (str[i] == ' ')
                {
                    str_0[i]++;
                    foll_spaces = 1;
                }
            }
        }
        foll_spaces = 0;
    }

    int p1;
    int fool = 0;
    int number_of_spaces=0;
    for (int i = 0; i < strlen(str); i += strlen(word))
    {
        for (int j = 0; j < strlen(word); j++)
        {
            if ((str_0[i + j] == 1))
            {
                fool = 1;
                p1 = i + j;
            }
            if (fool)
            {
                int v2 = p1 + strlen(word);
                int number_of_spaces = get_spaces(p1, v2, str);
                i+=number_of_spaces;
                int v = strlen(word) + number_of_spaces + p1;
                if (is_included(p1, v, word, str))
                {
                    for (int x1 = p1; x1 < v; x1++)
                    {
                        printf("%c", str[x1]);
                    }
                    printf("~");
                }
            }

            fool = 0;
        }
      int r=(strlen(word))+number_of_spaces;
    }
}
/*****o be reviewed****/



int main(void)
{

    //   printf("Insert word_input: MAX 8 CHARS!\n\n");

    /*********** thhe word input ***********************************************/

    char string2[30];
    scanf("%30s", string2);
    // str will be modified by strtok
    const char deli1[] = " ";
    const char deli2[] = "\n";
    const char deli3[] = "\t"; // deli could also be declared as [2] or as const char *. Take your pick...
    char *token;

    token = strtok(string2, deli1);
    token = strtok(string2, deli2);
    token = strtok(string2, deli3);
    int i = 0;
    // while(token[i]!='\0') {
    //     printf("%c, ",token[i]);
    //     i++;
    // }

    /****************** end word input ************************************************/
    while ((getchar()) != '\n')
        ;
   
    char string1[1024];
    //  char string1[TXT];
    scanf("%[^~]s", string1);
    i = 0;
    // while(string1[i]!='\0') {
    //      printf("%c, ",string1[i]);
    //      i++;
    // }

    printf("\n");
    /******* print function for test ********/
    //  for (int i = 0; i < 8; ++i) {
    //      printf("%c, ",string2[i]);
    //  }
    /*******end print function for test ********/

    int x = word_length_geo(token);
    printf("Gematria Sequences: ");
    text_length_geo(string1, x);
    printf("\n");

    //  for (int i = 0; i < length_of_string2; ++i)
    {
        //     printf("%c, ", word_for_atbash[i]);
    }
    /******reverse word*******/
    char *rev = malloc(sizeof token);
    int count = 0, j;
    while (token[count] != '\0')
    {
        count++;
    }
    j = count - 1;

    // reversing the string by swapping
    for (i = 0; i < count; i++)
    {
        rev[i] = token[j];
        j--;
    }
    /*****end reverse word*****/
    char *word1 = malloc(sizeof token);
    char *word2 = malloc(sizeof token);
    memmove(word1, word_for_atbash_generate(token), sizeof token);
    // printf("%s",word1);
    // free(word1);
    memmove(word2, word_for_atbash_generate(rev), sizeof token);
    // printf("%s",word2);
    // word_for_atbash_generate(rev);
    printf("Atbash Sequences: ");
    hatbash(string1, word1);
    free(word1);
    hatbash(string1, word2);
    free(word2);
    int xen = strlen(token);

    // int *ptr =
    printf("\nAnagram Sequences: ");
    findAnagrams(string1, token);
}