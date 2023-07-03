#include <iostream>
using namespace std;


class biadangDatar {
private:
    int x; // variabel untuk menyimpan input dari lingkaran maupun persegi panjang 
    int y;

public:
    biadangDatar() { // constructor
        x = 0;
        y = 0;
    }

    virtual void input() = 0; // fungsi yang menerima input dan mengirim input melalui fungsi setX untuk disimpan di x

    virtual float Luas(int a) { return 0; }  // fungsi untuk menghitung luas

    virtual float Keliling(int a) { return 0; } // fungsi untuk menghitung keliling
  
    virtual void cekUkuran() { return ; }

    void setX(int a) { // enkapsulasi (mutator method) fungsi untuk memberi/mengirim nilai  ke dalam variabel x di kelas bidangdatar.
        this->x = a;
    } 
    void setY(int b) {
        this->y = b;
    }

    int getX() { // enkapsulasi. fungsi untuk membaca/mengambil nilai dalam x (assesor method)
        return x;
    }

    int getY(int b) {
        this->y = b ;
    }
 
    virtual void cekUkuran() {
        bool pilihan;

        do {
            cout << "Apakah anda ingin mengulang program? (Y/N): ";
            cin >> pilihan;
            cout << endl;
        } while (pilihan == 'Y' || pilihan == 'N');

        return ;
    }

};

// 

class Lingkaran : public biadangDatar {  // inheritance/pewarisan
public:
    void input() {
        cout << "Masukkan jari-jari: ";
        int r;
        cin >> r;
        setX(r);   // enkapsulasi (mutator method) yg digunakan untuk memberi atau mengubah nilai variable dalam kelas  
    }

    float Luas(int r) {
        return 3.14 * r * r;   // rumus Luas Lingkarang
    }

    float Keliling(int r) {
        return 2 * 3.14 * r;    // // rumus Keliling Lingkarang
    }

};


class persegipanjang : public biadangDatar {  // inheritance/pewarisan 
public:
    void input() {
        cout << "Masukkan panjang: ";
        int p ;
        cin >> p;
        setX(p);
       
        
        cout << "Masukkan lebar: ";
        int l;
        cin >> l;
        setY(l);

    }

    float Luas(int p, int l) {
        return p * l;
    }

    float Keliling(int p, int l) {
        return 2 * (p + l);
    }
};

int main() {
    biadangDatar* bd;
    

    cout << "Lingkaran dibuat" << endl;
    bd = new Lingkaran();                                        // Operator new digunakan untuk mengalokasikan memori dan membuat objek dari kelas turunan,  kemudian ditunjuk oleh pointer bd.
    bd->input();
    int r = bd->getX();
    cout << "Luas Lingkaran = " << bd->Luas(r) << endl;
    cout << "Keliling Lingkaran = " << bd->Keliling(r) << endl;


    cout << "Persegi panjang dibuat" << endl;
    bd = new persegipanjang();
    bd->input();
    int p = bd->getX();
    int l = bd->getY(l);
    cout << "Luas persegi panjang = " << bd->Luas(bd->getX()) << endl;
    cout << "Keliling persegi panjang = " << bd->Keliling(bd->getX()) << endl;

    delete bd;
    
    return 0;

};

