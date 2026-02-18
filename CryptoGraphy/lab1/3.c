// program to implement hill cipher

#include <stdio.h>
#include <string.h>

int main()
{
    char pt[20], key[20][20], ct[20], dt[20];
    int i, m, n, j;

    printf("Enter the plain text: ");
    gets(pt);
    printf("Enter the size of key matrix (m n): ");
    scanf("%d%d", &m, &n);
    printf("enter the key matrix: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    printf("\n................ Encryption Process ................\n");
    printf("Plaintext: ");
    puts(pt);
    int len = strlen(pt);
    int k, sum=0;
    printf("\nKey: \n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }
    for(i = 0; i < len; i += n)
    {
        for (j = 0; j < n; j++)
        {
            sum = 0;
            for (k = 0; k < n; k++)
            {
                sum += (pt[i + k] - 'a') * key[k][j];
            }
            ct[i + j] = (sum % 26) + 'A';
        }
    }

    ct[len] = '\0';
    printf("Ciphertext: ");
    puts(ct);
    printf("\n................ Decryption Process ................\n");
    printf("Ciphertext: ");
    puts(ct);
    printf("\nKey: ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            dt[i] = ((key[i][j] - 97) * (ct[j] - 97)) % 26 + 97;
        }
    }
    dt[i] = '\0';
    printf("Decrypted Text: ");
    puts(dt);
    return 0;
}