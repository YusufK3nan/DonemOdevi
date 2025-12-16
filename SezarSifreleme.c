#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global değişkenler: Mesajları tutmak için karakter dizileri
char mesaj[200], sifrelimesaj[200];

// Fonksiyon prototipleri
void sezarsifreleme(char mesaj[], int x);
void sezarsifrecozme(char sifrelimesaj[], int y);

int main()
{
    int i, x, y;

    // Şifreleme işlemini başlat
    sezarsifreleme(mesaj, x);

    // Tampon belleği temizle (önceki scanf'ten kalan karakteri yutmak için)
    getchar();
    printf("\n\n");

    // Şifre çözme işlemini başlat
    sezarsifrecozme(sifrelimesaj, y);

    return 0;
}

// Sezar Şifreleme Fonksiyonu
// Girilen mesajı belirtilen anahtar değeri kadar ileri kaydırır
void sezarsifreleme(char mesaj[], int x)
{
    int i;
    printf("Sifrelemek Istediginiz Mesaji Giriniz: ");
    fgets(mesaj, 200, stdin);
    printf("Anahtar Degeri Girin: ");
    scanf("%d", &x);

    for (i = 0; i < strlen(mesaj); i++)
    {
        // Küçük harfler için (a-z) şifreleme
        if (mesaj[i] >= 'a' && mesaj[i] <= 'z')
        {
            // Formül: (Harf - 'a' + Kaydırma) % 26 + 'a'
            // % 26 işlemi alfabenin dışına çıkıldığında başa dönmeyi sağlar
            mesaj[i] = (mesaj[i] - 'a' + x) % 26 + 'a';
        }
        // Büyük harfler için (A-Z) şifreleme
        else if (mesaj[i] >= 'A' && mesaj[i] <= 'Z')
        {
            // Formül: (Harf - 'A' + Kaydırma) % 26 + 'A'
            mesaj[i] = (mesaj[i] - 'A' + x) % 26 + 'A';
        }
        // Diğer karakterlere (boşluk, nokta vs.) dokunmuyoruz.
    }

    printf("Sifreli Mesaj: ");
    for (i = 0; i < strlen(mesaj); i++)
    {
        printf("%c", mesaj[i]);
    }
}

// Sezar Şifre Çözme Fonksiyonu
// Şifreli mesajı belirtilen anahtar değeri kadar geri kaydırır
void sezarsifrecozme(char sifrelimesaj[], int y)
{
    int i;
    printf("Cozmek istediginiz mesaji Girin: ");
    fgets(sifrelimesaj, 200, stdin);
    printf("Anahtar Degeri Girin: ");
    scanf("%d", &y);

    for (i = 0; i < strlen(sifrelimesaj); i++)
    {
        // Küçük harfler için şifre çözme
        if (sifrelimesaj[i] >= 'a' && sifrelimesaj[i] <= 'z')
        {
            // Geriye doğru kaydırma işlemi
            // +26 eklememizin sebebi negatif sonuç çıkmasını engellemektir
            sifrelimesaj[i] = (sifrelimesaj[i] - 'a' - y + 26) % 26 + 'a';
        }
        // Büyük harfler için şifre çözme
        else if (sifrelimesaj[i] >= 'A' && sifrelimesaj[i] <= 'Z')
        {
            sifrelimesaj[i] = (sifrelimesaj[i] - 'A' - y + 26) % 26 + 'A';
        }
    }

    printf("Cozulmus Mesaj: ");
    for (i = 0; i < strlen(sifrelimesaj); i++)
    {
        printf("%c", sifrelimesaj[i]);
    }

}
