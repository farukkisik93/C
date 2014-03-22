#include <stdio.h>
#include <conio.h>

void main()
{
	int a, b, c;	// Değişkenler Tanımlanır
	char secim,cevap;
	A:printf("Yapilacak islemi seciniz.(+ , - , x , /)");
	secim = _getch();
	if (secim == '+')
	{
		printf("\n\n1. Sayiyi Giriniz:");
		scanf_s("%d", &a);
		printf("2. Sayiyi Giriniz:");
		scanf_s("%d", &b);
		c = a + b;   //a+b işlemi gerçekleştirilir.Sonuc c değişkenine aktarılır.
		printf("\nSonuc : %d",c);
		printf("\nYeni bir islem yapmak ister misiniz?\n\n");
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
			goto A;
		else
		{
			printf("\nCikis icin bir tusa basin.");
			_getch();
		}
	}
	else if (secim == '-')
	{
		printf("\n\n1. Sayiyi Giriniz:");
		scanf_s("%d", &a);
		printf("\n2. Sayiyi Giriniz:");
		scanf_s("%d", &b);
		c = a - b;   //a-b işlemi gerçekleştirilir.Sonuc c değişkenine aktarılır.
		printf("\nSonuc : %d", c);
		printf("\nYeni bir islem yapmak ister misiniz?\n\n");
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
			goto A;
		else
		{
			printf("\nCikis icin bir tusa basin.");
			_getch();
		}
	}
	else if (secim == 'x' || secim == 'X' || secim == '*')
	{
		printf("\n\n1. Sayiyi Giriniz:");
		scanf_s("%d", &a);
		printf("2. Sayiyi Giriniz:");
		scanf_s("%d", &b);
		c = a * b;   //a*b işlemi gerçekleştirilir.Sonuc c değişkenine aktarılır.
		printf("\nSonuc : %d", c);
		printf("\nYeni bir islem yapmak ister misiniz?\n\n");
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
			goto A;
		else
		{
			printf("\nCikis icin bir tusa basin.");
			_getch();
		}
	}
	else if (secim == '/')
	{
		printf("\n\n1. Sayiyi Giriniz:");
		scanf_s("%d", &a);
		printf("2. Sayiyi Giriniz:");
		scanf_s("%d", &b);                //a/b işlemi gerçekleştirilir.Sonuc c değişkenine aktarılır.
		float(c) = float(a) / float(b);   //İşlemin sonucunun tam olmaması ihtimaline karşın değişkenler float cinsine cevrilir.
		printf("\nSonuc : %5.2f", c);       //5.2f => Ondalık sayılar için 5, virgülün solundaki basamak sayisi. 2, vilgülün sağindaki basamak sayisi
		printf("\nYeni bir islem yapmak ister misiniz?\n\n");
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
			goto A;
		else
		{
			printf("\nCikis icin bir tusa basin.");
			_getch();
		}
	}
	else
	{	
		printf("\n\nHatali giris yaptiniz.");
		printf("\nYeni bir islem yapmak ister misiniz?\n\n");
		cevap = _getch();
		if (cevap == 'E' || cevap == 'e')
			goto A;
		else
		{
			printf("\nCikis icin bir tusa basin.");
			_getch();
		}
	}
}
