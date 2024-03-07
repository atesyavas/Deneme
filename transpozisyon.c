#include<stdio.h>
#include<string.h>


char arr[22][22], darr[22][22], sifrelenmisMesaj[111], desMesaj[111], anahtar[55];
char temp[55], temp2[55];
int k = 0;


void sifre(int i, int r);
void makeArray(int col, int row);
int findMin();

int main() {
    char duzMesaj[100], dmessage[100];
    int i, j, anahtarlen, emlen, flag = 0;
    int r, c, index, min, rows;

    
    printf("Ana metni giriniz: ");
    gets(duzMesaj);
    printf("Anahtar giriniz:\n");
    gets(anahtar);

    strcpy(temp, anahtar);        // Anahtarın uzunluğunun alınması ve temp dizisine kopyalanması
    anahtarlen = strlen(anahtar);

    
    k = 0;
    for (i = 0;; i++) {
        if (flag == 1)
        break;
    for (j = 0; anahtar[j] != NULL; j++) {
        if (duzMesaj[k] == NULL) {
            flag = 1;
            arr[i][j] = ' ';
        } else {
            arr[i][j] = duzMesaj[k++];
        }
    }
    }

    
    r = i;
    c = j;
    k = 0;

    
    for (i = 0; i < anahtarlen; i++) {       
        index = findMin();              // Şifreleme işlemi
        sifre(index, r);
    }

    
    sifrelenmisMesaj[k] = '\0';

    printf("\nsifrelenmis mesaj:\n");
    for (i = 0; sifrelenmisMesaj[i] != NULL; i++)
        printf("%c", sifrelenmisMesaj[i]);

    printf("\n\n");
    emlen = strlen(sifrelenmisMesaj);

    
    strcpy(temp, anahtar);     // Çözme işlemi için gerekli ayarlamaları yaptım 
    rows = emlen / anahtarlen;
    j = 0;

    
    for (i = 0, k = 1; sifrelenmisMesaj[i] != NULL; i++, k++) {
        temp2[j++] = sifrelenmisMesaj[i];
        if ((k % rows) == 0) {                   // deşifreleme işlemi
            index = findMin();
            makeArray(index, rows);
            j = 0;
        }
    }

    
    k = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {                  // Çözülen mesajın düzenlenmesi
            desMesaj[k++] = darr[i][j];
        }
    }

    
    desMesaj[k] = '\0';

    // Çözülen mesajın ekrana yazdırılması
    printf("desifrelenmis mesaj: ");
    for (i = 0; desMesaj[i] != NULL; i++)
        printf("%c", desMesaj[i]);

    printf("\n\n");

    return (0);
}


void sifre(int i, int r) {
    int j;
    for (j = 0; j < r; j++) {                        // Şifreleme fonksiyonu
        sifrelenmisMesaj[k++] = arr[j][i];
    }
    sifrelenmisMesaj[k] = '\0';
}


void makeArray(int col, int row) {
    int i, j;
    for (i = 0; i < row; i++) {                 // Çözme için matris oluşturma fonksiyonu
        darr[i][col] = temp2[i];
    }
}

int findMin() {           // En küçük değeri buluyor
    int i, j, min, index;

    min = temp[0];
    index = 0;
    for (j = 0; temp[j] != NULL; j++) {
        if (temp[j] < min) {
            min = temp[j];
            index = j;
        }
    }
    temp[index] = 123;
    return index;
}
