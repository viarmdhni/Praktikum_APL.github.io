#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;

string username = "octavia";
string password = "064";

struct detailproduk {
    string brand;
    double harga;
};

struct Produk {
    string jenis;
    detailproduk detail[6];
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

int binarySearch(string arr[], string key, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// fungsi, pointer deferences, sort huruf ascending, search
void menampilkanaz(string *jenis, string (*merk)[6], double (*harga)[6]) { 
    cout << "Pilih jenis produk makeup yang ingin anda lihat : " << endl; 
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << jenis[i] << endl;
    }
    int pilih;
    cin >> pilih;
    string cari;
    string pilihan;
    cout << "Ingin mencari brand? (y/n) \n= ";
    cin >> pilihan;
    if (pilihan == "y"){
        cout << "Masukkan brand yang ingin dicari: ";
        cin >> cari;

    // binary search
    int index = binarySearch(merk[pilih - 1], cari, 0, 5);
    if (index != -1) {
        cout << "Brand: " << merk[pilih - 1][index] << "\nHarga: Rp." << harga[pilih - 1][index] << "\n" << endl;
    } else {
        cout << "Brand " << cari << " tidak ditemukan." << endl;
    }
    }
    // error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }

    if (pilih >= 1 && pilih <= 6) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5 - i; ++j) {
                if (merk[pilih - 1][j] > merk[pilih - 1][j + 1]) { // bubble Sort huruf ascending
                    swap(merk[pilih - 1][j], merk[pilih - 1][j + 1]);
                    swap(harga[pilih - 1][j], harga[pilih - 1][j + 1]);
                }
            }
        }
        cout << "Brand " << jenis[pilih-1] << " :" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    } getch();
}

// fungsi, pointer deferences, sort huruf descending
void menampilkanza(string *jenis, string (*merk)[6], double (*harga)[6]) { 
    cout << "Pilih jenis produk makeup yang ingin anda lihat : " << endl; 
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << jenis[i] << endl;
    }
    int pilih;
    cin >> pilih;
    string cari;
    string pilihan;
    cout << "Ingin mencari brand? (y/n) \n= ";
    cin >> pilihan;
    if (pilihan == "y"){
        cout << "Masukkan brand yang ingin dicari: ";
        cin >> cari;

        // sequential search
        int i;
        for (i = 0; i < 6; ++i) {
            if (merk[pilih - 1][i] == cari) {
                cout << "Brand: " << merk[pilih - 1][i] << "\nHarga: Rp." << harga[pilih - 1][i] << "\n" << endl;
                break;
            }
        }
        if (merk[pilih - 1][i] != cari) {
            cout << "Brand " << cari << " tidak ditemukan." << endl;
        }
    }
    
    //error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }

    if (pilih >= 1 && pilih <= 6) {
        for (int i = 0; i < 6; ++i) {
            int max_index = i;
            for (int j = i + 1; j < 6; ++j) {// Selection Sort descending
                if (merk[pilih - 1][j] > merk[pilih - 1][max_index]) {
                    max_index = j;
                }
            }
            swap(merk[pilih - 1][i], merk[pilih - 1][max_index]);
            swap(harga[pilih - 1][i], harga[pilih - 1][max_index]);
        }
    cout << "Brand " << jenis[pilih-1] << " :" << endl;
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
    }
    } else {
        cout << "Pilihan tidak valid." << endl;
    } getch();
}

// fungsi, pointer deferences, sort angka ascending
void menampilkanharga(string *jenis, string (*merk)[6], double (*harga)[6]) { 
    cout << "Pilih jenis produk makeup yang ingin anda lihat : " << endl; 
    for (int i = 0; i < 6; ++i) {
        cout << i + 1 << ". " << jenis[i] << endl;
    }
    int pilih;
    cin >> pilih;
    
    //error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }

    if (pilih >= 1 && pilih <= 6) {
        for (int i = 1; i < 6; ++i) { 
            double temp_harga = harga[pilih - 1][i];
            string temp_merk = merk[pilih - 1][i];
            int j = i - 1;
            while (j >= 0 && harga[pilih - 1][j] > temp_harga) {
                harga[pilih - 1][j + 1] = harga[pilih - 1][j];
                merk[pilih - 1][j + 1] = merk[pilih - 1][j];
                j--;
            }
            harga[pilih - 1][j + 1] = temp_harga;
            merk[pilih - 1][j + 1] = temp_merk;
        }
        cout << "Brand " << jenis[pilih-1] << " :" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
        }
    } else {
        cout << "Pilihan tidak valid." << endl;
    }
}



// fungsi & pointer deferences
void menambah(Produk *produk, string *jenis, string (*merk)[6], double (*harga)[6]) {
    cout << "pilih jenis makeup yang ingin ditambah : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n= ";
    int pilih;
    cin >> pilih;

    //error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }
    if (pilih >= 1 && pilih <= 6) {
        cout << "Brand " << jenis[pilih-1] << " :" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
        }
        cout << "Masukkan nama brand : \n";
        cin >> produk->detail[pilih-1].brand;
        cout << "Masukkan harga produk : \n";
        cin >> produk->detail[pilih-1].harga; 

        //error handling
        if (cin.fail()) {
            cout << "Input harga tidak valid. Silakan masukkan harga lagi: ";
            cin.clear();
            cin.ignore();
        
        for (int i = 0; i <= 6; ++i) {
            if (merk[pilih-1][i].empty()) {
                merk[pilih-1][i] = produk->detail[pilih-1].brand;
                harga[pilih-1][i] = produk->detail[pilih-1].harga;
                break;
            }
        }
        produk->jenis = jenis[pilih-1];
        cout << "Data " << produk->jenis << " berhasil ditambahkan. /n";
        return;
    }
} 
}

// fungsi & pointer deferences
void mengedit(string* jenis, string (*merk)[6], double (*harga)[6]) {
    cout << "pilih jenis makeup yang ingin diedit : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n=";
    int pilih;
    cin >> pilih;

    //error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }
    if (pilih >= 1 && pilih <= 6) {
        cout << "Brand " << jenis[pilih-1] << " :" << endl;
        for (int i = 0; i < 6; ++i) {
            cout << i + 1 << ". " << merk[pilih-1][i] << "\n   Harga = Rp." << harga[pilih-1][i] << endl;
           }
        int pilihan;
        cout << "Pilih nomor brand yang ingin diedit: ";
        cin >> pilihan;
        
        //error handling
        if (pilihan < 1 || pilihan > 6) {
            cout << "Input tidak valid. Silakan masukkan nomor brand lagi: ";
            cin >> pilihan;
        }
        if (pilihan >= 1 && pilihan <= 6) {
            cout << "Masukkan nama brand : \n";
            cin >> merk[pilih-1][pilihan-1];
            cout << "Masukkan harga produk baru : ";
            cin >> harga[pilih-1][pilihan-1];

            //error handling
            if (cin.fail()) {
                cout << "Input harga tidak valid. Silakan masukkan harga lagi: ";
                cin.clear();
                cin.ignore();
                cin >> harga[pilih-1][pilihan-1];
                cout << "Data " << jenis[pilih-1] << " berhasil diedit." << endl;
            }
        }
    }
}

// fungsi & pointer deferences
void menghapus(string* jenis, string (*merk)[6], double (*harga)[6]) {
    cout << "pilih jenis makeup yang ingin dihapus : \n1. cushion \n2. powder \n3. maskara \n4. eyeshadow \n5. eyeliner \n6. lipstik \n=";
    int pilih;
    cin >> pilih;

    //error handling
    if (cin.fail() || pilih < 1 || pilih > 6) {
        cin.clear();
        cin.ignore();
        cout << "Input tidak valid. Silakan masukkan nomor pilihan lagi: ";
        cin >> pilih;
    }
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
        cout << "Menu : \n1. Menambahkan Produk \n2. Menampilkan Produk a-z \n3. Menampilkan produk z-a \n4. Menampilkan harga dari yang termurah \n5. Edit Produk \n6. Hapus Produk \n7. Keluar\npilih menu : ";
        cin >> pilihmenu;
        switch (pilihmenu) {
            case 1:
                menambah(&produk, jenis, merk, harga); // pointer address of
                break;
            case 2:
                menampilkanaz(jenis, merk, harga);
                break;
            case 3:
                menampilkanza(jenis, merk, harga);
                break;
            case 4:
                menampilkanharga(jenis, merk, harga);
                break;
            case 5:
                mengedit(jenis, merk, harga);
                break;
            case 6:
                menghapus(jenis, merk, harga);
                break;
            case 7:
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\n";
                getch();
                break;
        }
    } while (pilihmenu != 7);
    return 0;
}

// fungsi dan rekursif
int login(int coba = 0) {
    string user;
    string pw;
    cout << "Masukkan username: ";
    cin >> user;
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
}
