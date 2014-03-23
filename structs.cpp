#include <stdio.h>
#include <conio.h>

struct human                 //human için verilerin toplanacağı yapı
{
	char name[10];            //toplanılacak veriler ise ad,soyad,yaş,boy,kilo...
	char surname[10];
	int age;
	int weight;
	int height;
};

void main()
{
	struct human kisiler[3];                    //Structlar diziler halinde oluşturulabilir
	for (int i = 0; i < 3; i++)               //örneğin bu struct dizisi, 3 kişiye ait bilgileri tutmaktadir.
	{
		printf("%d.Kisi icin bilgi girin: \n", i + 1);
		fflush(stdin);
		printf("\nAd:");
		gets_s(kisiler[i].name);
		fflush(stdin);
		printf("Soyad:");
		gets_s(kisiler[i].surname);
		fflush(stdin);
		printf("Yas:");
		scanf_s("%d", &kisiler[i].age);
		printf("Boy:");
		scanf_s("%d", &kisiler[i].height);
		printf("Kilo:");
		scanf_s("%d", &kisiler[i].weight);
		printf("\n\n");
	}
	printf("Ad\t   Soyad\t Yas Kilo Boy\n");
	for (int i = 0; i < 3; i++)           //struct ile saklanan verilerin ekrana yazdırılması
		printf("%s\t   %s\t %d  %d   %d\n", kisiler[i].name, kisiler[i].surname, kisiler[i].age, kisiler[i].height, kisiler[i].weight);
	_getch();
}
