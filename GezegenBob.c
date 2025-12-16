#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonksiyon prototipleri
int asalmi(int x);

int main()
{
    // Harf dizileri tanımlanıyor
    char unluler[5] = {'a', 'e', 'i', 'o', 'u'};
    char unsuzler[] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};

    // Sonuçları tutacak 2 boyutlu dizi (maksimum 250 kelime, her biri 3 harf + 1 bitiş karakteri)
    char sonucListesi[250][4];
    int adet = 0; // Bulunan kelime sayısını tutar

    int i, j;

    // Ünlü-Ünsüz-Ünlü (ABA) kombinasyonlarını bul
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 21; j++)
        {
            // Harflerin ASCII değerleri toplamının asal olup olmadığını kontrol et
            int x = asalmi((unluler[i] + unsuzler[j] + unluler[i]));
            if (x == 1)
            {
                // Şartı sağlayan kelimeyi listeye ekle
                sonucListesi[adet][0] = unluler[i];
                sonucListesi[adet][1] = unsuzler[j];
                sonucListesi[adet][2] = unluler[i];
                sonucListesi[adet][3] = '\0'; // String bitiş karakteri
                adet++;
            }
        }
    }

    // Ünsüz-Ünlü-Ünsüz (BAB) kombinasyonlarını bul
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 21; j++)
        {
            // Harflerin ASCII değerleri toplamının asal olup olmadığını kontrol et
            int y = asalmi((unsuzler[j] + unluler[i] + unsuzler[j]));
            if (y == 1)
            {
                // Şartı sağlayan kelimeyi listeye ekle
                sonucListesi[adet][0] = unsuzler[j];
                sonucListesi[adet][1] = unluler[i];
                sonucListesi[adet][2] = unsuzler[j];
                sonucListesi[adet][3] = '\0';
                adet++;
            }
        }
    }

    // Bulunan kelimeleri alfabetik olarak sırala (Bubble Sort algoritması)
    char gecici[4];
    for (int a = 0; a < adet - 1; a++)
    {
        for (int b = a + 1; b < adet; b++)
        {
            // strcmp ile karşılaştırma yap, eğer sıralama yanlışsa yer değiştir
            if (strcmp(sonucListesi[a], sonucListesi[b]) > 0)
            {
                strcpy(gecici, sonucListesi[a]);
                strcpy(sonucListesi[a], sonucListesi[b]);
                strcpy(sonucListesi[b], gecici);
            }
        }
    }

    // Sonuçları ekrana yazdır
    printf("Bulunan ve Siralanan Kelimeler:\n");
    for (int s = 0; s < adet; s++)
    {
        printf("%d.%s\n", s + 1, sonucListesi[s]);
    }

    return 0;
}

// Bir sayının asal olup olmadığını kontrol eden fonksiyon
// Asal ise 1, değilse 0 döndürür
int asalmi(int x)
{
    if (x < 2)
        return 0; // 2'den küçük sayılar asal değildir

    // Sayının kareköküne kadar olan bölenleri kontrol et
    for (int k = 2; k * k <= x; k++)
    {
        if (x % k == 0)
            return 0; // Tam bölünüyorsa asal değildir
    }
    return 1; // Hiçbir sayıya bölünmediyse asaldır
}