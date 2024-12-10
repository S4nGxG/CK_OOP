#include <bits/stdc++.h>
using namespace std;

class YeuTo {
protected:
    int ChiSo;
public:
    YeuTo();
    int GetChiSo();
    virtual void ChiSoCao() = 0;  
    virtual void ChiSoThap() = 0;
    virtual void TinhCach() = 0;  
};

YeuTo::YeuTo() {}
int YeuTo::GetChiSo() {
    return ChiSo;
}

class O : public YeuTo {
public:
    O();
    O(int);
    void ChiSoCao();
    void ChiSoThap();
    void TinhCach();
};
O::O() {}
O::O(int value) {
    ChiSo = value;
}
void O::TinhCach() {  
    cout << "San sang trai nghiem (O)";
}
void O::ChiSoCao() {
    cout << "Nguoi thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc...\n";
}
void O::ChiSoThap() {
    cout << "Nguoi kha bao thu, kho tiep nhan nhung y tuong moi la. Ho thich su on dinh, quen thuoc va thuc te.\n";
}

class C : public YeuTo {
public:
    C();
    C(int);
    void ChiSoCao();
    void ChiSoThap();
    void TinhCach();
};
C::C() {}
C::C(int value) {
    ChiSo = value;
}
void C::TinhCach() {  
    cout << "Tu chu tan tam (C)";
}
void C::ChiSoCao() {
    cout << "Nguoi co diem cao o yeu to nay thuong la nguoi cham chi, co kha nang chiu duoc ap luc tot. Ho thuong la nguoi gan bo, trung thanh voi to chuc.\n";
}
void C::ChiSoThap() {
    cout << "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu cua to chuc kem.\n";
}

class E : public YeuTo {
public:
    E();
    E(int);
    void ChiSoCao();
    void ChiSoThap();
    void TinhCach();
};
E::E() {}
E::E(int value) {
    ChiSo = value;
}
void E::TinhCach() {  
        cout << "Huong ngoai (E)";
}
void E::ChiSoCao() {
    cout << "Nguoi co diem cao o yeu to nay thuong la nguoi nhiet tinh, nang dong, giao tiep tot, thich the hien ban than.\n";
}
void E::ChiSoThap() {
    cout << "Nguoi co diem thap o yeu to nay thuong ngai giai tiep, khong thich su noi bat, thich duoc lam viec doc lap.\n";
}

class A : public YeuTo {
public:
    A();
    A(int);
    void ChiSoCao();
    void ChiSoThap();
    void TinhCach();
};
A::A() {}
A::A(int value) {
    ChiSo = value;
}
void A::TinhCach() {  
        cout << "Hoa dong de chiu (A)";
}
void A::ChiSoCao() {
    cout << "Nguoi co diem cao o yeu to nay thuong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi thieu chinh kien.\n";
}
void A::ChiSoThap() {
    cout << "Nguoi co diem thap thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao.\n";
}

class N : public YeuTo {
public:
    N();
    N(int);
    void ChiSoCao();
    void ChiSoThap();
    void TinhCach();
};
N::N() {}
N::N(int value) {
    ChiSo = value;
}
void N::TinhCach() {  
        cout << "Bat on cam xuc (N)";
}
void N::ChiSoCao() {
    cout << "Nguoi co diem cao o yeu to nay thuong co cac cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem.\n";
}
void N::ChiSoThap() {
    cout << "Nguoi co diem thap thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than.\n";
}

class Person {
private:
    YeuTo *a[6];
public:
    Person();
    void Nhap();
    void TinhCach();
    bool NguyCo();
};
Person::Person() {}
void Person::Nhap() {
    int n;
    cout << "Nhap gia tri cua yeu to O: "; cin >> n;
    a[0] = new O(n);
    cout << "Nhap gia tri cua yeu to C: "; cin >> n;
    a[1] = new C(n);
    cout << "Nhap gia tri cua yeu to E: "; cin >> n;
    a[2] = new E(n);
    cout << "Nhap gia tri cua yeu to A: "; cin >> n;
    a[3] = new A(n);
    cout << "Nhap gia tri cua yeu to N: "; cin >> n;
    a[4] = new N(n);
}
void Person::TinhCach() {
    for(int i = 0; i < 5; i++) {  
        a[i]->TinhCach();  
        cout << " : ";
        if(a[i]->GetChiSo() >= 70) {
            a[i]->ChiSoCao();  
        }
        else {
            if(a[i]->GetChiSo() <= 30) {  
                a[i]->ChiSoThap();  
            }
            else cout << "Khong xac dinh!\n";
        }
    }
}

bool Person::NguyCo() {
    if(a[1]->GetChiSo() <= 30 || a[4]->GetChiSo() >= 70 || (a[2]->GetChiSo() <= 30 && a[4]->GetChiSo() >= 70))
        return true;
    return false;
}
int main() {
    Person n[100];
    int d;
    cout << "Nhap so luong nguoi can dien thong tin: "; cin >> d;
    for(int i = 0; i < d; i++) {
        cout << "Nhap thong tin nguoi thu " << i+1 << "\n"; 
        n[i].Nhap();
    }
    int t;
    cout << "Nhap thu tu nguoi can biet cac thong tin tinh cach la: "; cin >> t;
    n[t-1].TinhCach();  
    cout << "Nhung nguoi co nguy co cao ma nha tuyen dung can luu y la: ";
    for(int i = 0; i < d; i++) {
        if(n[i].NguyCo() == true) 
            cout << i+1 << " ";  
    }
    return 0;
}