#include <iostream>
#include <string>
using namespace std;

// ================== VARIABEL GLOBAL ==================
double saldo = 0;
string pengeluaran[100];
double jumlahPengeluaran[100];
int jumlahData = 0;

// ================== FUNCTION KOSONG ==================
void simpanData() {
    cout << "?? Fungsi simpanData() masih kosong (placeholder)\n";
}

void muatData() {
    cout << "?? Fungsi muatData() masih kosong (placeholder)\n";
}

void tambahPemasukan() {
    cout << "? Fungsi tambahPemasukan() masih kosong (placeholder)\n";
}

void catatPengeluaran() {
    cout << "? Fungsi catatPengeluaran() masih kosong (placeholder)\n";
}

void ringkasan() {
    cout << "?? Fungsi ringkasan() masih kosong (placeholder)\n";
}

void lihatDaftar() {
    cout << "?? Fungsi lihatDaftar() masih kosong (placeholder)\n";
}

// ================== FUNCTION MENAMPILKAN MENU ==================
void tampilkanMenu() {
    cout << "\n========== BUDGETBUDDY : KOST DAILY TRACKER ==========\n";
    cout << "1. Tambah Pemasukan\n";
    cout << "2. Catat Pengeluaran\n";
    cout << "3. Lihat Ringkasan Keuangan\n";
    cout << "4. Lihat Daftar Pengeluaran\n";
    cout << "5. Simpan dan Keluar\n";
    cout << "==================================================\n";
    cout << "Pilih menu (1-5): ";
}

// ================== FUNGSI UTAMA ==================
int main() {
    muatData(); 
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPemasukan(); break;
            case 2: catatPengeluaran(); break;
            case 3: ringkasan(); break;
            case 4: lihatDaftar(); break;
            case 5:
                simpanData();
                cout << "\nTerima kasih sudah pakai program ini ??\n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }

    } while (pilihan != 5);

    return 0;
}

