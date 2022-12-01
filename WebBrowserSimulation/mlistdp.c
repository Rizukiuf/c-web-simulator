/***********************************/
/* Program   : mlistdp.c */
/* Deskripsi : file DRIVER List Linier Double Pointer Simulasi Browser */
/* NIM/Nama  : 24060121130050/Rizki Utama Fauzi & 24060121140134/Dhiya Ulhaq*/
/* Tanggal   : 27-11-2022*/
/***********************************/

#include <stdio.h>
#include "listdp.h"
#include <string.h>
#include <stdlib.h>

int main()
{
/*Kamus Main*/
    List L1;
    infotype a[20], b[20], c[20], d[20], e[20], f[20], g[20], website[20];
    address Ads1, Ads2, Ads3, Ads4, Ads5, Ads6, Ads7;
    address CurrPage; //Posisi user/ Website yang sedang dibuka oleh user
    char input; //Input untuk simulasi Web Browser
    address A, DelLAds; //Alamat untuk menyimpan alokasi sementara dan elemen sebelum didealokasi
    boolean autocls; //Auto clear creen mode

/*Algoritma*/
    printf("Ini DRIVER modul ADT List Double Pointer Simulasi Browser.\n");

    printf("\n====================================================================== (Alokasi)");
    printf("\nNilai var ");
    strcpy(a,"Google"); printf("\na=%s, ", a);
    strcpy(b,"Facebook"); printf("\nb=%s, ", b);
    strcpy(c,"Bing"); printf("\nc=%s, ", c);
    strcpy(d,"Youtube"); printf("\nd=%s, ", d);
    strcpy(e,"Twitter"); printf("\ne=%s, ", e);
    strcpy(f,"Hoyoverse"); printf("\nf=%s, ", f);
    strcpy(g,"Whatsapp"); printf("\ng=%s, ", g);
    printf("\ndialokasikan pada address:");
    Ads1 = Alokasi(a); printf("\ninfo(Ads1)=%s", info(Ads1));
    Ads2 = Alokasi(b); printf("\ninfo(Ads2)=%s", info(Ads2));
    Ads3 = Alokasi(c); printf("\ninfo(Ads3)=%s", info(Ads3));
    Ads4 = Alokasi(d); printf("\ninfo(Ads4)=%s", info(Ads4));
    Ads5 = Alokasi(e); printf("\ninfo(Ads5)=%s", info(Ads5));
    Ads6 = Alokasi(f); printf("\ninfo(Ads6)=%s", info(Ads6));
    Ads7 = Alokasi(g); printf("\ninfo(Ads7)=%s", info(Ads7));
    printf("\n");

/* SIMULASI WEB BROWSER */
    printf("\n========================<SIMULASI WEB BROWSER>======================== (--)\n");
    printf("\n{CreateList(&L1)}");
    CreateList(&L1);
    CurrPage = First(L1);
    PrintCurrPage(L1, CurrPage);

    printf("\nOpening Web Browser...");
    printf("\nFirst Page at Ads1: {InsertFirst(&L1, Ads1)}");
    InsertFirst(&L1, Ads1);
    CurrPage = Ads1;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads2... {InsertLast(&L1, Ads2)}");
    InsertLast(&L1, Ads2);
    CurrPage = Ads2;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads3... {InsertLast(&L1, Ads3)}");
    InsertLast(&L1, Ads3);
    CurrPage = Ads3;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads4... {InsertLast(&L1, Ads4)}");
    InsertLast(&L1, Ads4);
    CurrPage = Ads4;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads5... {InsertLast(&L1, Ads5)}");
    InsertLast(&L1, Ads5);
    CurrPage = Ads5;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads6... {InsertLast(&L1, Ads6)}");
    InsertLast(&L1, Ads6);
    CurrPage = Ads6;
    PrintCurrPage(L1, CurrPage);

    printf("\nBrowsing Ads7... {InsertLast(&L1, Ads7)}");
    InsertLast(&L1, Ads7);
    CurrPage = Ads7;
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n         -- You went FORWARD --");
    CurrPage = next(CurrPage);
    PrintCurrPage(L1, CurrPage);

    printf("\n          -- You went BACK --");
    CurrPage = prev(CurrPage);
    PrintCurrPage(L1, CurrPage);

    /* Inputan User */
    autocls = false;
    do{
        printf("\nType 1 to BACK\nType 2 to FORWARD\nType r to RELOAD\n"
               "Type h to SHOW HISTORY\nType b to BROWSE New Website\n"
               "Type c to CLEAR SCREEN\nType m to CHANGE Autocls Mode\n"
               "Type 0 to EXIT\nInput: ");
        scanf(" %c", &input);
        if (autocls == true){
            system("cls");
        }
        if (input == '1'){
            if (prev(CurrPage) != Nil){
                printf("\n          -- You went BACK --");
                CurrPage = prev(CurrPage);
                PrintCurrPage(L1, CurrPage);
            }
            else{
                printf("\n   (!) Already on the first page! (!)");
                PrintCurrPage(L1, CurrPage);
            }
        }
        else if (input == '2'){
            if (next(CurrPage) != Nil){
                printf("\n         -- You went FORWARD --");
                CurrPage = next(CurrPage);
                PrintCurrPage(L1, CurrPage);
            }
            else{
                printf("\n   (!) Already on the last page! (!)");
                PrintCurrPage(L1, CurrPage);
            }
        }
        else if (input == 'r' || input == 'R'){
            printf("\n             -- Reloaded --             ");
            PrintCurrPage(L1, CurrPage);
        }
        else if (input == 'h' || input == 'H'){
            printf("\nHistory: "); PrintInfo(L1);
            PrintCurrPage(L1, CurrPage);
        }
        else if (input == 'b' || input == 'B'){
            printf("Enter website's name: ");
            scanf("%s", &website);
            A = Alokasi(website);
            while (next(CurrPage) != Nil){
                DelLast(&L1, &DelLAds);
                Dealokasi(&DelLAds);
            }
            InsertLast(&L1, A);
            CurrPage = A;
            PrintCurrPage(L1, CurrPage);
        }
        else if (input == 'c' || input == 'C'){
            system("cls");
        }
        else if (input == 'm' || input == 'M'){
            if (autocls == false){
                autocls = true;
                printf("\n     -- Autocls Mode ACTIVATED! --");
            }
            else{
                autocls = false;
                printf("\n    -- Autocls Mode DEACTIVATED! --");
            }
            PrintCurrPage(L1, CurrPage);

        }
        else if (input == '0'){
            printf("\nClosing the Web Browser...\nThank You, Come Again...\n");
            CurrPage = Nil;
            DelAll(&L1);
            printf("\n====================================================================== (--)");
            printf("\nOpen the Web Browser again?\n"
                   "Type y for YES, type n or any except y for NO\nInput: ");
            scanf(" %c", &input);
            if (input == 'y' || input == 'Y'){
                A = Alokasi("Google");
                InsertFirst(&L1, A);
                CurrPage = A;
                PrintCurrPage(L1, CurrPage);
            }
            else{
                printf("\nThank You for using Our Program!\n");
                input = '0';
            }
        }
        else{
            printf("\nWrong Input!\n");
        }
    }while(input != '0');

    return 0;
}
