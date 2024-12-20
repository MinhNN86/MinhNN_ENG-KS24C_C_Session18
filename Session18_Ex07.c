#include <stdio.h>
#include <string.h>
struct sinhVien{
    int id;
    char name[100];
    int age;
    char phoneNumber[100];
};
struct sinhVien sinhVien[50]= {
    {1, "Minh", 18, "0987654321"},
    {2, "Bach", 18, "0987654321"},
    {3, "Tuan", 18, "0987654321"},
    {4, "Thuong", 18, "0987654321"},
    {5, "Bang", 18, "0987654321"},
};
int main(){
    int viTriXoa, idXoa;
    int soSinhVien= 5;
    printf("nhap id sinh vien muon xoa: ");
    scanf("%d", &idXoa);
    if(idXoa <= 0 || idXoa > 5){
        printf("id khong hop le");
        return 1;
    }
    viTriXoa = idXoa - 1;
    for(int i = viTriXoa; i < soSinhVien; i++){
        sinhVien[i].id = sinhVien[i + 1].id;
        strcpy(sinhVien[i].name, sinhVien[i + 1].name);
        sinhVien[i].age = sinhVien[i + 1].age;
        strcpy(sinhVien[i].phoneNumber, sinhVien[i + 1].phoneNumber);
    }
    soSinhVien--;
    for(int i = 0; i < soSinhVien; i++){
        printf("id : %d |", sinhVien[i].id);
        printf("ten : %s |", sinhVien[i].name);
        printf(" tuoi : %d |", sinhVien[i].age);
        printf(" sdt : %s\n", sinhVien[i].phoneNumber);
    }
    return 0;
}