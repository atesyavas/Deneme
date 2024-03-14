#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Şifrelemeler için gerekli kütüphanedir. islower, isalpha, tolower, isdigit gibi fonksiyonları içerir

// Vigenere şifreleme fonksiyonu
void vigenere_encrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) { // Harf kontrolü
            char base = islower(text[i]) ? 'a' : 'A'; // Küçük harf kontrolü
            text[i] = ((text[i] - base + key[i % key_len] - 'a') % 26) + base; // Vigenere şifreleme
        }
    }
}

// Vigenere şifresini çözen fonksiyon
void vigenere_decrypt(char *text, char *key) {
    int text_len = strlen(text);
    int key_len = strlen(key);
    int i;

    for (i = 0; i < text_len; i++) {
        if (isalpha(text[i])) { // Harf kontrolü
            char base = islower(text[i]) ? 'a' : 'A'; // Küçük harf kontrolü
            text[i] = ((text[i] - base - (key[i % key_len] - 'a') + 26) % 26) + base; // Vigenere şifresini çözme
        }
    }
}

// Sezar şifreleme fonksiyonu
void sezarSifrele(char metin[], int kaydirma) {
    int i = 0;

    while (metin[i] != '\0') {
        if (isalpha(metin[i])) { // Harf kontrolü
            char base = islower(metin[i]) ? 'a' : 'A'; // Küçük harf kontrolü
            metin[i] = ((metin[i] - base + kaydirma) % 26) + base; // Sezar şifreleme
        } else if (isdigit(metin[i])) { // Sayı kontrolü
            metin[i] = ((metin[i] - '0' + kaydirma) % 10) + '0'; // Sezar şifreleme (sayılar için)
        }
        i++;
    }
}

// Sezar şifresini çözen fonksiyon
void sezarCoz(char sifreli[], int kaydir) {
    int j = 0;

    while (sifreli[j] != '\0') {
        if (isalpha(sifreli[j])) { // Harf kontrolü
            char base = islower(sifreli[j]) ? 'a' : 'A'; // Küçük harf kontrolü
            sifreli[j] = ((sifreli[j] - base - kaydir + 26) % 26) + base; // Sezar şifresini çözme
        } else if (isdigit(sifreli[j])) { // Sayı kontrolü
            sifreli[j] = ((sifreli[j] - '0' - kaydir + 10) % 10) + '0'; // Sezar şifresini çözme (sayılar için)
        }
        j++;
    }
}

// Atbash şifreleme fonksiyonu
void atbashSifreleme(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) { // Döngü metnin uzunluğuna göre çalışır
        if (isalpha(text[i])) { // Karakterin harf olup olmadığını kontrol eder
            char base = islower(text[i]) ? 'a' : 'A'; // Karakterin küçük harf olup olmadığını kontrol eder. Küçükse 'a', büyükse 'A' atanır 
            text[i] = base + ('z' - tolower(text[i])); // Karakterin tersini bulur, 'a' ve 'z', 'A' ve 'Z' gibi
        } else if (isdigit(text[i])) { // Karakter harf değilse sayı olup olmadığını kontrol eder 
            text[i] = '9' - (text[i] - '0'); // Karakter sayı ise sayının tersini bulur. '0' karakteri '9'a , '1' karakteri '8'e gibi
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
    getchar(); // İlk satır sonu karakterini temizle
    fgets(metin, sizeof(metin), stdin);

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
            fprintf(dosya, "%s", metin);
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
