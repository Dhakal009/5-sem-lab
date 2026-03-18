#include <stdio.h>
#include <string.h>

int modInv(int a) {
    for (int i = 1; i < 26; i++)
        if ((a * i) % 26 == 1) 
            return i;
    return -1;
}

int det(int k[3][3], int n) {
    if (n == 2) 
        return k[0][0] * k[1][1] - k[0][1] * k[1][0];
    
    return k[0][0] * (k[1][1] * k[2][2] - k[1][2] * k[2][1]) -
           k[0][1] * (k[1][0] * k[2][2] - k[1][2] * k[2][0]) +
           k[0][2] * (k[1][0] * k[2][1] - k[1][1] * k[2][0]);
}

void buildInv(int k[3][3], int inv[3][3], int n, int d, int di) {
    if (n == 2) {
        inv[0][0] = k[1][1];     inv[0][1] = -k[0][1];
        inv[1][0] = -k[1][0];    inv[1][1] = k[0][0];
    } else {
        inv[0][0] = (k[1][1] * k[2][2] - k[1][2] * k[2][1]);
        inv[0][1] = -(k[0][1] * k[2][2] - k[0][2] * k[2][1]);
        inv[0][2] = (k[0][1] * k[1][2] - k[0][2] * k[1][1]);
        inv[1][0] = -(k[1][0] * k[2][2] - k[1][2] * k[2][0]);
        inv[1][1] = (k[0][0] * k[2][2] - k[0][2] * k[2][0]);
        inv[1][2] = -(k[0][0] * k[1][2] - k[0][2] * k[1][0]);
        inv[2][0] = (k[1][0] * k[2][1] - k[1][1] * k[2][0]);
        inv[2][1] = -(k[0][0] * k[2][1] - k[0][1] * k[2][0]);
        inv[2][2] = (k[0][0] * k[1][1] - k[0][1] * k[1][0]);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp = ((inv[i][j] % 26 + 26) % 26);
            inv[i][j] = (di * temp) % 26;
        }
    }
}

void multiply(int mat[3][3], char *in, char *out, int n, int fromUpper) {
    int len = strlen(in);
    for (int i = 0; i < len; i += n) {
        for (int r = 0; r < n; r++) {
            int sum = 0;
            for (int c = 0; c < n; c++)
                sum += mat[r][c] * (in[i + c] - (fromUpper ? 65 : 97));
            out[i + r] = ((sum % 26 + 26) % 26) + (fromUpper ? 97 : 65);
        }
    }
    out[len] = '\0';
}

void printMatrix(int m[3][3], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%d ", m[i][j]);
        printf("\n");
    }
}

int main() {
    char plaintext[60], ciphertext[60];
    int keyMatrix[3][3], inverseMatrix[3][3];
    int choice, matrixSize;

    printf("Please Select Key Matrix Size:\n");
    printf("1. 2x2\n");
    printf("2. 3x3\n");
    printf("Enter the Choice: ");
    scanf("%d", &choice);
    
    matrixSize = (choice == 1) ? 2 : (choice == 2) ? 3 : 0;
    if (!matrixSize) {
        printf("Invalid Choice!\n");
        return 1;
    }

    printf("\nEnter Plain Text (lowercase only): ");
    scanf("%s", plaintext);

    printf("Enter %dx%d Key Matrix (row by row):\n", matrixSize, matrixSize);
    for (int i = 0; i < matrixSize; i++)
        for (int j = 0; j < matrixSize; j++) {
            printf("Key[%d][%d]: ", i, j);
            scanf("%d", &keyMatrix[i][j]);
        }

    int len = strlen(plaintext);
    while (len % matrixSize != 0) {
        plaintext[len++] = 'x';
    }
    plaintext[len] = '\0';


    printf("\n========== ENCRYPTION PROCESS ==========\n");
    printf("Plain Text:  %s\n", plaintext);
    printf("Key Matrix:\n");
    printMatrix(keyMatrix, matrixSize);

    multiply(keyMatrix, plaintext, ciphertext, matrixSize, 0);
    printf("\nCipher Text: %s\n", ciphertext);


    printf("\n========== DECRYPTION PROCESS ==========\n");
    printf("Cipher Text: %s\n", ciphertext);
    printf("Key Matrix:\n");
    printMatrix(keyMatrix, matrixSize);

    int determinant = ((det(keyMatrix, matrixSize) % 26) + 26) % 26;
    int modularInverse = modInv(determinant);
    
    buildInv(keyMatrix, inverseMatrix, matrixSize, determinant, modularInverse);
    multiply(inverseMatrix, ciphertext, plaintext, matrixSize, 1);
    
    printf("\nPlain Text:  %s\n", plaintext);

    return 0;
}