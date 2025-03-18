#include "spnrsll.h"
#include <stdio.h>

int main() {
    /* Kamus Lokal */
    List MyList;
    infotype isi;
    address P, Prec;
    P = Alokasi(9);

    /* Program */
    CreateList(&MyList); // List sudah terbentuk, digunakan untuk memanipulasi elemen

    // Studi kasus implementasi operasi dasar pada linked list
    printf("Menambahkan elemen ke depan: 7\n");
    InsVFirst(&MyList, 7);  
    PrintInfo(MyList);

    printf("Menambahkan elemen ke belakang: 11\n");
    InsVLast(&MyList, 11); 
    PrintInfo(MyList);

    Prec = Search(MyList, 7);  
    if (Prec != NULL) {
        printf("Menambahkan elemen ke 9 setelah 7\n");
        InsertAfter(&MyList, P, Prec);  
    }
    PrintInfo(MyList);

    printf("Menambahkan elemen ke depan 5\n");
    InsVFirst(&MyList, 5);  
    PrintInfo(MyList);

    printf("Menambahkan elemen ke belakang: 13\n");
    P = Alokasi(13);  
    if (P != NULL) {
        InsertLast(&MyList, P);  
    }
    PrintInfo(MyList);

    printf("Menghapus elemen terakhir\n");
    DelVLast(&MyList, &isi);  
    printf("Elemen yang dihapus: %d\n", isi);
    PrintInfo(MyList);

    printf("Menghapus elemen yang 7\n");
    DelP(&MyList, 7);  
    PrintInfo(MyList);

    printf("Menghapus elemen pertama\n");
    DelVFirst(&MyList, &isi);  
    printf("Elemen yang dihapus: %d\n", isi);
    PrintInfo(MyList);

    DelAll(&MyList);  
    PrintInfo(MyList);

    /* Finishing */
    return 0;
}
