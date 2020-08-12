#include <iostream>

using namespace std;

int main() {
	int Perros, Gatos, SumaPerros = 0, SumaGatos = 0, totalAnimales = 0;
	string NombreCuidador, confirmacion, continuar;

	do {
		do {
		
			cout << "Ingresa el nombre del cuidador: " << endl;
			cin >> NombreCuidador;

			cout << "Cuantos perros y gatos tiene?" << endl;
			cin >> Perros >> Gatos;

			SumaGatos += Gatos;
			SumaPerros += Perros;

			cout << "Los datos son correctos?" << endl;
			cin >> confirmacion;
	
		} while (confirmacion == "no");


		cout << "Agregar otra persona?" << endl;
		cin >> continuar;
		
	} while (continuar == "si");

	totalAnimales = SumaGatos + SumaPerros;
	float lol = SumaGatos / totalAnimales;
	cout << "El porcentaje de Gatos es de: " << SumaGatos / (SumaPerros + SumaGatos)  << endl;
	cout << "El porcentaje de Perros es de: " << (SumaPerros / (SumaPerros + SumaGatos) * 100) << endl;

	return 0;
}
