// 2 tah output

#include<stdio.h>
#include<string.h>
int main(){
    char pt[20], ct[20];
    int key, i;
    printf("enter the plain text: ");
    gets(pt);
    printf("enter the value of key: ");
    scanf("%d", &key);

    printf("\n..........................Encryption Process....................\n");
    printf("\nPlaintext: ");
    puts(pt);
    printf("Key: %d\n", key);

    for (i = 0; i < strlen(pt); i++)
    {
        if(pt[i]==' '){
            ct[i] = ' ';
            continue;
        }
        ct[i] = (((pt[i] - 97) + key) % 26) + 65;
    }
    printf("Ciphertext: ");
    puts(ct);

    printf("\n.........................Decryption Process....................\n");
    printf("Ciphertext:");
    puts(ct);
    printf("\nkey: %d\n", key);
    for (i = 0; i < strlen(pt); i++)
    {
        if (pt[i] == ' ')
        {
            ct[i] = ' ';
            continue;
        }
        ct[i] = (((26 + ct[i] - 65) - key) % 26) + 97;
    }

    printf("Plaintext: ");
    puts(pt);

    return 0;
}