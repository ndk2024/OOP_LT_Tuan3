#include <iostream>
#include <algorithm>
#include <cmath>
//Bài 5
using namespace std;

class cDaThuc
{
    private:
        int bac;
        int* a;

    public:
        cDaThuc() : bac(0), a(nullptr) {}
        void Nhap();
        void Xuat();
        cDaThuc operator+(const cDaThuc& other);
        cDaThuc operator-(const cDaThuc& other);
        double GiaTri(int x);
        ~cDaThuc() { delete[] a; }
};

double cDaThuc::GiaTri(int x)
{
    int giatri=0;
    for(int i=bac; i>=0; i--)
    {
        giatri+=a[i]*pow(x,i);
    }
    return giatri;
}
void cDaThuc::Nhap()
{
    do {
        std::cout << "Nhap bac cua da thuc: ";
        std::cin >> bac;
    } while (bac < 0);

    a = new int[bac + 1];
    std::cout << "Nhap cac he so (tu bac cao nhat den bac 0):\n";
    for (int i = bac; i >= 0; --i) {
        std::cin >> a[i];
    }
}

void cDaThuc::Xuat()
{
    for (int i = bac; i >= 0; --i) {
        if (a[i] != 0) {
            if (i < bac && a[i] > 0) {
                std::cout << " + ";
            } else if (i < bac && a[i] <0){
                std::cout << " ";
            }
            std::cout << a[i];
            if (i > 0) {
                std::cout << "x";
                if (i > 1) {
                    std::cout << "^" << i;
                }
            }
        }
    }
    std::cout << std::endl;
}

cDaThuc cDaThuc::operator+(const cDaThuc& other)
{
    cDaThuc result;
    result.bac = std::max(bac, other.bac);
    result.a = new int[result.bac + 1];

    for (int i = 0; i <= result.bac; ++i) {
        int coef1 = (i <= bac) ? a[i] : 0;
        int coef2 = (i <= other.bac) ? other.a[i] : 0;
        result.a[i] = coef1 + coef2;
    }
    return result;
}

cDaThuc cDaThuc::operator-(const cDaThuc& other) {
    cDaThuc result;
    result.bac = std::max(bac, other.bac);
    result.a = new int[result.bac + 1];

    for (int i = 0; i <= result.bac; ++i) {
        int coef1 = (i <= bac) ? a[i] : 0;
        int coef2 = (i <= other.bac) ? other.a[i] : 0;
        result.a[i] = coef1 - coef2;
    }
    return result;
}

int main() {
    cDaThuc d1, d2;
    cout << "Nhap da thuc 1:\n";
    d1.Nhap();
    cout << "Da thuc 1: ";
    d1.Xuat();

    cout << "Nhap da thuc 2:\n";
    d2.Nhap();
    cout << "Da thuc 2: ";
    d2.Xuat();

    cout << "\nTong hai da thuc:\n";
    cDaThuc Tong = d1 + d2;
    Tong.Xuat();

    std::cout << "\nHieu hai da thuc:\n";
    cDaThuc Hieu = d1 - d2;
    Hieu.Xuat();

    int x;
    cout<<"Nhap gia tri ";
    cin>>x;
    cout<<"Gia Tri Da Thuc 1: ";
    int giatri=d1.GiaTri(x);
    cout<<giatri<<endl;
    return 0;
}
