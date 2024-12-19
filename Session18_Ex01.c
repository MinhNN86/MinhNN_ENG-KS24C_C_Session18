#include <stdio.h>
#include <string.h>
struct sinhVien{
    char ten[100];
    int tuoi;
    char soDienThoai[20];
};
int main(){
    struct sinhVien sinhVien1;
    strcpy(sinhVien1.ten, "Nguyen Nhat Minh");
    sinhVien1.tuoi = 18;
    strcpy(sinhVien1.soDienThoai, "1234567");
    
    printf("%s\n", sinhVien1.ten);
    printf("%d\n", sinhVien1.tuoi);
    printf("%s", sinhVien1.soDienThoai);
    return 0;
}