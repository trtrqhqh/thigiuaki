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

// Hàm tìm phần tử chứa MSSV lớn nhất
char* timMSSVLonNhat(char mangMSSV[][11], int kichThuoc) {
    char* maxMSSV = mangMSSV[0];

    for (int i = 1; i < kichThuoc; ++i) {
        if (!soSanhMSSV(maxMSSV, mangMSSV[i])) {
            maxMSSV = mangMSSV[i];
        }
    }

    return maxMSSV;
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
    char* maxMSSV = timMSSVLonNhat(arrayMSSV, 5);

    // Tìm địa chỉ của phần tử chứa MSSV lớn nhất
    char* ptrMaxMSSV = maxMSSV;
    std::cout << "\nĐịa chỉ của phần tử chứa MSSV lớn nhất \"2305CT3999\": " << (void*)ptrMaxMSSV << std::endl;
    std::cout << "MSSV lớn nhất: " << maxMSSV << std::endl;

    return 0;
}
