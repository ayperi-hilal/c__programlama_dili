#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>

FILE *fo, *fg;//file tipinde pointer tamýnladýk

void kayit_ekle();//1
void kayit_listeleme();//2
/*void kayit_silme();//3
void kayit_guncelle();//4
void kayit_noara();//5
void kayit_adara();//6*/

struct  ogrenci// yapý tanýmladýk
{
	int no,durum;//kayýt silme durumunundan bahsediliyor. eðer kayýt silinirse durum sýfýr olacak gibi
	char ad[10];
	char soy[10];
};

//yukarýyý kullanabilmek için yukarýfdakþ sýnýfa ait bir nesne tanýmlýyoruz ki kullanabilelim aksi halde kullanmak mümkün deðil 

struct ogrenci ogr,gec; //iki adet öðrenci nesnesi tanýmladýrk.biri kayýt  diðeride geçici bellek için

//kullanýcý ile ara iletiþim için main kýsmý önemlidir.
//kullanýcýdan istenen çalýþmalar bu kýsýmda belirtilir. veri alýþ veriþi burada yapýlýr.

int main()
{
	int secim,tus;							// kullanýcýdan istenen seçimin bulunduðu kýsým.	
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
	scanf("%d", &secim)	;//kullanýcýnýn girdiði sayýsý tutup secim deðiþkeninin içerisine atýlýr.
	
	//secime göre switch case yapýsý oluþturulur.
	switch(secim)
	{
	case 1:kayit_ekle();break;
	case 2:kayit_listeleme();break;
	/*case 3:kayýt_silme();break;
	case 4:kayýt_güncelleme();break;
	case 5:kayýt_noara();break;
	case 6:kayýt_adara();break;
	*/
		default : printf("lüften 1-6 arasi bir sayi giriniz! \n\n"); break;
	}	
	printf("cikmak için 0 giriniz menuye dönmek icin bir sayiya basiniz\n\n");
	scanf("%d",&tus);
	
				
	}
	while (tus!=0);
	return 0;
}

//string türünde dönüþ olacaðý için void tipnde bir fonksiyon tanýmlamak gerekiyor. geriye herhangi bir þey döndüðrmeyeceðiz.
void kayit_ekle()

{//dosya açma ve  açýlýp açýlmadýðýný sorgulama
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


	
	
	printf("Öðrenci Numarasý Girin: ");
	scanf("%d",&ogr.no);
	
	while(fscanf(fo,"%d %s %s %d",&gec.no,gec.ad,gec.soy,&gec.durum)!=EOF)//EOF DOSYANIN BÝTTÝÐÝNÝ ÝFADE EDER
	//fscanf okuma için açýlýr. 
	{
				if(ogr.no==gec.no&& gec.durum==1)
					
				{
					printf( "bu kayýt mevcut baþka no giriniz \n");
					fclose(fo);
					return;
				}
	}
	fclose(fo);
	fo=fopen("C:\\DOKÜMANTASYON\ogrenci.txt","r+");
	fo=fopen("C:\\DOKÜMANTASYON\gecici.txt","w+");
	printf("ogrencinin adýný en fala 10 karakter giriniz: \n");
	scanf("%s",&ogr.ad);
	printf("öðencinin soyadýný en fazla 10 kaakter  olarak giriniz: ");
	scanf("%s",&ogr.soy);
	if(strlen(ogr.ad)>=10||strlen(ogr.soy)>=10)
	{
		printf("fazla karakter girildi : \n\n");return;
	}
	
	int yazildi=0;
	while(fscanf(fo,"%d %s %s %d",&gec.no,gec.ad,gec.soy,&gec.durum)!=EOF)//EOF DOSYANIN BÝTTÝÐÝNÝ ÝFADE EDER
	//fscanf okuma için açýlýr. 
	{
				if(strcmp(ogr.ad,gec.ad)<0&&yazildi==0)	//Str1 parametresi ile gösterilen karakter dizisini str2 parametresi ile gösterilen karakter dizisi ile karþýlaþtýrýr. 
				//Eðer her iki karakter dizisindeki tüm karakterler ayný ise sýfýr deðeri, aksi takdirde sýfýrdan farklý bir deðer geri döndürür
				{
					fprintf(fg,"%d %s %s 1\n",&ogr.no,ogr.ad,ogr.soy);
					yazildi=1;
				}
	if(yazildi==0)
	{
	fprintf(fg,"%d %s %s %d\n",&gec.no,gec.ad,gec.soy,&gec.durum);
	}	
	
	printf("\n\n");
	printf("... KAYIT EKLENDÝ :)..\n\n");
	fclose(fo);
	fclose(fg);
	remove("C:\\DOKÜMANTASYON\ogrenci.txt");
	rename("C:\\DOKÜMANTASYON\gecici.txt","C:\\DOKÜMANTASYON\ogrenci.txt");	
		

	}
}
//break;
void kayit_listeleme(){
	fo=fopen("C:\DOKÜMANTASYON\ogrenci.txt","r");
	while(fscanf(fo,"%d %s %s %d",&ogr.no,ogr.ad,ogr.soy,&ogr.durum)!=EOF)//dosyanýn sonuna kadar okumasý saðlanýr.
	{
		
		if(ogr.durum!=0)//kayýt silinmemiþ ise listelemede görünsün
		{
			printf("NO:%8d AD:%8s SOYAD:%8s \n",ogr.no,ogr.ad,ogr.soy);
			
		}
	}printf("liste bos kayit eklemek icin 1 e basiniz \n");
	fclose(fo);
	
	
}











/*	case 3:kayýt_silme();break;
	case 4:kayýt_güncelleme();break;
	case 5:kayýt_noara();break;
	case 6:kayýt_adara();break;*/
































