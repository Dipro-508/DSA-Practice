#include <stdio.h>
int main()
{
    char str[100];
    int freq[256] = {0};
    int unique = 1;
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        unsigned char c = str[i];

        freq[c]++;

        if(freq[c] > 1)
        {
            unique = 0;
            break;
        }
    }

    if(unique)
        printf("All characters are unique.\n");
    else
        printf("Characters are not unique.\n");

    return 0;
}