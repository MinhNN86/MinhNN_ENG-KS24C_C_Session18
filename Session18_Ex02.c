#include <stdio.h>
#include <string.h>

struct sinhVien{
    char ten[100];
    int tuoi;
    char soDienThoai[100];
};
struct sinhVien sv1;
int main(){
    printf("nhap ten cua ban: ");
    fgets(sv1.ten, sizeof(sv1.ten), stdin);
    sv1.ten [strlen(sv1.ten) - 1] = '\0';
    printf("nhap vao so dien thoai ban: ");
    fgets(sv1.soDienThoai, sizeof(sv1.soDienThoai), stdin);
    fflush(stdin);
    printf("nhap tuoi ban: ");
    scanf("%d", &sv1.tuoi);
    
    printf("ten: %s\n", sv1.ten);
    printf("tuoi: %d\n", sv1.tuoi);
    printf("sdt: %s\n", sv1.soDienThoai);
}