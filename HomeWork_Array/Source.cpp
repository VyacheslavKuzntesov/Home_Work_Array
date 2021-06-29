#include<iostream>
#include <conio.h>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

void main()
{
	const int n = 10;
	int arr1[n] = { 1,2,3,4,5,6,7,8,9,10 };
	int smechenie = 0;
	int storona_smecheniya = 0;
	int peremenaya_dlya_smecheniya = 0;
	int peremenaya_dlya_smecheniya_2 = 0;

	do
	{
		int arr[n] = { 1,2,3,4,5,6,7,8,9,10 };
		setlocale(LC_ALL, "Rus");
		cout << "Введите сторону смещения (1 - влево, 2 - вправо, 3 - для выхода из программы): "; cin >> storona_smecheniya;
		if (storona_smecheniya != 3)
		{
			cout << "Введите на сколько шагов будет смещения: "; cin >> smechenie;
		}

		if (smechenie > 10)
		{
			smechenie %= 10;
		}

		if (smechenie == 10)
		{
			cout << "Массив до смещения:    ";
			for (int i = 0; i < n; i++)
			{
				if (arr1[i] == 10)
				{
					cout << "  " << arr1[i];
				}
				else
				{
					cout << "   " << arr1[i];
				}
			}
			cout << endl;
			cout << "Массив после смещения: ";
			for (int i = 0; i < n; i++)
			{
				if (arr[i] == 10)
				{
					cout << "  " << arr[i];
				}
				else
				{
					cout << "   " << arr[i];
				}
			}
		}
		else
		{
			switch (storona_smecheniya)
			{
			case 1:
				peremenaya_dlya_smecheniya = arr[9];
				for (int i = 0; i < smechenie; i++)
				{
					for (int j = 8; j >= 0; j--)
					{
						if (j != 0)
						{
							peremenaya_dlya_smecheniya_2 = peremenaya_dlya_smecheniya;
							peremenaya_dlya_smecheniya = arr[j];
							arr[j] = peremenaya_dlya_smecheniya_2;
						}
						else
						{
							peremenaya_dlya_smecheniya_2 = peremenaya_dlya_smecheniya;
							peremenaya_dlya_smecheniya = arr[0];
							arr[0] = peremenaya_dlya_smecheniya_2;
							arr[9] = peremenaya_dlya_smecheniya;
						}
					}
				}
				break;
			case 2:
				peremenaya_dlya_smecheniya = arr[0];
				for (int i = 0; i < smechenie; i++)
				{
					for (int j = 1; j < n + 1; j++)
					{
						if (j != 10)
						{
							peremenaya_dlya_smecheniya_2 = peremenaya_dlya_smecheniya;
							peremenaya_dlya_smecheniya = arr[j];
							arr[j] = peremenaya_dlya_smecheniya_2;
						}
						else
						{
							arr[0] = peremenaya_dlya_smecheniya;
						}
					}
				}
				break;
			default:
				if (storona_smecheniya == 3)
				{
					cout << "Выход";
				}
				else
				{
					cout << "Нет такой программы" << endl;
				}
				break;
			}

			if (storona_smecheniya == 1 || storona_smecheniya == 2)
			{
				cout << endl;
				cout << "Массив до смещения:    ";
				for (int i = 0; i < n; i++)
				{
					if (arr1[i] == 10)
					{
						cout << "  " << arr1[i];
					}
					else
					{
						cout << "   " << arr1[i];
					}
				}
				cout << endl;
				cout << "Массив после смещения: ";
				for (int i = 0; i < n; i++)
				{
					if (arr[i] == 10)
					{
						cout << "  " << arr[i];
					}
					else
					{
						cout << "   " << arr[i];
					}
				}
			}
			cout << endl;
			cout << endl;
		}
		} while (storona_smecheniya != 3);
}