#include <iostream>
#include <string>
using namespace std;

int main() {
    // Khai báo và khởi tạo mảng chứa chuỗi các MSSV
    char arrayMSSV[5][11] = {"", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002"};

    // Hiển thị các MSSV trong mảng
    cout << "Danh sách MSSV ban đầu:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "MSSV " << i + 1 << ": " << arrayMSSV[i] << endl;
    }

    // Yêu cầu người dùng nhập MSSV của mình
    cout << "\nVui lòng nhập MSSV của bạn: ";
    cin.getline(arrayMSSV[0], 11);

    // Hiển thị lại các MSSV sau khi người dùng nhập
    cout << "\nDanh sách MSSV sau khi người dùng nhập:\n";
    for (int i = 0; i < 5; ++i) {
        cout << "MSSV " << i + 1 << ": " << arrayMSSV[i] << endl;
    }

    return 0;
}
