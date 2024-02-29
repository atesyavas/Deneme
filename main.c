#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000


void atbashEncrypt(char *text) {
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
    FILE *file;
    char text[MAX_LENGTH];


    file = fopen("metin.txt", "r");
    if (file == NULL) {
        printf("Dosya açma hatasý!\n");
        return 1;
    }
    fgets(text, MAX_LENGTH, file);
    fclose(file);

 
    atbashEncrypt(text);

  
    file = fopen("metin.txt", "w");
    if (file == NULL) {
        printf("Dosya açma hatasý!\n");
        return 1;
    }
    fputs(text, file);
    fclose(file);

    printf("Metin basariyla Atbash sifreleme yontemiyle sifrelendi ve metin.txt dosyasina yazildi.\n");

    return 0;
}

