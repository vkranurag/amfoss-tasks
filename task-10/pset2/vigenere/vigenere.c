#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int assign(char c)
{
    if (isupper(c))
    {
        c -= 65;
    }
    if (islower(c))
    {
        c -= 97;
    }
    return c;
}
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        int kl = strlen(k);
        for (int i = 0; i < strlen(k); i++)
        {
            if (!isalpha(k[i]))
            {
                printf("Usage: ./vigenere keyword\n");
                return 1;
            }
        }
        string text = get_string("plaintext: ");
        int textl = strlen(text);
        char cipher[textl];
        printf("ciphertext: ");
        for (int i = 0, j = 0; i < textl; i++)
        {
            int key = assign(k[j]);
            if (isupper(text[i]))
            {
                cipher[i] = (text[i] + key - 65) % 26 + 65;
                j = (j + 1) % kl;
            }
            else if (islower(text[i]))
            {
                cipher[i] = (text[i] + key - 97) % 26 + 97;
                j = (j + 1) % kl;
            }
            else
            {
                cipher[i] = text[i];
            }
            printf("%c", cipher[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }
}

