#include <iostream> 
#include <iomanip>
#include <string>

//#include <time.h>
#include <chrono>
using namespace std;

///*Tạo hàm nhập mảng 1 chiều trong C++*/
//void input_array(int array[], int length)
//{
//    //array: tên mảng
//    //length: độ dài mảng
//    for (int i = 0; i < length; i++)
//    {
//        cin >> array[i];
//    } 
//}
//
///*Tạo hàm xuất mảng 1 chiều trong C++*/
//void show_array(int array[], int length) {
//    //array: tên mảng
//    //length: độ dài mảng
//    for (int i = 0; i < length; i++)
//    {
//        cout << array[i] << ' ';
//    }
//    cout << endl;
//}
//
//int main() {
//    /*Nhập mảng 1 chiều trong C++*/
//    int n;
//    cout << ">>Nhap so phan tu: ";
//    cin >> n;
//
//    //int array[n - 1];
//    // Mảng trong stack không khởi tạo động theo kiểu trên, nếu muốn sử dụng mảng động thì phải cấp phát động bằng malloc với C hoặc là sử dụng new với C++.
//    int* array = new int[n-1]; //tạo mảng trong C++ phải tạo như malloc trong C
//
//    cout << ">>Nhap phan tu:\n";
//    input_array(array, n);
//
//    /*xuất mảng 1 chiều trong C++*/
//    cout << ">>Mang vua nhap:\n";
//    show_array(array, n);
//
//    return 0;
//}


int main() {
    //int* arr = new int[6];
    //mảng bắt đầu từ 0-> n-1
    //int M[] = {2, 0, 2, 1, 1, 0};
    int M[] = {2, 0, 2, 1, 1, 0, 2, 0, 1, 1, 2, 0, 2, 1, 1, 0, 2, 0, 1, 1 };
    //lấy size mảng
    //Độ dài mảng = kích thước mảng / kích thước 1 phần tử
    //size M = 24byte / 4byte(1 int) = 6 phần tử
    int length = sizeof M / sizeof(int);
    cout << length << endl;
    cout << "Mang chua sap xep la: ";
    //xuất mảng chưa sắp xếp
    for (size_t i = 0; i < length; i++) // chạy đến M[5]
    {
        cout << M[i] << ' ';
    }


    // Capture the start time
    auto start = chrono::steady_clock::now();


    /* chuyển phần tử bé hơn 1 về đầu array
    2 0 2 1 1 0
    0 2 2 1 1 0
    0 0 2 1 1 2
    */
    int pivot = 1,
        poiter_smaller = 0 /*Poiter tại phần tử đầu tiên*/,
        tg_smaller;
    for (int i = 0; i < length; i++)
    {
        if (M[i] < pivot)
        {
            tg_smaller = M[i];
            M[i] = M[poiter_smaller]; //đổi chỗ cho nhau
            M[poiter_smaller] = tg_smaller;
            poiter_smaller+=1;
        }
    }
    cout << "\nMang 1: ";
    for (size_t i = 0; i < length; i++)
    {
        cout << M[i] << ' ';
    }
    /* chuyển phần tử lớn hơn 1 về cuối array
    0 0 2 1 1 2
    0 0 2 1 1 2
    0 0 1 1 2 2
    */
    int poiter_larger = (length - 1) /*Poiter tại phần tử cuối*/,
        tg_larger;
    for (int i = (length-1) ; i >= 0; i-=1)
    {
        if (M[i] > pivot)
        {
            tg_larger = M[i];
            M[i] = M[poiter_larger];
            M[poiter_larger] = tg_larger;
            poiter_larger -= 1;
        }/*
        else if (M[i] < pivot)
        {
            break;
        }*/
    }
    // Dutch National Flag Problem
    cout << "\nMang done: ";
    for (size_t i = 0; i < length; i++)
    {
        cout << M[i] << ' ';
    }
    cout << endl;

    // Capture the end time
    auto end = chrono::steady_clock::now();
    //calculate time
    auto diff = end - start;
    cout << "\nRuntime: " << chrono::duration <double>(diff).count() << " seconds" << endl;

    system("pause");
    return 0;
}