/*
________________________________________________________________________
							PROJECT UAS
========================================================================
==========       PROGRAM DATABASE PENJUALAN KERIPIK         ============
========================================================================

    *Create and modified By :
    	Name :
    		- Saifullah
			- Nirma
			- Rahmah
			- Nunum
			- Aldi


	Menggunakan : - Array
				  - Pointer
				  - Struct
				  - Searching
________________________________________________________________________

*/



//LIBRARY ATAU HEADER
#include <iostream> //library default untuk menggunakan string, int, cout
#include <cstring> //library digunakan untuk fungsi strcmp untuk membandingkan string dengan string yang lainnya
//#include <cstdlib>
#include <conio.h> //library untuk getch() = inputan keyboard


using namespace std;



int main(){
	
	char lanjut, pilihan;//VARIABLE INI DIGUNAKAN UNTUK MELANJUTKAN DAN MEMILIH PILIHAN DI MENU
	
	//function untuk membuat File
	FILE *fp, *ft; //POINTER  INI DIGUNAKAN UNTUK MEMASUKAN DATA KEDALAM FILE DENGAN FORMAT .TXT
	

	//STRUCT DAN ARRAY
	struct data_keripik{
	    char nama_produk[50], rasa_produk[50];
	    int id_produk;
	};

	struct data_keripik k; //MEMBUAT STRUCT data_keripik menjadi variabel 'k'
	char dnama_produk[50];
	long int datasize; //digunakan tipe data long int untuk menyimpan data dalam jumlah yang banyak

	
	//function atau perulangan untuk membuat file berformat .txt
	fp=fopen("data_keripik","rb+");

	if (fp == NULL){
    	fp = fopen("data_keripik.txt","wb+");
    	if (fp==NULL){
        cout << "Cannot open file";
        return 0;
    	}
	}
	
	datasize = sizeof(k); //mengalokasikan atau menyimpan inputan data kedalam memori
    

    while(1)//PERULANGAN WHILE
    {
        //TAMPILAN MENU
		system("cls");
		cout << "\t==================================================\n" ;
        cout << "\t====== PROGRAM DATABASE PENJUALAN KERIPIK  =======\n" ;
        cout << "\t==================================================\n" ;
        cout << "\n\n";
        cout << "\n \t\t 1. Menambahkan Data";
        cout << "\n \t\t 2. Menampilkan Data";
        cout << "\n \t\t 3. Mengedit Data";
        cout << "\n \t\t 4. Menghapus Data";
        cout << "\n \t\t 5. Keluar Dari Program";
        cout << "\n\n";
        cout << "\t\t Ketik Pilihan :=> ";
        //=======================================================================
        
        pilihan = getche(); //digunakannya perintah getche() disini untuk menginput inputan keyboard pilihan secara langsung tidak perlu menekan tombol "ENTER" lagi.
        switch(pilihan) { //PERULANGAN SWITCH CASE UNTUK MEMILIH PILIHAN MENU
        	
        //MENGINPUT ATAU MENAMBAHKAN DATA
        case '1' :
            fseek(fp,0,SEEK_END); //SEEK_END POSISI POINTER DIAKHIR FILE
            lanjut ='Y';
            while(lanjut == 'Y' || lanjut == 'y')
            {
                system("cls");
                cout << "\t==================================================\n" ;
        		cout << "\t====== PROGRAM DATABASE PENJUALAN KERIPIK  =======\n" ;
        		cout << "\t==================================================\n" ;
        		cout << "\n\n";
                cout << "\t\t Nama Produk/Merek  \t: ";
                cin >> k.nama_produk;
                cout << "\t\t Rasa/ Jenis Produk \t: ";
                cin >> k.rasa_produk;
                cout << "\t\t Id Produk  \t\t: ";
                cin >> k.id_produk;
                fwrite(&k,datasize,1,fp);
                cout << "\n \t Mau Menambahkan Data lagi ? (Y/N) ";
                fflush(stdin); //fflush(stdin) digunakan uuntuk membersihkan stream atau buffer inputan sebelumnya pada memori.
                lanjut = getchar();
            }
            break;
            
        //MENAMPILKAN LIST DATA YANG SUDAH DI INPUT
        case '2':
            system("cls");
            rewind(fp);
            cout << "\t==================================================\n" ;
        	cout << "\t====== PROGRAM DATABASE PENJUALAN KERIPIK  =======\n" ;
        	cout << "\t==================================================\n" ;
        	cout << "\n\n";
        	cout << "\n\n";
            cout << "\t List Data yang sudah di input \n";
            cout << "\t __________________________________";
            cout << "\n";
            while (fread(&k,datasize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\t Nama Produk/Merek \t: "<< k.nama_produk << "\n";
				cout <<"\t Rasa/Jenis Produk \t: " << k.rasa_produk << "\n";
                cout <<"\t Id Produk \t\t: " << k.id_produk << "\n";
                cout << "\t ----------------------------------";
            }
            
            cout << "\n\n";
            system("pause");
            break;


		//MENGEDIT ATAU MERUBAH DATA 
		//MENGGUNAKAN METODE PENGGUNAAN SEARCHING 
        case '3' :
            
            lanjut= 'Y';
            while (lanjut == 'Y'|| lanjut == 'y')
            {
            	system("cls");
            	cout << "\t==================================================\n" ;
        		cout << "\t====== PROGRAM DATABASE PENJUALAN KERIPIK  =======\n" ;
        		cout << "\t==================================================\n" ;
        		cout << "\n\n";
                cout << "\n\t Masukan nama Produk/Merek yang mau di edit : ";
                cin >> dnama_produk;

                rewind(fp);
                while (fread(&k,datasize,1,fp) == 1) //PERULANGAN WHWILE UNTUK MENEMUKAN DATA 
                {
                    if (strcmp(k.nama_produk, dnama_produk) == 0) //PERULANGAN IF UNTUK MEMBANDINGKAN VARIABLE NAMA_PRODUK SEBELUMNYA DENGAN VARIABLE NAMA_PRODUK YG BARU
                    {
                    	cout << "\n\t Masukan Produk Baru \n";
                        cout << "\t Nama Produk/Merek : ";
                        cin >> k.nama_produk;
                        cout << "\t Rasa/Jenis Produk : ";
                        cin >> k.rasa_produk;
                        cout << "\t Id Produk    : ";
                        cin >> k.id_produk;
                        fseek(fp, - datasize, SEEK_CUR); //SEEK_CUR POSISI POINTER SAAT INI
                        fwrite(&k,datasize,1,fp);
                        break;
                    }
                    else
                        cout<<"Data tidak ditemukan";
                }
                cout << "\n \t Mau mengedit data lagi ? (Y/N) ";
                fflush(stdin); //fflush(stdin) digunakan uuntuk membersihkan stream atau buffer inputan sebelumnya pada memori.
                lanjut = getchar();
            }
            break;

		//MENDELETE ATAU MENGHAPUS DATA
		//MENGGUNAKAN METODE PENGGUNAAN SEARCHING 
        case '4':
            
            lanjut = 'Y';
            while (lanjut == 'Y'|| lanjut == 'y')
            {
            	system("cls");
            	cout << "\t==================================================\n" ;
        		cout << "\t====== PROGRAM DATABASE PENJUALAN KERIPIK  =======\n" ;
        		cout << "\t==================================================\n" ;
        		cout << "\n\n";
                cout << "\n\t Masukan Nama produk/Merek yang mau di delete : ";
                cin >> dnama_produk;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&k, datasize, 1, fp) == 1)

                    if (strcmp(k.nama_produk, dnama_produk) != 0)
                    {
                        fwrite(&k,datasize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("data_keripik.txt");
                rename("temp.dat","data_keripik.txt");

                fp=fopen("data_keripik.txt","rb+");

                cout << "\n\t Mau mendelete data lagi ? (Y/N) ";
                fflush(stdin); //fflush(stdin) digunakan uuntuk membersihkan stream atau buffer inputan sebelumnya pada memori.
                lanjut = getchar();
            }

            break;
		
		//UNTUK PILIHAN EXIT PROGRAM 
        case '5':
            fclose(fp);
            system ("cls");
            cout << "\n\n";
            cout << "\t\t     PROGRAM SELESAI";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    return 0;
}
