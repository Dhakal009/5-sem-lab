// program to implement OTP cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char pt[20], key[20], ct[20], dt[20];
    int i;

    printf("Enter the plain text: ");
    scanf("%s", pt);

    for(i=0;i<strlen(pt);i++){
        if(pt[i]==' '){
            key[i]=' ';
            continue;
        }
        else{
            key[i]=rand()%26 + 97;
        }
    }
    key[i]='\0';
    printf("Generated key: ");
    puts(key);

    

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
    