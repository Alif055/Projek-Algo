#include <iostream>
#include <fstream>
using namespace std;
 // cek line 205-207 ul menunya case 4
 // sm line 136 ul 2 2nya di konsep balik ke main menu
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

void ftm(Mahasiswa* head) {
    cout << "\n=== Data Mahasiswa Fakultas Teknologi Mineral ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == "FTM") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t " << bantu->jalurMasuk << "\t\t" << bantu->nilai << "\n";
        }
        bantu = bantu->next;
    }
}

void feb(Mahasiswa* head) {
    cout << "\n=== Data Mahasiswa Fakultas Ekonomi dan Bisnis ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == "FEB") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai << "\n";
        }
        bantu = bantu->next;
    }
}

void fti(Mahasiswa* head) {
    cout << "\n=== Data Mahasiswa Fakultas Teknik Industri ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == "FTI") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai << "\n";
        }
        bantu = bantu->next;
    }
}

void fp(Mahasiswa* head) {
    cout << "\n=== Data Mahasiswa Fakultas Pertanian ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == "FP") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai << "\n";
        }
        bantu = bantu->next;
    }
}

void fisip(Mahasiswa* head) {
    cout << "\n=== Data Mahasiswa Fakultas Ilmu Sosial ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai\n";

    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->fakultas == "FISIP") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai << "\n";
        }
        bantu = bantu->next;
    }
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
    cout << "|6. Kembali ke Menu Utama\t|\n";
    cout << "\npilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        ftm(head);
        break;
    case 2:
        feb(head);
        break;
    case 3:
        fti(head);
        break;
    case 4:
        fp(head);
        break;
    case 5:
        fisip(head);
        break;
    case 6:
        exit(0);
        break;
    default:
        cout << "pilihan tidak valid\n";
        break;
    }
}

void tampildataSNBP(Mahasiswa* head){
    cout << "\n=================== Data Mahasiswa Jalur SNBP ==================|\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai SNBP\t|\n";
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->jalurMasuk == "SNBP") {
            cout << bantu->nim << "\t" << bantu->nama << "\t"<< bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai <<"\t\t|" << "\n";
        }
        bantu = bantu->next;
    } cout << "================================================================|\n";
}

void tampildataSNBT(Mahasiswa* head){
    cout << "\n=================== Data Mahasiswa Jalur SNBT ==================|\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai SNBT\t|\n";

    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->jalurMasuk == "SNBT") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai <<"\t\t|" << "\n";
        }
        bantu = bantu->next;
    } cout << "================================================================|\n";
}

void tampildatamandiri(Mahasiswa* head){
    cout << "\n================== Data Mahasiswa Jalur Mandiri =================|\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\tNilai UM\t|\n";

    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->jalurMasuk == "Mandiri") {
            cout << bantu->nim << "\t" << bantu->nama << "\t" << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\t\t" << bantu->nilai <<"\t\t |" << "\n";
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
    cout << "|4. Kembali ke Menu Utama\t\t|\n";
    cout << "|_______________________________________|\n";
    cout << "\npilihan :";
        cin>>pilihan;
    switch (pilihan)
    {
    case 1:
        tampildataSNBP(head);
        break;
    case 2:
        tampildataSNBT(head);
        break;
    case 3:
        tampildatamandiri(head);
        break;
    case 4:     //benerin sekalian dong ul ini menunya| benerin sekalian dong ul ini menunya
        exit(0);//benerin sekalian dong ul ini menunya| benerin sekalian dong ul ini menunya
        break;  //benerin sekalian dong ul ini menunya| benerin sekalian dong ul ini menunya
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
    default:
        break;
    }
}



void tampilnilai() {
    int pilihan;
    cout << "\n=== Menu Tampilkan Nilai ===\n";
    cout << "1. Nilai SNBP secara ascending\n";
    cout << "2. Nilai SNBP secara descending\n";
    cout << "3. Nilai SNBT secara ascending\n";
    cout << "4. Nilai SNBT secara descending\n";
    cout << "5. Nilai Mandiri secara ascending\n";
    cout << "6. Nilai Mandiri secara descending\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
    cin >> pilihan;
    switch (pilihan)
    {
    case 1:
        /* code */
        break;
    case 2:
        /* code */
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        /* code */
        break;
    case 6:
        /* code */
        break;
    default:
        break;
    }

}

void cari(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    
    string cari;
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

void edit(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    
    string cari;
    cout << "\nMasukkan NIM yang akan diedit: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        if (bantu->nim == cari) {
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
    cout << "\nMasukkan NIM yang akan dihapus: ";
    getline(cin, cari);
    
    Mahasiswa* bantu = *head;
    Mahasiswa* prev = nullptr;
    

    if (bantu != nullptr && bantu->nim == cari) {
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

    cout << "\n=== Statistik Data Mahasiswa ===\n";
    cout << "Total Mahasiswa : " << total << "\n";

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
        cout << "\n=== Menu Utama ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data\n";
        cout << "3. Cari Data\n";
        cout << "4. Edit Data\n";
        cout << "5. Statistik Data\n";
        cout << "6. Hapus Data\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: tambahData(&head); break;
            case 2: tampilkanData(head); break;
            case 3: cari(head); break;
            case 4: edit(head); break;
            case 5: statistikdata(head); break;
            case 6: dilet(&head); break;
            case 0: save(head); break;
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
