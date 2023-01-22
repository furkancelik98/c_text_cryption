#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

int main()
{
	FILE *fptr;
	FILE *fptr2;
	int sec;
	char dosya_adi[50];
	char temp, son;
	int ba, ia, ua;

	while (1)
	{
		printf("1 - Sifrele\n2 - Sifre coz\n3 - Cikis\n\nSeciniz ? : ");
		scanf("%d", &sec);

		switch (sec)
		{
		case 1:
		{
			printf("\nLutfen sifrelenecek metnin bulundugu txt uzantili dosyayi program ile ayni\nklasore koyun. Ardindan asagiya dosya ismini, uzantisiyla beraber yazin. \nOrnegin : deneme.txt \n\nDosya adini girin : ");
			scanf("%s", dosya_adi);

			if ((fptr = fopen(dosya_adi, "r")) == NULL)
			{
				printf("Dosya bulunamadi!\n\n-------------\n\n");
			}
			else
			{
				printf("Birinci anahtari girin : ");
				scanf("%d", &ba);
				printf("Ikinci anahtari girin : ");
				scanf("%d", &ia);
				printf("Ucuncu anahtari girin : ");
				scanf("%d", &ua);

				printf("Sifrelenmis dosyanin adini uzantisiyla birlikte girin.\nOrnegin : sifrelenmis_dosya.abc\nDosya adi : ");
				scanf("%s", dosya_adi);

				fptr2 = fopen(dosya_adi, "w");
				while (!feof(fptr))
				{
					fscanf(fptr, "%c", &temp);

					son = temp + (((ba + ia) * ua) + ba) * ba;

					fprintf(fptr2, "%c", son);

				}
				fclose(fptr);
				fclose(fptr2);
				printf("Sifreleme tamamlandi.\n\n-------------\n\n");
			}
			break;
		}


		case 2:
		{
			printf("\nLutfen sifresi cozulecek metnin bulundugu dosyayi program ile ayni\nklasore koyun. Ardindan asagiya dosya ismini, uzantisiyla beraber yazin. \nOrnegin : deneme.txt \n\nDosya adini girin : ");
			scanf("%s", dosya_adi);

			if ((fptr = fopen(dosya_adi, "r")) == NULL)
			{
				printf("Dosya bulunamadi!\n\n-------------\n\n");
			}

			else
			{
				printf("Sifrelemede kullanilan anahtarlari sirasiyla girin.\n");
				printf("Birinci anahtari girin : ");
				scanf("%d", &ba);
				printf("Ikinci anahtari girin : ");
				scanf("%d", &ia);
				printf("Ucuncu anahtari girin : ");
				scanf("%d", &ua);

				printf("Cozulmus dosyanin adini uzantisiyla birlikte girin.\nOrnegin : cozulmus_dosya.txt\nDosya adi : ");
				scanf("%s", dosya_adi);

				fptr2 = fopen(dosya_adi, "w");
				while (!feof(fptr))
				{
					fscanf(fptr, "%c", &son);

					temp = son - (((ba + ia) * ua) + ba) * ba;

					fprintf(fptr2, "%c", temp);

				}
				fclose(fptr);
				fclose(fptr2);
				printf("Sifre cozme tamamlandi.\n\n-------------\n\n");
			}
			break;
		}

		case 3:
		{
			return 0;
			break;
		}

		default:
		{
			printf("\nYanlis giris yaptiniz.\n\n-------------\n\n");
		}

		}
	}
	_getch();
	return 0;
}