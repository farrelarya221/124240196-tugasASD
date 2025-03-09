#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

using namespace std;

struct Film
{
    string judul;
    string kode;
    float rating;
};

void tampilkanFilm(Film *film, int jumlah)
{
    
    cout << "\n====== DAFTAR FILM BIOSKOP PLAZA FARREL ======\n";
    cout << setw(5) << "No" << setw(10) << "Kode" << setw(30) << "Judul" << setw(10) << "Rating" << endl;
    cout << "---------------------------------------------\n";

    for (int i = 0; i < jumlah; i++)
    {
        cout << setw(5) << i + 1 << setw(10) << (film + i)->kode << setw(30) << (film + i)->judul
             << setw(10) << fixed << setprecision(1) << (film + i)->rating << endl;
    }
    cout << "--------------------------------------------------------\n";
}

int sequentialSearch(Film *film, int jumlah, string kode)
{
    for (int i = 0; i < jumlah; i++)
    {
        if ((film + i)->kode == kode)
        {
            return i;
        }
    }
    return -1;
}

void sortJudul(Film *film, int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = 0; j < jumlah - i - 1; j++)
        {
            if ((film + j)->judul > (film + j + 1)->judul)
            {
                Film temp = *(film + j);
                *(film + j) = *(film + j + 1);
                *(film + j + 1) = temp;
            }
        }
    }
}

int binarySearch(Film *film, int start, int end, string judul)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((film + mid)->judul == judul)
        {
            return mid;
        }
        if ((film + mid)->judul > judul)
        {
            return binarySearch(film, start, mid - 1, judul);
        }
        return binarySearch(film, mid + 1, end, judul);
    }
    return -1;
}

int partisiQuickSort(Film *film, int low, int high)
{
    float pivot = (film + high)->rating;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if ((film + j)->rating <= pivot)
        {
            i++;
            Film temp = *(film + i);
            *(film + i) = *(film + j);
            *(film + j) = temp;
        }
    }
    Film temp = *(film + i + 1);
    *(film + i + 1) = *(film + high);
    *(film + high) = temp;

    return (i + 1);
}

void quickSort(Film *film, int low, int high)
{
    if (low < high)
    {
        int pi = partisiQuickSort(film, low, high);
        quickSort(film, low, pi - 1);
        quickSort(film, pi + 1, high);
    }
}

void bubbleSort(Film *film, int jumlah)
{
    for (int i = 0; i < jumlah - 1; i++)
    {
        for (int j = 0; j < jumlah - i - 1; j++)
        {
            if ((film + j)->rating < (film + j + 1)->rating)
            {
                Film temp = *(film + j);
                *(film + j) = *(film + j + 1);
                *(film + j + 1) = temp;
            }
        }
    }
}

Film *inisialisasiFilm(int *jumlahFilm)
{
    *jumlahFilm = 10;
    Film *daftarFilm = new Film[*jumlahFilm];

    daftarFilm[0] = {"Petaka Gunung Gede", "2006", 9.0};
    daftarFilm[1] = {"Kalian Pantas Mati", "2007", 8.8};
    daftarFilm[2] = {"Buried Hearts", "2008", 9.4};
    daftarFilm[3] = {"Parasite", "2009", 9.5};
    daftarFilm[4] = {"Alchemy of Souls", "2010", 10.0};
    daftarFilm[5] = {"True Beauty", "2011", 8.5};
    daftarFilm[6] = {"Lighter and Princess", "2012", 9.9};
    daftarFilm[7] = {"The Long Ballad", "2013", 9.8};
    daftarFilm[8] = {"The Chronicles of Narnia", "2014", 9.2};
    daftarFilm[9] = {"The Monkey", "2015", 7.9};
    return daftarFilm;
}

int main()
{
    int jumlahFilm, pilihan;
    string cariKode, cariJudul;
    Film *daftarFilm = inisialisasiFilm(&jumlahFilm);
    // Membuat salinan data asli untuk menu tampilan data sebelum diurutkan
    Film *daftarFilmAsli = new Film[jumlahFilm];
    for (int i = 0; i < jumlahFilm; i++)
    {
        daftarFilmAsli[i] = daftarFilm[i];
    }

    do
    {
        system("cls");
        cout << "\n=== MENU SISTEM BIOSKOP PLAZA FARREL ===\n";
        cout << "1. Tampilkan Semua Film\n";
        cout << "2. Cari Film berdasarkan Kode\n";
        cout << "3. Cari Film berdasarkan Judul\n";
        cout << "4. Urutkan Film berdasarkan Rating (Ascending)\n";
        cout << "5. Urutkan Film berdasarkan Rating (Descending)\n";
        cout << "6. Tampilkan Data Film Asli (Sebelum Diurutkan)\n"; // Menu baru
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            system("cls");
            tampilkanFilm(daftarFilm, jumlahFilm);
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
        case 2:
            system("cls");
            cout << "\nMasukkan Kode Film: ";
            cin.ignore();
            getline(cin, cariKode);
            int hasilPencarian;
            hasilPencarian = sequentialSearch(daftarFilm, jumlahFilm, cariKode);
            if (hasilPencarian != -1)
            {
                cout << "\nFilm ditemukan: " << daftarFilm[hasilPencarian].judul << endl;
            }
            else
            {
                cout << "\nFilm tidak ditemukan!\n";
            }
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
        case 3:
            system("cls");
            sortJudul(daftarFilm, jumlahFilm);
            cout << "\nMasukkan Judul Film: ";
            cin.ignore();
            getline(cin, cariJudul);
            int hasilBinary;
            hasilBinary = binarySearch(daftarFilm, 0, jumlahFilm - 1, cariJudul);
            if (hasilBinary != -1)
            {
                cout << "\nFilm ditemukan: " << daftarFilm[hasilBinary].judul << "(Kode: " << daftarFilm[hasilBinary].kode << ", Rating: " << daftarFilm[hasilBinary].rating << ")\n";
            }
            else
            {
                cout << "\nFilm tidak ditemukan!\n";
            }
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
        case 4:
            system("cls");
            quickSort(daftarFilm, 0, jumlahFilm - 1);
            cout << "\nData film telah diurutkan berdasarkan Rating (Ascending) menggunakan Quick Sort\n";
            tampilkanFilm(daftarFilm, jumlahFilm);
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
            
        case 5:
            system("cls");
            bubbleSort(daftarFilm, jumlahFilm);
            cout << "\nData film telah diurutkan berdasarkan Rating (Descending) menggunakan Bubble Sort\n";
            tampilkanFilm(daftarFilm, jumlahFilm);
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
            
        case 6:
            system("cls");
            cout << "\nData Film Asli (Sebelum Diurutkan)\n";
            tampilkanFilm(daftarFilmAsli, jumlahFilm);
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
            break;
            
        case 0:
            system("cls");
            cout << "\nTerima kasih telah menggunakan Sistem Manajemen Data Bioskop Plaza Ambarukmo\n";
            cout << "\nTekan Enter untuk keluar...";
            system ("pause");
            break;
            
        default:
            system("cls");
            cout << "\nPilihan tidak valid. Silakan coba lagi.\n";
            cout << "\nTekan Enter untuk melanjutkan...";
            system ("pause");
        }

    } while (pilihan != 0);
    
    system("cls");
    return 0;
}