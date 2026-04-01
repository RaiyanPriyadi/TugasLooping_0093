#include <iostream>
using namespace std;

// Deklarasi Variabel Global
int angka;
int pilihan;

// Fungsi (Prosedur) untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "\n======================================\n";
    cout << "      MENU PENGECEKAN BI\n";
    cout << "======================================\n";
    cout << "1. Cek Bilangan Prima\n";
    cout << "2. Cek Bilangan Fibonacci\n";
    cout << "0. Keluar\n";
    cout << "Masukkan pilihan Anda (0/1/2): ";
}

// Fungsi (Prosedur) untuk menerima input angka dari pengguna
void inputAngka() {
    cout << "Masukkan angka yang ingin dicek: ";
    cin >> angka;
}

// Fungsi bertipe bool untuk mengecek Bilangan Prima menggunakan while loop
bool cekPrima(int n) {
    if (n <= 1) {
        return false; // Bilangan <= 1 bukan bilangan prima
    }
    
    int i = 2;
    // Pengecekan cukup sampai akar kuadrat dari n untuk efisiensi
    while (i * i <= n) {
        if (n % i == 0) {
            return false; // Jika bisa dibagi angka lain, bukan prima
        }
        i++;
    }
    return true;
}

// Fungsi bertipe bool untuk mengecek Bilangan Fibonacci menggunakan while loop
bool cekFibonacci(int n) {
    if (n < 0) {
        return false; // Deret Fibonacci standar dimulai dari 0
    }
    
    int a = 0;
    int b = 1;
    
    // Perulangan untuk mencari angka Fibonacci hingga mencapai atau melebihi n
    while (a < n) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    
    // Jika a sama dengan n, berarti n adalah bagian dari deret Fibonacci
    return (a == n);
}

// Fungsi (Prosedur) untuk menampilkan hasil pengecekan Bilangan Prima
void tampilkanHasilPrima(bool isPrima) {
    if (isPrima) {
        cout << "-> HASIL: " << angka << " adalah Bilangan Prima.\n";
    } else {
        cout << "-> HASIL: " << angka << " BUKAN Bilangan Prima.\n";
    }
}

// Fungsi (Prosedur) untuk menampilkan hasil pengecekan Bilangan Fibonacci
void tampilkanHasilFibonacci(bool isFibonacci) {
    if (isFibonacci) {
        cout << "-> HASIL: " << angka << " termasuk dalam deret Fibonacci.\n";
    } else {
        cout << "-> HASIL: " << angka << " TIDAK termasuk dalam deret Fibonacci.\n";
    }
}

// Fungsi Utama
int main() {
    pilihan = -1; // Inisialisasi awal agar masuk ke dalam while loop
    
    while (pilihan != 0) {
        tampilkanMenu();
        cin >> pilihan;
        
        switch (pilihan) {
            case 1:
                inputAngka();
                // Memanggil fungsi cekPrima dan meneruskan hasilnya ke prosedur tampilan
                tampilkanHasilPrima(cekPrima(angka));
                break;
                
            case 2:
                inputAngka();
                // Memanggil fungsi cekFibonacci dan meneruskan hasilnya ke prosedur tampilan
                tampilkanHasilFibonacci(cekFibonacci(angka));
                break;
                
            case 0:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
                
            default:
                // Menangani jika input selain 0, 1, dan 2
                cout << "Pilihan tidak valid. Silakan coba lagi dengan memasukkan angka 0, 1, atau 2.\n";
                break;
        }
    }
    
    return 0;
}
