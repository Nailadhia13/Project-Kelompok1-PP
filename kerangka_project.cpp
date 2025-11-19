#include <iostream> // untuk input output
#include <string> // untuk pakai tipe data string
#include <iomanip> // untuk format angka desimal untuk mengatur jumlah angka di belakang koma
#include <fstream> // untuk baca dan nulis file
using namespace std;

// ================== DEKLARASI DAN INISIALISASIIN DULU VARIABEL GLOBALNYA ==================
double saldo = 0; // pake double karena uang bisa aja punya nilai desimal
string pengeluaran[100]; // untuk nyimpen nama pengeluarannya user (misal: buat makan, buat gojek, dll)
double jumlahPengeluaran[100]; // untuk nyimpen harga atau jumlah dari pengeluarannya
int jumlahData = 0; // untuk nyimpen ada berapa data pengeluaran yang udah tercatat, makanya dimukai dari 0

// ================== FUNCTION BUAT BIKIN FILE BARU SECARA LANGSUNG ==================
//menyimpan data dari program ke file
void simpanData() { // fungsi tanpa mengembalikan nilai, cuma untuk menyimpan data ke file
	ofstream file ("keuangan.txt"); // buka atau buat file untuk nyimpen data pengeluaran, whiich is nama filenya "keuangan.txt"
	
	if (file.is_open()){ //memastikan file berhasil dibuka
		file << saldo << endl; // nyimpen saldo di baris pertama, lalu pindah baris
		//nah abis itu, nantikan user nginput tuh pengeluarannya
		//nanti otomatis dalam file ini ke list pengeluaran beserta nilai pengeluarannya
		for ( int i = 0; i < jumlahData; i++) { // untuk nulis semua data pengeluaran satu persatu
			file << pengeluaran[i] << " = " << jumlahPengeluaran[i] << endl; // format penulisan yang bakal tampil di file
		}	
		file.close(); // nutup file dan mastiin supaya data beneran kesimpen
    	cout << "Data berhasil disimpan ke 'keuangan.txt'\n"; //kalau is_opennya true maka data akan disimpan
	} else { // kalau is_opennya false maka masuk ke else dan tampilannya bakal begini :
		cout << "Gagal menyimpan data!\n";
	}
}
// ================== FUNCTION UNTUK MEMUAT DATA DARI FILE ==================
//membaca kembali data lama saat program dibuka kembali
void muatData() { // fungsi untuk baca data dari file ke memori program
	ifstream file("keuangan.txt"); // buka dulu dong filenya biar kebaca
	
	if(file.is_open()) { //kalau file berhasil dibuka
		file >> saldo; // baca salo dari baris pertama
		file.ignore(); // ngelewati newline biar pembacaaan baris berikutnya dengan getline ga bermasalah
		
		string line; //menyimpan satu baris teks yang dibaca dari file
		jumlahData = 0; //data dari file dimulai dari 0
		
		//========== pake looping biar data pengeluaran kebaca ==============
		while (getline(file, line)) { //baca baris pertama sampai habis, getline baca satu baris sampe /n
			size_t pos = line.find ("="); // cari posisi karakter "=" dalam suatu baris
			if (pos != string::npos) { //jika format "=" ditemukan berarti format baris sesuai harapan
				pengeluaran [jumlahData] = line.substr (0, pos); //ngambil substring  dari awal sampai sebelum koma 
				jumlahPengeluaran[jumlahData] = stod(line.substr(pos + 1)); //ngambil substring  dari after koma sampai akhir (angka) 
				//lalu angka tersebut diubah jadi bentuk double atau desimal, makanya ada stod (string to double)
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
    cout << "Hai anak maniez, silahkan mau pilih yang mana? (1-5): ";
	//user diminta menginputkan fitur yang ingin digunakan
}

// ================= FUNCTION TAMBAH PEMASUKAN =================
void tambahPemasukan() {
double jumlah;
cout << "Ciee mau nabung, mau nabung berapa nich : Rp ";
cin >> jumlah;
saldo += jumlah;
cout << "Pemasukan sebesar Rp"
	 << fixed << setprecision(2)
	 << jumlah << " Berhasil ditambahkan!!! OTW JADI SULTAN NIH" << endl; 
}

// ================== FUNCTION CATAT PENGELUARAN ==================
void catatPengeluaran() {
    double jumlah;
	string tujuan;
	cout << "Masukkan nominal, EH TAPI KALO MAU JADI SULTAN GABOLE BOROS YA!! : Rp ";
	cin >> jumlah;
	cin.ignore();
	cout << "Untuk apa uangnya dipakai (misal: makan, kuota, laundry) : ";
	getline(cin, tujuan);

	// ==== PERCABANGAN: cek saldonya dah cukup pa blom ====
	if(jumlah > saldo){
		cout << "Saldo tidak cukup untuk pengeluaran ini! MAKANYA JGN BOROS!!! \n";
	} else {
		saldo -= jumlah;
		pengeluaran[jumlahData] = tujuan;
		jumlahPengeluaran[jumlahData] = jumlah;
		jumlahData++;
		cout << "Pengeluaran Rp" << jumlah << " untuk  '" << tujuan << "' telah dicatat.\n";
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

// ================== FUNCTION LIHAT DAFTAR PENGELUARAN ==================
void lihatDaftar() {
    cout << "\n========== DAFTAR PENGELUARAN ==========\n";

// ================= PERULANGAN UNTUK MENAMPILKAN DATA ===================
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

// ================== FUNGSI UTAMA ===============================
int main() { // otak besar jalannya program ini
    muatData(); // muat data lama untuk dieksekusi
    int pilihan; //variabel untuk nyimpen pilihan dari user

    do { // program paling tidak menjalankan 1 fitur sekali
        tampilkanMenu(); //memanggil fungsi yang nampilin menu ke layar dan program bakal nunggu user milih
        cin >> pilihan; //user milih menu

        switch (pilihan) {
            case 1: tambahPemasukan(); //kalau user pilih ini, maka jalankan fungsi tersebut
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
            default: //ini kalau usernya ngawur misalnya disuruhnya nginput pilihan 1-5 dia malah nginput 7
                cout << "Pilihan tidak valid! Coba lagi.\n";
        }
    } while (pilihan != 5); //selama user ga milih 5 maka case di atas akan terus berulang

    return 0;
}

