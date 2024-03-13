#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char arr[22][22], darr[22][22], sifrelenmisMesaj[111], desMesaj[111], anahtar[55];
char temp[55], temp2[55], dosyaAdi[50];
int k = 0;


void sifre(int i, int r);
void makeArray(int col, int row);
int findMin();

int main() {
    char duzMesaj[100], dmessage[100];
    int i, j, anahtarlen, emlen, flag = 0;
    int r, c, index, min, rows, e;
    char txt[] = ".txt";

    
    printf("Desifrelemek istediginiz metni giriniz: ");
    gets(duzMesaj);
    printf("Sifreleme anahtari giriniz: ");
    gets(anahtar);

    strcpy(temp, anahtar);        // Anahtarýn uzunluðunun alýnmasý ve temp dizisine kopyalanmasý
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
        index = findMin();              // Þifreleme iþlemi
        sifre(index, r);
    }

    
    sifrelenmisMesaj[k] = '\0';
    
    printf("Sifrelenmis metni yazmak icin bir belge adi giriniz: ");
	scanf("%s",dosyaAdi);
	dosyaAdi[strcspn(dosyaAdi, "\n")] = '\0';
	strcat(dosyaAdi, txt);

    printf("\nSifrelenmis mesaj:\n");
    for (i = 0; sifrelenmisMesaj[i] != NULL; i++)
        printf("%c", sifrelenmisMesaj[i]);
        
    printf("\n\n");
    
	FILE *dosya = fopen(dosyaAdi, "w");
	if (dosya == NULL) {
		printf("Dosya acilamadi!");
		return 1;
	}
	fprintf(dosya, "%s", sifrelenmisMesaj);
	fclose(dosya);

	printf("Transpozisyon sifreleme ile metin, dosyaya yazildi.\n");

    printf("\n\n");
    emlen = strlen(sifrelenmisMesaj);

    
    strcpy(temp, anahtar);     // Çözme iþlemi için gerekli ayarlamalarý yaptým 
    rows = emlen / anahtarlen;
    j = 0;

    
    for (i = 0, k = 1; sifrelenmisMesaj[i] != NULL; i++, k++) {
        temp2[j++] = sifrelenmisMesaj[i];
        if ((k % rows) == 0) {                   // deþifreleme iþlemi
            index = findMin();
            makeArray(index, rows);
            j = 0;
        }
    }

    
    k = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {                  // Çözülen mesajýn düzenlenmesi
            desMesaj[k++] = darr[i][j];
        }
    }

    
    desMesaj[k] = '\0';
    
    printf("Sifrelenmis metnin bulundugu dosyanin adini giriniz: ");
    scanf("%s",dosyaAdi);
	strcat(dosyaAdi, txt);
	dosyaAdi[strcspn(dosyaAdi, "\n")] = '\0';
	
	FILE *dosya2 = fopen(dosyaAdi, "r");
	if (dosya2 == NULL) {
        perror("Dosya acilamadi");
        return 1;
    }
    
	
	fclose(dosya2);

    // Çözülen mesajýn ekrana yazdýrýlmasý
    printf("Desifrelenmis mesaj: ");
    for (i = 0; desMesaj[i] != NULL; i++) {
    	printf("%c", desMesaj[i]);
	}

    printf("\n\n");
    printf("Desifrelenmis metni kaydetmek icin bir dosya adi giriniz: ");
    scanf("%s",dosyaAdi);
	strcat(dosyaAdi, txt);

    FILE *dosya3 = fopen(dosyaAdi, "w"); // "w" modunu kullanarak dosyayÄ± yazma modunda aÃ§Ä±n

    if (dosya3 == NULL) {
        perror("Dosya acilamadi");
        return 1;
    }

    fprintf(dosya3, "%s", desMesaj);
	fclose(dosya3);

    printf("Sifrelenmis metin dosyadan okunarak desifrelendi ve diger dosyaya yazildi.\n");

    return 0;
}


void sifre(int i, int r) {
    int j;
    for (j = 0; j < r; j++) {                        // Þifreleme fonksiyonu
        sifrelenmisMesaj[k++] = arr[j][i];
    }
    sifrelenmisMesaj[k] = '\0';
}


void makeArray(int col, int row) {
    int i, j;
    for (i = 0; i < row; i++) {                 // Çözme için matris oluþturma fonksiyonu
        darr[i][col] = temp2[i];
    }
}

int findMin() {           // En küçük deðeri buluyor
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
