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

// FUNCTUION TAMBAH PEMNASUKAN
void tambahPemasukan() {
double jumlah;
cout << "Masukkan jumlah pemasukan : Rp ";
cin >> jumlah;
saldo += jumlah;
cout << "? Pemasukan sebesar Rp" << fixed << setprecision(2) << jumlah << "Berhasil ditambahkan" << endl; 
}

// ================== FUNCTION CATAT PENGELUARAN ==================
void catatPengeluaran() {
    double jumlah;
	string tujuan;
	cout << "Masukkan jumlah uang pengeluaran: Rp ";
	cin >> jumlah;
	cin.ignore();
	cout << "Untuk apa uangnya dipakai (misal: makan, pulsa, laundry)? ";
	getline(cin, tujuan);

	// ==== PERCABANGAN: cek saldonya dah cukup pa blom ====
	if(jumlah > saldo){
		cout << "? Saldo tidak cukup untuk pengeluaran ini!\n";
	} else {
		saldo -= jumlah;
		pengeluaran[jumlahData] = tujuan;
		jumlahPengeluaran[jumlahData] = jumlah;
		jumlahData++;
		cout << "? Pengeluaran Rp" << jumlah << " untuk  '" << tujuan << "' telah dicatat.\n";
	}
}

// ================== FUNCTION RINGKASAN KEUANGAN ==================
void ringkasan() {
    cout << "\n========== RINGKASAN KEUANGAN ==========\n";
    cout << "Saldo saat ini : Rp" << fixed << setprecision(2) << saldo << endl;

    double total = 0;
    for (int i = 0; i < jumlahData; i++) {
        total += jumlahPengeluaran[i]; 
    }

    cout << "Total pengeluaran : Rp" << total << endl;
    cout << "Jumlah transaksi  : " << jumlahData << " kali\n";
    cout << "========================================\n";
}
void lihatDaftar() {
    cout << "\n========== DAFTAR PENGELUARAN ==========\n";

    // ==== PERULANGAN UNTUK MENAMPILKAN DATA ====
    for (int i = 0; i < jumlahData; i++) {
        cout << i + 1 << ". " << pengeluaran[i]
             << " - Rp" << fixed << setprecision(2)
             << jumlahPengeluaran[i] << endl;
    }

    if (jumlahData == 0) {
        cout << "Belum ada data pengeluaran.\n";
    }

    cout << "========================================\n";
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

