#include <stdio.h>
#include <string.h>

struct Dish{
    int id;
    char name[100];
    float price;
};

int main(){
    struct Dish Menu[100]= {
        {1, "thit lon", 30},
        {2, "thit bo", 50},
        {3, "thit ga", 20},
        {4, "pho", 35},
        {5, "com", 10},
    };
    int luaChon;
    int soMonAn = 5;
    while (1){
        printf("\n1. In ra gia tri cac mon an trong menu\n");
        printf("2. Them phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phat tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu\n");
        printf("6. Tim kiem phan tu theo name nhap vao\n");
        printf("7. Thoat\n");
        printf("Lua chon: ");
        scanf("%d", &luaChon); fflush(stdin);
        switch(luaChon){
            case 1: //In ra gia tri cac mon an trong menu
                for(int i = 0; i < soMonAn; i++){
                    printf("id %d | Mon an: %s | Gia: %.3f\n", Menu[i].id, Menu[i].name, Menu[i].price);
                }
                break;
            case 2:{ //Them phan tu vao vi tri chi dinh
                int viTriThem;
                printf("nhap vi tri ban muon them: ");
                scanf("%d", &viTriThem); 
                fflush(stdin);
                if(viTriThem < 0 || viTriThem > 5){
                    printf("vi tri them khong hop le");
                    break;
                }
                for(int i = soMonAn; i > viTriThem; i--){
                    Menu[i].id = Menu[i - 1].id;
                    strcpy(Menu[i].name, Menu[i - 1].name);
                    Menu[i].price = Menu[i - 1].price;
                }
                soMonAn++;
                Menu[viTriThem].id = soMonAn;
                printf("nhap ten mon an moi: ");
                fgets(Menu[viTriThem].name, sizeof(Menu[viTriThem].name), stdin);
				fflush(stdin);
                Menu[viTriThem].name[strlen(Menu[viTriThem].name) - 1] = '\0';
                printf("nhap gia mon an moi: ");
                scanf("%f", &Menu[viTriThem].price);
                printf("da cap nhat mon an vao menu");
                break;
        	}
            case 3:{ //Sua mot phan tu o vi tri chi dinh
                int vtriSua;
                printf("nhap vi tri can sua trong menu: ");
                scanf("%d", &vtriSua);
                fflush(stdin);
                if(vtriSua < 0 || vtriSua >= 5){
                    printf("vi tri sua khong hop le");
                    break;
                }
                printf("nhap lai ten mon an can sua: ");
                fgets(Menu[vtriSua].name, sizeof(Menu[vtriSua].name), stdin);
                fflush (stdin);
                Menu[vtriSua].name[strlen(Menu[vtriSua].name) - 1] = '\0';
                printf("nhap lai gia mon an moi: ");
                scanf("%f", Menu[vtriSua].price);
                printf("da cap nhat mon an trong menu");
                break;
            }
            case 4:{ //Xoa mot phat tu o vi tri chi dinh
                int vtriXoa;
                printf("nhap vi tri muon xoa menu: ");
                scanf("%d", &vtriXoa);
                if(vtriXoa < 0 || vtriXoa >= 5){
                    printf("vi tri them khong hop le");
                    break;
                }
                for(int i = vtriXoa; i < soMonAn; i++){
                    Menu[i].id = Menu[i + 1].id;
                    strcpy(Menu[i].name, Menu[i + 1].name);
                    Menu[i].price = Menu[i + 1].price;
                }
                soMonAn--;
                printf("da xoa mon an trong menu");
                break;
            }
            case 5:{ //Sap xep cac phan tu
                int luaChonSapXep;
                printf("1. Giam dan theo price\n");
                printf("2. Tang dan theo price\n");
                printf("lua chon: ");
                scanf("%d", &luaChonSapXep);
                switch(luaChonSapXep){
                    case 1: //Giam dan theo price
                        for(int i = 0; i < soMonAn - 1; i++){
                            for(int j = 0; j < soMonAn - i - 1; j++){
                                if(Menu[j].price < Menu[j + 1].price){
                                    int tempID = Menu[j].id;
                                    Menu[j].id = Menu[j + 1].id;
                                    Menu[j + 1].id = tempID;

                                    char tempTen[100];
                                    strcpy(tempTen, Menu[j].name);
                                    strcpy(Menu[j].name, Menu[j + 1].name);
                                    strcpy(Menu[j + 1].name, tempTen);

                                    float tempPrice = Menu[j].price;
                                    Menu[j].price = Menu[j + 1].price;
                                    Menu[j + 1].price = tempPrice;
                                }
                            }
                        }
                        break;
                    case 2: //Tang dan theo price
                        for(int i = 0; i < soMonAn - 1; i++){
                            for(int j = 0; j < soMonAn - i - 1; j++){
                                if(Menu[j].price > Menu[j + 1].price){
                                    int tempID = Menu[j].id;
                                    Menu[j].id = Menu[j + 1].id;
                                    Menu[j + 1].id = tempID;
                                    
                                    char tempTen[100];
                                    strcpy(tempTen, Menu[j].name);
                                    strcpy(Menu[j].name, Menu[j + 1].name);
                                    strcpy(Menu[j + 1].name, tempTen);

                                    float tempPrice = Menu[j].price;
                                    Menu[j].price = Menu[j + 1].price;
                                    Menu[j + 1].price = tempPrice;
                                }
                            }
                        }
                        break;
                }

                printf("da sap xep lai menu");
                break;
            }
            case 6:{  //Tim kiem phan tu theo name nhap vao
                char timKiemName[100];
                int checkTimKiem = 0;
                printf("nhap mon an de tim kiem: ");
                fflush(stdin);
                fgets(timKiemName, sizeof(timKiemName), stdin);
                timKiemName[strlen(timKiemName) - 1] = '\0';
                for(int i = 0; i < soMonAn; i++){
                    if((strcmp(Menu[i].name, timKiemName)) == 0){
                        printf("Mon nay la mon id %d", i + 1);
                        checkTimKiem = 1;
                    }
                }
                if(!checkTimKiem){
                    printf("khong tim thay trong menu");
                }
                break;
            }
            case 7: //Thoat
                return 0;
                break;
            default:
                printf("lua chon khong hop le");
        }
    }
}