#include<stdio.h>
#include<conio.h>

//Foksiyon Prototipleri
void giris();                          // void değer döndürmeyen fonksiyondur.
int ParaCek(int y, int x);             // "int" ParaCek, "int" türünde veri döndüren fonksiyon. 
int ParaYatir(int y, int x);           // int ParaYatir("int" y, "int" x), fonksiyona gönderilern verinin türünü belirtir.

void main()
{
	char cevap,secim;
	int cekilen, yatirilan;
	int hesap = 5000;
	cevap = 'e';
	while (cevap == 'e' || cevap == 'E')
	{
		giris();
		secim = _getch();
		if (secim == '1')
		{
			printf("\nHesabiniza Yatirmak Istediginiz Para Miktarini Giriniz(Rakamla):  ");
			scanf_s("%d", &yatirilan);
			int a = ParaYatir(hesap, yatirilan);
			printf("Hesaptaki yeni bakiyeniz: %d", ParaYatir(hesap, yatirilan));
			hesap = a;
		}
		else if (secim == '2')
		{
			printf("\nHesabinizda Cekmek Istediginiz Para Miktarini Giriniz(Rakamla):  ");
			scanf_s("%d", &cekilen);
			int a = ParaCek(hesap, cekilen);
			printf("Hesaptaki yeni bakiyeniz: %d", ParaCek(hesap, cekilen));
			hesap = a;
		}
		else
			printf("\nHatali giris yaptiniz.\n");
		printf("\nTekrar islem yapmak istiyor musunuz?\n\n");
		cevap = _getch();
	}
}

void giris()
{
	printf("BANKA SISTEMINE HOSGELDINIZ!\nLutfen Yapmak Icin Bir Islem Seciniz.\n1.Para Yatirma\n2.Para Cekme");
}

int ParaCek(int y, int x)            // bu fonksiyon parametreleri icin y=hesap, x=cekilen değişkenlerine karşılık gelir. İsimlerinin aynı olması şart değildir.
{	
	int bakiye = y - x;
	return bakiye;                   // return ile dondurulen degisken tipinin fonk değişken tipiyle aynı olmasi sarttir
}

int ParaYatir(int y, int x)          // bu fonksiyon parametreleri icin y=hesap, x=yatirilan değişkenlerine karşılık gelir. İsimlerinin aynı olması şart değildir.
{	
	int bakiye = y + x;
	return bakiye;                  // return ile dondurulen degisken tipinin fonk değişken tipiyle aynı olmasi sarttir
}
