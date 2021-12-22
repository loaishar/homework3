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
    // printf("~");
}

void text_length_geo(char *str_new, int word_length)
{
    int first_telda = 0;
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
            first_telda++;
            if (first_telda != 1)
            {
                printf("~");
            }
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
int hatbash(char str_new2[], char word[])
{
    int first_telda = 0;
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
                    first_telda++;
                    if (first_telda != 1)
                    {
                        printf("~");
                    }
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
    return first_telda;
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

char *remove_white_spaces(char str[])
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
int not_contain_zero(int from, int to, int *arraysum2)
{
    // int n = sizeof(arraysum2) / sizeof(int);
    for (int i = from; i < to; i++)
    {
        if (arraysum2[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int exist_in_the_rext(char c, char *str, int begin, int end)
{
    for (int i = begin; i <= end; i++)
    {
        if (str[i] == c)
        {
            return 1;
        }
    }
    return 0;
}
int IsFroBeToEn_included_in_word(int begin, int end, char *str, char *word)
{
    int wordlength = strlen(word);
    for (int i = 0; i < wordlength; i++)
    {
        if (!(exist_in_the_rext(word[i], str, begin, end)))
        {
            return 0;
        }
    }
    return 1;
}
void printanagram(int *str1_0, int *str2_spaces, int length, char *str, char *word)
{
    int first_telda = 0;
    int spaces = 0;
    int c = 0, begin, end;
    int strLength = strlen(str);
    int *arrayssum = (int *)malloc(strLength * sizeof(int));
    for (int i = 0; i < strLength; i++)
        arrayssum[i] = str1_0[i] + str2_spaces[i];
    int cunter = 0;
    for (int x = 0; x < strLength; x++)
    {
        if ((arrayssum[x] == 0))
        {

            c = 0;
        }
        if ((arrayssum[x] == 2))
        {

            spaces++;
        }
        if ((arrayssum[x] == 1) && (c == 0))
        {
            begin = x;
            c++;
        }
        else
        {
            if ((arrayssum[x] == 1))
            {
                c++;
                if (c == length)
                {
                    end = x;
                    int shall = begin;
                    if (not_contain_zero(begin, end, arrayssum))
                    {
                        if (IsFroBeToEn_included_in_word(begin, end, str, word))
                        {
                            first_telda++;
                            if (first_telda != 1)
                            {
                                printf("~");
                            }
                            // printf("%d\n",begin);
                            while (begin < (end) + 1)
                            {

                                printf("%c", str[begin]);
                                begin++;
                            }
                            //  printf("~");
                        }
                        else
                        {
                            x = x - spaces - 1;
                        }
                    }
                    c = 0;
                    spaces = 0;
                }
            }
        }
    }
}

void findAnagrams(char *str, char *word)
{
    int number = strlen(str);
    char *stringa_for_rem_space = (char *)malloc(number * sizeof(char));
    strcpy(stringa_for_rem_space, str);
    char *stringa_without_spaces = (char *)malloc(number * sizeof(char));
    strcpy(stringa_without_spaces, remove_white_spaces(stringa_for_rem_space));
    free(stringa_for_rem_space);
    int *str_0 = (int *)malloc(number * sizeof(int));
    memset(str_0, 0, sizeof str_0);
    int *str_spacec = (int *)malloc(number * sizeof(int));
    memset(str_spacec, 0, sizeof str_spacec);
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == ' ')
            str_spacec[i] += 2;
        for (int j = 0; j < strlen(word); j++)
        {
            if (word[j] == str[i])
            {
                if (str_0[i] == 0)
                {
                    str_0[i]++;
                    // i = 0;
                }
            }
        }
    }
    int wl = strlen(word);
    printanagram(str_0, str_spacec, wl, str, word);
}

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
    int y = hatbash(string1, word2);
    free(word2);
    if (y == 1)
    {
        printf("~");
    }
    hatbash(string1, word1);

    free(word1);
    int xen = strlen(token);

    // int *ptr =
    printf("\nAnagram Sequences: ");
    findAnagrams(string1, token);
}