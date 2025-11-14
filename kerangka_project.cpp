//============================== WELCOME TO OUR PROGRAM, KAK!!===================================
//============================ BUDGETBUDDY : KODT DAILY TRACKER =================================
//================================== KELOMPOK 1 : ILKOMP B ======================================

#include <iostream> // untuk input output program
#include <string> // untuk tipe data string
#include <iomanip> // untuk format angka desimal
#include <fstream> // untuk membuat/membaca/menulis file
using namespace std;

// ================== DEKLARASI DAN INISIALISASIIN DULU VARIABEL GLOBALNYA ==================
double saldo = 0; // kenapa diinisialisasiin dari 0? karena saldo user dimulai dari 0
string pengeluaran[100]; // pake panjang array 100 ya untuk antisipasi ajasi gamungkin juga kan pengeluaran user sampe 100 wkwk banyak bet buat apa aje coba
double jumlahPengeluaran[100]; // menyesuaikan banyaknya pengeluaran, misal pengeluarannya buat makan, nah ini input jumlah pengeluarannya
int jumlahData = 0; // data pengeluaran yang diinputkan oleh user

// ================== FUNCTION BUAT BIKIN FILE BARU SECARA LANGSUNG ==================
void simpanData() { // kenapa pake void? karena ini fungsi tanpa mengembalikan nilai, sekadar untuk menyimpan data ke file
	ofstream file ("keuangan.txt"); // membuat file yg namanya "keuangan.txt"
	
	if (file.is_open()){ // ngecek apakah file udah berhasil kebuka apa belom
		file << saldo << endl; // menyimpan saldo ke dalam file di baris pertama
		//nah abis itu, nantikan user nginput tuh pengeluarannya
		//nanti otomatis dalam file ini ke list pengeluaran beserta nilai pengeluarannya
		for ( int i = 0; i < jumlahData; i++) { // untuk nulis semua data pengeluaran satu persatu
			file << pengeluaran[i] << " = " << jumlahPengeluaran[i] << endl; // format penulisan yang bakal tampil di file
		}	
		file.close(); //abis user nginput filenya bakal ketutup
    	cout << "Data berhasil disimpan ke 'keuangan.txt'\n";
	} else { // kalau is_opennya false maka masuk ke else dan tampilannya bakal begini :
		cout << "Gagal menyimpan data!\n";
	}
}
// ================== FUNCTION UNTUK MEMUAT DATA DARI FILE ==================
void muatData() { //baca data dari file ke memory program
	ifstream file("keuangan.txt"); //ifstream buat apa hayo? yaa betul, buat buka file keuangan.txt yg dh kita buat
	
	if(file.is_open()) { // kalau file berhasil dibuka
		file >> saldo; // ini akan ngebaca data di file dari barisan pertama
		file.ignore(); //lewati sisa newline biar pembacaan baris berikutnya dengan getline ga bermasalah
		
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

void ringkasan() {
    cout << "fiturnya ntar ditambahin sama sehen\n";
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

