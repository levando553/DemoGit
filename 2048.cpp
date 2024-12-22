#include <iostream>
#include <conio.h>
#include <string>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
int score=0;
int highscore=0;
void menu(){
    cout<<"\t   _____    ______       __     _______     "<<endl;
    cout<<"\t  /  __ \\  /  __  \\     /  |   /  ___  \\ "<<endl;
    cout<<"\t  |_|  \\ | | /  \\ |    /   |   | /   \\ | "<<endl;
    cout<<"\t       | | | |  | |   / /| |   | \\___/ |   "<<endl;
    cout<<"\t      / /  | |  | |  / /_| |_   \\     /    "<<endl;
    cout<<"\t     / /   | |  | | |____   _|  / ___ \\    "<<endl;
    cout<<"\t    / /    | |  | |      | |   | /   \\ |   "<<endl;
    cout<<"\t   / /___  | |__| |      | |   | \\___/ |   "<<endl;
    cout<<"\t  |______| \\______/      |_|   \\_______/  "<<endl;

     cout <<"\n                      _*-*_MENU_*-*_\n"<< endl;
     cout <<"            1.Bat dau"<<endl;
     cout <<"            2.Huong dan"<<endl;
     cout <<"            3.Xem diem"<<endl;
     cout <<"            4.Thoat game"<<endl;
}
void huongdan(){
     cout <<"\t\t\t\tHuong dan choi"<<endl;
     cout <<"\t\t1.Su dung cac phim mui ten de di chuyen cac o"<<endl;
     cout <<"\t\t2.Hai o co cung so co the hop nhat thanh mot va hien thi tong cua chung"<<endl;
     cout <<"\t\t3.Nguoi choi tao ra o 2048 se gianh chien thang"<<endl;
     cout <<"\t\t4.Khi bang chua day so, tro choi se ket thuc"<<endl;
     cout <<"\t\t5.Nhan ESC de thoat game"<<endl;
     cout <<"\n\t\tNhan ESC de quay lai"<<endl;
    getch();
}
void showhighscore() {
    cout << "\n\t\tDiem cao nhat: " << highscore << endl;
    cout << "\n\t\tNhan ESC de quay lai" << endl;
    getch();
}
void updatehighscore(int currentscore) {
    if (currentscore > highscore) {
        highscore = currentscore;
    }
}
void moveleft(int a[5][5]) {
    for (int i = 0; i <5; i++) {
        int arr[5] = { 0 };
        int k = 0;
        for (int j = 0; j < 5; j++) {
            if (a[i][j] != 0) {
                if (arr[k] == 0) {
                    arr[k] = a[i][j];
                } else if (arr[k] == a[i][j]) {
                    arr[k++] *= 2;
                    score += arr[k - 1];
                } else {
                    arr[++k] = a[i][j];
                }
            }
        }
        for (int j = 0; j < 5; j++) {
            a[i][j] = arr[j];
        }
    }
}


void moveup(int a[5][5]) {
    for (int j = 0; j < 5; j++) {
        int arr[5] = { 0 };
        int k= 0;
        for (int i = 0; i < 5; i++) {
            if (a[i][j] != 0) {
                if (arr[k] == 0) {
                    arr[k] = a[i][j];
                } else if (arr[k] == a[i][j]) {
                    arr[k++] *= 2;
                    score += arr[k - 1];
                } else {
                    arr[++k] = a[i][j];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
           a[i][j] = arr[i];
        }
    }
}
void movedown(int a[5][5]) {
    for (int j = 0; j < 5; j++) {
        int arr[5] = { 0 };
        int k = 4;
        for (int i = 4; i >= 0; i--) {
            if (a[i][j] != 0) {
                if (arr[k] == 0) {
                    arr[k] = a[i][j];
                } else if (arr[k] == a[i][j]) {
                    arr[k--] *= 2;
                    score += arr[k + 1];
                } else {
                    arr[--k] = a[i][j];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            a[i][j] = arr[i];
        }
    }
}
void moveright(int a[5][5]) {
    for (int i = 0; i < 5; i++) {
       for (int j=0;j<3;j++){
        swap(a[i][j],a[i][4-j]);
       }
    }
    moveleft(a);
    for (int i=0;i<5;i++){
        for (int j=0;j<3;j++){
            swap(a[i][j],a[i][4-j]);
        }
    }
}
void themso(int a[5][5])
{
	int i,j;
	srand(time(0));
	while(1)
	{
		i=rand()%5;
		j=rand()%5;
		if(a[i][j]==0)
		{
			a[i][j]=pow(2,rand()%2 + 1);
			break;
		}
	}
}
void taobang(int a[5][5]){
	cout<<"\n\t\tNhan ESC de thoat game";
	cout<<"\n\n\t\tDiem hien tai: " << score;
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<5;i++){
		cout<<"\t\t\t\t--------------------------------------------------------\n\t\t\t\t";
		for(j=0;j<5;j++){
			cout << "|";
			if(a[i][j]==0) cout<<"          ";
			else{
				int x= 0, b = a[i][j];
				while(b){
					x++;
					b /= 10;
				}
                int y = 10 - x;
                int left = y / 2;
                int right = y - left;
                cout << setw(left) << "" << a[i][j] << setw(right) << "";
			}
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t--------------------------------------------------------\n";
}
bool kiemtra(int b[5][5], int a[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (b[i][j] != a[i][j]) {
                return false;
            }
        }
    }
    return true;
}
bool canmove(int a[5][5]) {
for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (a[i][j] == 0) {
                return true;
            }
            if (i < 4 && a[i + 1][j] == a[i][j]) {
                return true;
            }
            if (j < 4 && a[i][j + 1] == a[i][j]) {
                return true;
            }
        }
    }
    return false;
}
void play(){
	int i1,i2,i3,i4,i,j;
	int a[5][5]={0},tmp[5][5]={0};
	srand(time(0));
	i1=rand()%5;
	i2=rand()%5;
	while(1){
		i3=rand()%5;
		i4=rand()%5;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=4;
	taobang(a);
	int ch;
	while (1){
    	for(i=0;i<5;i++)
    		for(j=0;j<5;j++)
    			tmp[i][j]=a[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) moveup(a);
        if(ch==80) movedown(a);
        if(ch==75) moveleft(a);
        if(ch==77) moveright(a);
        if (ch==27) {
                score=0;
        break;
        }
		if(!kiemtra(tmp,a))
			themso(a);
		taobang(a);
        updatehighscore(score);
        if (a[i][j] == 2048) {
                system("cls");
                cout << "\n\n\t\t\tYOU WIN!!\n";
                cout << "\n\t\t\tDiem dat duoc: " << score << "\n\n\n";
                cout << "\n\t\t\t1. Choi lai\n";
                cout << "\n\t\t\t2. Thoat\n";
                cout << "\n\t\t\tLua chon cua ban: ";
                int luachon;
                cin >> luachon;
                if (luachon == 1) {
                    score = 0;
                    play();
                } else {
                    exit(0);
                }
            }
		if (!canmove(a)) {
            cout << "\n\n\t\t\tGAME OVER!!\n";
            cout << "\n\n\t\t\tDiem dat duoc: " << score << "\n\n\n";
            cout << "\n\t\t\t1. Choi lai";
            cout << "\n\t\t\t2. Thoat\n";
            cout << "\n\t\t\tLua chon cua ban: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                score = 0;
                play();
            } else {
                break;
            }
        }
	}
}
int main (){
	int luachon;
	while (luachon<4){
	system("cls");
	menu();
		cout <<"\n\t\t\t\tVui long dua ra lua chon: ";
		cin >> luachon;
		switch (luachon){
			case 1:
				system("cls");
				play();
				break;
			case 2:
				system("cls");
				huongdan() ;
				break;
            case 3:
                system("cls");
                showhighscore();
                break;
            case 4:
				cout << "\n\t\t\t\tThoat khoi game. Hen gap lai!" << endl;
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai." << endl;
                break;
        }
	}
	return 0;
}

