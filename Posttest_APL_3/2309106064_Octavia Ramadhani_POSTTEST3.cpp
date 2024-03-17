#include <iostream>
#include <conio.h>
using namespace std;

string username = "octavia";
string password = "064";

struct Produk {
	string jenis;
	struct detail {
		string brand;
		double harga;
	} detail;
};

string jenis[] = {"cushion", "powder", "maskara", "eyeshadow", "eyeliner", "lipstik"};
string merk[][6] = {
{"Instaperfect", "Wardah", "Luxcrime", "Skintific", "Somethinc"},
{"Make Over", "Luxcrime", "Wardah", "Somethinc", "Barenbliss"}, 
{"Somethinc", "Barenbliss", "Maybelline", "Rose All Day"}, 
{"Pinkflash", "Y.O.U", "Make Over"}, 
{"Pinkflash", "Make Over", "Luxcrime"}, 
{"Wardah", "Focallure", "Y.O.U", "ESQA", "Rollover Reaction"},
};
double harga[][6] = {
{185000, 115000, 130000, 262000, 285000},
{145000, 129000, 63000, 142000, 130000},
{90000, 79000, 90000, 130000},
{132000, 60000, 78000},
{40000, 128000, 109000},
{48000, 110000, 93000, 100000, 109000},
};

// prosedur
void menampilkan() {
    cout << "Pilih jenis produk makeup yang ingin anda lihat : " << endl; 
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << jenis[i] << endl;
    }
    int pilihan;
    cin >> pilihan;
    pilihan--;
    if (pilihan >= 0 && pilihan < 6) {
        cout << "Brand " << jenis[pilihan] << " :" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << merk[pilihan][i] << "\n   Harga = Rp." << harga[pilihan][i] << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    } getch();
}

// prosedur
void menambah(Produk & produk) {
	cout << "pilih jenis makeup yang ingin ditambah : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n= ";
	int pilih;
	cin >> pilih;
	if (pilih >= 1 && pilih <= 6) {
		cout << "Brand " << jenis[pilih-1] << " :" << endl;
       	for (int i = 0; i < 6; ++i) {
           	cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
		}
		cout << "Masukkan nama brand : \n";
		cin >> produk.detail.brand;
		cout << "Masukkan harga produk : \n";
		cin >> produk.detail.harga; 
		
		for (int i = 0; i <= 6; ++i) {
			if (merk[pilih-1][i].empty()) {
            	merk[pilih-1][i] = produk.detail.brand;
            	harga[pilih-1][i] = produk.detail.harga;
            	break;
        	}
        }
        produk.jenis = jenis[pilih-1];
		cout << "Data " << produk.jenis << " berhasil ditambahkan. /n";
		return;
	} else {	
		cout << "Pilihan tidak valid." << endl;
	}
} 

// prosedur
void mengedit() {
	cout << "pilih jenis makeup yang ingin diedit : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n=";
	int pilih;
	cin >> pilih;
	if (pilih >= 1 && pilih <= 6) {
		cout << "Brand " << jenis[pilih-1] << " :" << endl;
       	for (int i = 0; i < 6; ++i) {
           	cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
		}
	
		int pilihan;
		cout << "Pilih nomor brand yang ingin diedit: ";
		cin >> pilihan;

		if (pilihan >= 1 && pilihan <= 6) {
			cout << "Masukkan nama brand : \n";
			cin >> merk[pilih-1][pilihan-1];
			cout << "Masukkan harga produk baru : ";
			cin >> harga[pilih-1][pilihan-1];
			cout << "Data " << jenis[pilih-1] << " berhasil diedit." << endl;
		} else {
			cout << "Pilihan tidak valid." << endl;
		}
	} else {
		cout << "Pilihan tidak valid." << endl;
	}
}

// prosedur
void menghapus() {
	cout << "pilih jenis makeup yang ingin dihapus : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n=";
	int pilih;
	cin >> pilih;
	if (pilih >= 1 && pilih <= 6) {
		cout << "Brand " << jenis[pilih-1] << " :" << endl;
       	for (int i = 0; i < 6; ++i) {
           	cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
		}
		int pilihan;
		cout << "Pilih nomor brand yang ingin dihapus: ";
		cin >> pilihan;
		
		if (pilihan >= 1 && pilihan <= 6) {
			merk[pilih-1][pilihan-1] = "";
			harga[pilih-1][pilihan-1] = 0;
			cout << "Data " << jenis[pilih-1] << " berhasil dihapus." << endl;
			menampilkan();
		} else {
			cout << "Pilihan tidak valid." << endl;
		}
	} else {
		cout << "Pilihan tidak valid." << endl;
	}
}

// fungsi
int menu() {
	Produk produk;
	int pilihmenu;
	do {
		cout << "Menu : \n1. Menambahkan Produk \n2. Menampilkan Produk \n3. Edit Produk \n4. Hapus Produk \n5. Keluar\npilih menu : ";
		cin >> pilihmenu;
		switch (pilihmenu) {
			case 1:
				menambah(produk);
				break;
			case 2:
				menampilkan();
				break;
			case 3:
				mengedit(); 
				break;
			case 4:
				menghapus();
				break;
			case 5:
				break;
			default:
                cout << "Pilihan tidak ada dalam menu.\n";
                getch();
                break;
		}
	} while (pilihmenu != 5);
	return 0;
}

// fungsi dan rekursif
int login(int coba = 0) {
	string user;
    cout << "Masukkan username: ";
    cin >> user;
    string pw;
	cout << "Masukkan password: ";
    cin >> pw;
    
    if (user == username && pw == password) {
		cout << "Login berhasil. Selamat datang!\n";
		menu();
		return 1;
    } else {
		cout << "Username/Password yang anda masukkan salah.\n";
		if (coba < 2) {
			cout << "coba lagi.\n";
			login(coba + 1); // rekursif
		} else {
			cout << "Gagal login. Coba lagi nanti.\n";
			getch();
		}
		return 0;
    }
}

// fungsi
int main() {
    int menulogin;
    do {
        cout << "Menu:\n";
        cout << "1. Login\n";
        cout << "2. Keluar\n";
        cout << "Pilih: ";
        cin >> menulogin;

        switch (menulogin) {
            case 1: {
                login();
				break;
	        }
	        
            case 2: {
            	cout << "keluar dari program.\n";
            	break;
        	}

            default:
                cout << "Pilihan tidak ada dalam menu.\n";
        }
    } while (menulogin != 2);
    return 0;
}


