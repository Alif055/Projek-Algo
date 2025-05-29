#include <iostream>
#include <fstream>
using namespace std;
struct Mahasiswa {
    string nim;
    string nama;
    string fakultas;
    string jalurMasuk;
    float nilai;
    Mahasiswa* next;
};

void tambahData(Mahasiswa** head) {
    Mahasiswa* baru = new Mahasiswa;
    
    cout << "\nMasukkan NIM: ";
    getline(cin, baru->nim);
    cout << "Masukkan Nama: ";
    getline(cin, baru->nama);
    cout << "Masukkan Fakultas: ";
    getline(cin, baru->fakultas);
    cout << "Masukkan Jalur Masuk: ";
    getline(cin, baru->jalurMasuk);
    cout << "Masukkan Nilai " << baru->jalurMasuk << " : ";
    cin >> baru->nilai;

    baru->next = nullptr;
    
    if (*head == nullptr || baru->nim < (*head)->nim) {
        baru->next = *head;
        *head = baru;
    } else {
        Mahasiswa* bantu = *head;
        while (bantu->next != nullptr && bantu->next->nim < baru->nim) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
    
    cout << "Data berhasil ditambahkan!\n";
}

void tampildatafakultas(Mahasiswa* head, string namafakultas) {
    cout << "\n====================== Data Mahasiswa " << namafakultas <<" ======================|\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai SNBP\t|\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == namafakultas) {
            cout << bantu->nim << "\t" << bantu->nama << "\t"<< bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai <<"\t\t|" << "\n";
        }
        bantu = bantu->next;
    } cout << "================================================================|\n";
}

void datafakultas(Mahasiswa* head) {
    int pilihan;
    cout << "\n_________________________________\n";
    cout << "|  Menu Tampilan Data Fakultas  |\n";
    cout << "|1. Fakultas Teknologi Mineral\t|\n";
    cout << "|2. Fakultas Ekonomi dan Bisnis\t|\n";
    cout << "|3. Fakultas Teknik Industri\t|\n";
    cout << "|4. Fakultas Pertanian\t\t|\n";
    cout << "|5. Fakultas Ilmu Sosial\t|\n";
    cout << "|0. Kembali ke Menu Utama\t|\n";
    cout << "\npilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        tampildatafakultas(head, "FTM");
        break;
    case 2:
        tampildatafakultas(head, "FEB");
        break;
    case 3:
        tampildatafakultas(head, "FTI");
        break;
    case 4:
        tampildatafakultas(head, "FP");
        break;
    case 5:
        tampildatafakultas(head, "FISIP");
        break;
    case 0:
        cout << "kembali ke menu utama...\n";
        break;
    default:
        cout << "pilihan tidak valid\n";
        break;
    }
}

void tampildatajalur(Mahasiswa* head, string jalur){
    cout << "\n=================== Data Mahasiswa Jalur " << jalur <<" ==================|\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai SNBP\t|\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->jalurMasuk == jalur) {
            cout << bantu->nim << "\t" << bantu->nama << "\t"<< bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai <<"\t\t|" << "\n";
        }
        bantu = bantu->next;
    } cout << "================================================================|\n";
}

void datajalurmasuk(Mahasiswa* head) {
    int pilihan;
    cout << "_________________________________________\n";
    cout << "|     Menu Tampilan Data Jalur Masuk    |\n";
    cout << "|1. Jalur SNBP\t\t\t\t|\n";
    cout << "|2. Jalur SNBT\t\t\t\t|\n";
    cout << "|3. Jalur Mandiri\t\t\t|\n";
    cout << "|0. Kembali ke Menu Utama\t\t|\n";
    cout << "|_______________________________________|\n";
    cout << "\npilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        tampildatajalur(head, "SNBP");
        break;
    case 2:
        tampildatajalur(head, "SNBT");
        break;
    case 3:
        tampildatajalur(head, "Mandiri");
        break;
    case 0:   
        cout << "kembali ke menu utama...\n";
        break;  
    default:
        cout << "pilihan tidak valid\n";
        break;
    }
}

void tampilkanData(Mahasiswa* head) {
    int pilihan;
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    cout << "|------Menu Tampilan Data-------|\n";
    cout << "|1. Berdasarkan Fakultas\t|\n";
    cout << "|2. Berdasarkan Jalur Masuk\t|\n";
    cout << "|0. Kembali ke Menu Utama\t|\n";
    cout << "|-------------------------------|\n";

    cout << "\nPilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        datafakultas(head);
        break;
    case 2:
        datajalurmasuk(head);
        break;
    case 0:
        cout <<"kembali ke menu utama...\n";
        break;
    default:
        cout << "pilihan tidak valid\n";
        break;
    }
}

void quickSortMahasiswa(Mahasiswa* arr[], int awal, int akhir, bool ascending) {
    int low = awal, high = akhir;
    float pivot = arr[(awal + akhir) / 2]->nilai;

    do {
        if (ascending) {
            while (arr[low]->nilai < pivot) low++;
            while (arr[high]->nilai > pivot) high--;
        } else {
            while (arr[low]->nilai > pivot) low++;
            while (arr[high]->nilai < pivot) high--;
        }

        if (low <= high) {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
    } while (low <= high);

    if (awal < high)
        quickSortMahasiswa(arr, awal, high, ascending);
    if (low < akhir)
        quickSortMahasiswa(arr, low, akhir, ascending);
}


void tampilkanUrutNilai(Mahasiswa* head, string jalur, bool ascending) {
    Mahasiswa* arr[100];
    int n = 0;
    Mahasiswa* bantu = head;

    while (bantu != nullptr) {
        if (bantu->jalurMasuk == jalur) {
            arr[n++] = bantu;
        }
        bantu = bantu->next;
    }

    if (n == 0) {
        cout << "Tidak ada data mahasiswa untuk jalur " << jalur << ".\n";
        return;
    }

    quickSortMahasiswa(arr, 0, n - 1, ascending);

    cout << "\n=======================================================\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";
    cout << "=======================================================\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i]->nim << "\t" << arr[i]->nama << "\t" << arr[i]->fakultas
             << "\t\t" << arr[i]->jalurMasuk << "\t\t" << arr[i]->nilai << "\n";
    }
}



void tampilnilai(Mahasiswa* head) {
    int pilihan;
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    cout << "\n=== Menu Tampilkan Nilai ===\n";
    cout << "1. Nilai SNBP secara ascending\n";
    cout << "2. Nilai SNBP secara descending\n";
    cout << "3. Nilai SNBT secara ascending\n";
    cout << "4. Nilai SNBT secara descending\n";
    cout << "5. Nilai Mandiri secara ascending\n";
    cout << "6. Nilai Mandiri secara descending\n";
    cout << "0. kembali ke menu utama...\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        tampilkanUrutNilai(head, "SNBP", true);
        break;
    case 2:
        tampilkanUrutNilai(head, "SNBP", false);
        break;
    case 3:
        tampilkanUrutNilai(head, "SNBT", true);
        break;
    case 4:
        tampilkanUrutNilai(head, "SNBT", false);
        break;
    case 5:
        tampilkanUrutNilai(head, "Mandiri", true);
        break;
    case 6:
        tampilkanUrutNilai(head, "Mandiri", false);
        break;
    case 0:
        cout << "kembali ke menu utama...\n";
        break;
    default:
        cout << "pilihan tidak valid\n";
        break;
    }

}

void carinim(Mahasiswa* head) {
    string cari;
    cin.ignore();
    cout << "\nMasukkan NIM yang dicari: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->nim == cari) {
            cout << "\nData Mahasiswa:\n";
            cout << "NIM\t\t: " << bantu->nim << "\n";
            cout << "Nama\t\t: " << bantu->nama << "\n";
            cout << "Fakultas\t: " << bantu->fakultas << "\n";
            cout << "Jalur Masuk\t: " << bantu->jalurMasuk << "\n";
            cout << "Nilai\t\t: " << bantu->nilai << "\n";
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "\nData tidak ditemukan!\n";
}

void carinama(Mahasiswa* head) {
    string cari;
    cin.ignore();
    cout << "\nMasukkan nama yang dicari: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->nama == cari) {
            cout << "\nData Mahasiswa:\n";
            cout << "NIM\t\t: " << bantu->nim << "\n";
            cout << "Nama\t\t: " << bantu->nama << "\n";
            cout << "Fakultas\t: " << bantu->fakultas << "\n";
            cout << "Jalur Masuk\t: " << bantu->jalurMasuk << "\n";
            cout << "Nilai\t\t: " << bantu->nilai << "\n";
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "\nData tidak ditemukan!\n";
}

void cari(Mahasiswa* head) {
    int pilihan;
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    cout << "|------Menu Pencarian Data------|\n";
    cout << "|1. Berdasarkan NIM \t\t|\n";
    cout << "|2. Berdasarkan Nama \t\t|\n";
    cout << "|0. Kembali ke Menu Utama\t|\n";
    cout << "|-------------------------------|\n";

    cout << "\nPilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        carinim(head);
        break;
    case 2:
        carinama(head);
        break;
    case 0:
        cout << "kembali ke menu utama...";
        break;
    default:
        cout << "pilihan tidak valid\n";
        break;
    }
}

void edit(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    
    string cari;
    cout << "\nMasukkan NIM atau Nama yang akan diedit: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->nim == cari || bantu->nama == cari) {
            cout << "\nData saat ini:\n";
            cout << "NIM\t\t: " << bantu->nim << "\n";
            cout << "Nama\t\t: " << bantu->nama << "\n";
            cout << "Fakultas\t: " << bantu->fakultas << "\n";
            cout << "Jalur Masuk\t: " << bantu->jalurMasuk << "\n";
            cout << "Nilai\t\t: " << bantu->nilai << "\n";
            cout << "_________________________";
            cout << "\nMasukkan data baru:\n";
            cout << "Nama: ";
            getline(cin, bantu->nama);
            cout << "Fakultas: ";
            getline(cin, bantu->fakultas);
            cout << "Jalur Masuk: ";
            getline(cin, bantu->jalurMasuk);
            cout << "Nilai:";
            cin >> bantu->nilai;
            
            cout << "Data berhasil diperbarui!\n";
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "\nData tidak ditemukan!\n";
}

void dilet(Mahasiswa** head) {
    if (*head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    
    string cari;
    cout << "\nMasukkan NIM atau Nama yang akan dihapus: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = *head;
    Mahasiswa* prev = nullptr;
    

    if (bantu != nullptr && (bantu->nim == cari || bantu->nama == cari)) {
        *head = bantu->next;
        delete bantu;
        cout << "Data berhasil dihapus!\n";
        return;
    }
    

    while (bantu != nullptr && bantu->nim != cari) {
        prev = bantu;
        bantu = bantu->next;
    }
    
    if (bantu == nullptr) {
        cout << "\nData tidak ditemukan!\n";
        return;
    }
    

    prev->next = bantu->next;
    delete bantu;
    cout << "Data berhasil dihapus!\n";
}

void save(Mahasiswa* head) {
    ofstream file("data_mahasiswa.txt");
    
    if (!file) {
        cout << "Gagal membuka file!\n";
        return;
    }
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        file << bantu->nim << "\n";
        file << bantu->nama << "\n";
        file << bantu->fakultas << "\n";
        file << bantu->jalurMasuk << "\n";
        file << bantu->nilai << "\n";
        bantu = bantu->next;
    }
    
    file.close();
}

void bacaDariFile(Mahasiswa** head) {
    ifstream file("data_mahasiswa.txt");
    
    if (!file) {
        return;
    }
    
    while (true) {
        Mahasiswa* baru = new Mahasiswa;
        
        if (!getline(file, baru->nim)) break;
        if (!getline(file, baru->nama)) break;
        if (!getline(file, baru->fakultas)) break;
        if (!getline(file, baru->jalurMasuk)) break;
        file >> baru->nilai;
        file.ignore();
        
        baru->next = nullptr;
        
        if (*head == nullptr || baru->nim < (*head)->nim) {
            baru->next = *head;
            *head = baru;
        } else {
            Mahasiswa* bantu = *head;
            while (bantu->next != nullptr && bantu->next->nim < baru->nim) {
                bantu = bantu->next;
            }
            baru->next = bantu->next;
            bantu->next = baru;
        }
    }
    
    file.close();
}

void statistikdata(Mahasiswa* head) {
    int total = 0;
    int fti = 0, ftm = 0, feb = 0, fp = 0, fisip = 0;
    int snbp = 0, snbt = 0, mandiri = 0;

    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        total++;
        if (bantu->fakultas == "FTI") fti++;
        else if (bantu->fakultas == "FTM") ftm++;
        else if (bantu->fakultas == "FEB") feb++;
        else if (bantu->fakultas == "FP") fp++;
        else if (bantu->fakultas == "FISIP") fisip++;

        if (bantu->jalurMasuk == "SNBP") snbp++;
        else if (bantu->jalurMasuk == "SNBT") snbt++;
        else if (bantu->jalurMasuk == "Mandiri") mandiri++;

        bantu = bantu->next;
    }

    cout << "\n========================================\n";
    cout << "======= Statistik Data Mahasiswa =======\n";
    cout << "========================================\n";
    cout << "\nTotal Mahasiswa : " << total << "\n";

    cout << "\nJumlah per Fakultas:\n";
    cout << "FTI   : " << fti << "\n";
    cout << "FTM   : " << ftm << "\n";
    cout << "FEB   : " << feb << "\n";
    cout << "FP    : " << fp << "\n";
    cout << "FISIP : " << fisip << "\n";

    cout << "\nJumlah per Jalur Masuk:\n";
    cout << "- SNBP    : " << snbp << "\n";
    cout << "- SNBT    : " << snbt << "\n";
    cout << "- Mandiri : " << mandiri << "\n";
}

int main() {
    Mahasiswa* head = nullptr;
    int pilihan;
    
    bacaDariFile(&head);
    
    do {
        cout << "\n========================================\n";
        cout << "=== Sistem Penerimaan Mahasiswa Baru ===\n";
        cout << "========================================\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Edit Data\n";
        cout << "5. Sorting Nilai\n";
        cout << "6. Statistik Data\n";
        cout << "7. Hapus Data\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: 
                tambahData(&head); 
                break;
            case 2: 
                tampilkanData(head); 
                break;
            case 3:    
                cari(head); 
                break;
            case 4: 
                edit(head); 
                break;
            case 5: 
                tampilnilai(head);
                break;
            case 6: 
                statistikdata(head); 
                break;
            case 7: 
                dilet(&head); 
                break;
            case 0: 
                save(head); 
                break;
            default: cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);
    
    while (head != nullptr) {
        Mahasiswa* temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}
