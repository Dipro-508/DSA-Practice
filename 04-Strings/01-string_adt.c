#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char str[100], upper[100], lower[100];
    int i;
    int len = 0, vowels = 0, consonants = 0, digits = 0, special = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';
    for(i = 0; str[i] != '\0'; i++)
    {
        len++;
        if(isalpha(str[i]))
        {
            char ch = tolower(str[i]);

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        else if(isdigit(str[i]))
        {
            digits++;
        }
        else if(str[i] != ' ')
        {
            special++;
        }
        upper[i] = toupper(str[i]);
        lower[i] = tolower(str[i]);
    }
    upper[i] = '\0';
    lower[i] = '\0';
    printf("\n----- String ADT -----\n");
    printf("Original String : %s\n", str);
    printf("Length          : %d\n", len);
    printf("Vowels          : %d\n", vowels);
    printf("Consonants      : %d\n", consonants);
    printf("Digits          : %d\n", digits);
    printf("Special Chars   : %d\n", special);
    printf("Uppercase       : %s\n", upper);
    printf("Lowercase       : %s\n", lower);
    return 0;
}