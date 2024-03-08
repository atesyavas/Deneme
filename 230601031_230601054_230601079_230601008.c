#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sezarSifrele(char metin[], int kaydirma) {
    int i = 0;

    while (metin[i] != '\0') {
        //küçük harfi şifreleme
        if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + (metin[i] - 'a' + kaydirma) % 26; 
        }
        // Büyük harfi şifreleme
        else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' + kaydirma) % 26;
        }
        //sayıları şifreleme
        else if(metin[i]>='0'&&metin[i]<='9') {
            metin[i]='0'+(metin[i]-'0'+kaydirma)%10;
        }
        i++;
    }
}

void sezarCoz(char sifreli[], int kaydir) {
    int j=0;

    while(sifreli[j]!='\0') {
        //küçük harfin şifresini çözme
        if(sifreli[j]>='a'&&sifreli[j]<='z') {
            sifreli[j]='z'+(sifreli[j]-'z'-kaydir)%26;
        }
        //büyük harfin şifresini çözme
        else if(sifreli[j]>='A'&&sifreli[j]<='Z') {
            sifreli[j]='Z'+(sifreli[j]-'Z'-kaydir)%26;
        }
        //sayıların şifresini çözme
        else if(sifreli[j]>='0'&&sifreli[j]<='9') {
            sifreli[j]='9'+(sifreli[j]-'9'-kaydir)%10;
        }
        
        j++;
    }
}



void atbashSifreleme(char *text) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = 'Z' - (text[i] - 'A');
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = 'z' - (text[i] - 'a');
        }
    }
}

int main() {
    char metin[100];
    char dosyaAdi[50];
    int secim, kaydirma;

    // Kullanıcıdan dosya adını alma
    printf("Dosya adini girin: ");
    scanf("%s", dosyaAdi);

    // Kullanıcıya seçenekleri sunma
    printf("\nSecim yapiniz:\n");
    printf("1. Sezar sifreleme\n");
    printf("2. Atbash sifreleme\n");
    printf("3. Sezar sifre cozme\n");
    printf("Secim: ");
    scanf("%d", &secim);

    // Kullanıcıdan metni alma
    printf("\nMetni giriniz: ");
    scanf("%s", metin);

    // Cezar Şifreleme seçildiyse
    if (secim == 1) {
        // Kullanıcıdan kaydırma miktarını alma
        printf("Sifre kaydirma miktarini giriniz: ");
        scanf("%d", &kaydirma);
        
        // Cezar Şifreleme işlemini yapma
        sezarSifrele(metin, kaydirma);

        // Sonucu dosyaya yazma
        FILE *dosya = fopen(dosyaAdi, "w");
        if (dosya == NULL) {
            printf("Dosya acilamadi!\n");
            return 1;
        }
        fprintf(dosya, "Sifrelenmis metin: %s", metin);
        fclose(dosya);

        printf("Sezar sifreleme ile metin dosyaya yazildi.\n");
    }

    else if(secim==2)
    {
        atbashSifreleme(metin);

        // Sonucu dosyaya yazma
        FILE *dosya = fopen(dosyaAdi, "w");
        if (dosya == NULL) 
        {
            printf("Dosya acilamadi!\n");
            return 1;
        }
        fprintf(dosya, "Sifresi cozulmus metin: %s", metin);
        fclose(dosya);

        printf("Atbash sifre cozme ile metin dosyaya yazildi.\n");
    }   
        

    else if(secim==3)
    {
        // Kullanıcıdan kaydırma miktarını alma
        printf("Sifre kaydirma miktarini giriniz: ");
        scanf("%d", &kaydirma);
        
        // Cezar Şifreleme işlemini yapma
        sezarCoz(metin, kaydirma);

        // Sonucu dosyaya yazma
        FILE *dosya = fopen(dosyaAdi, "w");
        if (dosya == NULL) {
            printf("Dosya acilamadi!\n");
            return 1;
        }
        fprintf(dosya, "Metnin orijinal hali: %s", metin);
        fclose(dosya);

        printf("Sezar ile sifrelenen metin orijinal haline cevrildi.\n");
    }

    }
