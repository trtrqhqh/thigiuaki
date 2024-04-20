#include <iostream>
#include <string>
using namespace std;

int main() {
    // Khai báo và khởi tạo mảng chứa chuỗi các MSSV
    char arrayMSSV[5][11] = {"", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002"};

    // Hiển thị các MSSV trong mảng
    cout << "Danh sách MSSV:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "MSSV " << i + 1 << ": " << arrayMSSV[i] << endl;
    }

    return 0;
}
