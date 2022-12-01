/***********************************/
/* Program   : listdp.h */
/* Deskripsi : file HEADER List Linier Double Pointer Simulasi Browser */
/* NIM/Nama  : 24060121130050/Rizki Utama Fauzi & 24060121140134/Dhiya Ulhaq*/
/* Tanggal   : 27-11-2022*/
/***********************************/

/* File : listdp.h */
/* contoh ADT list berkait dengan representasi fisik pointer */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#ifndef listdp_H
#define listdp_H

#include <stdio.h>
#include <stdlib.h>

#define Nil         NULL
#define info(P)     (P)->info
#define next(P)     (P)->next
#define prev(P)     (P)->prev
#define First(L)    (L).First

typedef enum{false,true} boolean;

typedef char infotype[20];

typedef struct tElmtList *address;
typedef struct tElmtList {
    infotype info;
    address next;
    address prev;
}ElmtList;

typedef struct {
    address First;
}List;


/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L);
/* Mengirim true jika list kosong */

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L);
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P);
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */

void InsertAfter (List *L, address P, address Prec);
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (List *L, address P);
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */

void DelLast (List *L, address *P);
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */

void DelAfter (List *L, address *Pdel, address Prec);
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */


/* ----- Proses Semua Elemen List ----- */
void PrintInfo (List L);
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint
              Jika list kosong, hanya menuliskan "list kosong" */


/* Nambahin sendiri buat ngetes komponen prev tElmtList */
void PrintInversInfo (List(L));
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint dari belakang
              Jika list kosong, hanya menuliskan "list kosong" */

void DelAll (List *L);
/*{ I.S. sembarang }
{ F.S. Delete semua elemen list dan alamat elemen di-dealokasi }
{ List L menjadi list kosong } */


/* Print Page yang saat ini sedang diakses oleh user */
void PrintCurrPage (List L, address P);
/* I.S.     : List mungkin kosong
   F.S.     : Membuat tampilan user interface alamat situs yang sedang diakses.
              Jika list kosong, menampilkan "You didn't open the browser!",
              Jika list tidak kosong, menampilkan info(P) */


#endif // listdp_H
