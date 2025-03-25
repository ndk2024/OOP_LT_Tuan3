#include <iostream>
#include <bits/stdc++.h>
//Bai 7
using namespace std;
struct NgaySinh
{
    int ngay, thang,nam;
};
void NhapNS(NgaySinh &a)
{
    cout<<"Nhap ngay sinh: ";
    cin>>a.ngay>>a.thang>>a.nam;
}
void XuatNS(NgaySinh a)
{
    cout<<a.ngay<<"/"<<a.thang<<"/"<<a.nam<<endl;
}
class cNhanVienVP
{
    private:
        string maNV;
        string hoTen;
        NgaySinh ngaySinh;
        double luong;
    public:
        cNhanVienVP()
        {
            maNV=hoTen="";
            luong=0;
            ngaySinh.ngay=ngaySinh.thang=ngaySinh.nam=0;
        };
        void Nhap();
        void Xuat();
        int namSinh()
        {
            return this->ngaySinh.nam;
        }
        double GetLuong()
        {
            return this->luong;
        }
        ~cNhanVienVP()
        {
            maNV=hoTen="";
            luong=0;
            ngaySinh.ngay=ngaySinh.thang=ngaySinh.nam=0;
        }

};
void cNhanVienVP::Nhap()
{
    cin.ignore();
    cout<<"Nhap Ma Nhan vien: ";
    getline(cin, maNV);
    cout<<"Nhap ho ten: ";
    getline(cin,hoTen);
    NhapNS(ngaySinh);
    cout<<"Nhap luong: ";
    cin>>luong;
}
void cNhanVienVP::Xuat()
{
    cout<<maNV<<endl;
    cout<<hoTen<<endl;
    XuatNS(ngaySinh);
    cout<<luong<<endl;
}
void nhapDS(cNhanVienVP danhsach[], int n)
{
    for(int i=0; i<n; i++)
    {
        danhsach[i].Nhap();
    }
}
void xuatDS(cNhanVienVP danhsach[], int n)
{
    for(int i=0; i<n; i++)
    {
        danhsach[i].Xuat();
    }
}

void NVmaxLuong(cNhanVienVP danhsach[], int n)
{
    double maxLuong=danhsach[0].GetLuong();
    int index=0;
    for(int i=1; i<n; i++)
    {
        if(maxLuong< danhsach[i].GetLuong())
        {
            maxLuong=danhsach[i].GetLuong();
            index=i;
        }
    }
    cout<<"Nhan vien co luong cao nhat: "<<endl;
    danhsach[index].Xuat();
}

void TongTien(cNhanVienVP danhsach[], int n)
{
    double sum=0;
    for(int i=0; i<n; i++)
    {
        sum+=danhsach[i].GetLuong();
    }
    cout<<sum;
}
void maxAge(cNhanVienVP danhsach[], int n)
{
    int nam=danhsach[0].namSinh();
    int index=0;
    for(int i=1; i<n; i++)
    {
        if(nam>danhsach[i].namSinh())
        {
            index=i;
            nam=danhsach[i].namSinh();
        }
    }
    danhsach[index].Xuat();
}

void SapXep(cNhanVienVP danhsach[], int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(danhsach[i].GetLuong()>danhsach[j].GetLuong())
                swap(danhsach[i],danhsach[j]);
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
    }while (n<0);
    // Nhap xuat danh sach
    cNhanVienVP *danhsach=new cNhanVienVP[n];
    nhapDS(danhsach, n);
    xuatDS(danhsach,n);

    //Nhan vien co luong cao nhat
    cout<<endl;
    NVmaxLuong(danhsach, n);

    //Tính tổng lương
    cout<<endl<<"Tong tien luong la: "<<endl;
    TongTien(danhsach,n);

    // Nhân viên có tuổi cao nhất
    cout<<endl<<"Nhan vien cao tuoi nhat: "<<endl;
    maxAge(danhsach, n);

    //Sắp xếp danh sách tăng dần theo lương
    SapXep(danhsach, n);
    xuatDS(danhsach,n);
    return 0;
}
