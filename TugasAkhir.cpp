#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
using namespace std;

int i,j,ini,itu, pos, pas;
int pin[4][100], nasabah=1, nas=0, loginpin;
long rek[4][100], saldo[4][100], loginrek;
bool sukses=false;
string nama[4][100], alamat[4][100], noHP[4][100];

void daftar();
void transaksi();
void admin();
void login();
void ceksaldo();
void tarikTunai();
void setorTunai();
void transfer();
void cetakNasabah();
void cariNasabah();
void cariRek();
void cariNama();

main()
{
	int pilih1;
	menu:
	system("cls");
	cout<<"========================="<<endl;
	cout<<"     ATM LAH INTINYA"<<endl;
	cout<<"========================="<<endl;
	cout<<endl;
	cout<<"1. Pendaftaran Nasabah \n2. Transaksi \n3. Login Admin \n4. Exit "<<endl;
	cout<<"\nPilih : "; cin>>pilih1;
	switch (pilih1) {
		case 1 :
			daftar();
			goto menu;
			break;
		case 2 :
			transaksi();
			break;
		case 3 :
			admin();
			break;
		case 4 : 
			exit(0);
			break;
		default : 
			cout<<"Salah input!"<<endl;
			system("pause");
			goto menu;
	}
}

void daftar(){
//	char pilihan;
	int pilih2, bank, konfirm[4][100];
	
	system("cls");
	cout<<"DAFTAR BANK"<<endl;
	cout<<"1. Bank Sihyuk \n2. Bank Suman \n3. Bank Hyunsuk \n4. Bank Jinyong \n5. Cancel"<<endl;
	cout<<"Pilih : "; cin>>pilih2;
	system("cls");
	switch(pilih2){
		case 1 :
			bank=0;
			rek[bank][nas]=11110000;
			break;
		case 2 :
			bank=1;
			rek[bank][nas]=22220000;
			break;
		case 3 :
			bank=2;
			rek[bank][nas]=33330000;
			break;
		case 4 :
			bank=3;
			rek[bank][nas]=44440000;
			break;
		case 5 :
			main();
			break;
		default :
			cout<<"Salah input!"<<endl;
			system("pause");
			daftar();
	}
	//cout<<"Minimal setoran awal Rp 200.000\n";
	//cout<<"Lanjutkan? (y/n)\n"; cin >> pilihan;
	
	//if (pilihan=='y' || pilihan=='Y'){
		//ini if yg pilihan tak hapus ya has, soalnya ini yg bawah jg udh ada peringatannya, gmn?
	cout<<"Pendaftaran Rekening"<<endl;
	cout<<"Masukkan Nama Anda	  : "; cin.ignore(); getline(cin, nama[bank][nas]);
	cout<<"Masukkan Alamat Anda	  : "; getline(cin, alamat[bank][nas]);
	cout<<"Masukkan No HP Anda	  : "; getline(cin, noHP[bank][nas]);
	
	saldo :
	cout<<"Masukkan Jumlah Uang Anda : Rp "; cin >> saldo[bank][nas];
	if (saldo[bank][nas] < 200000) {
		cout << "Minimal setoran awal Rp 200.000\n\n";
		goto saldo;
		}
	cout<<"Buat Pin		  : "; cin >> pin[bank][nas];
	do{
	cout<<"Konfirmasi Pin		  : "; cin >> konfirm[bank][nas];	
	} while (konfirm[bank][nas]!=pin[bank][nas]);
	
	rek[bank][nas]+=nas+1;
	cout<<"\nRekening Berhasil dibuat."<<endl;
	cout<<"\nData Nasabah Bank Gatau Namanya Apa";
	cout<<"\nNomor Rekening	: " << rek[bank][nas];
	cout<<"\nNama		: " << nama[bank][nas];
	cout<<"\nAlamat		: " << alamat[bank][nas];
	cout<<"\nNo HP Anda	: " << noHP[bank][nas];
	cout<<"\nJumlah Uang	: Rp " << saldo[bank][nas] << endl;
	system("pause");
	cout<<"\nIngat atau catat nomor rekening dan PIN Anda sebelum melanjutkan!\n";
	nasabah+=nas;
	nas++;
	system("pause");
	//} 
	//else 
	//cout << endl;
}
	
void transaksi(){
	char lagi; 
	int pilih3;
	
	login();
	
	submenu:
	system("cls");
	cout<<"TRANSAKSI"<<endl;
	cout<<"1. Cek Saldo \n2. Tarik Tunai \n3. Setor Tunai \n4. Transfer \n5. Logout"<<endl;
	cout<<"Pilih : "; cin>>pilih3;
	switch (pilih3){
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
			transfer();
			cout<<"Apakah Anda ingin melakukan transaksi lagi? (y/n) : ";
			cin>>lagi;
			if(lagi=='y'||lagi=='Y'){
				goto submenu;
			} else {
				main();
			}
			break;
		case 5 :
			main();
			break;
		default :
			cout<<"Salah input!"<<endl;
			system("pause");
			goto submenu;
	}
} 

void login() {
	
	system("cls");
	sukses=false;
	
	cout<<"Masukkan Rekening Anda	: "; cin>>loginrek;
	for(i=0; i<4; i++){
		for(j=0; j<nasabah; j++){
			if(loginrek==rek[i][j]){
				ulang:
				cout<<"Masukkan PIN		: "; cin>>loginpin;
				if(loginpin==pin[i][j]){
					ini=i;
					itu=j;
					sukses=true;
					break;
				}
				else{
					cout<<"PIN Anda salah!"<<endl<<endl;
					goto ulang;
				}
			}
		}
	} 
	if (sukses){
		cout<<"Login Berhasil"<<endl<<endl;
	} else {
		cout<<"Rekening salah atau belum terdaftar, lakukan Pendaftaran Rekening terlebih dahulu."<<endl<<endl;
		system("pause");
		main();
	}
	
	system("pause");
}

void ceksaldo(){
	system("cls");
	cout<<"Nomor Rekening	: "<<rek[ini][itu]<<endl;
	cout<<"Nama Nasabah	: "<<nama[ini][itu]<<endl;
	cout<<"Saldo Anda	: "<<saldo[ini][itu]<<endl<<endl;
	system("pause");
}

void tarikTunai(){
	long tarik; 
	system("cls");
	cout<<"Saldo Anda saat ini : Rp "<<saldo[ini][itu]<<endl;
	tarik :
	cout<<"Masukkan Nominal Penarikan : Rp "; cin>>tarik;
	if(tarik%50000==0){
		if(saldo[ini][itu]>=tarik){
			cout<<"\nPenarikan Berhasil!"<<endl;
			saldo[ini][itu]=saldo[ini][itu]-tarik;
			cout<<"\nSisa saldo Anda : Rp "<<saldo[ini][itu]<<endl;
			}
		else
		cout<<"\nMaaf saldo Anda tidak mencukupi."<<endl;
		}
	else{
	cout << "\nJumlah penarikan minimal Rp 50.000 atau kelipatannya.\n";
	goto tarik;
	}
}

void setorTunai(){
	long setor; 
	system("cls");
	cout<<"Saldo Anda saat ini		: Rp "<<saldo[ini][itu]<<endl;
	setor :
	cout<<"Masukkan Nominal Setor	: Rp "; cin>>setor;
	if(setor%50000==0){
		cout<<"\nSetoran Berhasil!"<<endl;
		saldo[ini][itu]=saldo[ini][itu]+setor;
		cout<<"\nJumlah saldo Anda : Rp "<<saldo[ini][itu]<<endl;
	}
	else{
	cout << "\nJumlah penyetoran minimal Rp 50.000 atau kelipatannya.\n";
	goto setor;
	}
}

void transfer() {
	long tujuan, trf;
	string namatf;

	system("cls");
	cout<<"\nSaldo Anda saat ini	 : Rp "<<saldo[ini][itu]<<endl<<endl;
	cout<<"Masukkan Tujuan Transfer : "; cin >> tujuan;
	sukses=false;
	for(i=0; i<4; i++){
		for(j=0; j<nasabah; j++){
			if(tujuan!=rek[ini][itu] && tujuan==rek[i][j]){
				pos=i;
				pas=j;
				sukses=true;
				break;
				}
			}
		}
		
	if (sukses){
		cout<<"Rekening atas nama	 : "<<nama[pos][pas]<<endl;
		}	
	else { //yg namatf ini mending dihapus ga si? soalnya kan kita udh punya bank bank sendiri?
		cout<<"Rekening atas nama	 : "; cin.ignore(); getline(cin, namatf);
		}
	
	cout<<"\nMasukkan Nominal Transfer: Rp "; cin >> trf;
	cout<<endl;
	
	if (trf>=10000){	
		if (trf<=saldo[ini][itu]){
			if (tujuan/10000!=rek[ini][itu]/10000){ 
				saldo[ini][itu]-=6500;
				}
			else{
				saldo[ini][itu]-=trf;
				saldo[pos][pas]+=trf;	
				cout << "Transfer berhasil!\n";
				cout << "\nSisa saldo Anda		 : Rp "<<saldo[ini][itu];
			}
		}
		else {
			cout << "Maaf, saldo anda tidak cukup.\n";
			}
	}
	else {
		cout << "Minimal transaksi Rp 10.000,-\n";
		}
	cout<<endl;
	}

void admin (){
	string username, pw;
	int pilihadmin;
	
	login :
	system("CLS");
	cout << "\nLogin Admin\n";
	cout << "Username\t: "; cin >> username;
	cout << "Password\t: "; cin >> pw;
	
	if (username == "admin" && pw == "inipassword") {
		cout << "Login berhasil!\n\n\n";
		system ("pause");
		ini = i;
		menuadm :
		system("CLS");
		cout << "Menu Admin : \n";
		cout << "1. Cetak Daftar Nasabah \n2. Cari Nasabah \n3. Logout \n";
		cout << "Pilih : "; cin >> pilihadmin;
		
		switch (pilihadmin) {
			case 1 :
				cetakNasabah();
				system ("pause");
				goto menuadm;
				break;
				
			case 2 :
				cariNasabah();
				system ("pause");
				goto menuadm;
				break;
			
			case 3 :
				main();
				break;
			default :
				cout<<"Salah input!"<<endl;
				system("pause");
				goto menuadm;
			}
		}
	else if (username == "admin") {
		cout << "Password salah!\n\n";
		system("pause");
		goto login;
		}
	else if (pw == "inipassword") {
		cout << "Username salah!\n\n";
		system("pause");
		goto login;
		}
	else {
		cout << "Username dan Password salah!\n\n";
		system("pause");
		goto login;
	}
}

void cetakNasabah() {
	cout<<endl;
    cout<<"|==========================================================================================================|\n";
    cout<<"|                  				            DAFTAR NASABAH BANK                                           |\n";
	cout<<"|====|=================|======================|=======================|==================|=================|\n";
	cout<<"| No |   No Rekening   |         Nama         |         Alamat        |     Nomor HP     |   Total Saldo   |\n";
	cout<<"|====|=================|======================|=======================|==================|=================|\n";
	for(i=0; i<4; i++) {
	  for(j=0; j<nasabah; j++) {
		cout<<setw(4)<<i+1;
		cout<<setw(15)<<rek[i][j];
		cout<<setw(24)<<nama[i][j];
		cout<<setw(26)<<alamat[i][j];
		cout<<setw(17)<<noHP[i][j];
		cout<<setw(17)<<saldo[i][j]<<endl;
        }
    }
	cout<<"|====|=================|======================|=======================|==================|=================|\n";
	}

void cariNasabah() {
	int pilih4;
	system("CLS");
	
	cout<<"Cari Nasabah Berdasarkan"<<endl;
	cout<<"1. Nomor Rekening \n2. Nama Nasabah"<<endl;
	cout<<"Pilih : "; cin>>pilih4;
	switch (pilih4){
		case 1 : 
			cariRek();
			break;
		case 2 :
			cariNama();
			break;
		default :
			cariNasabah();
	}

}

void cariRek(){
	long no;
	system("cls");
	cout<<"Masukan Nomer Rekening yang Akan Dicari : "; cin>>no;
	cout<<endl;
	for(i=0; i<4; i++){
		for(j=0; j<nasabah; j++){
			if(no==rek[i][j]){
				pos=i;
				pas=j;
				sukses=true;
				break;
			}
		else
		sukses=false;
		}
	}
	if(sukses) {
		cout<<"Nomer Rekening	: "<<rek[pos][pas]<<endl;
		cout<<"Nama Nasabah	: "<<nama[pos][pas]<<endl;
		cout<<"Alamat		: "<<alamat[pos][pas]<<endl;
		cout<<"Saldo		: Rp "<<saldo[pos][pas]<<endl<<endl;
		}
	else
		cout<<"Nomer Rekening Tidak Ditemukan"<<endl<<endl;
		
	system("pause");
}

void cariNama (){
	string fName;
	
	cout<<"Masukkan Nama Nasabah yang Akan Dicari : "; cin.ignore(); getline(cin, fName);
	cout<<endl;
	for(i=0; i<4; i++){
		for(j=0; j<nasabah; j++){
			if(fName==nama[i][j]){
				pos=i;
				pas=j;
				sukses=true;
				break;
			}
		else
		sukses=false;
		}
	}
	if(sukses) {
		cout<<"Nomer Rekening	: "<<rek[pos][pas]<<endl;
		cout<<"Nama Nasabah	: "<<nama[pos][pas]<<endl;
		cout<<"Alamat		: "<<alamat[pos][pas]<<endl;
		cout<<"Saldo		: Rp "<<saldo[pos][pas]<<endl<<endl;
		}
	else
		cout<<"Nama Tidak Ditemukan"<<endl<<endl;
		
	system("pause");
}
