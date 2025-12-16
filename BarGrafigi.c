#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Fonksiyon prototipleri
void yataygrafik(int ciro[]);
void dikeygrafik(int ciro[]);

// Global değişkenler
int ciro[12];          // 12 aylık ciro verilerini tutacak dizi
int i, j, max, seviye; // Döngü ve yardımcı değişkenler

int main()
{
    // Rastgele sayı üretimi için kullanılan kod dizini
    srand(time(NULL));

    // 12 ay için rastgele ciro değerleri (1-10 arası) atanıyor
    for (i = 0; i < 12; i++)
    {
        ciro[i] = rand() % 10 + 1;
    }

    // Yatay grafiği çizdir
    yataygrafik(ciro);
    printf("\n");

    // Dikey grafiği çizdir
    dikeygrafik(ciro);

    system("pause"); // Konsol penceresinin kapanmasını engeller
    return 0;
}

// Yatay bar grafiği çizen fonksiyon
void yataygrafik(int ciro[12])
{
    printf("\nYatay Grafigi: \n\n");
    for (i = 0; i < 12; i++)
    {
        printf("%d.:", i + 1); // Ay numarasını yazdır
        // Ciro değeri kadar yıldız (*) yazdır
        for (j = 0; j < ciro[i]; j++)
        {
            printf(" * ");
        }
        printf("\n"); // Bir sonraki satıra geç
    }
}

// Dikey bar grafiği çizen fonksiyon
void dikeygrafik(int ciro[12])
{
    // En yüksek ciro değerini bul (grafiğin yüksekliğini belirlemek için)
    max = ciro[0];

    for (i = 1; i < 12; i++)
    {
        if (ciro[i] > max)
        {
            max = ciro[i];
        }
    }

    printf("\n\n\nDikey Grafigi: \n\n");

    // En üst seviyeden başlayarak  çizimaşağıya doğru satır satır yap
    for (seviye = max; seviye >= 1; seviye--)
    {
        for (i = 0; i < 12; i++)
        {
            // Eğer o ayın cirosu şu anki seviyeye eşit veya büyükse yıldız koy
            if (ciro[i] >= seviye)
            {
                printf(" * ");
            }
            else
            {
                printf("   "); // Değilse boşluk bırak
            }
        }
        printf("\n"); // Bir alt seviyeye (satıra) geç
    }

    // Alt eksene ay numaralarını yazdır
    for (i = 0; i < 12; i++)
    {
        printf("%2d ", i + 1);
    }
}