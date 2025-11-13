#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

// ================== DEKLARASI DAN INISIALISASIIN DULU VARIABEL GLOBALNYA ==================
double saldo = 0;
string pengeluaran[100];
double jumlahPengeluaran[100];
int jumlahData = 0;

// ================== FUNCTION BUAT BIKIN FILE BARU SECARA LANGSUNG ==================
void simpanData() {
	ofstream file ("keuangan.txt");
	
	if (file.is_open()){
		file << saldo << endl;
		//nah abis itu, nantikan user nginput tuh pengeluarannya
		//nanti otomatis dalam file ini ke list pengeluaran beserta nilai pengeluarannya
		for ( int i = 0; i < jumlahData; i++) {
			file << pengeluaran[i] << " = " << jumlahPengeluaran[i] << endl;
		}	
		file.close(); //abis user nginput filenya bakal ketutup
    	cout << "Data berhasil disimpan ke 'keuangan.txt'\n";
	} else {
		cout << "Gagal menyimpan data!\n";
	}
}
// ================== FUNCTION UNTUK MEMUAT DATA DARI FILE ==================
void muatData() {
	ifstream file("keuangan.txt");
	
	if(file.is_open()) {
		file >> saldo;
		file.ignore();
		
		string line;
		jumlahData = 0;
		
		//========== pake looping biar data pengeluaran kebaca ==============
		while (getline(file, line)) {
			size_t pos = line.find (",");
			if (pos != string::npos) {
				pengeluaran [jumlahData] = line.substr (0, pos);
				jumlahPengeluaran[jumlahData] = stod(line.substr(pos + 1));
				jumlahData++;
			}
		}
		file.close(); //janlup tutup file after baca filenyahh
		cout << "Data berhasil dimuat dari 'keuangan.txt'\n";
	} else {
		cout << "Belum ada data tersimpan, mulai dulu dari awal.\n";
	}
}

//================== FUNCTION MENAMPILKAN MENU ==================
void tampilkanMenu() {
    cout << "\n========== BUDGETBUDDY : KOST DAILY TRACKER ==========\n";
    cout << "1. Tambah Pemasukan\n";
    cout << "2. Catat Pengeluaran\n";
    cout << "3. Lihat Ringkasan Keuangan\n";
    cout << "4. Lihat Daftar Pengeluaran\n";
    cout << "5. Simpan dan Keluar\n";
    cout << "==================================================\n";
    cout << "Pilih dulu dong menunya (1-5): ";
}

void tambahPemasukan() {
    cout << "fiturnya ntar ditambahin sama rayen\n";
}

void catatPengeluaran() {
    cout << "fiturnya ntar ditambahin sama bita\n";
}

void ringkasan() {
    cout << "fiturnya ntar ditambahin sama sehen\n";
}

void lihatDaftar() {
    cout << "fiturnya ntar ditambahin sama emil\n";
}

// ================== FUNGSI UTAMA ==================
int main() {
    muatData(); 
    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahPemasukan(); 
				break;
            case 2: catatPengeluaran(); 
				break;
            case 3: ringkasan(); 
				break;
            case 4: lihatDaftar(); 
				break;
            case 5:
                simpanData();
                cout << "\nHOLAA!! Makasii yaa sudah mau pakai program ini!! semoga harimu senin terus:) \n";
                break;
            default:
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5);

    return 0;
}

