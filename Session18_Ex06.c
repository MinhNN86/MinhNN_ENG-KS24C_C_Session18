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
    int idThem = 6;
    sinhVien[idThem - 1].id = idThem;
    printf("ten sinh vien muon them: ");
    fgets(sinhVien[idThem - 1].name, sizeof(sinhVien[idThem - 1].name), stdin); fflush(stdin);
    sinhVien[idThem - 1].name[strlen(sinhVien[idThem - 1].name) - 1]= '\0';
    printf("tuoi sinh vien muon them: ");
    scanf("%d", &sinhVien[idThem - 1].age); fflush(stdin);
    printf("so dien thoai sinh vien muon them: ");
    fgets(sinhVien[idThem - 1].phoneNumber, sizeof(sinhVien[idThem - 1].phoneNumber), stdin);
    sinhVien[idThem - 1].phoneNumber[strlen(sinhVien[idThem - 1].phoneNumber) - 1]= '\0';
    printf("Danh sach sinh vien sau khi sua:\n");
    for(int i = 0; i < idThem; i++){
        printf("id : %d |", sinhVien[i].id);
        printf("ten : %s |", sinhVien[i].name);
        printf(" tuoi : %d |", sinhVien[i].age);
        printf(" sdt : %s\n", sinhVien[i].phoneNumber);
    }
    return 0;
}