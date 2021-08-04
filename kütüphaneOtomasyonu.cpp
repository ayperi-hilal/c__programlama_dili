#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

FILE *fo, *fg;//file tipinde pointer tam�nlad�k

void kayit_ekle();//1
void kayit_listeleme();//2
/*void kayit_silme();//3
void kayit_guncelle();//4
void kayit_noara();//5
void kayit_adara();//6*/

struct  ogrenci// yap� tan�mlad�k
{
	int no,durum;//kay�t silme durumunundan bahsediliyor. e�er kay�t silinirse durum s�f�r olacak gibi
	char ad[10];
	char soy[10];
};

//yukar�y� kullanabilmek i�in yukar�fdak� s�n�fa ait bir nesne tan�ml�yoruz ki kullanabilelim aksi halde kullanmak m�mk�n de�il 

struct ogrenci ogr,gec; //iki adet ��renci nesnesi tan�mlad�rk.biri kay�t  di�eride ge�ici bellek i�in

//kullan�c� ile ara ileti�im i�in main k�sm� �nemlidir.
//kullan�c�dan istenen �al��malar bu k�s�mda belirtilir. veri al�� veri�i burada yap�l�r.

int main()
{
	int secim,tus;							// kullan�c�dan istenen se�imin bulundu�u k�s�m.	
	do
	{
	
	printf ("MENU");
	printf("\n\n\n");
	printf("[1]-Kayit Ekle\n");
	printf("[2]-Kayit Listeleme\n");
	printf("[3]-Kayit Silme\n");
	printf("[4]-Kayit Guncelleme\n");	
	printf("[5]-Kayit Numara Arama\n");
	printf("[6]-Kayit Isim Arama\n");
	printf("\n");
	printf("Yapmak Istediginiz Islemi Seciniz:   ");	
	scanf("%d", &secim)	;//kullan�c�n�n girdi�i say�s� tutup secim de�i�keninin i�erisine at�l�r.
	
	//secime g�re switch case yap�s� olu�turulur.
	switch(secim)
	{
	case 1:kayit_ekle();break;
	case 2:kayit_listeleme();break;
	/*case 3:kay�t_silme();break;
	case 4:kay�t_g�ncelleme();break;
	case 5:kay�t_noara();break;
	case 6:kay�t_adara();break;
	*/
		default : printf("l�ften 1-6 arasi bir sayi giriniz! \n\n"); break;
	}	
	printf("cikmak i�in 0 giriniz menuye d�nmek icin bir sayiya basiniz\n\n");
	scanf("%d",&tus);
	
				
	}
	while (tus!=0);
	return 0;
}

//string t�r�nde d�n�� olaca�� i�in void tipnde bir fonksiyon tan�mlamak gerekiyor. geriye herhangi bir �ey d�nd��rmeyece�iz.
void kayit_ekle()

{//dosya a�ma ve  a��l�p a��lmad���n� sorgulama
	int no;
	FILE *fo;
	fo=fopen("dosya.txt","w");
	
	if ((fo=fopen("dosya.txt","w"))==NULL)
	{
		printf("dosya acma hatasi");
	//exit(1);
	}
	else
	{
		printf("Islem yapmak uzere dosya acildi...");
		
	}
	
//	return 0;


	
	
	printf("��renci Numaras� Girin: ");
	scanf("%d",&ogr.no);
	
	while(fscanf(fo,"%d %s %s %d",&gec.no,gec.ad,gec.soy,&gec.durum)!=EOF)//EOF DOSYANIN B�TT���N� �FADE EDER
	//fscanf okuma i�in a��l�r. 
	{
				if(ogr.no==gec.no&& gec.durum==1)
					
				{
					printf( "bu kay�t mevcut ba�ka no giriniz \n");
					fclose(fo);
					return;
				}
	}
	fclose(fo);
	fo=fopen("C:\\DOK�MANTASYON\ogrenci.txt","r+");
	fo=fopen("C:\\DOK�MANTASYON\gecici.txt","w+");
	printf("ogrencinin ad�n� en fala 10 karakter giriniz: \n");
	scanf("%s",&ogr.ad);
	printf("��encinin soyad�n� en fazla 10 kaakter  olarak giriniz: ");
	scanf("%s",&ogr.soy);
	if(strlen(ogr.ad)>=10||strlen(ogr.soy)>=10)
	{
		printf("fazla karakter girildi : \n\n");return;
	}
	
	int yazildi=0;
	while(fscanf(fo,"%d %s %s %d",&gec.no,gec.ad,gec.soy,&gec.durum)!=EOF)//EOF DOSYANIN B�TT���N� �FADE EDER
	//fscanf okuma i�in a��l�r. 
	{
				if(strcmp(ogr.ad,gec.ad)<0&&yazildi==0)	//Str1 parametresi ile g�sterilen karakter dizisini str2 parametresi ile g�sterilen karakter dizisi ile kar��la�t�r�r. 
				//E�er her iki karakter dizisindeki t�m karakterler ayn� ise s�f�r de�eri, aksi takdirde s�f�rdan farkl� bir de�er geri d�nd�r�r
				{
					fprintf(fg,"%d %s %s 1\n",&ogr.no,ogr.ad,ogr.soy);
					yazildi=1;
				}
	if(yazildi==0)
	{
	fprintf(fg,"%d %s %s %d\n",&gec.no,gec.ad,gec.soy,&gec.durum);
	}	
	
	printf("\n\n");
	printf("... KAYIT EKLEND� :)..\n\n");
	fclose(fo);
	fclose(fg);
	remove("C:\\DOK�MANTASYON\ogrenci.txt");
	rename("C:\\DOK�MANTASYON\gecici.txt","C:\\DOK�MANTASYON\ogrenci.txt");	
		

	}
}
//break;
void kayit_listeleme(){
	fo=fopen("C:\DOK�MANTASYON\ogrenci.txt","r");
	while(fscanf(fo,"%d %s %s %d",&ogr.no,ogr.ad,ogr.soy,&ogr.durum)!=EOF)//dosyan�n sonuna kadar okumas� sa�lan�r.
	{
		
		if(ogr.durum!=0)//kay�t silinmemi� ise listelemede g�r�ns�n
		{
			printf("NO:%8d AD:%8s SOYAD:%8s \n",ogr.no,ogr.ad,ogr.soy);
			
		}
	}printf("liste bos kayit eklemek icin 1 e basiniz \n");
	fclose(fo);
	
	
}











/*	case 3:kay�t_silme();break;
	case 4:kay�t_g�ncelleme();break;
	case 5:kay�t_noara();break;
	case 6:kay�t_adara();break;*/
































