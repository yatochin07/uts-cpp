#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void importantScreen() {
    cout << "+--------------------------------------------+" << endl;
    cout << "|      Selamat Datang di Coffe Shop Kami     |" << endl;
    cout << "|  Disini Menyediakan Banyak Variasi Minuman |" << endl;
    cout << "+--------------------------------------------+" << endl << endl;
    cout << "========== List Harga ==========" << endl;
    cout << "Kopi                  = 20.000" << endl;
    cout << "Teh                   = 15.000" << endl;
    cout << "Jus                   = 25.000" << endl;
    cout << "Ukuran Kecil          = free" << endl;
    cout << "Ukuran Sedang         = tambah 5.000" << endl;
    cout << "Ukuran Besar          = tambah 10.000" << endl;
    cout << "Topping Whipped Cream = tambah 5.000" << endl;
    cout << "Topping Sirup         = tambah 3.000" << endl << endl;

}
int main() {
    int totalHarga, jenis, ukuran, topping,tbaw, tbak, jmlMinuman;
    string tp, tb;
    float diskon;
    char pilihanUlang;

    importantScreen();

    cout << "Apakah Anda ingin membeli ? (y/n) : ";
    cin >> pilihanUlang;
    if (pilihanUlang == 'n') {
        exit(0);
    }
    system("cls");
    do {
        // Memilih jenis minuman
        int jenis;
        cout << "== Jenis Minuman ==" << endl;
        cout << "1. Kopi"<< endl;
        cout << "2. Teh" << endl;
        cout << "3. Jus" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> jenis;
        system("cls");

        // Memilih ukuran minuman
        int ukuran;
        cout << "== Ukuran Minuman ==" << endl;
        cout << "1. Kecil" << endl;
        cout << "2. Sedang" << endl;
        cout << "3. Besar" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> ukuran;
        system("cls");

        // Memilih topping minuman
        int topping;
        cout << "== Topping Minuman == (opsional)" << endl;
        cout << "1. Whipped Cream" << endl;
        cout << "2. Sirup Rasa" << endl;
        cout << "3. Tidak memilih" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> topping;
        system("cls");

        // Menampilkan pilihan yang dipilih
        cout << "Pilihan Anda adalah berikut : " << endl;
        cout << "Jenis Minuman    = " << (jenis == 1 ? "Kopi" : (jenis == 2 ? "Teh" : "Jus" )) << endl;
        cout << "Ukuran Minuman   = " << (ukuran == 1 ? "Kecil" : (ukuran == 2 ? "Sedang" : "Besar" )) << endl;
        cout << "Topping Minuman  = " << (topping == 1 ? "Whipped Cream" : (topping == 2 ? "Sirup Rasa" : "Pilihan Topping tidak ada")) << endl;
        cout << "Berapa jumlah minuman yang ingin Anda pesan : "; cin >> jmlMinuman;
    
        const int 
        hargaKopi = 20000,
        hargaTeh = 15000,
        hargaJus = 25000,
        hargaKecil = 0,
        hargaSedang = 5000,
        hargaBesar = 10000,
        hargaWcream = 5000,
        hargaSirup = 3000;

        switch (jenis) {
            case 1:
                jenis = hargaKopi;
                break;
            case 2:
                jenis = hargaTeh;
                break;
            case 3:
                jenis = hargaJus;
                break;
            default:
                break;
        }
        switch (ukuran) {
            case 1:
                ukuran = hargaKecil;
                break;
            case 2:
                ukuran = hargaSedang;
                break;
            case 3:
                ukuran = hargaBesar;
                break;
            default:
                break;
        }
        switch (topping) {
            case 1:
                topping = hargaWcream;
                break;
            case 2:
                topping = hargaSirup;
                break;
            case 3:
                topping = 0;
                break;
            default:
                break;
        }
        totalHarga = jenis + ukuran + topping;
        cout << endl;

        // Konfirmasi untuk melanjutkan atau tidak
        cout << "Apakah Anda ingin melanjutkan pembayaran? (y/n): ";
        cin >> pilihanUlang;
        if (pilihanUlang == 'n') {
            exit(0);
        }
    } while (pilihanUlang == 'n');
        system("cls");
        tbaw = totalHarga * jmlMinuman;
        cout << "Berikut adalah tagihan Anda = " << tbaw << endl;
        cout << "Masukkan tanggal pemesanan Anda (DD/MM) : "; cin >> tp;
        cout << "Masukkan tanggal dan bulan lahir Anda (DD/MM) : "; cin >> tb;
        system("cls");
        if ((tp == "11/11") && (tb != "11/11")) {
            if (jmlMinuman >= 2 ) {
                if (tbaw > 50000) {
                    diskon = 0.35;
                    tbak = tbaw - (tbaw * diskon);
                    cout << "Selamat Anda mendapatkan diskon sebesar 35 %" << endl;
                    cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
                } else {
                    diskon = 0.2;
                    tbak = tbaw - (tbaw * diskon);
                    cout << "Selamat Anda mendapatkan diskon sebesar 20 %" << endl;
                    cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
                }
            } else if (jmlMinuman = 1 ) {
                if (tbaw >= 25000) {
                    diskon = 0.05;
                    tbak = tbaw - (tbaw * diskon);
                    cout << "Selamat Anda mendapatkan diskon sebesar 5 %" << endl;
                    cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
                } else {
                    cout << "Maaf Anda belum dapat diskon" << endl;
                    cout << "Berikut adalah tagihan Anda = " << tbaw << endl;
                }
            } else {
                cout << "Maaf Anda belum dapat diskon" << endl;
                cout << "Berikut adalah tagihan Anda = " << tbaw << endl;
            }
        } else {
            cout << "Maaf Anda belum dapat diskon" << endl;
            cout << "Berikut adalah tagihan Anda = " << tbaw << endl;
        }

    return 0;
}