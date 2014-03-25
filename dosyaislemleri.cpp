#include <stdio.h>
#include <conio.h>
#include <windows.h>

char menu();
void ogrenciekle();
void ogrencilerilistele();            //Kullanılacak fonksiyonlar burda tanımlanıyor
void ogrenciara();
void kayitdegistir();
void ogrencisil();

struct ogrenciler
{
	char ad[10];
	char soyad[10];                  //Kullanacağımız Struct yapısı oluşturulur
	int yazili1;
	int yazili2;
}sekizA[BUFSIZ], yedek[BUFSIZ];     //Kullanılacak Structlar oluşturulur

void main()
{
	char secim;
	char cevap = 'e';
	while (cevap == 'e' || cevap == 'E')
	{
		secim = menu();
		switch (secim)
		{
		case '1':
			ogrenciekle();
			break;
		case '2':
			ogrencilerilistele();
			break;
		case '3':
			ogrenciara();
			break;
		case '4':
			kayitdegistir();
			break;
		case '5':
			ogrencisil();
			break;
		default:
			printf("\nHatali Giris.\n");
			break;
		}
		printf("\nBaska islemle devam etmek ister misiniz? (E)vet (H)ayir\n");
		cevap = _getch();
	}
}

char menu()
{
	char secim;
	printf("\t\t..::HOSGELDINIZ::..\n\n\t\t1-Ogrenci Ekle\n\n\t\t2-Ogrencileri Listele\n\n\t\t3-Ogrenci Ara\n\n\t\t4-Kayit Degistir\n\n\t\t5-Ogrenci Sil\n");
	secim = _getch();
	return secim;
}

void ogrenciekle()
{
	int sayi;
	FILE *dosya;                                                                //dosya oluşturulur
	errno_t errorCode = fopen_s(&dosya, "E:\\sekizA.txt", "a");                 //dosya ekleme modunda açılır.
	printf("\nKac kisi ekleyeceksiniz?\n");
	scanf_s("%d", &sayi);
	for (int i = 0; i < sayi; i++)
	{
		printf("\n%d.Kayit edilecek ogrenci icin gerekli bilgileri girin:", i + 1);
		printf("\nAd:");
		fflush(stdin);
		gets_s(sekizA[i].ad);
		printf("\nSoyad:");
		fflush(stdin);
		gets_s(sekizA[i].soyad);
		printf("\n1. Yazili Notu:");
		scanf_s("%d", &sekizA[i].yazili1);
		printf("\n2. Yazili Notu:");
		scanf_s("%d", &sekizA[i].yazili2);
		fprintf(dosya, "%s\t%s\t%d\t%d\n", sekizA[i].ad, sekizA[i].soyad, sekizA[i].yazili1, sekizA[i].yazili2);
	}
	fclose(dosya);                                                               //dosya kapatılır
}

void ogrencilerilistele()
{
	int a = 0;
	FILE *dosya;                                                                 //dosya oluşturulur
	errno_t errorCode = fopen_s(&dosya, "E:\\sekizA.txt", "r");                 //dosya ekleme modunda açılır.
	while (!feof(dosya))                                                         //txt dosyasındaki kayıtlar okunur
	{
		fscanf_s(dosya, "%s\t", yedek[a].ad, 10);
		fscanf_s(dosya, "%s\t", yedek[a].soyad, 10);
		fscanf_s(dosya, "%d\t", &yedek[a].yazili1);
		fscanf_s(dosya, "%d", &yedek[a].yazili2);
		a++;
	}
	printf("Ad      Soyad   Yazili1 Yazili2\n");
	for (int i = 0; i < (a - 1); i++)
		printf("%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
	_getch();
	fclose(dosya);																 //dosya kapatılır
}

void ogrenciara()
{
	int a = 0;
	char secim;
	char aranacak[10];
	FILE *dosya;
	errno_t errorCode = fopen_s(&dosya, "E:\\sekizA.txt", "r");
	printf("Arama kriteri seciniz: \n1.Ad\n2.Soyad");
	secim = _getch();
	switch (secim)
	{
	case '1':
		printf("\nAranacak Adi Giriniz(Max 10 karakter):");
		gets_s(aranacak);
		while (!feof(dosya))                                               //txt dosyasındaki kayıtlar okunur
		{
			fscanf_s(dosya, "%s\t", yedek[a].ad, 10);
			fscanf_s(dosya, "%s\t", yedek[a].soyad, 10);
			fscanf_s(dosya, "%d\t", &yedek[a].yazili1);
			fscanf_s(dosya, "%d", &yedek[a].yazili2);
			a++;
		}
		for (int i = 0; i < (a - 1); i++)
		{
			if (strcmp(aranacak, yedek[i].ad) == 0)                      //aranan ad, txt dosyasına kayıtlı kişiler içinde aranır
			{
				printf("%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
			}
		}
		break;
	case '2':
		printf("\nAranacak Soyadi Giriniz(Max 10 karakter):");
		gets_s(aranacak);
		while (!feof(dosya))                                         //txt dosyasındaki kayıtlar okunur
		{
			fscanf_s(dosya, "%s\t", yedek[a].ad, 10);
			fscanf_s(dosya, "%s\t", yedek[a].soyad, 10);
			fscanf_s(dosya, "%d\t", &yedek[a].yazili1);
			fscanf_s(dosya, "%d", &yedek[a].yazili2);
			a++;
		}
		for (int i = 0; i < (a - 1); i++)
		{ 
			if (strcmp(aranacak, yedek[i].soyad) == 0)             //aranan soyad, txt dosyasına kayıtlı kişiler içinde aranır
			{
				printf("%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
			}
		}
		break;
	default:
		printf("/nHatali Giris");
		break;
	}
}

void kayitdegistir()
{
	int a = 0;
	char secim;
	char dad[10];
	char dsoyad[10];
	FILE *dosya;                                                                    //dosya oluşturulur
	errno_t errorCode = fopen_s(&dosya, "E:\\sekizA.txt", "r");                      //dosya okuma modunda açılır.
	printf("\nDegistirilmek istenen kayida ait AD bilgisini girin:");
	fflush(stdin);
	gets_s(dad);
	printf("\nDegistirilmek istenen kayida ait SOYAD bilgisini girin:");
	fflush(stdin);
	gets_s(dsoyad);
	while (!feof(dosya))                                              //txt dosyasındaki kayıtlar okunur
	{
		fscanf_s(dosya, "%s\t", yedek[a].ad, 10);
		fscanf_s(dosya, "%s\t", yedek[a].soyad, 10);
		fscanf_s(dosya, "%d\t", &yedek[a].yazili1);
		fscanf_s(dosya, "%d", &yedek[a].yazili2);
		a++;
	}
	for (int i = 0; i < (a - 1); i++)
	{
		if (strcmp(dad, yedek[i].ad) == 0 && strcmp(dsoyad, yedek[i].soyad) == 0)        //Değiştirilecek kayıt aranır
		{
			printf("\nDegistirilecek Kayit : %s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
			printf("\nYeni Ad:");
			fflush(stdin);
			gets_s(yedek[i].ad);
			printf("\nYeni Soyad:");
			fflush(stdin);
			gets_s(yedek[i].soyad);
			printf("\nYeni 1.Yazili Notu:");
			scanf_s("%d", &yedek[i].yazili1);
			printf("\nYeni 2.Yazili Notu:");
			scanf_s("%d", &yedek[i].yazili2);
		}
	}
	fclose(dosya);                                               //dosya kapatılır
	FILE *dosyaa;                                                //dosya oluşturulur 
	fopen_s(&dosyaa, "E:\\sekizA.txt", "w");                     //dosya yazma modunda açılır.
	for (int i = 0; i < (a - 1); i++)
	{
		fprintf(dosyaa, "%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);   //txt dosyası düzeltilmiş şekilde baştan yazılır
	}
	fclose(dosyaa);                                             //dosya kapatılır
}

void ogrencisil()
{
	int a = 0;
	int skonum;
	char secim;
	char sad[10];
	char ssoyad[10];
	FILE *dosya,*dosyaa;                                                   //dosya oluşturulur
	errno_t errorCode = fopen_s(&dosya, "E:\\sekizA.txt", "r");            //dosya okuma modunda açılır.
	printf("\nSilinmek istenen kayida ait AD bilgisini girin:");
	fflush(stdin);
	gets_s(sad);
	printf("\nSilinmek istenen kayida ait SOYAD bilgisini girin:");
	fflush(stdin);
	gets_s(ssoyad);
	while (!feof(dosya))
	{                                                                          //txt dosyasındaki kayıtlar okunur
		fscanf_s(dosya, "%s\t", yedek[a].ad, 10);
		fscanf_s(dosya, "%s\t", yedek[a].soyad, 10);
		fscanf_s(dosya, "%d\t", &yedek[a].yazili1);
		fscanf_s(dosya, "%d", &yedek[a].yazili2);
		a++;
	}
	for (int i = 0; i < (a - 1); i++)
	{
		if (strcmp(sad, yedek[i].ad) == 0 && strcmp(ssoyad, yedek[i].soyad) == 0)    //Silinecek kayıt aranır
			skonum = i;
	}
	fclose(dosya);                                                              //dosya kapatılır
	fopen_s(&dosyaa, "E:\\sekizA.txt", "w");                                   //dosya yazma modunda açılır.
	if (skonum>0)
	{
		for (int i = 0; i < skonum; i++)
			fprintf(dosyaa, "%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
	}
	else
	{
		for (int i = skonum + 1; i < a; i++)
		{
			fprintf(dosyaa, "%s\t%s\t%d\t%d\n", yedek[i].ad, yedek[i].soyad, yedek[i].yazili1, yedek[i].yazili2);
		}
	}
	fclose(dosyaa);                                                              //dosya kapatılır
}
