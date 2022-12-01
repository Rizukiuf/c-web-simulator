/***********************************/
/* Program   : listdp.c */
/* Deskripsi : file BODY List Linier Double Pointer Simulasi Browser */
/* NIM/Nama  : 24060121130050/Rizki Utama Fauzi & 24060121140134/Dhiya Ulhaq*/
/* Tanggal   : 27-11-2022*/
/***********************************/

#ifndef listdp_C
#define listdp_C

#include "listdp.h"

/*Prototype*/
/* ----- Test List Kosong ----- */
boolean ListEmpty (List L){
/* Mengirim true jika list kosong */
/*Kamus Lokal*/

/*Algoritma*/
    return First(L) == Nil;
}

/* ----- Pembuatan List Kosong ----- */
void CreateList (List *L){
/* I.S.		: sembarang
   F.S.		: Terbentuk list kosong */
/*Kamus Lokal*/

/*Algoritma*/
    First(*L) = Nil;
}

/* ----- Manajemen Memori ----- */
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak Nil,
   dan misalnya menghasilkan P, maka
   Info(P) = X, Next(P) = Nil
   Jika alokasi gagal, mengirimkan Nil */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    P = (address)malloc(sizeof(ElmtList));
    if(P!=Nil){
        strcpy(info(P),X);
        //info(P) = X;
        next(P) = Nil;
        prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address *P){
/* I.S.		: P terdefinisi
   F.S.		: P dikembalikan ke sistem
   Melakukan dealokasi/pengembalian address P */
/*Kamus Lokal*/

/*Algoritma*/
    free(*P);
}

/* ----- Primitif Berdasarkan Alamat ------ */
/* Penambahan Elemen Berdasarkan Alamat */
void InsertFirst (List *L, address P){
/* I.S. 	: Sembarang, P sudah dialokasi
   F.S.		: Menambahkan elemen ber-address P sebagai elemen pertama */
/*Kamus Lokal*/
    address Last;
/*Algoritma*/
    if (!ListEmpty(*L)){
        next(P) = First(*L);
        prev(First(*L)) = P;
    }
    First(*L) = P;
}

void InsertAfter (List *L, address P, address Prec){
/* I.S.		: Prec pastilah elemen list dan bukan elemen terakhir,
			  P sudah dialokasi
   F.S. 	: Insert P sebagai elemen sesudah elemen beralamat Prec */
/*Kamus Lokal*/

/*Algoritma*/
    next(P) = next(Prec);
    prev(next(Prec)) = P;
    next(Prec) = P;
    prev(P) = Prec;
}

void InsertLast (List *L, address P){
/* I.S.		: Sembarang, P sudah dialokasi
   F.S.		: P ditambahkan sebagai elemen terakhir yang baru */
/*Kamus Lokal*/
    address Last;
/*Algoritma*/
    if (ListEmpty(*L)){
        First(*L) = P;
    }
    else{
        Last = First(*L);
        while (next(Last) != Nil){
            Last = next(Last);
        }
        next(Last) = P;
        prev(P) = Last;
    }
}

/* Penghapusan Sebuah Elemen */
void DelFirst (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen pertama list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              First element yang baru adalah suksesor elemen pertama yang
              lama */
/*Kamus Lokal*/

/*Algoritma*/
    *P = First(*L);
    if (next(*P) == Nil){
        First(*L) = Nil;
    }
    else{
        First(*L) = next(*P);
        prev(First(*L)) = Nil;
        next(*P) = Nil;
    }
}

void DelLast (List *L, address *P){
/* I.S.     : List tidak kosong
   F.S.     : P adalah alamat elemen terakhir list sebelum penghapusan
              Elemen list berkurang satu (mungkin menjadi kosong)
              Last element baru adalah predesesor elemen pertama yang
              lama, jika ada */
/*Kamus Lokal*/

/*Algoritma*/
    *P = First(*L);
    if (next(*P) == Nil){
        First(*L) = Nil;
    }
    else{
        while (next(*P) != Nil){
            *P = next(*P);
        }
        next(prev(*P)) = Nil;
        prev(*P) = Nil;
    }
}

void DelAfter (List *L, address *Pdel, address Prec){
/* I.S.     : List tidak kosong. Prec adalah anggota list L.
   F.S.     : Menghapus Next(Prec) :
              Pdel adalah alamat elemen list yang dihapus */
/*Kamus Lokal*/

/*Algoritma*/
    *Pdel = next(Prec);
    next(Prec) = next(next(Prec));
    prev(next(Prec)) = Prec;
    prev(*Pdel) = Nil;
    next(*Pdel) = Nil;
}

/* Proses Semua Elemen List */
void PrintInfo(List L){
/*  I.S. : List mungkin kosong
    F.S. : Jika list tidak kosong, semua info yg disimpan pada elemen
    list diprint
    Jika list kosong, hanya menuliskan "list kosong" */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    if (!ListEmpty(L)){
        P = First(L);
        printf("[");
        while (P != Nil){
            printf(" %s ", info(P));
            P = next(P);
        }
        printf("]");
    }
    else{
        printf("list kosong\n");
    }
}


/* Nambahin sendiri buat ngetes komponen prev tElmtList */
void PrintInversInfo (List(L)){
/* I.S.     : List mungkin kosong
   F.S.     : Jika list tidak kosong, semua info yg disimpan pada elemen
              list diprint dari belakang
              Jika list kosong, hanya menuliskan "list kosong" */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    if (!ListEmpty(L)){
        P = First(L);
        while (next(P) != Nil){
            P = next(P);
        }
        printf("[");
        while (P != Nil){
            printf(" %s ", info(P));
            P = prev(P);
        }
        printf("]\n");
    }
    else{
        printf("list kosong\n");
    }
}

void DelAll (List *L){
/*{ I.S. sembarang }
{ F.S. Delete semua elemen list dan alamat elemen di-dealokasi }
{ List L menjadi list kosong } */
/*Kamus Lokal*/
    address P;
/*Algoritma*/
    while (!ListEmpty(*L)){
        DelFirst(L, &P); //next(P) sudah di-Nil-kan
        Dealokasi(&P);
    }
}


/* Print Page yang saat ini sedang diakses oleh user */
void PrintCurrPage (List L, address P){
/* I.S.     : List mungkin kosong
   F.S.     : Membuat tampilan user interface alamat situs yang sedang diakses.
              Jika list kosong, menampilkan "You didn't open the browser!",
              Jika list tidak kosong, menampilkan info(P) */
/*Kamus Lokal*/
    int i, lenght;
/*Algoritma*/
    if (P != Nil){
        printf("\n");
        if (prev(P) != Nil && next(P) != Nil){
            printf("<< To Back                 To Forward >>");
        }
        else{
            if (next(P) != Nil){
                printf("                           To Forward >>");
            }
            if (prev(P) != Nil){
                printf("<< To Back");
            }
        }
        printf("\n+--------------------------------------+\n|");
        lenght = strlen(info(P));
        for (i = 1; i <= (38-lenght)/2; i++){
            printf(" ");
        }
        printf("%s", info(P));
        while (i <= 38-lenght){
            printf(" ");
            i++;
        }
        printf("|\n+--------------------------------------+\n");
    }
    else{
        printf("\n+--------------------------------------+");
        printf("\n|     You didn't open the browser!     |");
        printf("\n+--------------------------------------+\n");
    }
}

#endif // listdp_C
