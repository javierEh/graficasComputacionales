/*********************************************************
Materia: Graficas Computacionales
Fecha: 20/08/17
Autor: A01374645 Javier Esponda
*********************************************************/

#include "InputFile.h"
#include <iostream>
#include <fstream>
#include <iostream>

bool InputFile::Read(std::string filename){
	std::ifstream file;
	std::string text;

	file.open(filename, std::ios::in);
	if (!file){
		_contents = "";
		return false;
	}
	_contents = "";

	while (std::getline(file, text))
		_contents += text + "\n";
	
	file.close();
	return true;
	
}

std::string InputFile::GetContents()
{
	return _contents;
}
