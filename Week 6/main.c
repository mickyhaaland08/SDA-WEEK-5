#include "mahasiswa.h"

// Menampilkan menu
void TampilkanMenu() {
    printf("\n===== MENU UTAMA =====\n");
    printf("1. Tambah Data Mahasiswa\n");
    printf("2. Lihat dan Urutkan Daftar Mahasiswa\n");
    printf("3. Tampilkan Jumlah Mahasiswa\n");
    printf("4. Salin Mahasiswa dengan Nilai > 70\n");
    printf("5. Lihat Data yang Telah Disalin\n");
    printf("6. Hapus Data Duplikat\n");
    printf("7. Hapus Seluruh Data\n");
    printf("0. Keluar dari Program\n");
    printf("Masukkan pilihan Anda: ");
}

// Menampilkan sub menu untuk mengurutkan daftar mahasiswa
void SubmenuUrutkan(List *L) {
    int pilihan, tipeUrutan;
    printf("\nUrutkan berdasarkan:\n");
    printf("1. Nama Mahasiswa\n");
    printf("2. Nilai UTS\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &pilihan);
    
    printf("\nPilih jenis urutan:\n");
    printf("1. Urutan Menaik \n");
    printf("2. Urutan Menurun \n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d", &tipeUrutan);

    if (pilihan == 1 || pilihan == 2) {
        SortList(L, pilihan == 1, tipeUrutan == 1);
        printf("\n=== Daftar Mahasiswa Setelah Pengurutan ===\n");
        PrintList(*L);
    } else {
        printf("Pilihan tidak valid! Silakan coba lagi.\n");
    }
}

int main() {

    List L1 = NULL, L2 = NULL;
    infotype data;
    int pilihan;

    do {
        TampilkanMenu();
        scanf("%d", &pilihan);
        getchar();  

        switch (pilihan) {
            case 1:
                printf("Masukkan Nama Mahasiswa: ");
                fgets(data.nama, sizeof(data.nama), stdin);
                data.nama[strcspn(data.nama, "\n")] = 0;
                printf("Masukkan Nilai UTS: ");
                scanf("%d", &data.nilaiUTS);
                InsertSortedByNama(&L1, data);
                printf("Data mahasiswa berhasil ditambahkan.\n");
                break;

            case 2:
                if (L1 == NULL) {
                    printf("Daftar mahasiswa masih kosong!\n");
                } else {
                    SubmenuUrutkan(&L1);
                }
                break;

            case 3:
                printf("Total Mahasiswa: %d\n", HitungElement(L1));
                break;

            case 4:
                CopyAtas70(&L2, L1);
                printf("Mahasiswa dengan Nilai UTS > 70 telah disalin ke daftar baru.\n");
                break;

            case 5:
                if (L2 == NULL) {
                    printf("Belum ada data yang disalin.\n");
                } else {
                    printf("\n=== Daftar Mahasiswa dengan Nilai > 70 ===\n");
                    PrintList(L2);
                }
                break;

            case 6:
                RemoveDuplikat(&L2);
                printf("Data duplikat telah dihapus dari daftar.\n");
                break;

            case 7: {
                char konfirmasi;
                printf("Apakah Anda yakin ingin menghapus semua data? (y/n): ");
                scanf(" %c", &konfirmasi);
                if (konfirmasi == 'y' || konfirmasi == 'Y') {
                    DeleteList(&L1);
                    DeleteList(&L2);
                    printf("Seluruh data telah dihapus.\n");
                } else {
                    printf("Penghapusan data dibatalkan.\n");
                }
                break;
            }

            case 0:
                printf("Keluar dari program...\n");
                DeleteList(&L1);
                DeleteList(&L2);
                break;

            default:
                printf("Pilihan tidak valid! Silakan masukkan nomor yang sesuai.\n");
        }
    } while (pilihan != 0);

    return 0;
}
