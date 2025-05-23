#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string fakultas;
    string jalurMasuk;
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

void tampilkanData(Mahasiswa* head) {
    if (head == nullptr) {
        cout << "\nTidak ada data mahasiswa!\n";
        return;
    }
    
    cout << "\n=== Daftar Mahasiswa ===\n";
    cout << "NIM\tNama\tFakultas\tJalur Masuk\n";
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        cout << bantu->nim << "\t" << bantu->nama << "\t" 
             << bantu->fakultas << "\t\t" << bantu->jalurMasuk << "\n";
        bantu = bantu->next;
    }
}

void cariData(Mahasiswa* head) {
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
            cout << "\nData ditemukan:\n";
            cout << "NIM: " << bantu->nim << "\n";
            cout << "Nama: " << bantu->nama << "\n";
            cout << "Fakultas: " << bantu->fakultas << "\n";
            cout << "Jalur Masuk: " << bantu->jalurMasuk << "\n";
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "\nData tidak ditemukan!\n";
}

void editData(Mahasiswa* head) {
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
            cout << "NIM: " << bantu->nim << "\n";
            cout << "Nama: " << bantu->nama << "\n";
            cout << "Fakultas: " << bantu->fakultas << "\n";
            cout << "Jalur Masuk: " << bantu->jalurMasuk << "\n";
            
            cout << "\nMasukkan data baru:\n";
            cout << "Nama: ";
            getline(cin, bantu->nama);
            cout << "Fakultas: ";
            getline(cin, bantu->fakultas);
            cout << "Jalur Masuk: ";
            getline(cin, bantu->jalurMasuk);
            
            cout << "Data berhasil diperbarui!\n";
            return;
        }
        bantu = bantu->next;
    }
    
    cout << "\nData tidak ditemukan!\n";
}

void hapusData(Mahasiswa** head) {
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

void simpanKeFile(Mahasiswa* head) {
    ofstream file("data_mahasiswa.txt");
    
    if (!file) {
        cout << "Gagal membuka file!\n";
        return;
    }
    
    Mahasiswa* bantu = head;
    while (bantu != nullptr) {
        file << bantu->nim << "," << bantu->nama << "," << bantu->fakultas << "," << bantu->jalurMasuk << "\n";
        bantu = bantu->next;
    }
    
    file.close();
}

void bacaDariFile(Mahasiswa** head) {
    ifstream file("data_mahasiswa.txt");
    
    if (!file) {
        return;
    }
    
    Mahasiswa* baru;
    string temp;
    
    while (true) {
        baru = new Mahasiswa;
        
        getline(file, baru->nim, ',');
        if (file.eof()) {
            delete baru;
            break;
        }
        

        getline(file, baru->nama, ',');

        getline(file, baru->fakultas, ',');
        

        getline(file, baru->jalurMasuk);
        
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
        cout << "5. Hapus Data\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        
        switch (pilihan) {
            case 1: tambahData(&head); break;
            case 2: tampilkanData(head); break;
            case 3: cariData(head); break;
            case 4: editData(head); break;
            case 5: hapusData(&head); break;
            case 0: simpanKeFile(head); break;
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
