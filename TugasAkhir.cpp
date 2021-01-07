#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int pilih1, pilih2,i,ini;
int pin[100], nasabah=1, nas=0, loginpin;
long rek[100], saldo[100], loginrek, tarik, setor;
bool sukses=false;
char lagi;
string nama[100];

void daftar();
void transaksi();
void login();
void ceksaldo();
void tarikTunai();
void setorTunai();

main()
{
	menu:
	system("cls");
	cout<<"========================="<<endl;
	cout<<"     ATM LAH INTINYA"<<endl;
	cout<<"========================="<<endl;
	cout<<endl;
	cout<<"1. Pendaftaran Nasabah \n2. Transaksi \n3. Exit "<<endl;
	cout<<"Pilih : "; cin>>pilih1;
	switch (pilih1) {
		case 1 :
			daftar();
			system("cls");
			goto menu;
			break;
		case 2 :
			transaksi();
			break;
		case 3 : 
			exit(0);
			break;
		default : 
			cout<<"Salah input!"<<endl;
			goto menu;
	}
}

void daftar(){
	ulang:
	bool ada=false;
	
	system("cls");
	cout<<"Pendaftaran Rekening"<<endl;
	cout<<"Masukkan Nomor Rekening   : "; cin>>rek[nas];
	cout<<"Masukkan Nama Anda        : "; cin.ignore(); getline(cin, nama[nas]);
	cout<<"Buat Pin		: "; cin>>pin[nas];
	cout<<"Masukkan Jumlah Uang Anda : "; cin>>saldo[nas];
	cout<<endl;
	if(nas>=1){
		for(i=0; i<nasabah; i++){
			if(rek[nas]==rek[i]){
				ada=true;
			}	
		}	
		if(ada){
			cout<<"Nomor Rekening tersebut telah terdaftar, coba lagi."<<endl;
			system("pause");
			goto ulang;
		}else{
			cout<<"\nRekening Berhasil dibuat"<<endl;
		}
	}
	nasabah+=nas;
	nas++;
	system("pause");
	
	}
	
void transaksi(){
	login();
	
	submenu:
	system("cls");
	cout<<"TRANSAKSI"<<endl;
	cout<<"1. Cek Saldo \n2. Tarik Tunai \n3. Setor Tunai \n4. Logout"<<endl;
	cout<<"Pilih : "; cin>>pilih2;
	switch (pilih2){
		case 1 :
			ceksaldo();
			goto submenu;
			break;
		case 2	:
			tarikTunai();
			cout<<"\nApakah Anda ingin melakukan transaksi lagi? (y/n) : ";
			cin>>lagi;
			if(lagi=='y'||lagi=='Y'){
				goto submenu;
			} else {
				main();
			}
			break;
		case 3 :
			setorTunai();
			cout<<"Apakah Anda ingin melakukan transaksi lagi? (y/n) : ";
			cin>>lagi;
			if(lagi=='y'||lagi=='Y'){
				goto submenu;
			} else {
				main();
			}
			break;
		case 4 :
			main();
			break;
		default :
			cout<<"Salah Input!"<<endl;
	}
} 

void login() {
	system("cls");
	do{
	cout<<"Masukkan Rekening Anda : "; cin>>loginrek;
	cout<<"Masukkan PIN			  : "; cin>>loginpin;
	for(i=0; i<nasabah; i++){
		if(loginrek==rek[i]){
			if(loginpin==pin[i]){
				ini=i;
				sukses=true;
				cout<<"Login Berhasil"<<endl<<endl;
				break;
			} else{
				cout<<"PIN Anda salah!"<<endl<<endl;
			}
		}else if (loginrek!=rek[i]){
			if(loginpin==pin[i]){
				cout<<"Rekening Anda salah"<<endl<<endl;
			} else {
				cout<<"Anda belum terdaftar, lakukan Pendaftaran Rekening terlebih dahulu"<<endl;
				system("pause");
				main();
			}
		}
	}
	} while (loginrek!=rek[i] || loginpin!=pin[i]);
	system("pause");
}

void ceksaldo(){
	cout<<"Nomor Rekening	: "<<rek[ini]<<endl;
	cout<<"Nama Nasabah		: "<<nama[ini]<<endl;
	cout<<"Saldo Anda		: "<<saldo[ini]<<endl<<endl;
	system("pause");
}

void tarikTunai(){
	cout<<"Saldo Anda saat ini : Rp"<<saldo[ini]<<endl;
	cout<<"Masukkan Nominal Penarikan : Rp"; cin>>tarik;
	if(saldo[ini]>=tarik){
		cout<<"\nPenarikan Berhasil!"<<endl;
		saldo[ini]=saldo[ini]-tarik;
		cout<<"Sisa saldo Anda : Rp"<<saldo[ini]<<endl;
	}else{
		cout<<"Maaf saldo Anda tidak mencukupi"<<endl;
	}
}

void setorTunai(){
	cout<<"Saldo Anda saat ini : Rp"<<saldo[ini]<<endl;
	cout<<"Masukkan Nominal Penarikan : Rp"; cin>>setor;
	cout<<"\nSetoran Berhasil!"<<endl;
	saldo[ini]=saldo[ini]+setor;
	cout<<"Jumlah saldo Anda : Rp"<<saldo[ini]<<endl;
}
















