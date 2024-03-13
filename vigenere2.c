#include <stdio.h>
#include <string.h>

void vigenere_encrypt(char *text, char *key)                            //vigenere sifreleme
{
    int text_uzun = strlen(text);
    int key_uzun = strlen(key);
    int i;

    for (i = 0; i < text_uzun; i++) 
	{
        text[i] = ((text[i] + key[i % key_uzun]) % 256);
    }
}

void vigenere_decrypt(char *text, char *key)                              //vigenere desifreleme
{
    int text_uzun = strlen(text);
    int key_uzun = strlen(key);
    int i;

    for (i = 0; i < text_uzun; i++) 
	{
        text[i] = ((text[i] - key[i % key_uzun] + 256) % 256);         
    }
}

int main()
 {
    char text[1000], key[100];
      FILE *input_file, *output_file;
      int i;

    char input_file_name[100];
      printf("dosya ismini yazin: ");               //dosya ismini al
      scanf("%s", input_file_name);
 
    input_file = fopen(input_file_name, "r");        //dosyayi ac
    if (input_file == NULL) 
	{
        printf("Dosya acilamadi \n");
        return 1;
    }
       printf("key i gir: ");          //anahtari iste
       scanf("%s", key);

    fgets(text, sizeof(text), input_file);               //dosya içindeki yaziyi oku

    vigenere_encrypt(text, key);                 //dosya içindeki yaziyi sifrele

    fclose(input_file);

    char output_file_name[100];                     //sifrelenmis metni yazmak için dosya iste
        printf("sifrelenmis metni hangi dosyaya aktarmak istersin : ");
        scanf("%s", output_file_name);

    output_file = fopen(output_file_name, "w");          //sifrelenmis metnin yazılacagı dosyayi aç
      if (output_file == NULL) 
    	{
            printf("Dosya acilamadi \n");
            return 1;
        }

    fprintf(output_file, "%s", text);         //sifrelenmis metni hedef dosyaya yaz

    fclose(output_file);

    input_file = fopen(output_file_name, "r");         //sifrelenmis metni çözmek için dosyayi ac
       if (input_file == NULL)
	    {
           printf("Dosya acilamadi  \n");
           return 1;
        }
 
    fgets(text, sizeof(text), input_file);    //metni dosyadan oku

    vigenere_decrypt(text, key);      //vigenere yöntemiyle sifreyi çöz
    fclose(input_file);     

    output_file = fopen("cözülmüs.txt", "w");  //cözülmüs metni yazmak icin dosyay
    if (output_file == NULL) 
	{
        printf("Dosya acilamadi  \n");
        return 1;
    }

    fprintf(output_file, "%s", text);   //cözülmüs metni yaz

    fclose(output_file);  //çözülmüs dosyayi kapa

    return 0;
}
