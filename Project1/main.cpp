/*********************************************************
Materia: Graficas Computacionales
Fecha: 20 de agosto de 2017
Autor: A01374645 Javier Esponda Hernandez
*********************************************************/

/*
#include <GL/glew.h>
#include <GL/freeglut.h>

void GameLoop() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//WARNING!!!! Esto es OpenGL viejito, solo lo vamos a usar esta clase
	//Prohibido el resto del semestre
	glBegin(GL_TRIANGLES);

	//Tenemos que indicar las coordenadas de los triangulos
	//Indicamos el color de cada uno
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2d(-1.0f, -1.0f);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2d(1.0f, -1.0f);
	
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2d(0, 1.0f);
	

	
	



	glEnd();

	glutSwapBuffers();
}

int main(int argc, char* argv[]) {
	//Inicializar freeglut
	//Freeglut se encarga de crear una ventana en donde podemos dibujar
	glutInit(&argc, argv);

	//Inicializar el contexto de OpenGL. El contexto se refiere a las capacidades que va a 
	//tener nuestra aplicacion grafica
	//En este caso estamos trabajando con el pipeline clasico
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	//Freeglut nos permite configurar eventos que ocurren en la ventana.
	//Un evento que nos interesa es cuando alguien cierra la ventana.
	//En este caso simplemente dejamos de renderear la escena y terminamos el programa.
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	//Configuramos el gramebuffer y en este caso estamos solicitando un buffer true color RGBA, un buffer de profundidad
	//y un segundo buffer para renderear.
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);

	//Iniciar las dimensiones de la ventana (en pixeles)
	glutInitWindowSize(400, 400);

	//Creamos la ventana y le damos un titulo
	glutCreateWindow("Hello World GL");

	//Asociamos una funcion de render. Esta funcion se mandara llamar para dibujar un frame
	glutDisplayFunc(GameLoop);

	//inicializar GLEW. Esta libreria se encarga de obtener el API de OpenGL de nuestra tarjeta de video. SHAME ON YOU MICROSOFT
	glewInit();

	//Configurar OpenGL. Este es el color por default del buffer de color en el framebuffer
	glClearColor(1.0f, 1.0f, 0.5f, 1.0f);
	
	//Iniciar la aplicacion. El main se pausara en esta linea hasta que se cierre la ventana de OpenGL
	glutMainLoop();

	return 0;
}
*/

/*
#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Employee.h"
#include "main.h"
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
	cout << primoFalse << "\n\n";

	//////////////////////////////////////////////////////////////
	cout << "Circulo\n";
	Circle circulo(2.0, "green");
	cout << circulo.getRadius() << endl << endl;

	cout << "Rectangulo\n";
	Rectangle rectangle(2.0, 4.0);
	cout << rectangle.getArea() << "\n\n";

	cout << "Employee\n";
	Employee employee(1, "Javier", "Esponda", 10);
	cout << employee.GetName() << endl;
	cout << employee.GetSalary() << endl;
	cout << employee.GetAnnualSalary() << endl;
	cout << employee.RaiseSalary(10) << endl;
	cout << employee.Print();

	//Pausar el programa hasta que alguien oprima una tecla
	cin.get();
	return 0;
}

*/

//Main para el metodo inputFile
#include <iostream>
#include <stdlib.h>
#include "InputFile.h"


int main(int argc, char* argv[]){
	
	std::string filename = "Prueba.txt"; InputFile myFile;
	myFile.Read(filename);
	std::string contents = myFile.GetContents();
	std::cout << "Contents: " << contents << std::endl;
	std::cin.get();
}
