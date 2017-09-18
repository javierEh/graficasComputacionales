/*********************************************************
Materia: Graficas Computacionales
Fecha: 20/08/17
Autor: A01374645 Javier Esponda
*********************************************************/

#include <string>

class InputFile {
public:
	bool Read(std::string filename);
	std::string GetContents();

private:
	std::string _contents;
};
