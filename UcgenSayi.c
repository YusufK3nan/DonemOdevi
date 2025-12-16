#include <stdio.h>
#include <stdlib.h>

// Fonksiyon prototipleri
int ucgensayihesapla(int n);
void ucgensayiyazdir(int n, int sayi);
void ucgenyazdir(int dizi[], int n, int k);

// Global değişkenler
int i, j, n, a, k = 0;

int main()
{
    // Kullanıcıdan üçgenin satır sayısını (n) al
    printf("Bir Sayi Giriniz: ");
    scanf("%d", &n);

    // İlk n adet üçgen sayısını yazdır
    printf("%d tane ucgen sayi dizisi: ", n);
    ucgensayiyazdir(n, 1);
    printf("\n\n");

    // Toplam eleman sayısını hesapla (n * (n + 1) / 2 formülü ile)
    a = (n * (n + 1)) / 2;

    int dizi[a]; // Üçgeni oluşturacak sayıları tutacak dizi

    // Üçgen şeklini yazdır
    ucgenyazdir(dizi, n, 0);

    return 0;
}

// Rekürsif olarak üçgen sayısını hesaplayan fonksiyon
// Örn: 3 için 3+2+1 = 6 döndürür
int ucgensayihesapla(int sayi)
{
    if (sayi <= 0)
    {
        return 0; // Temel durum: 0 veya negatifse 0 döndür
    }
    return sayi + ucgensayihesapla(sayi - 1); // Kendisi + bir eksiğinin üçgen sayısı
}

// Rekürsif olarak n adet üçgen sayısını ekrana yazdıran fonksiyon
void ucgensayiyazdir(int n, int sayi)
{
    if (sayi > n)
    {
        return; // Temel durum: İstenen sayıya ulaşıldıysa dur
    }
    printf("%d ", ucgensayihesapla(sayi)); // O anki sayının üçgen sayısını yazdır
    ucgensayiyazdir(n, sayi + 1);          // Bir sonraki sayı için fonksiyonu çağır
}

// Sayıları üçgen şeklinde (piramit gibi) yazdıran fonksiyon
void ucgenyazdir(int dizi[], int n, int k)
{
    printf("Ucgen: \n");

    // Diziyi 1'den başlayarak doldur (1, 2, 3, ..., a)
    for (i = 0; i < a; i++)
    {
        dizi[i] = i + 1;
    }

    // Satır satır üçgeni oluştur
    for (i = 1; i <= n; i++)
    {
        // Hizalama için boşluk bırak
        for (j = 1; j <= n - i; j++)
        {
            printf(" ");
        }
        // O satırdaki sayıları yazdır
        for (j = 1; j <= i; j++)
        {
            printf("%d ", dizi[k++]); // Diziden sıradaki elemanı al ve k'yı artır
        }
        printf("\n"); // Alt satıra geç
    }
}