# Special-ID-Generator
## Razzan Kautsar Mahendra
## 5048261049

<img width="469" height="181" alt="Screenshot 2026-09-27 221757" src="https://github.com/user-attachments/assets/c23d4cb5-9880-4715-ab46-264e25247d60" />

Output tersebut didapat dari 3 input yang juga sudah tertera pada screenshot, menggunakan tipe data char untuk nama dan asal kota, int untuk umur. Untuk menghasilkan Special ID tersebut, biar saya jelaskan secara urut. Pada bagian awal ID dan akhir ID berupa huruf dengan cara menghitung panjang string nama secara manual dengan perulangan while. Tambahan logika if juga untuk akhir ID agar dilakukan pengecekan jika yang di input huruf kecil maka dengan tambahan logika if dapat mengubahnya menjadi kapital di output secara otomatis. Setelah itu, operasi pertama yang saya gunakan adalah 6767 - umur, lalu dilanjut dengan umur itu sendiri, terakhir operasi kedua adalah nilai dari penjumlahan dari inisial dari asal kota (Nilai huruf kapital + Nilai huruf kecil). Dan semua komponen variabel disatukan menggunakan sprintf menjadi satu string baru yang disimpan di variabel id.

### Penjelasan kode yang saya buat:
- #include <stdio.h>: memanggil library
- int main(): fungsi utama (tempat program dieksekusi)
- char nama[100], asal_kota[100]: menampung 100 karakter
- int umur: menyimpan angka umur
- printf(): menampilkan petunjuk input
- scanf(): membaca input
- while: mencek karakter satu per satu sampai menemukan karakter '\0' (karakter penanda akhir string). Digunakan untuk menghitung panjang nama
- nama[len - 1]: mengambil karakter terakhir dari nama
- if (akhiran >= 'a' && akhiran <= 'z'): mengecek apakah huruf terakhir berupa huruf kecil. Jika ya, dikurangi 32 (karena selisih kode ASCII huruf kecil dan kapital adalah 32) untuk mengubahnya menjadi huruf kapital.
- int op1 = 6767 - umur: operasi pengurangan
- asal_kota[0]: mengambil huruf pertama (inisial) dari asal kota
- if ... else: menentukan pasangan huruf kapital (asal_besar) dan huruf kecil (asal_kecil) dari inisial tersebut
- op2: Menjumlahkan nilai desimal ASCII dari huruf besar dan huruf kecil inisial kota
- sprintf(): Berfungsi untuk menyatukan/menggabungkan (konkatenasi) semua komponen variabel (nama[0], op1, umur, op2, dan akhiran) menjadi satu string baru yang disimpan dalam variabel id

### Berikut source code lengkap yang saya buat
#include <stdio.h>

int main() {
    char nama[100], asal_kota[100];
    int umur;

    printf("Masukkan nama depan anda: "); 
    scanf(" %s", &nama);
    printf("Masukkan asal kota anda: ");
    scanf(" %s", &asal_kota);
    printf("Masukkan umur anda: ");
    scanf(" %d", &umur);

    int len = 0;
    while (nama[len] != '\0') {
        len++;
    }
    char akhiran = nama[len - 1];
    if (akhiran >= 'a' && akhiran <= 'z') {
        akhiran = akhiran-32;
    }

    int op1 = 6767 - umur;

    char inisial_asal = asal_kota[0];
    char asal_besar, asal_kecil;

    if (inisial_asal >= 'a' && inisial_asal <= 'z') {
        asal_kecil = inisial_asal;
        asal_besar = inisial_asal - 32;
    } else {
        asal_besar = inisial_asal;
        asal_kecil = inisial_asal + 32;
    }
    int op2 = (int)asal_besar + (int)asal_kecil;

    char id[50];
    sprintf(id, "%c%d%d%d%c", nama[0], op1, umur, op2, akhiran);


    printf("\n----------------------------------------------\n");
    printf("\nID   : %s\n", id);
    printf("Nama : %s\n", nama);
    printf("Asal : %s\n", asal_kota);
    printf("\n----------------------------------------------\n");

}
