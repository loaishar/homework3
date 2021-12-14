#include <stdio.h>
#define WORD 8
#define TXT 8

int main(void)
{
    char str[TXT + 1]; /* allocate one more element for terminating null-character */
    int i;
    char c;

    printf("Insert str: MAX 8 CHARS!\n\n");
    for(i = 0; i <= TXT; i++){
        c = getchar();

        if(i == TXT){
            break;
        }
        else{
            str[i] = c;
        }
    }
    str[TXT] = '\0'; /* terminate the string */

   // printf("%s\n", str);

    char word_input[WORD + 1]; 
    int n;
    char m;

    printf("Insert word_input: MAX 8 CHARS!\n\n");
    for(n = 0; n <= WORD; n++){
        m = getchar();

        if(n == WORD){
            break;
        }
        else{
            word_input[n] = m;
        }
    }
    word_input[WORD] = '\0';

    //printf("%s\n", word_input);
    func_A(str,word_input);

    
}


void func_A(char str[],char input[])
{
   int  sum_for_word=0;
   char ch;
        char letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};  
        for (int i=0; i<31; i++){
            ch=input[i];
            for (int j = 0; j < 26; j++)
            {
                if(ch==letters[j])
                sum_for_word+=j+1;
            }
            
        }
        printf("the sum is : %d",sum_for_word);
        
        
        
}