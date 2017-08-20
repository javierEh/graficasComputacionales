//Si son archivos dentro de nuestro proyecto va con comillas
#include "Circle.h"

Circle::Circle(){
	_radius = 1.0;
	_color = "red";
}

Circle::Circle(double r) {
	_radius = r;
	_color = "red";
}

Circle::Circle(double r, std::string c) {
	_radius = r;
	_color = c;
}

double Circle::getRadius(){
	return _radius;
}

std::string Circle::GetColor(){
	return _color;
}

void Circle::SetRadius(double r){
	_radius = r;
}

void Circle::SetColor(std::string c){
	_color = c;
}

double Circle::getArea() {
	return 3.14159 * _radius * _radius;
}

