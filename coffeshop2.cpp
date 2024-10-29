#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cstdlib>

using namespace std;

// Fungsi selamat datang & list menu dan harga
void importantScreen()
{
    cout << "+--------------------------------------------+" << endl;
    cout << "|      Selamat Datang di Coffe Shop Kami     |" << endl;
    cout << "|  Disini Menyediakan Banyak Variasi Minuman |" << endl;
    cout << "+--------------------------------------------+" << endl
         << endl;
    cout << "============ List Menu dan Harga ============" << endl;
    cout << "Kopi                  = 20.000" << endl;
    cout << "Teh                   = 15.000" << endl;
    cout << "Jus                   = 25.000" << endl;
    cout << "Ukuran Kecil          = free" << endl;
    cout << "Ukuran Sedang         = tambah 5.000" << endl;
    cout << "Ukuran Besar          = tambah 10.000" << endl;
    cout << "Topping Whipped Cream = tambah 5.000" << endl;
    cout << "Topping Sirup         = tambah 3.000" << endl
         << endl;
}

// Fungsi untuk memformat angka ke dalam format Rp. xxx.xxx
string formatRupiah(int amount)
{
    string formatted = "Rp. ";
    int count = 0;
    // Untuk memisahkan angka setiap 3 digit dengan titik
    for (int i = to_string(amount).length() - 1; i >= 0; --i)
    {
        formatted += to_string(amount)[i];
        count++;
        if (count % 3 == 0 && i != 0)
        {
            formatted += '.';
        }
    }
    reverse(formatted.begin() + 4, formatted.end()); // Reverse string tanpa Rp.
    return formatted;
}

void receipt() {
        int hargaMinuman, hargaUkuran, hargaTopping, jenis, ukuran, topping, tbak, jmlMinuman;
        float diskon;

        cout << "+--------------------------------------------------+" << endl;
        cout << "|  Terimakasih telah belanja di Coffe Shop Kami    |" << endl;
        cout << "|         Semoga Harimu Menyenangkan :)            |" << endl;
        cout << "|  *********************************************   |" << endl;
        cout << "+--------------------------------------------------+" << endl
             << endl;

        int persen = diskon * 100;

        if (jenis == 1) {
            hargaMinuman = 20000;
        } else if (jenis == 2) {
            hargaMinuman = 15000;
        } else {
            hargaMinuman = 25000;
        }

        if (ukuran == 1) {
            hargaUkuran = 0;
        } else if (ukuran == 2) {
            hargaUkuran = 5000;
        } else {
            hargaUkuran = 10000;
        }

        if (topping == 1) {
            hargaTopping= 5000;
        } else if (topping == 2) {
            hargaTopping = 3000;
        } else {
            hargaTopping = 0;
        }


        cout << "Minuman         = " << (jenis == 1 ? "Kopi" : (jenis == 2 ? "Teh" : "Jus")) << " " << "➞" << " " << formatRupiah(hargaMinuman) << endl;
        cout << "UKuran          = " << (ukuran == 1 ? "Kecil" : (ukuran == 2 ? "Sedang" : "Besar")) << " " << "➞" << " " << formatRupiah(hargaUkuran) << endl;
        cout << "Topping         = " << (topping == 1 ? "Whipped Cream" : (topping == 2 ? "Sirup Rasa" : "Tidak pakai topping")) << " " << "➞" << " " << formatRupiah(hargaTopping) << endl
             << endl;
        cout << "Jumlah Minuman  = " << jmlMinuman << " pcs" << endl;
        cout << "Diskon          = " << persen << " %" << endl;

        cout << "Total belanja Anda adalah = " << formatRupiah(tbak) << endl;
}

// Fungsi Algoritma pembelian
int main()
{
    int totalHarga, jenis, ukuran, topping, tbaw, tbak, hargaMinuman, hargaUkuran, hargaTopping, jmlMinuman;
    string tp, tb;
    float diskon;
    char pilihanUlang, checkout;

    importantScreen();

    cout << "Apakah Anda ingin membeli ? (y/n) : ";
    cin >> pilihanUlang;
    if (pilihanUlang == 'n')
    {
        system("clear");
        cout << "Anda keluar dari program" << endl;
        exit(0);
    }
    system("clear");
    do
    {
        // Memilih jenis minuman
        int jenis;
        cout << "== Jenis Minuman ==" << endl;
        cout << "1. Kopi" << endl;
        cout << "2. Teh" << endl;
        cout << "3. Jus" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> jenis;
        system("clear");

        // Memilih ukuran minuman
        int ukuran;
        cout << "== Ukuran Minuman ==" << endl;
        cout << "1. Kecil" << endl;
        cout << "2. Sedang" << endl;
        cout << "3. Besar" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> ukuran;
        system("clear");

        // Memilih topping minuman
        int topping;
        cout << "== Topping Minuman == (opsional)" << endl;
        cout << "1. Whipped Cream" << endl;
        cout << "2. Sirup Rasa" << endl;
        cout << "3. Tidak memilih" << endl;
        cout << "Masukkan pilihan (1/2/3) : ";
        cin >> topping;
        system("clear");

        // Menampilkan pilihan yang dipilih
        cout << "Pilihan Anda adalah berikut : " << endl;
        cout << "Jenis Minuman    = " << (jenis == 1 ? "Kopi" : (jenis == 2 ? "Teh" : "Jus")) << endl;
        cout << "Ukuran Minuman   = " << (ukuran == 1 ? "Kecil" : (ukuran == 2 ? "Sedang" : "Besar")) << endl;
        cout << "Topping Minuman  = " << (topping == 1 ? "Whipped Cream" : (topping == 2 ? "Sirup Rasa" : "Tidak pakai topping")) << endl;
        cout << "Berapa jumlah minuman yang ingin Anda pesan : ";
        cin >> jmlMinuman;

        const int
            hargaKopi = 20000,
            hargaTeh = 15000,
            hargaJus = 25000,
            hargaKecil = 0,
            hargaSedang = 5000,
            hargaBesar = 10000,
            hargaWcream = 5000,
            hargaSirup = 3000;

        switch (jenis)
        {
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
        switch (ukuran)
        {
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
        switch (topping)
        {
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
        if (pilihanUlang == 'y')
        {
            system("clear");
        }
    } while (pilihanUlang == 'n');
    tbaw = totalHarga * jmlMinuman;
    cout << "Berikut adalah tagihan Anda = " << formatRupiah(tbaw) << endl;
    cout << "Masukkan tanggal pemesanan Anda (DD/MM) : ";
    cin >> tp;
    cout << "Masukkan tanggal dan bulan lahir Anda (DD/MM) : ";
    cin >> tb;
    system("clear");
    if ((tp == "11/11") && (tb != "11/11"))
    {
        if (jmlMinuman >= 2)
        {
            if (tbaw > 50000)
            {
                diskon = 0.35;
                tbak = tbaw - (tbaw * diskon);
                cout << "Selamat Anda mendapatkan diskon sebesar 35 %" << endl;
                cout << "Tagihan Anda sekarang adalah = " << formatRupiah(tbak) << endl;
            }
            else
            {
                diskon = 0.2;
                tbak = tbaw - (tbaw * diskon);
                cout << "Selamat Anda mendapatkan diskon sebesar 20 %" << endl;
                cout << "Tagihan Anda sekarang adalah = " << formatRupiah(tbak) << endl;
            }
        }
        else if (jmlMinuman = 1)
        {
            if (tbaw >= 25000)
            {
                diskon = 0.05;
                tbak = tbaw - (tbaw * diskon);
                cout << "Selamat Anda mendapatkan diskon sebesar 5 %" << endl;
                cout << "Tagihan Anda sekarang adalah = " << formatRupiah(tbak) << endl;
            }
            else
            {
                cout << "Maaf Anda belum dapat diskon" << endl;
                cout << "Berikut adalah tagihan Anda = " << formatRupiah(tbaw) << endl;
            }
        }
        else
        {
            cout << "Maaf Anda belum dapat diskon" << endl;
            cout << "Berikut adalah tagihan Anda = " << formatRupiah(tbaw) << endl;
        }
    }
    else
    {
        cout << "Maaf Anda belum dapat diskon" << endl;
        cout << "Berikut adalah tagihan Anda = " << formatRupiah(tbaw) << endl;
    }

    cout << "Apakah anda ingin checkout ? (y/n) : ";
    cin >> checkout;
    if (checkout == 'y')
    {
        system("clear");
        cout << "Ini adalah struk pembeliannya : " << endl << endl;
        receipt();
        
    } else {
        system("clear");
        cout << "Pesanan dibatalkan" << endl;
        exit(0);
    }

    return 0;
}
