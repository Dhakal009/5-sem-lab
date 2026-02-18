// program to implement vernam cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char pt[20], key[20], ct[20], dt[20];
    int i;

    printf("Enter the plain text: ");
    gets(pt);

    printf("Enter the key: ");
    gets(key);


    int lenkey = strlen(key);
    int lenpt = strlen(pt);
    int z = 0;
    for (i = lenkey;i<lenpt;i++){
        if(pt[i]==' '){
            key[i]=' ';
            continue;
        }
        else{
            key[i]=key[z];
            z++;
        }
    }
    key[i]='\0';

    puts(key);

    if (strlen(pt) != strlen(key))
    {
        printf("Length of key and plaintext do not match.\n");
        return 1;
    }

    printf("\n................ Encryption Process ................\n");
    printf("Plaintext: ");
    puts(pt);
    printf("\nKey: ");
    puts(key);

    for (i = 0; i < strlen(pt); i++)
    {
        ct[i] = (((pt[i] - 97) + key[i] - 97) % 26) + 65;
    }
    ct[i] = '\0';
    printf("Ciphertext: ");
    
    puts(ct);

    printf("\n................ Decryption Process ................\n");
    printf("Ciphertext: ");
    puts(ct);
    printf("\nKey: ");
    puts(key);

    for (i = 0; i < strlen(ct); i++)
    {
        dt[i] = (((26 + ct[i] - 65) - key[i] + 97) % 26) + 97;
    }
    dt[i] = '\0';

    printf("Plaintext: ");
    puts(dt);

    return 0;
}
    