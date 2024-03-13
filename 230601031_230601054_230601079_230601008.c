#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void vigenere_encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((text[i] - base + key[i % key_len] - 'a') % 26) + base;
        }
    }
}

void vigenere_decrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = ((text[i] - base - (key[i % key_len] - 'a') + 26) % 26) + base;
        }
    }
}

void sezarSifrele(char metin[], int kaydirma) {
    int i = 0;

    while (metin[i] != '\0') {
        if (isalpha(metin[i])) {
            char base = islower(metin[i]) ? 'a' : 'A';
            metin[i] = ((metin[i] - base + kaydirma) % 26) + base;
        } else if (isdigit(metin[i])) {
            metin[i] = ((metin[i] - '0' + kaydirma) % 10) + '0';
        }
        i++;
    }
}

void sezarCoz(char sifreli[], int kaydir) {
    int j = 0;

    while (sifreli[j] != '\0') {
        if (isalpha(sifreli[j])) {
            char base = islower(sifreli[j]) ? 'a' : 'A';
            sifreli[j] = ((sifreli[j] - base - kaydir + 26) % 26) + base;
        } else if (isdigit(sifreli[j])) {
            sifreli[j] = ((sifreli[j] - '0' - kaydir + 10) % 10) + '0';
        }
        j++;
    }
}

void atbashSifreleme(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (isalpha(text[i])) {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = base + ('z' - (tolower(text[i]) - 'a'));
        } else if (isdigit(text[i])) {
            text[i] = '9' - (text[i] - '0');
        }
    }
}

int main() {
    char metin[100];
    char dosyaAdi[50];
    int secim, kaydirma;

    printf("Dosya adini girin: ");
    scanf("%s", dosyaAdi);

    printf("\nSecim yapiniz:\n");
    printf("1. Sezar sifreleme\n");
    printf("2. Atbash sifreleme\n");
    printf("3. Sezar sifre cozme\n");
    printf("4. Vigenere sifreleme\n");
    printf("5. Vigenere sifre cozme\n");
    printf("Secim: ");
    scanf("%d", &secim);

    printf("\nMetni giriniz: ");
    scanf("%s", metin);

    FILE *dosya = fopen(dosyaAdi, "w");
    if (dosya == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    switch (secim) {
        case 1:
            printf("Sifre kaydirma miktarini giriniz: ");
            scanf("%d", &kaydirma);
            sezarSifrele(metin, kaydirma);
            fprintf(dosya, "Sifrelenmis metin: %s", metin);
            printf("Sezar sifreleme ile metin dosyaya yazildi.\n");
            break;
        case 2:
            atbashSifreleme(metin);
            fprintf(dosya, "Sifresi cozulmus metin: %s", metin);
            printf("Atbash sifre cozme ile metin dosyaya yazildi.\n");
            break;
        case 3:
            printf("Sifre kaydirma miktarini giriniz: ");
            scanf("%d", &kaydirma);
            sezarCoz(metin, kaydirma);
            fprintf(dosya, "Metnin orijinal hali: %s", metin);
            printf("Sezar ile sifrelenen metin orijinal haline cevrildi.\n");
            break;
        case 4:
            printf("Vigenere anahtarini giriniz: ");
            char anahtar[100];
            scanf("%s", anahtar);
            vigenere_encrypt(metin, anahtar);
            fprintf(dosya, "Vigenere sifrelenmis metin: %s", metin);
            printf("Vigenere sifreleme ile metin dosyaya yazildi.\n");
            break;
        case 5:
            printf("Vigenere anahtarini giriniz: ");
            char anahtar2[100];
            scanf("%s", anahtar2);
            vigenere_decrypt(metin, anahtar2);
            fprintf(dosya, "Vigenere sifresi cozulmus metin: %s", metin);
            printf("Vigenere sifre cozme ile metin dosyaya yazildi.\n");
            break;
        default:
            printf("Gecersiz secim!\n");
            break;
    }

    fclose(dosya);
    return 0;
}
