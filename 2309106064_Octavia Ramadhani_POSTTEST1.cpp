#include <iostream>
#include <map>
using namespace std;

struct akun {
    int user;
    string password;
}

map<int, akun> daftarAkun;

void registerAkun() {
    int user;
    cout << "Masukkan username: ";
    cin >> user;

    string password;
    cout << "Masukkan password: ";
    cin >> password;

    akun baru;
    baru.user = user;
    baru.password = password;
    daftarAkun[user] = baru;

    cout << "Akun berhasil didaftarkan.\n";
}

void login() {
    int user;
    cout << "Masukkan username: ";
    cin >> user;
    if (daftarAkun.find(user) == daftarAkun.end()) {
        cout << "Username tidak terdaftar.\n";
        return;
    }
    int coba = 0; 
    while (coba < 3) {
        string password;
        cout << "Masukkan password: ";
        cin >> password;
        if (daftarAkun[user].password == password) {
            cout << "Login berhasil. Selamat datang!\n";
            } else {
                cout << "Password salah.\n";
                coba++;
            }
    }
    cout << "Gagal login. Coba lagi nanti.\n";
}

void angka() {
    double angka;
    cout << "masukkan angka yang ingin di konversi : \n"
    cin >> angka;
}

void km_jam(double angka) {
    int choice;
    do {
        cout << "Ubah ke :\n";
        cout << "1. Centimeter/detik\n";
        cout << "2. Meter/detik\n";
        cout << "3. Mil/jam\n";
        cout << "4. keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        switch (choice) {
            case 1:
                return (angka * 100000) / 3600;
                break;
            case 2:
                return (angka * 1000) / 3600;
                break;
            case 3:
                return (angka * 0.621371);
                break;
            case 4:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 4);
}

void cm_det(double angka) {
    int choice;
    do {
        cout << "Ubah ke :\n";
        cout << "1. Kilometer/jam\n";
        cout << "2. Meter/detik\n";
        cout << "3. Mil/jam\n";
        cout << "4. keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        switch (choice) {
            case 1:
                return (angka / 100000.0) * 3600.0;
                break;
            case 2:
                return angka / 100.0;
                break;
            case 3:
                return angka * 3600 / 160934.4;
                break;
            case 4:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 4);
}

void m_det(double angka) {
    int choice;
    do {
        cout << "Ubah ke :\n";
        cout << "1. Kilometer/jam\n";
        cout << "2. Centimeter/detik\n";
        cout << "3. Mil/jam\n";
        cout << "4. keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        switch (choice) {
            case 1:
                return angka * 3600 / 1000;
                break;
            case 2:
                return angka * 100;
                break;
            case 3:
                return angka * 2.23694;
                break;
            case 4:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 4);
}

void mil_jam(double angka) {
    int choice;
    do {
        cout << "Ubah ke :\n";
        cout << "1. Kilometer/jam\n";
        cout << "2. Centimeter/detik\n";
        cout << "3. Meter/detik\n";
        cout << "4. keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        switch (choice) {
            case 1:
                return angka * 1.60934
                break;
            case 2:
                return angka * 1609.34 * 100 / 3600;
                break;
            case 3:
                return angka * 1609.34 / 3600;
                break;
            case 4:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 4);
}

int main() {
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerAkun();
                break;
            case 2:
                login();
                break;
            case 3:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 3);
    return 0;
}

int main() {
    int choice;
    do {
        cout << "pilih jenis angka yang ingin dikonversi : ";
        cout << "1. Kilometer/jam\n";
        cout << "2. Centimeter/detik\n";
        cout << "3. Meter/detik\n";
        cout << "4. Mil/jam\n";
        cout << "5. keluar\n";
        cout << "Pilih: ";
        cin >> choice;
        switch (choice) {
            case 1:
                angka();
                km_jam();
                break;
            case 2:
                angka();
                cm_det()
                break;
            case 3:
                angka();
                m_det();
                break;
            case 4:
                angka();
                mil_jam();
                break;
            case 5:
                cout << "Progam berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak ada dalam menu.\nSilakan coba lagi.\n";
        }
    } while (choice != 5);
    return 0;
}
