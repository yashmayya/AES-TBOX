#include <cstdio>
#include "AES-KeyExp.h"
#include "AES-Tbox-Encryption.h"

int main(int argc, char* argv[])
{
    BYTE bKey[16]	= { 0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F };
    BYTE bInput[16] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF };

    BYTE bExpKey[176];

    // //Print Cleatext
    printf("Cleartext\n");
    for(int i = 1; i<=16; i++){
        printf(("%02X%c"),bInput[i-1], i % 4 == 0 ? '\n' : ' ');
    }

    KeyExpansion(bKey, bExpKey);
    ComputeTBoxes();
    AesEncyption(bInput, bExpKey);

    // Print Key
    printf("\n\nKey\n");
    for(int i = 1; i<=16; i++){
        printf("%02X%c", bKey[i-1], i % 4 == 0 ? '\n' : ' ');
    }
    // Print Ciphertext
    printf("\n\nCiphertext\n");
    for(int i = 1; i<=16; i++){
        printf("%02X%c" , bInput[i-1], i % 4 == 0 ? '\n' : ' ');
    }

    ComputeInvTBoxes();
    AesDecryption(bInput, bExpKey);

    printf("\n\nDecrypted text\n");
    //Print decrypted
    for(int i = 1; i<=16; i++){
        printf(("%02X%c"),bInput[i-1], i % 4 == 0 ? '\n' : ' ');
    }

    return 0;
}


