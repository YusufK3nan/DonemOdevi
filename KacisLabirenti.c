#include <stdio.h>
#include <stdbool.h>

// Labirentin boyutunu belirleyen sabit. 5x5'lik bir matris kullanacağız.
#define BOYUT 5

// Labirent haritası:
// 1: Gidilebilir yol
// 0: Duvar veya engel
// Başlangıç noktası (0,0), Çıkış noktası (4,4) olarak varsayılmıştır.
int labirent[BOYUT][BOYUT] = {
    {1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1},
    {1, 1, 1, 0, 1},
    {0, 0, 1, 1, 1},
    {1, 1, 1, 0, 1}};

// Ziyaret edilen hücreleri tutan matris.
// 1: Ziyaret edildi, 0: Henüz ziyaret edilmedi.
// Bu matris, sonsuz döngüye girmeyi engeller (aynı yere tekrar gitmemek için).
int ziyaret[BOYUT][BOYUT] = {0};

// Çözüm yolunu tutan matris.
// 1: Çözüm yolunun parçası, 0: Çözüm yolunda değil.
int yol[BOYUT][BOYUT] = {0};

// Hareket yönleri dizileri.
// dx: Satır değişimi, dy: Sütun değişimi.
// Sırasıyla: Aşağı (1,0), Yukarı (-1,0), Sağ (0,1), Sol (0,-1)
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// Bir hücreye gitmenin güvenli olup olmadığını kontrol eden fonksiyon.
// x, y: Kontrol edilecek koordinatlar.
bool gecerli(int x, int y)
{
    // 1. Koordinatlar labirent sınırları içinde mi? (0 ile BOYUT-1 arasında)
    // 2. Hücre bir yol mu? (labirent[x][y] == 1)
    // 3. Hücre daha önce ziyaret edildi mi? (ziyaret[x][y] == 0)
    return x >= 0 && x < BOYUT && y >= 0 && y < BOYUT && labirent[x][y] == 1 && ziyaret[x][y] == 0;
}

// Derinlik Öncelikli Arama (DFS) algoritması ile yolu bulan özyinelemeli (recursive) fonksiyon.
// x, y: Şu anki konum.
bool dfs(int x, int y)
{
    // ADIM 1: Hedefe ulaştık mı kontrolü.
    // Eğer sağ alt köşeye (4,4) geldiysek ve orası da yol ise, çıkışı bulduk demektir.
    if (x == BOYUT - 1 && y == BOYUT - 1 && labirent[x][y] == 1)
    {
        yol[x][y] = 1; // Çıkış noktasını yola ekle
        return true;   // Başarı ile dön
    }

    // ADIM 2: Geçerlilik kontrolü.
    // Eğer buraya gitmek güvenli değilse (duvar, sınır dışı veya ziyaret edilmiş), geri dön.
    if (!gecerli(x, y))
    {
        return false;
    }

    // ADIM 3: İşaretleme.
    // Bu hücreye geldik, ziyaret edildi olarak işaretle.
    ziyaret[x][y] = 1;
    // Şimdilik bu hücrenin çözüm yolunun bir parçası olduğunu varsayıyoruz.
    yol[x][y] = 1;

    // ADIM 4: Komşuları gezme.
    // 4 farklı yöne (Aşağı, Yukarı, Sağ, Sol) gitmeyi dene.
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k]; // Yeni satır
        int ny = y + dy[k]; // Yeni sütun

        // Eğer komşu hücreden çıkışa giden bir yol bulunursa, true döndür.
        if (dfs(nx, ny))
        {
            return true; // Yolu bulduk, üst fonksiyona haber ver.
        }
    }

    // ADIM 5: Geri İzleme (Backtracking).
    // Eğer 4 yöne de gidip çıkış bulamadıysak, bu hücre çıkışa giden yolda DEĞİLDİR.
    // Yoldan çıkar (0 yap) ama ziyaret edildi (1) olarak kalsın ki tekrar denemeyelim.
    yol[x][y] = 0;
    return false; // Bu yoldan çıkış yok.
}

// Matrisi ekrana düzgün formatta yazdıran yardımcı fonksiyon.
void matrisiYazdir(const char *baslik, int m[BOYUT][BOYUT])
{
    printf("%s\n", baslik);
    for (int i = 0; i < BOYUT; i++)
    {
        for (int j = 0; j < BOYUT; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    printf("Labirent Cozucu Baslatiliyor...\n");

    // Aramayı başlangıç noktasından (0,0) başlat.
    bool bulundu = dfs(0, 0);

    if (bulundu)
    {
        printf("Cikis yolu bulundu!\n");
        // Bulunan yolu (1'ler gidilen yol, 0'lar gidilmeyen yerler) ekrana bas.
        matrisiYazdir("Yol matrisi:", yol);
    }
    else
    {
        printf("Cikis yolu bulunamadi.\n");
    }

    return 0;
}