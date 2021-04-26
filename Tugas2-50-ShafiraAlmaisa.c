#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
  int no, jlh, uang, nomorm, total, sisa, tambahan, kembalian, sisa2;
  int price[6] = {0, 30000, 25000, 30000, 25000, 35000};
  char decision;

  // membuat fungsi untuk output menu
  void menu() {
    printf(" _______________________________________________\n");
    printf("+\t|\t\t\t\t\t+\n");
    printf("|  No   |   Menu                       Harga    |\n");
    printf("+_______|_______________________________________+\n");
    printf("|\t|\t\t\t\t\t|\n");
    printf("|   1   | Tiramishoot                    30k    |\n");
    printf("|   2   | Browsyu Milkeu                 25k    |\n");
    printf("|   3   | Dreamy Taro                    30k    |\n");
    printf("|   4   | Reddeu Velvet                  25k    |\n");
    printf("|   5   | Sparkling Rainbow              35k    |\n");
    printf("+_______|_______________________________________+\n");
  }

  // membuat fungsi hitung pembayaran
  void payment() {

    total = jlh * price[nomorm];

    printf("\nTotal belanjaan     : Rp. %d", total);
    printf("\nMasukkan uang anda  : Rp. ");
    scanf("%d", &uang);
    getchar();

    sisa = uang - total;
    sisa2 = sisa;

    if (sisa < 0) {

      sisa = sisa * -1;

      printf("\nUang anda kurang        : Rp. %d", sisa);
      printf("\nMasukkan uang tambahan  : Rp. ");
      scanf("%d", &tambahan);
      getchar();

      kembalian = tambahan - sisa;

      printf("\nKembalian anda          : Rp. %d", kembalian);
    } else {
      printf("\nKembalian anda          : Rp. %d", sisa2);
    }
  }

  // membuat fungsi belanja

  void belanja() {
    printf("\nApakah anda ingin belanja yang lain (y/n) ? ");
    scanf("%c", &decision);
    getchar();

    while (decision != 'y' && decision != 'n') {
      printf("\nMaaf input anda tidak sesuai!\n");
      printf("Apakah anda ingin belanja yang lain (y/n) ? ");
      scanf("%c", &decision);
      getchar();
    }
  }

  // fungsi untuk memesan
  
  void shop() {
    printf("\ninput nomor menu : ");
    scanf(" %d", &nomorm);
    getchar();

    while (nomorm > 5) {
      printf("\nMaaf, input anda tidak sesuai!\n");
      printf("input nomor menu : ");
      scanf(" %d", &nomorm);
      getchar();
    }

    printf("input banyak menu ini yang diinginkan : ");
    scanf("%d", &jlh);
    getchar();

    belanja();
  }

  // fungsi untuk pengulangan program

  void opening() {
    printf("\n\n1. Daftar menu\n");
    printf("2. Belanja\n");
    printf("3. Keluar\n\n");

    printf("Pilihan anda : ");
    scanf("%d", &no);
    getchar();

    while (no > 3) {
      printf("\nMaaf, input anda tidak sesuai!\n");
      printf("Pilihan anda : ");
      scanf("%d", &no);
      getchar();
    }

    switch (no) {
      case 1:
          menu();
          break;
      case 2:
          shop();
          break;
      default:
          exit(0);
    }

  }

  printf("----------------------------------\n");
  printf("|                                |\n");
  printf("| Selamat datang di bubbly boba! |\n");
  printf("|                                |\n");
  printf("----------------------------------");

  opening();

  printf("\nTekan enter untuk lanjut...");
  getch();

  opening();

  switch (decision) {
    case 'y':
        shop();
        break;
    default:
        break;
  }

  payment();

  return 0;
}
