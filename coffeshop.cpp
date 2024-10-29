#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

void importantScreen() {
    cout << "+--------------------------------------------+" << endl;
    cout << "|      Selamat Datang di Coffe Shop Kami     |" << endl;
    cout << "|  Disini Menyediakan Banyak Variasi Minuman |" << endl;
    cout << "+--------------------------------------------+" << endl << endl;
    cout << "============ List Menu dan Harga ============" << endl;
    cout << "Kopi                  = 20.000" << endl;
    cout << "Teh                   = 15.000" << endl;
    cout << "Jus                   = 25.000" << endl;
    cout << "Ukuran Kecil          = free" << endl;
    cout << "Ukuran Sedang         = tambah 5.000" << endl;
    cout << "Ukuran Besar          = tambah 10.000" << endl;
    cout << "Topping Whipped Cream = tambah 5.000" << endl;
    cout << "Topping Sirup         = tambah 3.000" << endl << endl;
}

string formatRupiah(int amount) {
    string formatted = "Rp. ";
    int count = 0;
    for (int i = to_string(amount).length() - 1; i >= 0; --i) {
        formatted += to_string(amount)[i];
        count++;
        if (count % 3 == 0 && i != 0) {
            formatted += '.';
        }
    }
    reverse(formatted.begin() + 4, formatted.end());
    return formatted;
}

int main() {
    int totalHarga, jenis, ukuran, topping, tbaw, tbak, hargaMinuman, hargaUkuran, hargaTopping, jmlMinuman;
    string tp, tb;
    float diskon = 0.0;
    char pilihanUlang, checkout;

    importantScreen();
    
    cout << "Apakah Anda ingin membeli ? (y/n) : ";
    cin >> pilihanUlang;
    system("cls");
    if (pilihanUlang == 'n') {
        system("cls");
        cout << "Anda keluar dari program" << endl;
        exit(0);
        return 0;
    }
    
    do {
        cout << "== Jenis Minuman ==" << endl;
        cout << "1. Kopi" << endl;
        cout << "2. Teh" << endl;
        cout << "3. Jus" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> jenis;
        system("cls");

        cout << "== Ukuran Minuman ==" << endl;
        cout << "1. Kecil" << endl;
        cout << "2. Sedang" << endl;
        cout << "3. Besar" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> ukuran;
        system("cls");

        cout << "== Topping Minuman == (opsional)" << endl;
        cout << "1. Whipped Cream" << endl;
        cout << "2. Sirup Rasa" << endl;
        cout << "3. Tidak memilih" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> topping;
        system("cls");

        cout << "Berapa jumlah minuman yang ingin Anda pesan : ";
        cin >> jmlMinuman;

        const int hargaKopi = 20000, hargaTeh = 15000, hargaJus = 25000;
        const int hargaKecil = 0, hargaSedang = 5000, hargaBesar = 10000;
        const int hargaWcream = 5000, hargaSirup = 3000;

        switch (jenis) {
            case 1: hargaMinuman = hargaKopi; break;
            case 2: hargaMinuman = hargaTeh; break;
            case 3: hargaMinuman = hargaJus; break;
            default: hargaMinuman = 0; break;
        }
        switch (ukuran) {
            case 1: hargaUkuran = hargaKecil; break;
            case 2: hargaUkuran = hargaSedang; break;
            case 3: hargaUkuran = hargaBesar; break;
            default: hargaUkuran = 0; break;
        }
        switch (topping) {
            case 1: hargaTopping = hargaWcream; break;
            case 2: hargaTopping = hargaSirup; break;
            case 3: hargaTopping = 0; break;
            default: hargaTopping = 0; break;
        }

        tbaw = (hargaMinuman + hargaUkuran + hargaTopping) * jmlMinuman;

        cout << "Apakah Anda ingin melanjutkan pembayaran? (y/n): ";
        cin >> pilihanUlang;
        system("cls");
    } while (pilihanUlang == 'n');
    cout << "Berikut adalah tagihan Anda = " << formatRupiah(tbaw) << endl;
    cout << "Masukkan tanggal pemesanan Anda (DD/MM) : ";
    cin >> tp;
    cout << "Masukkan tanggal dan bulan lahir Anda (DD/MM) : ";
    cin >> tb;

    if ((tp == "11/11") && (tb != "11/11")) {
        if (jmlMinuman >= 2) {
            diskon = tbaw > 50000 ? 0.35 : 0.2;
        } else if (jmlMinuman == 1) {
            diskon = tbaw >= 25000 ? 0.05 : 0;
        }
    }

    tbak = tbaw - (tbaw * diskon);
    cout << "Tagihan Anda sekarang adalah = " << formatRupiah(tbak) << endl;

    cout << "Apakah anda ingin checkout ? (y/n) : ";
    cin >> checkout;
    system("cls");
    if (checkout == 'y') {
        cout << "+--------------------------------------------------+" << endl;
        cout << "|  Terimakasih telah belanja di Coffe Shop Kami    |" << endl;
        cout << "|         Semoga Harimu Menyenangkan :)            |" << endl;
        cout << "+--------------------------------------------------+" << endl;
        cout << "Minuman         = " << (jenis == 1 ? "Kopi" : (jenis == 2 ? "Teh" : "Jus")) << " ➞ " << formatRupiah(hargaMinuman) << endl;
        cout << "Ukuran          = " << (ukuran == 1 ? "Kecil" : (ukuran == 2 ? "Sedang" : "Besar")) << " ➞ " << formatRupiah(hargaUkuran) << endl;
        cout << "Topping         = " << (topping == 1 ? "Whipped Cream" : (topping == 2 ? "Sirup Rasa" : "Tidak pakai topping")) << " ➞ " << formatRupiah(hargaTopping) << endl;
        cout << "Jumlah Minuman  = " << jmlMinuman << " pcs" << endl;
        cout << "Diskon          = " << (diskon * 100) << " %" << endl;
        cout << "Total belanja Anda adalah = " << formatRupiah(tbak) << endl;
    } else {
        system("cls");
        cout << "Pesanan dibatalkan, Anda keluar dari program" << endl;
        exit(0);
    }

    return 0;
}
