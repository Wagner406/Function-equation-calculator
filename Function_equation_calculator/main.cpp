#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

enum types_e
{
	LIN_FIND_M = 1,
	LIN_FIND_T,
	QUAD_FIND_A,
	QUAD_FIND_B,
	QUAD_FIND_C
};

struct math_t
{
	float x1; 
	float x2;
	float y1;
	float y2;
	float a;
	float b;
	float c;
	float m;
	float t;
};

//Quadratische Funktion
void prozess_quadrat(math_t kordinaten, types_e mode)
{
	switch (mode)
	{
		case (QUAD_FIND_A): {	//Gegeben ist a und b,c ist gesucht (A. 2013-5 und L. 2013-21)
			if ((kordinaten.x1 > 0) || (kordinaten.x1 < 0)) {
				std::cout << "\nErgebnis:\na = " << kordinaten.a << "\nb = " << ((kordinaten.y1 - kordinaten.y2) - ((kordinaten.a * pow(kordinaten.x1, 2)) - (kordinaten.a * pow(kordinaten.x2, 2)))) / (kordinaten.x1 - kordinaten.x2) << "\nc = "
					<< kordinaten.y1 - ((kordinaten.a * pow(kordinaten.x1, 2)) + (kordinaten.x1 * (((kordinaten.y1 - kordinaten.y2) - ((kordinaten.a * pow(kordinaten.x1, 2)) - (kordinaten.a * pow(kordinaten.x2, 2)))) / (kordinaten.x1 - kordinaten.x2)))) << "\n\n";
				break;
			}
			else if (kordinaten.x1 == 0) {
				std::cout << "\nErgebnis:\na = " << kordinaten.a << "\nb = " << (kordinaten.y2 - (kordinaten.a * pow(kordinaten.x2, 2)) - kordinaten.y1) / kordinaten.x2 << "\nc = " << kordinaten.y1 << "\n\n";
				break;
			}

			else if (kordinaten.x2 == 0) {
				std::cout << "\nErgebnis:\na = " << kordinaten.a << "\nb = " << (kordinaten.y1 - (kordinaten.a * pow(kordinaten.x1, 2)) - kordinaten.y2) / kordinaten.x1 << "\nc = " << kordinaten.y2 << "\n\n";
				break;
			}
			break;
		}
		case (QUAD_FIND_B): {	//Gegeben ist b und a,c ist gesucht
			if ((kordinaten.x1 > 0) || (kordinaten.x1 < 0)) {
				std::cout << "\nErgebnis:\na = " << ((kordinaten.y1 - kordinaten.y2) - ((kordinaten.x1 * kordinaten.b) - (kordinaten.x2 * kordinaten.b))) / (pow(kordinaten.x1, 2) - (pow(kordinaten.x2, 2))) << "\nb = " 
					<< kordinaten.b << "\nc = " << kordinaten.y1 - ((((kordinaten.y1 - kordinaten.y2) - ((kordinaten.x1 * kordinaten.b) - (kordinaten.x2 * kordinaten.b))) / (pow(kordinaten.x1, 2) - (pow(kordinaten.x2, 2)))) * (pow(kordinaten.x1, 2)) + (kordinaten.x1 * kordinaten.b)) << "\n\n";
				break;
			}
			else if (kordinaten.x1 == 0) {
				//a berechnen
				std::cout << "\nErgebnis:\na = " << (kordinaten.y2 - ((kordinaten.x2 * kordinaten.b) + kordinaten.y1)) / (pow(kordinaten.x2, 2)) << "\nb = " << kordinaten.b << "\nc = " << kordinaten.y1 << "\n\n";
				break;
			}
			else if (kordinaten.x2 == 0) {
				std::cout << "\nErgebnis:\na = " << (kordinaten.y1 - ((kordinaten.x1 * kordinaten.b) + kordinaten.y2)) / (pow(kordinaten.x1, 2)) << "\nb = " << kordinaten.b << "\nc = " << kordinaten.y2 << "\n\n";
				break;
			}
			break;
		}
		case (QUAD_FIND_C): {	//Gegeben ist c und a,b ist gesucht (A. S.34 und L. S.48) 
			//a berechnen
			kordinaten.a = ((kordinaten.x2 * (kordinaten.y1 - kordinaten.c)) - (kordinaten.x1 * (kordinaten.y2 - kordinaten.c))) / ((kordinaten.x2 * pow(kordinaten.x1, 2)) - (kordinaten.x1 * pow(kordinaten.x2, 2)));
	
			std::cout << "\nErgebnis:\na = " << kordinaten.a << "\nb = " << (kordinaten.y1 - (((kordinaten.x2 * pow(kordinaten.x1, 2)) / kordinaten.x2 * kordinaten.a) + kordinaten.c)) / kordinaten.x1 << "\nc = " << kordinaten.c << "\n\n";
			break;
		}
	}
}

//Menü
void menu()
{
	std::cout << "\nLineare Funktion\n\n\n(1) Gesucht ist m\n(2) Gesucht ist t\n\n\nQuadratische Funktion\n\n\n(3) Gegeben ist a\n(4) Gegeben ist b\n(5) Gegeben ist c\n" << std::endl;

	types_e input;
	math_t kordinaten;

	scanf("%d", &input);
	
	switch (input) {
		case(types_e::LIN_FIND_M): {
			std::cout << "\nGebe ein: x1, y1, x2, y2\n";
			std::cin >> kordinaten.x1 >> kordinaten.y1 >> kordinaten.x2 >> kordinaten.y2;
			
			std::cout << "m = " << (kordinaten.y2 - kordinaten.y1) / (kordinaten.x2 - kordinaten.x1) << std::endl << std::endl;
			
			break;
		}
		
		case(types_e::LIN_FIND_T): {
			std::cout << "\nGebe ein: m, x1, y1\n";
			std::cin >> kordinaten.m >> kordinaten.x1 >> kordinaten.y1;
			
			std::cout << "t = " << (kordinaten.m * kordinaten.x1) - kordinaten.y1 << std::endl << std::endl;
			
			break;
		}
		
		case(types_e::QUAD_FIND_A): {
			std::cout << "\nGebe ein: x1,  y1,  x2,  y2  a\n";
			std::cin >> kordinaten.x1 >> kordinaten.y1 >> kordinaten.x2 >> kordinaten.y2 >> kordinaten.a;
			
			prozess_quadrat(kordinaten, QUAD_FIND_A);
			break;
		}
		
		case(types_e::QUAD_FIND_B): {
			std::cout << "\nGebe ein: x1,  y1,  x2,  y2  b\n";
			std::cin >> kordinaten.x1 >> kordinaten.y1 >> kordinaten.x2 >> kordinaten.y2 >> kordinaten.b;
			
			prozess_quadrat(kordinaten, QUAD_FIND_B);
			break;
		}
		
		case(types_e::QUAD_FIND_C): {
			std::cout << "\nGebe ein: x1,  y1,  x2,  y2  c\n";
			std::cin >> kordinaten.x1 >> kordinaten.y1 >> kordinaten.x2 >> kordinaten.y2 >> kordinaten.c;
			
			prozess_quadrat(kordinaten, QUAD_FIND_C);
			break;
		}
		
		default:
			std::cout << "Ungueltig, versuche es nochmal\n\n";
		break;
	}
	system("Pause");
	system("cls");

	menu();
}

int main() 
{
	menu();

	return 0;
}