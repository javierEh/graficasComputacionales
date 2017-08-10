/*********************************************************
Materia: Graficas Computacionales
Fecha: 10 de agosto de 2017
Autor: A01374645 Javier Esponda Hernandez
*********************************************************/

#include <iostream>

//Para no tener que escribir std en cada llamada
using namespace std;

int PerimetroRectangulo(int base, int altura) {
	int perimetro;
	base = base * 2;
	altura = altura * 2;
	perimetro = base + altura;

	return perimetro;
}

float AreaTriangulo(float base, float altura) {
	float area;
	area = (base * altura) / 2;

	return area;
}

int Mayor(int numero1, int numero2, int numero3) {
	if (numero1 > numero2) {
		if (numero1 > numero3) {
			return numero1;
		}
		else {
			return numero3;
		}
	}
	else if (numero2 > numero3) {
		return numero2;
	}
	else {
		return numero3;
	}
}

int Menor(int numero1, int numero2, int numero3) {
	if (numero1 < numero2) {
		if (numero1 < numero3) {
			return numero1;
		}
		else {
			return numero3;
		}
	}
	else if (numero2 < numero3) {
		return numero2;
	}
	else {
		return numero3;
	}
}

void FilaEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		cout << "*";
	}
}

void MatrizEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << "*";
		}
		cout << "\n";
	}
}

void PiramideEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i + j) > n) {
				cout << "*";
			}
		}
		cout << "\n";
	}
}

void FlechaEstrellas(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if ((i + j) > n) {
				cout << "*";
			}
		}
		cout << "\n";
	}
	for (int i = n - 1; i > 0; i--) {
		for (int j = n; j > 0; j--) {
			if ((i + j) > n) {
				cout << "*";
			}
		}
		cout << "\n";
	}
}

void Fibonacci(int n) {
	int a = 1, b = 1, c;
	cout << a << " ";
	cout << b << " ";

	for (int i = 0; i < n - 2; i++) {
		c = a + b;
		a = b;
		b = c;

		cout << c << " ";
	}
}

bool EsPrimo(int numero) {
	int cont = 0;
	bool primo;

	for (int i = 1; i < (numero + 1); i++) {
		if (numero % i == 0) {
			cont++;
		}
	}
	if (cont == 2) {
		primo = true;
	}
	else {
		primo = false;
	}
	return primo;
}


int main() {
	//Linea de output para mandar algo a pantalla
	//std::cout << "Hello, World!" << std::endl;

	//1 Calcular el perimetro de un rectangulo
	int p = PerimetroRectangulo(5, 3);
	//std::cout << p;
	cout << p << "\n\n";

	//2 Calcular el area de un triangulo
	float a = AreaTriangulo(5.0f, 3.0f);
	cout << a << "\n\n";

	//3 Encontrar el numero mayor
	int mayor = Mayor(5, 9, 1);
	cout << mayor << "\n\n";

	//4 Encontrar el numero menor
	int menor = Menor(5, 9, 1);
	cout << menor << "\n\n";

	//5 Fila de estrellas con ciclo
	FilaEstrellas(5);
	cout << "\n\n";

	//6 Matriz de estrellas
	MatrizEstrellas(4);
	cout << "\n";

	//7 Piramide estrellas
	PiramideEstrellas(6);
	cout << "\n";

	//8 Flecha de estrellas
	FlechaEstrellas(3);
	cout << "\n";

	//9 Fibonacci
	Fibonacci(9);
	cout << "\n\n";

	//10 Es primo o no?
	bool primoTrue = EsPrimo(79);
	cout << primoTrue << "\n\n";

	bool primoFalse = EsPrimo(52);
	cout << primoFalse;

	//Pausar el programa hasta que alguien oprima una tecla
	cin.get();
	return 0;
}