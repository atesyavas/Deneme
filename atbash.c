#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    FILE *dosya;
    char text[9999];


   dosya = fopen("metin.txt", "r");
    if (dosya == NULL) {
        printf("Dosya acma hatasi!\n");
        return 1;
    }
    fgets(text, 9999 , dosya);
    fclose(dosya);

 
    atbashSifreleme(text);

  
   dosya = fopen("metin.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açma hatasy!\n");
        return 1;
    }
    fputs(text, dosya);
    fclose(dosya);

    printf("Metin basariyla Atbash sifreleme yontemiyle sifrelendi ve metin.txt dosyasina yazildi.\n");
    
    int sifre=4141;
    int anahtar;
  	printf("Metni orijinal haline cevirmek icin lutfen anahtari girin: ");
  	scanf("%d",&anahtar);
	
	if(anahtar==sifre)
	{
		printf("Tebrikler dogru anahtar! Metin orijinal haline cevirildi.\n");
		atbashSifreleme(text);
	
		dosya = fopen("metin.txt", "w");
    if (dosya == NULL) {
        printf("Dosya açma hatasy!\n");
        return 1;
    }
    fputs(text, dosya);
    fclose(dosya);
		
	}
	else
	printf("Anahtar yanlis girildi!");
	
	
    return 0;
}
