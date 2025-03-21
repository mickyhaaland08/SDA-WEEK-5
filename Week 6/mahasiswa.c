#include "mahasiswa.h"

// Deklarasi fungsi-fungsi yang berada di mahasiswa.h

// Membuat node baru dengan data tertentu
void Create_Node(address *p, infotype data) {
    *p = (address)malloc(sizeof(ElmtList));
    if (*p != NULL) {
        (*p)->info = data;
        (*p)->next = NULL;
    }
}

// Menghapus node dan membebaskan memori
void DeAlokasi(address *p) {
    free(*p);
    *p = NULL;
}

// Mengecek apakah list kosong
bool isEmpty(List L) {
    return (L == NULL);
}

// Mencetak seluruh elemen dalam list
void PrintList(List L) {
    while (L != NULL) {
        printf("Nama: %s, Nilai UTS: %d\n", L->info.nama, L->info.nilaiUTS);
        L = L->next;
    }
}

// *** OPERASI PENYISIPAN ***

// Menyisipkan elemen dengan alokasi baru di awal list
void InsVFirst(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        InsertFirst(L, P);
    }
}

// Menyisipkan elemen di awal list berdasarkan alamat
void InsertFirst(List *L, address P) {
    P->next = *L;
    *L = P;
}

// Menyisipkan elemen dengan alokasi baru di akhir list
void InsVLast(List *L, infotype X) {
    address P;
    Create_Node(&P, X);
    if (P != NULL) {
        InsertLast(L, P);
    }
}

// Menyisipkan elemen di akhir list berdasarkan alamat
void InsertLast(List *L, address P) {
    if (isEmpty(*L)) {
        *L = P;
    } else {
        address temp = *L;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

// Menyisipkan elemen setelah elemen tertentu
void InsertAfter(List *L, address P, address Prec) {
    if (Prec != NULL) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

// *** OPERASI PENGHAPUSAN ***

// Menghapus elemen pertama
void DelVFirst(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        DelFirst(L, &P);
        *X = P->info;
        DeAlokasi(&P);
    }
}

// Menghapus elemen pertama berdasarkan alamat
void DelFirst(List *L, address *P) {
    if (!isEmpty(*L)) {
        *P = *L;
        *L = (*L)->next;
        (*P)->next = NULL;
    }
}

// Menghapus elemen terakhir
void DelVLast(List *L, infotype *X) {
    address P;
    if (!isEmpty(*L)) {
        DelLast(L, &P);
        *X = P->info;
        DeAlokasi(&P);
    }
}

// Menghapus elemen terakhir berdasarkan alamat
void DelLast(List *L, address *P) {
    if (!isEmpty(*L)) {
        address temp = *L, prev = NULL;
        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }
        *P = temp;
        if (prev != NULL) {
            prev->next = NULL;
        } else {
            *L = NULL;
        }
    }
}

// Menghapus elemen tertentu dari list
void DelP(List *L, infotype X) {
    address P = *L, prev = NULL;
    while (P != NULL && strcmp(P->info.nama, X.nama) != 0) {
        prev = P;
        P = P->next;
    }
    if (P != NULL) {
        if (prev != NULL) {
            prev->next = P->next;
        } else {
            *L = P->next;
        }
        DeAlokasi(&P);
    }
}

// Menghapus elemen setelah elemen tertentu
void DelAfter(List *L, address *Pdel, address Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        *Pdel = Prec->next;
        Prec->next = (*Pdel)->next;
        (*Pdel)->next = NULL;
    }
}

// *** OPERASI PENCARIAN ***

// Mencari elemen dengan nilai tertentu
address Search(List L, infotype X) {
    while (L != NULL) {
        if (strcmp(L->info.nama, X.nama) == 0) {
            return L;
        }
        L = L->next;
    }
    return NULL;
}

// Mengecek apakah alamat P ada dalam list
bool FSearch(List L, address P) {
    while (L != NULL) {
        if (L == P) {
            return true;
        }
        L = L->next;
    }
    return false;
}

// Mencari elemen sebelum elemen dengan nilai tertentu
address SearchPrec(List L, infotype X) {
    address prev = NULL;
    while (L != NULL && strcmp(L->info.nama, X.nama) != 0) {
        prev = L;
        L = L->next;
    }
    return prev;
}

// *** FUNGSI TAMBAHAN ***

// Mengurutkan list secara ascending atau descending berdasarkan nama atau nilai
void SortList(List *L, bool byNama, bool ascending) {
    if (isEmpty(*L) || (*L)->next == NULL) return;

    bool swapped;
    do {
        swapped = false;
        address curr = *L, prev = NULL, next = curr->next;
        while (next != NULL) {
            bool condition = byNama ? (strcmp(curr->info.nama, next->info.nama) > 0)
                                    : (curr->info.nilaiUTS > next->info.nilaiUTS);
            if ((ascending && condition) || (!ascending && !condition)) {
                swapped = true;
                if (prev == NULL) {
                    *L = next;
                } else {
                    prev->next = next;
                }
                curr->next = next->next;
                next->next = curr;
                prev = next;
            } else {
                prev = curr;
                curr = next;
            }
            next = curr->next;
        }
    } while (swapped);
}

// Menghitung jumlah elemen dalam list
int HitungElement(List L) {
    int count = 0;
    while (L != NULL) {
        count++;
        L = L->next;
    }
    return count;
}

// Menyalin elemen dengan nilai lebih dari 70 ke list baru
void CopyAtas70(List *dest, List src) {
    while (src != NULL) {
        if (src->info.nilaiUTS > 70) {
            InsVLast(dest, src->info);
        }
        src = src->next;
    }
}

// Menghapus elemen duplikat berdasarkan nama
void RemoveDuplikat(List *L) {
    address curr = *L;
    while (curr != NULL && curr->next != NULL) {
        address prev = curr, temp = curr->next;
        while (temp != NULL) {
            if (strcmp(curr->info.nama, temp->info.nama) == 0) {
                prev->next = temp->next;
                DeAlokasi(&temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

// Menghapus seluruh list
void DeleteList(List *L) {
    address temp;
    while (*L != NULL) {
        temp = *L;
        *L = (*L)->next;
        DeAlokasi(&temp);
    }
}

// Menyisipkan elemen secara terurut berdasarkan nama
void InsertSortedByNama(List *L, infotype X) {
    address P;
    Create_Node(&P, X);

    if (isEmpty(*L) || strcmp((*L)->info.nama, X.nama) > 0) {
        InsertFirst(L, P);
    } else {
        address temp = *L;
        while (temp->next != NULL && strcmp(temp->next->info.nama, X.nama) < 0) {
            temp = temp->next;
        }
        InsertAfter(L, P, temp);
    }
}
