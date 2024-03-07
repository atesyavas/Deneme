#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shiftChar(char *metin, int shift, int direction) {
    int i;
	for (i = 0; i < strlen(metin); i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + (metin[i] - 'a' + shift * direction + 26) % 26; 
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' + shift * direction + 26) % 26;
        } else if (metin[i] >= '0' && metin[i] <= '9') {
            metin[i] = '0' + (metin[i] - '0' + shift * direction + 10) % 10;
        }
    }
}

void atbashSifreleme(char *metin) {
    int uzunluk = strlen(metin);
    int i;
	for (i = 0; i < uzunluk; i++) {
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'z' - (metin[i] - 'a');
        } else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'Z' - (metin[i] - 'A');
        }
    }
}

void writeToFile(char *filename, char *metin) {
    FILE *dosya = fopen(filename, "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return;
    }
    fprintf(dosya, "%s", metin);
    fclose(dosya);
}

int main() {
    char metin[100];
    char dosyaAdi[50];
    int shift, operation;

    printf("Dosya adini girin: ");
    scanf("%s", dosyaAdi);

    printf("\nSecim yapiniz:\n");
    printf("1. Sezar sifreleme\n");
    printf("2. Atbash sifreleme\n");
    printf("3. Sezar sifre cozme\n");
    printf("Secim: ");
    scanf("%d", &operation);

    printf("\nMetni giriniz: ");
    scanf("%s", metin);

    if (operation == 1 || operation == 3) {
        printf("Sifre kaydirma miktarini giriniz: ");
        scanf("%d", &shift);
        shiftChar(metin, shift, operation == 1 ? 1 : -1);
    } else if (operation == 2) {
        atbashSifreleme(metin);
    }

    writeToFile(dosyaAdi, metin);

    if (operation == 1) {
        printf("Cezar Sifreleme ile metin dosyaya yazildi.\n");
    } else if (operation == 2) {
        printf("Atbash Sifreleme ile metin dosyaya yazildi.\n");
    } else {
        printf("Sezar Sifre cozme ile metin dosyaya yazildi.\n");
    }

    return 0;
}
