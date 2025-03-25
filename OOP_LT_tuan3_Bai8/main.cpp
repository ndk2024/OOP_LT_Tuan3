#include <iostream>
#include <bits/stdc++.h>
//Bai 8
using namespace std;

class cNhanVienSX
{
    private:
        string maNV;
        string hoTen;
        int namSinh;
        int spGC;
        double donGia;
        double luong;
    public:
        cNhanVienSX();
        void Nhap();
        void Xuat();
        double TinhLuong()
        {
           luong=spGC*donGia;
           return luong;
        }
        double getNS()
        {
            return this->namSinh;
        }
        double GetLuong()
        {
            return this->luong;
        }
};
cNhanVienSX::cNhanVienSX()
{
    maNV=hoTen="";
    int namSinh=0,spGC=0;
    double donGia=0;
}
void cNhanVienSX::Nhap()
{
    cin.ignore();
    cout<<"Nhap Ma Nhan vien: ";
    getline(cin, maNV);
    cout<<"Nhap ho ten: ";
    getline(cin, hoTen);
    cout<<"Nhap nam sinh: ";
    cin>>namSinh;
    cout<<"Nhap so sap pham: ";
    cin>>spGC;
    cout<<"Nhap don gia: ";
    cin>>donGia;
    TinhLuong();
}

void cNhanVienSX::Xuat()
{
    cout << left << setw(15) << maNV << setw(25) << hoTen << setw(10) << namSinh << setw(10) << luong << endl;
}
void NhapDS(cNhanVienSX danhsach[],  int n)
{
    for(int i=0; i<n; i++)
    {
        danhsach[i].Nhap();
    }
}
void XuatDS(cNhanVienSX danhsach[], int n) {
    cout << left << setw(15) << "Ma NV" << setw(25) << "Ho Ten" << setw(10) << "Nam Sinh" << setw(10) << "Luong" << endl;
    cout << "-------------------------------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        danhsach[i].Xuat();
    }
}

void NVminLuong(cNhanVienSX danhsach[], int n)
{
    double minLuong=danhsach[0].GetLuong();
    int index=0;
    for(int i=1; i<n; i++)
    {
        if(minLuong>danhsach[i].GetLuong())
        {
            index=i;
            minLuong=danhsach[i].GetLuong();
        }
    }
    danhsach[index].Xuat();
}

void TongTien(cNhanVienSX danhsach[], int n)
{
    double sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=danhsach[i].GetLuong();
    }
    cout<<sum;
}

void NVmaxTuoi(cNhanVienSX danhsach[], int n)
{
    int maxTuoi=danhsach[0].getNS();
    int index=0;
    for(int i=1; i<n; i++)
    {
        if(maxTuoi>danhsach[i].getNS())
        {
            index=i;
            maxTuoi=danhsach[i].getNS();
        }
    }
    danhsach[index].Xuat();
}

void SapXep(cNhanVienSX danhsach[], int n)
{
    for(int i=0;i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(danhsach[i].GetLuong()>danhsach[j].GetLuong())
            {
                swap(danhsach[i], danhsach[j]);
            }
        }
    }
}
int main()
{
    int n;
    do
    {
        cout<<"Nhap so luong nhan vien: ";
        cin>>n;
    }while(n<0);
    cNhanVienSX *danhsach= new cNhanVienSX[n];
    NhapDS(danhsach, n);
    XuatDS(danhsach,n);

    //Nhan vien co luong thap nhat
    cout<<endl<<"Nhan Vien co luong thap nhat: ";
    NVminLuong(danhsach, n);


    //Tong luong phai tra
    cout<<endl<<"Tong luong cong ty tra: ";
    TongTien(danhsach, n);

    //Nhan Vien co tuoi cao nhat
    cout<<endl<<"Nhan vien co tuoi cao nhat: ";
    NVmaxTuoi(danhsach, n);

    //Sap xep dnah sach tang theo luong
    SapXep(danhsach,n);
    XuatDS(danhsach, n);
    delete []danhsach;
    return 0;
}
