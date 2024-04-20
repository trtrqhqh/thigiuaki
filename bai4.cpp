#include <iostream>
#include <cstring>

// Hàm trợ giúp để so sánh 2 chuỗi MSSV
bool soSanhMSSV(char mssv1[], char mssv2[]) {
    // So sánh phần số đầu tiên (tức phần “2305” của “2305CT1010”)
    int soSanhSo = std::strcmp(mssv1, mssv2);
    
    // Nếu số đầu tiên khác nhau, trả về kết quả so sánh
    if (soSanhSo != 0) 
        return soSanhSo < 0;
    
    // Nếu số đầu tiên giống nhau, tiếp tục so sánh phần "CT" và "1010"
    return std::atoi(mssv1 + 5) < std::atoi(mssv2 + 5);
}

// Hàm sắp xếp mảng MSSV theo thứ tự từ thấp đến cao
void sapXepMSSV(char mangMSSV[][11], int kichThuoc) {
    for (int i = 0; i < kichThuoc - 1; ++i) {
        for (int j = 0; j < kichThuoc - i - 1; ++j) {
            // Nếu mangMSSV[j] > mangMSSV[j + 1], đổi chỗ 2 chuỗi
            if (!soSanhMSSV(mangMSSV[j], mangMSSV[j + 1])) {
                char temp[11];
                strcpy(temp, mangMSSV[j]);
                strcpy(mangMSSV[j], mangMSSV[j + 1]);
                strcpy(mangMSSV[j + 1], temp);
            }
        }
    }
}

int main() {
    char arrayMSSV[5][11] = {"", "2301CT1234", "2302CT3456", "2305CT3999", "2304CT0002"};

    // Nhập MSSV của user vào phần tử đầu tiên của mảng
    std::cout << "Nhập MSSV của bạn: ";
    std::cin >> arrayMSSV[0];

    // In ra mảng MSSV ban đầu
    std::cout << "Mảng MSSV ban đầu:" << std::endl;
    for(int i = 0; i < 5; ++i) {
        std::cout << "MSSV " << i+1 << ": " << arrayMSSV[i] << std::endl;
    }

    // Sắp xếp mảng MSSV theo thứ tự từ thấp đến cao
    sapXepMSSV(arrayMSSV, 5);

    // In ra mảng MSSV đã sắp xếp
    std::cout << "\nMảng MSSV đã sắp xếp:" << std::endl;
    for(int i = 0; i < 5; ++i) {
        std::cout << "MSSV " << i+1 << ": " << arrayMSSV[i] << std::endl;
    }

    return 0;
}
