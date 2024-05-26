#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define max 15

struct SumberDaya {
    string nama;
    int jumlah;
    string jenis;
};

SumberDaya sumber_daya[max];
int pos = 0;

void tampilkan(SumberDaya* ptr = sumber_daya, int index = 0) {
    if (index == 0) {
        system("cls");
        if (pos > 0) {
            cout << "Data Tersimpan" << endl;
        } else {
            cout << "Data Kosong" << endl;
            return;
        }
    }
    if (index < pos) {
        cout << index + 1 << ". " << ptr[index].nama << ",\n " << "Jumlah: " << ptr[index].jumlah << ",\n " << "Jenis: " << ptr[index].jenis << endl;
        tampilkan(ptr, index + 1);
    }
}

void tambah() {
    system("cls");
    string loop;
    int pilihan;
    do {
        tampilkan();
        if (pos < max) {
            cin.ignore();
            cout << "Tambah Nama Sumber Daya Survival: ";
            getline(cin, sumber_daya[pos].nama); 
            cout << "Tambah Jumlah Sumber Daya Survival: ";
            cin >> sumber_daya[pos].jumlah;  
            cin.ignore();
            do {
                cout << "Pilih Jenis Data:\n1. Elektronik\n2. Konsumsi\n3. Senjata Survival\n4. Perlengkapan P3K Obat Obatan\nPilihan: ";
                cin >> pilihan;
                switch (pilihan) {
                    case 1:
                        sumber_daya[pos].jenis = "Elektronik";
                        break;
                    case 2:
                        sumber_daya[pos].jenis = "Konsumsi";
                        break;
                    case 3:
                        sumber_daya[pos].jenis = "Senjata Survival";
                        break;
                    case 4:
                        sumber_daya[pos].jenis = "Perlengkapan P3K Obat Obatan";
                        break;
                    default:
                        cout << "Pilihan tidak valid!" << endl;
                        break;
                }
            } while (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4);
            pos++;
            tampilkan(sumber_daya);
            do {
                cout << "Ulangi? (y/t): ";
                cin >> loop;
            } while (loop != "y" && loop != "t");
        } else {
            cout << "Penyimpanan Penuh" << endl;
            break;
        }
    } while (loop == "y");
}

void edit() {
    system("cls");
    string loop;
    if (pos == 0) {
        cout << "Ga Ada Data 1 pun, Keluar Dari Menu Edit\n";
        do {
            cout << "Kembali Menu Utama (y): ";
            cin >> loop;
        } while (loop != "y");
        return;
    }
    int y;
    do {
        tampilkan();
        do {
            cout << "Ubah Data Ke: ";
            cin >> y;
            cin.ignore();
            if (y > 0 && y <= pos) {
                int pilihan;
                do {
                    cout << "Pilih data yang ingin diubah:\n1. Nama Sumber Daya Survival\n2. Jumlah Sumber Daya Survival\n3. Jenis Sumber Daya Survival\nPilihan: ";
                    cin >> pilihan;
                    cin.ignore();
                    if (pilihan != 1 && pilihan != 2 && pilihan != 3) {
                        cout << "Pilihan Tidak Valid!\n";
                    }
                } while (pilihan != 1 && pilihan != 2 && pilihan != 3);
                switch (pilihan) {
                    case 1:
                        cout << "Ubah Nama Sumber Daya Survival Menjadi: ";
                        getline(cin, sumber_daya[y - 1].nama);
                        break;
                    case 2:
                        cout << "Ubah Jumlah Sumber Daya Survival Menjadi: ";
                        cin >> sumber_daya[y - 1].jumlah;
                        cin.ignore();
                        break;
                    case 3:
                        do {
                            cout << "Ubah Jenis Data Menjadi:\n1. Elektronik\n2. Konsumsi\n3. Senjata Survival\n4. Perlengkapan P3K Obat Obatan\nPilihan: ";
                            cin >> pilihan;
                            switch (pilihan) {
                                case 1:
                                    sumber_daya[y - 1].jenis = "Elektronik";
                                    break;
                                case 2:
                                    sumber_daya[y - 1].jenis = "Konsumsi";
                                    break;
                                case 3:
                                    sumber_daya[y - 1].jenis = "Senjata Survival";
                                    break;
                                case 4:
                                    sumber_daya[y - 1].jenis = "Perlengkapan P3K Obat Obatan";
                                    break;
                                default:
                                    cout << "Pilihan tidak valid!" << endl;
                                    break;
                            }
                        } while (pilihan != 1 && pilihan != 2 && pilihan != 3 && pilihan != 4);
                        break;
                    default:
                        cout << "Pilihan tidak valid" << endl;
                        break;
                }
                tampilkan();
            } else {
                cout << "Indeks tidak valid" << endl;
                do {
                    cout << "Ingin mengulang edit? (y/t)";
                    cin >> loop;
                    if (loop == "t") {
                        return;
                    }
                } while (loop != "y");
            }
        } while (y <= 0 || y > pos);
        do {
            cout << "Ubah Lagi (y/t): ";
            cin >> loop;
            if (loop != "y" && loop != "t") {
                cout << "Pilihan Tidak Valid!\n";
            }
        } while (loop != "y" && loop != "t");
    } while (loop == "y");
}

void hapus() {
    string loop;
    int x;
    do {
        tampilkan();
        if (pos > 0) {
            cout << "Hapus Data Ke: ";
            cin >> x;
            if (x > 0 && x <= pos) {
                for (int i = x; i < pos; i++) {
                    sumber_daya[i - 1] = sumber_daya[i];
                }
                pos--;
                tampilkan();
                if (pos == 0) {
                    return;
                }
                do {
                    cout << "Hapus Lagi (y/t): ";
                    cin >> loop;
                } while (loop != "y" && loop != "t");
            } else {
                cout << "Indeks tidak valid" << endl;
                do {
                    cout << "ingin mengulang hapus atau keluar (y/t)? ";
                    cin >> loop;
                } while (loop != "y" && loop != "t");
            }
        } else {
            do {
                cout << "Kembali (y): ";
                cin >> loop;
                if (loop == "y") {
                    return;
                }
            } while (loop != "y");
        }
    } while (loop == "y");
}

void bubbleSortNama() {
    bool tukar;
    do {
        tukar = false;
        for (int i = 1; i < pos; i++) {
            if (sumber_daya[i - 1].nama > sumber_daya[i].nama) {
                swap(sumber_daya[i - 1], sumber_daya[i]);
                tukar = true;
            }
        }
    } while (tukar);
}

void bubbleSortJumlah() {
    bool tukar;
    do {
        tukar = false;
        for (int i = 1; i < pos; i++) {
            if (sumber_daya[i - 1].jumlah > sumber_daya[i].jumlah) {
                swap(sumber_daya[i - 1], sumber_daya[i]);
                tukar = true;
            }
        }
    } while (tukar);
}

void bubbleSortJenis() {
    bool tukar;
    do {
        tukar = false;
        for (int i = 1; i < pos; i++) {
            if (sumber_daya[i - 1].jenis > sumber_daya[i].jenis) {
                swap(sumber_daya[i - 1], sumber_daya[i]);
                tukar = true;
            }
        }
    } while (tukar);
}

void binarySearch() {
    bubbleSortNama();
    string loop;
    string key;
    do {
        int awal = 0, akhir = pos - 1, tengah;
        bool found = false;
        cout << "Masukkan Nama Perlengkapan Sumber Daya yang ingin dicari: ";
        cin.ignore();
        getline(cin, key);
        while (awal <= akhir) {
            tengah = (awal + akhir) / 2;
            if (sumber_daya[tengah].nama == key) {
                cout << "Data ditemukan pada indeks ke-" << tengah + 1 << endl;
                cout << sumber_daya[tengah].nama << ", " << sumber_daya[tengah].jumlah << ", " << sumber_daya[tengah].jenis << endl;
                found = true;
                do {
                    cout << "Ingin Mengulang Cari? (y/t): ";
                    cin >> loop;
                    if (loop == "t") {
                        return;
                    }
                } while (loop != "y");
                break;
            } else if (sumber_daya[tengah].nama > key) {
                akhir = tengah - 1;
            } else {
                awal = tengah + 1;
            }
        }
        if (!found) {
            cout << "Nama tidak ditemukan" << endl;
            do {
                cout << "Ingin Mengulang Cari? (y/t): ";
                cin >> loop;
                if (loop == "t") {
                    return;
                }
            } while (loop != "y");
        }
    } while (loop == "y");
}

void sortMenu() {
    if (pos == 0) {
        cout << "Ga Ada Data 1 pun, Keluar Dari Menu Sorting\n";
        return;
    }
    int pilihan;
    do {
        cout << "Pilih metode pengurutan:\n1. Nama Sumber Daya Survival\n2. Jumlah Sumber Daya Survival\n3. Jenis Sumber Daya Survival\nPilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                bubbleSortNama();
                cout << "Data diurutkan berdasarkan Nama Sumber Daya Survival." << endl;
                break;
            case 2:
                bubbleSortJumlah();
                cout << "Data diurutkan berdasarkan Jumlah Sumber Daya Survival." << endl;
                break;
            case 3:
                bubbleSortJenis();
                cout << "Data diurutkan berdasarkan Jenis Sumber Daya Survival." << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
        }
    } while (pilihan < 1 || pilihan > 3);
    tampilkan();
}

void searchMenu() {
    string loop;
    if (pos == 0) {
        cout << "Ga Ada Data 1 pun, Keluar Dari Menu Cari\n";
        do {
                    cout << "Kembali Menu Utama (y): ";
                    cin >> loop;
                } while (loop != "y");
        return;
    }
    tampilkan();
    binarySearch();
}

void importFile() {
    ifstream file("tes_export.txt");
    if (!file) {
        cout << "File tidak ditemukan!" << endl;
        return;
    }
    string nama, jenis;
    int jumlah;
    while (file >> nama >> jumlah >> jenis) {
        if (pos < max) {
            sumber_daya[pos].nama = nama;
            sumber_daya[pos].jumlah = jumlah;
            sumber_daya[pos].jenis = jenis;
            pos++;
        } else {
            cout << "Penyimpanan penuh, beberapa data mungkin tidak diimpor." << endl;
            break;
        }
    }
    file.close();
    cout << "Data berhasil diimpor dari file." << endl;
}

void exportFile() {
    if (pos == 0) {
        cout << "Ga Ada Data 1 pun, Keluar Dari Menu Cari\n";
        return;
    }
    ofstream file("tes_export.txt");
    if (!file) {
        cout << "File tidak bisa dibuka!" << endl;
        return;
    }
    for (int i = 0; i < pos; i++) {
        file << sumber_daya[i].nama << " " << sumber_daya[i].jumlah << " " << sumber_daya[i].jenis << endl;
    }
    file.close();
    cout << "Data berhasil diekspor ke file." << endl;
}

int main() {
    int pil;
    string loop;
    do {
        system("cls");
        cout << "1. Tambah Perlengkapan Sumber Daya\n2. Ubah Sesuatu\n3. Hapus Sesuatu Perlengkapan Sumber Daya\n4. Tampilkan List\n5. Urutkan List Perlengkapan Sumber Daya\n6. Cari Nama Perlengkapan Sumber Daya\n7. Import Data dari File\n8. Ekspor Data ke File\n9. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pil;
        switch (pil) {
            case 1:
                tambah();
                break;
            case 2:
                edit();
                break;
            case 3:
                hapus();
                break;
            case 4:
                tampilkan();
                do {
                    cout << "Kembali Menu Utama (y): ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 5:
                sortMenu();
                do {
                    cout << "Kembali Menu Utama (y): ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 6:
                searchMenu();
                break;
            case 7:
                importFile();
                do {
                    cout << "Kembali Menu Utama (y): ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 8:
                exportFile();
                do {
                    cout << "Kembali Menu Utama (y): ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 9:
                cout << "Keluar Program" << endl;
                break;
            default:
                cout << "Pilih 1 - 9" << endl;
                break;
        }
    } while (pil != 9);
    cout << "Program Selesai . . ." << endl;
    return 0;
}
