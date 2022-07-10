/*Sử dụng các cấu trúc dữ liệu đã học, viết chương trình cho phép nhập và lưu trữ thông tin về một đồ thị cho trước trên máy tính 
bằng các phương pháp ma trận liền kề, danh sách liền kề và danh sách cạnh.
Kiểm tra xem đồ thị đã cho là đồ thị vô hướng hay có hướng.
Liệt kê số bậc của tất cả các đỉnh trong trường hợp đồ thị vô hướng, hay bán bậc ra và bán bậc vào trong trường hợp đồ thị có hướng.
Tạo file dữ liệu và demo với các đồ thị ở Chương 1, slide 23.*/


#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
using namespace std;

bool kiemtraFiletontai(ifstream &fi) { // kiểu dữ liệu dùng để đọc thông tin từ các file
    bool cotontai = true;
    bool khongtontai = fi.fail(); // fail trả về false nếu đối tượng của ifstream không liên kết với file được
    if (khongtontai == true) {
        cotontai = false;
    }
    return cotontai;
}

void docfile(ifstream& fi, int** a, int n) // cấp phát động mảng 2 chiều bằng con trỏ
{
    int x, i;
    while (!fi.eof()) // true khi con trỏ đã trỏ tới cuối file và với false thì ngược lại.
    {
        fi >> i; 
        cout << "Day la i ne: " << i;
        while (true)
        {
            fi >> x; 
             cout << "Day la x ne: " << x;
            if (x > 0)
                a[i][x] = 1;
            if (fi.eof())
                break;
            char c;
            fi.get(c); 
            cout << "Day la C ne:" << c << "hello c";
            char ch[2] = { c };
            if (strcmp(ch, " ") != 0) 
            {
                break;
            }
        }
    }
}

void xuatmatranke(int** a, int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

bool kiemtradothi(int** a, int n)
{
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != a[j][i]) {
                return false;
            }
        }
    } 
    return true;
}

void demsobac(int** a, int n) {
    if (kiemtradothi(a, n)) {
        cout << "Ket luan: Do thi vo huong\n";
        int sobac = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1) {
                    sobac++;
                }
            }
            cout << "Dinh " << i << " co " << sobac << " bac" << endl;
        }
    }
    else {
        cout << "Ket luan: Do thi co huong\n";

        for (int i = 1; i <= n; i++)
        {
            int bacra = 0, bacvao = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[i][j] == 1)
                    bacra++;
                if (a[j][i] == 1)
                    bacvao++;
            }
            cout << "Dinh " << i << " co " << bacvao << "bac vao va " << bacra << "bac ra\n";
        }
    }
}

int main()
{
    cout << "BT1: Bieu dien do thi --- 2051120333/Tcheng Nhu Quan\n";
    ifstream fi("TH01_input.txt");
    kiemtraFiletontai(fi);
    if (kiemtraFiletontai(fi) == true) {
        cout << "File ton tai\n";
    }
    else {
        cout << "Loi. File khong ton tai!\n";
    }

    int n = 0;
    fi >> n;
    string s;
    getline(fi, s);

    int** a = new int* [n + 1];
    for (int i = 1; i <= n; i++)
        a[i] = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) a[i][j] = 0;

    docfile(fi, a, n);
    cout << "Xuat ma tran ke cua do thi la: " << endl;
    xuatmatranke(a, n);
    fi.close();
    demsobac(a, n);

    for (int i = 1; i <= n; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}
