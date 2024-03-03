#include <stdio.h>


void sezarSifrele(char metin[], int kaydirma) // şifreleme fonksiyonu oluşturma
{
    
    int i = 0;

    while (metin[i] != '\0') 
    {
        //küçük harfi şifreleme
        if (metin[i] >= 'a' && metin[i] <= 'z')
        {
            metin[i] = 'a' + (metin[i] - 'a' + kaydirma) % 26; 
        }
        // Büyük harfi şifreleme
        else if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' + kaydirma) % 26;
        }
        i++;
    }
}

void sezarCoz(char sifreli[], int kaydir ) //şifre çözme fonksiyonu oluşturma
{
    int j=0;

    while(sifreli[j]!='\0')
    {
        if(sifreli[j]>='a'&&sifreli[j]<='z')
        {
            sifreli[j]='z'+(sifreli[j]-'z'-kaydir)%26;
        }
        j++;
    }
}

int main() {
    char metin[100];
    int kaydirma;
  

    // Kullanıcıdan metni ve kaydırma miktarı alma
    printf("Sifrelemek istediginiz metni giriniz--> ");
    scanf("%s", metin);
    printf("Sifre kaydirma miktarini giriniz--> ");
    scanf("%d", &kaydirma);

    // Şifreleyecek fonksiyonu çağırma
    sezarSifrele(metin, kaydirma);
    printf("Sifrelenmis metin=> %s\n", metin);

    //Şifre çözecek fonksiyonu çağırma
    sezarCoz(metin,kaydirma);
    printf("Sifresi cozulmus metin=> %s",metin);

    return 0;
}
