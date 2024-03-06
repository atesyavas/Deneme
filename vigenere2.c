#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void get_key(char *text, char *key, char *key2) 
{
   int text_uzun = strlen(text);
   int key_uzun = strlen(key);
   
      strncpy(key2, key, key_uzun);
      key2[key_uzun] = '\0';
   
}

void vigenere_sifreleme(char *text, char *key)
{
   char key2[100];
   get_key(text, key, key2);
   int text_uzun = strlen(text);
   int key_uzun = strlen(key2);

   FILE *outfile = fopen("sifrelenen.txt", "w");

   for (int i = 0; i < text_uzun; i++)                                         // sadece harfler için islem yapmasi için isalpha ve isupper komutlarini kullan
   {
       if (isalpha(text[i])) 
	   {
           int shift = isupper(key2[i]) ? key2[i] - 65 : key2[i] - 97;   // soru isareti: 1.madde ? 2.madde : 3.madde (1. madde dogruysa 2. madde uygulanir yanlissa 3. madde uygulanir) 
           if (isupper(text[i])) 
		   {
               text[i] = ((text[i] - 65 + shift) % 26) + 65;
           } else 
		   {
               text[i] = ((text[i] - 97 + shift) % 26) + 97;
           }
       }

       fprintf(outfile, "%c", text[i]);
   }

   fclose(outfile);
}

int main()
 {
   char text[9999];                                                 //metin dosyasini oku
   FILE *infile = fopen("sifrelenecek.txt", "r");
   fgets(text, sizeof(text), infile);
   fclose(infile);

   char key[99];                                                    //kullanicidan anahtari al
   printf("***************************\n");
   printf("sifrelemekte kullanilanacak anahtari giriniz: \n");
   scanf("%s", key);
   
   vigenere_sifreleme(text, key);                                   //metni sifrele ve sonucu dosyaya yaz

   return 0;
}
