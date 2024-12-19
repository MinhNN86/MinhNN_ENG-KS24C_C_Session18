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
    int timID;
    int soSinhVienCoDuLieu = 5;
    printf("nhap id sinh vien can tim: ");
    scanf("%d", &timID); fflush(stdin);
    if(timID < 1 || timID > soSinhVienCoDuLieu){
        printf("id khong ton tai");
        return 1;
    }
    char tenMoi[100];
    printf("sua ten cua sinh vien id %d la: ", timID);
    fgets(tenMoi, sizeof(tenMoi), stdin); fflush(stdin);
    tenMoi[strlen(tenMoi) - 1]= '\0';
    strcpy(sinhVien[timID - 1].name, tenMoi);
    printf("sua tuoi cua sinh vien id %d la: ", timID);
    scanf("%d", &sinhVien[timID - 1].age);
    printf("Danh sach sinh vien sau khi sua:\n");
    for(int i = 0; i < soSinhVienCoDuLieu; i++){
        printf("id : %d |", sinhVien[i].id);
        printf("ten : %s |", sinhVien[i].name);
        printf(" tuoi : %d |", sinhVien[i].age);
        printf(" sdt : %s\n", sinhVien[i].phoneNumber);
    }
    return 0;
}