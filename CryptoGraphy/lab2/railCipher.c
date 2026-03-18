// WAP To implement Rail Fence Cipher technique.
#include <stdio.h>
#include <string.h>

int main()
{
    char pt[100], ct[100], dt[100];
    int i, j, k, rails, len;

    printf("Enter Plain Text:");
    scanf("%s", pt);
    printf("Enter Number of Rails:");
    scanf("%d", &rails);

    len = strlen(pt);

    printf("\n..............Encryption Process..............\n");
    printf("\nPlain Text:");
    puts(pt);


    k = 0;
    for (i = 0; i < rails; i++)
    {
        int up = 2 * (rails - 1); 
        int down = 2 * i;         
        int top = up - down;     
        for (j = i; j < len; j += up)
        {
            ct[k++] = pt[j];  

            
            if (down != 0 && top != 0 && j + top < len)
                ct[k++] = pt[j + top];
        }
    }
    ct[k] = '\0';

    printf("\nCipher Text:");
    puts(ct);

    printf("\n..............Decryption Process..............\n");
    printf("\nCipher Text:");
    puts(ct);

    
    int idx[100], pos = 0;
    int cycle = 2 * (rails - 1);

    
    for (i = 0; i < len; i++)
    {
        int rem = i % cycle;
        idx[i] = (rem < rails) ? rem : cycle - rem;
    }

    
    k = 0;
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            if (idx[j] == i)
                dt[j] = ct[k++];
    dt[len] = '\0';

    printf("\nPlain Text:");
    puts(dt);

    return 0;
}