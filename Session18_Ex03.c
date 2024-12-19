#include <stdio.h>
#include <string.h>

struct sinhVien{
    char ten[100];
    int tuoi;
    char soDienThoai[100];
};
struct sinhVien sv[4];
int main(){
    int soSV = 5;
    for(int i = 0; i < soSV; i++){
        printf("ten sinh vien thu %d la: ", i + 1);
        fgets(sv[i].ten, sizeof(sv[i].ten), stdin);
        sv[i].ten [strlen(sv[i].ten) - 1] = '\0';
        fflush(stdin);
        printf("tuoi sinh vien thu %d la: ", i + 1);
        scanf("%d", &sv[i].tuoi);
        fflush(stdin);
        printf("sdt sinh vien thu %d la: ", i + 1);
        fgets(sv[i].soDienThoai, sizeof(sv[i].soDienThoai), stdin);
    }
    for(int i = 0; i < soSV; i++){
        printf("ten sinh vien thu %d la: %s |", i + 1, sv[i].ten);
        printf(" tuoi sinh vien thu %d la: %d |", i + 1, sv[i].tuoi);
        printf(" sdt sinh vien thu %d la: %s", i + 1, sv[i].soDienThoai);
    }
}