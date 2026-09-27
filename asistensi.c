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