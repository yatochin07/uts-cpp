#include <iostream>
#include <string>

using namespace std;

int main() {
    char pilihanUlang;
    
    do {
        // Memilih jenis minuman
        int jenisMinuman;
        cout << "Pilih jenis minuman:\n";
        cout << "1. Kopi\n";
        cout << "2. Teh\n";
        cout << "3. Cokelat\n";
        cout << "Masukkan pilihan (1-3): ";
        cin >> jenisMinuman;

        // Memilih ukuran minuman
        int ukuranMinuman;
        cout << "Pilih ukuran minuman:\n";
        cout << "1. Kecil\n";
        cout << "2. Sedang\n";
        cout << "3. Besar\n";
        cout << "Masukkan pilihan (1-3): ";
        cin >> ukuranMinuman;

        // Memilih topping minuman
        int toppingMinuman;
        cout << "Pilih topping:\n";
        cout << "1. Whipped Cream\n";
        cout << "2. Cokelat Serut\n";
        cout << "3. Caramel\n";
        cout << "Masukkan pilihan (1-3): ";
        cin >> toppingMinuman;

        // Menampilkan pilihan yang dipilih
        cout << "\nAnda memilih:\n";
        cout << "Jenis Minuman: " << (jenisMinuman == 1 ? "Kopi" : (jenisMinuman == 2 ? "Teh" : "Cokelat")) << endl;
        cout << "Ukuran: " << (ukuranMinuman == 1 ? "Kecil" : (ukuranMinuman == 2 ? "Sedang" : "Besar")) << endl;
        cout << "Topping: " << (toppingMinuman == 1 ? "Whipped Cream" : (toppingMinuman == 2 ? "Cokelat Serut" : "Caramel")) << endl;

        // Konfirmasi untuk melanjutkan atau tidak
        cout << "Apakah Anda ingin melanjutkan ke pembayaran? (y/t): ";
        cin >> pilihanUlang;

    } while (pilihanUlang == 't' || pilihanUlang == 'T');

    cout << "Terima kasih! Selamat menikmati minuman Anda!" << endl;

    return 0;
}

