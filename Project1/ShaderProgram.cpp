#include "ShaderProgram.h"
#include "InputFile.h"
#include "shader.h"
#include <memory>

ShaderProgram::ShaderProgram() {	//El constructor inicializa los valores por default de las variables.
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram() {
	//El destructor manda a llamar el m�todo DeleteProgram() (Opcional +2 puntos)
	DeleteProgram();
}

void ShaderProgram::CreateProgram() {
	//El m�todo CreateProgram() es el encargado de crear el programa shader utilizando la instrucci�n de OpenGL adecuada. 
	//Guarda un identificador del programa creado en la variable _programHandle.
	_programHandle = glCreateProgram();	//Crear el manager de los shaders

}

void ShaderProgram::AttachShader(std::string path, GLenum type) {
	/*
	El m�todo AttachShader(�) recibe la ruta a un archivo shader (path) y el tipo de shader que se quiere crear (type) con los cuales se creara
	un objeto de clase Shader, la cual se incluir� en la lista _attachedShaders. La lista _attachedShaders es una lista de unique_ptr.
	Debido a que no vimos este tipo de dato en clase, se incluye el c�digo a continuaci�n:
	*/

	// Create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));

	//Se utilizan apuntadores(unique_ptr) en este m�todo para evitar que la referencia al objeto original se pierda cuando el m�todo termina.
	//Para poder utilizar apuntadores en un archivo fuente, es necesario hacer uso de la librer�a memory.
}

void ShaderProgram::LinkProgram() {
	//El m�todo LinkProgram()tiene que adjuntar los shaders en la lista _attachedShaders al programa shader utilizando el m�todo glAttachShader().
	for (int i = 0; i<_attachedShaders.size(); i++) {
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());
	}
	//Despu�s, iniciar el proceso de linkeo utilizando la funci�n de OpenGL adecuada.Por ?ltimo, debe mandar a llamar el m�todo DeleteAndDetachShaders().
	glLinkProgram(_programHandle); //Verificar que todos los shaders que este manager administra pueden trabajar entre si.
	DeleteAndDetachShaders();

}

void ShaderProgram::Activate() {
	//El m�todo Activate() hace bind del programa shader para poderlo usar.
	glUseProgram(_programHandle);		//Le decimos a OpenGl que lo vamos a utilizar

}

void ShaderProgram::Deactivate() {
	//El m�todo Deactivate() hace unbind del programa shader.
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name) {
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());	//Hacemos match entre el indice del buffer y el nombre de la variable en el shadder
																						//El m�todo SetAttribute(�) es el encargado de hacer la relaci�n entre el �ndice de posici�n de un VBO (locationIndex) y el nombre de la variable (name) en el shader.

}

void ShaderProgram::SetUniformf(std::string name, float value) {

	//Los m�todos SetUniformf(�) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este m�todo debe encontrar la posici�n de la variable en el shader, utilizando la funci�n de OpenGL adecuada, y darles el valor correcto.
	glUniform1f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), value); //Le damos valor al uniform
}

void ShaderProgram::SetUniformf(std::string name, float x, float y) {
	//Los m�todos SetUniformf(�) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este m�todo debe encontrar la posici�n de la variable en el shader, utilizando la funci�n de OpenGL adecuada, y darles el valor correcto.
	glUniform2f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y); //Le damos valor al uniform
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z) {
	glUniform3f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z); //Le damos valor al uniform
																							 //Los m�todos SetUniformf(�) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
																							 //Este m�todo debe encontrar la posici�n de la variable en el shader, utilizando la funci�n de OpenGL adecuada, y darles el valor correcto.
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w) {
	glUniform4f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z, w); //Le damos valor al uniform
																								//Los m�todos SetUniformf(�) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
																								//Este m�todo debe encontrar la posici�n de la variable en el shader, utilizando la funci�n de OpenGL adecuada, y darles el valor correcto.
}

void ShaderProgram::DeleteAndDetachShaders() {
	//El m�todo DeleteAndDetachShaders() recorre la lista _attachedShaders y los va eliminando del programa shader uno por uno utilizando la funci�n glDetachShader(). 
	//Al terminar este proceso, debe borrar la lista.
	for (int i = 0; i<_attachedShaders.size(); i++) {
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
	}
	_attachedShaders.clear();		//Borrar una lista de inicio a fin
}

void ShaderProgram::DeleteProgram() {
	//El m�todo DeleteProgram() llama al m�todo DeleteAndDetachShaders() y borra el programa shader guardado en el identificador _programHandle.
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);


}