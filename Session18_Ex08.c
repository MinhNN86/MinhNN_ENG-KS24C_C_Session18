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
    int viTriThem;
    int soSinhVien= 5;
    printf("nhap vi tri them sinh vien : ");
    scanf("%d", &viTriThem); fflush(stdin);
    if(viTriThem < 0 || viTriThem > 5){
        printf("vi tri them khong hop le");
        return 1;
    }
    for(int i = soSinhVien; i > viTriThem; i--){
        sinhVien[i].id = sinhVien[i - 1].id;
        sinhVien[i].id++;
        strcpy(sinhVien[i].name, sinhVien[i - 1].name);
        sinhVien[i].age = sinhVien[i - 1].age;
        strcpy(sinhVien[i].phoneNumber, sinhVien[i - 1].phoneNumber);
    }
    soSinhVien++;
    sinhVien[viTriThem].id = viTriThem + 1;
    printf("nhap ten sinh vien moi: ");
    fgets(sinhVien[viTriThem].name, sizeof(sinhVien[viTriThem].name), stdin); fflush(stdin);
    sinhVien[viTriThem].name[strlen(sinhVien[viTriThem].name) - 1] = '\0';
    printf("nhap tuoi sinh vien moi: ");
    scanf("%d", &sinhVien[viTriThem].age); fflush(stdin);
    printf("nhap so dien thoai sinh vien moi: ");
    fgets(sinhVien[viTriThem].phoneNumber, sizeof(sinhVien[viTriThem].phoneNumber), stdin); fflush(stdin);
    sinhVien[viTriThem].phoneNumber[strlen(sinhVien[viTriThem].phoneNumber) - 1] = '\0';
    
    for(int i = 0; i < soSinhVien; i++){
        printf("id : %d |", sinhVien[i].id);
        printf("ten : %s |", sinhVien[i].name);
        printf(" tuoi : %d |", sinhVien[i].age);
        printf(" sdt : %s\n", sinhVien[i].phoneNumber);
    }
    return 0;
}