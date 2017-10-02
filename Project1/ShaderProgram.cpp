#include "ShaderProgram.h"
#include "InputFile.h"
#include "shader.h"
#include <memory>


ShaderProgram::ShaderProgram(){	//El constructor inicializa los valores por default de las variables.
	_programHandle = 0;
}

ShaderProgram::~ShaderProgram(){
	//El destructor manda a llamar el mÈtodo DeleteProgram() (Opcional +2 puntos)
	DeleteProgram();
}

void ShaderProgram::CreateProgram(){
	//El mÈtodo CreateProgram() es el encargado de crear el programa shader utilizando la instrucciÛn de OpenGL adecuada. 
	//Guarda un identificador del programa creado en la variable _programHandle.
	_programHandle = glCreateProgram();	//Crear el manager de los shaders

}

void ShaderProgram::AttachShader(std::string path, GLenum type){
	/*
	El mÈtodo AttachShader(Ö) recibe la ruta a un archivo shader (path) y el tipo de shader que se quiere crear (type) con los cuales se creara 
	un objeto de clase Shader, la cual se incluir· en la lista _attachedShaders. La lista _attachedShaders es una lista de unique_ptr.
	Debido a que no vimos este tipo de dato en clase, se incluye el cÛdigo a continuaciÛn:
	*/																						
																						
	// Create and add the shaders to a list
	std::unique_ptr<Shader> shader(new Shader);
	shader->CreateShader(path, type);
	_attachedShaders.push_back(std::move(shader));

	//Se utilizan apuntadores(unique_ptr) en este mÈtodo para evitar que la referencia al objeto original se pierda cuando el mÈtodo termina.
	//Para poder utilizar apuntadores en un archivo fuente, es necesario hacer uso de la librerÌa memory.
}

void ShaderProgram::LinkProgram(){
	//El mÈtodo LinkProgram()tiene que adjuntar los shaders en la lista _attachedShaders al programa shader utilizando el mÈtodo glAttachShader().
	for(int i =0; i<_attachedShaders.size(); i++){
		glAttachShader(_programHandle, _attachedShaders[i]->GetHandle());	
	}
	//DespuÈs, iniciar el proceso de linkeo utilizando la funciÛn de OpenGL adecuada.Por ˙ltimo, debe mandar a llamar el mÈtodo DeleteAndDetachShaders().
	glLinkProgram(_programHandle); //Verificar que todos los shaders que este manager administra pueden trabajar entre si.
	DeleteAndDetachShaders();

}

void ShaderProgram::Activate(){
	//El mÈtodo Activate() hace bind del programa shader para poderlo usar.
	glUseProgram(_programHandle);		//Le decimos a OpenGl que lo vamos a utilizar

}

void ShaderProgram::Deactivate(){
	//El mÈtodo Deactivate() hace unbind del programa shader.
	glUseProgram(0);
}

void ShaderProgram::SetAttribute(GLuint locationIndex, std::string name){
	glBindAttribLocation(_programHandle, locationIndex, (const GLchar*)name.c_str());	//Hacemos match entre el indice del buffer y el nombre de la variable en el shadder
	//El mÈtodo SetAttribute(Ö) es el encargado de hacer la relaciÛn entre el Ìndice de posiciÛn de un VBO (locationIndex) y el nombre de la variable (name) en el shader.

}

void ShaderProgram::SetUniformf(std::string name, float value){

	//Los mÈtodos SetUniformf(Ö) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este mÈtodo debe encontrar la posiciÛn de la variable en el shader, utilizando la funciÛn de OpenGL adecuada, y darles el valor correcto.
	glUniform1f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), value); //Le damos valor al uniform
}

void ShaderProgram::SetUniformf(std::string name, float x, float y){
	//Los mÈtodos SetUniformf(Ö) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este mÈtodo debe encontrar la posiciÛn de la variable en el shader, utilizando la funciÛn de OpenGL adecuada, y darles el valor correcto.
	glUniform2f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y); //Le damos valor al uniform
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z){
	glUniform3f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z); //Le damos valor al uniform
	//Los mÈtodos SetUniformf(Ö) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este mÈtodo debe encontrar la posiciÛn de la variable en el shader, utilizando la funciÛn de OpenGL adecuada, y darles el valor correcto.
}

void ShaderProgram::SetUniformf(std::string name, float x, float y, float z, float w){
	glUniform4f(glGetUniformLocation(_programHandle, (const GLchar*)name.c_str()), x, y, z, w); //Le damos valor al uniform
	//Los mÈtodos SetUniformf(Ö) reciben el nombre (name) de un uniform en el shader y el valor de la variable. 
	//Este mÈtodo debe encontrar la posiciÛn de la variable en el shader, utilizando la funciÛn de OpenGL adecuada, y darles el valor correcto.
}

void ShaderProgram::DeleteAndDetachShaders(){
	//El mÈtodo DeleteAndDetachShaders() recorre la lista _attachedShaders y los va eliminando del programa shader uno por uno utilizando la funciÛn glDetachShader(). 
	//Al terminar este proceso, debe borrar la lista.
	for (int i = 0;i<_attachedShaders.size();i++) {
		glDetachShader(_programHandle, _attachedShaders[i]->GetHandle());
	}
	_attachedShaders.clear();		//Borrar una lista de inicio a fin
}

void ShaderProgram::DeleteProgram(){
	//El mÈtodo DeleteProgram() llama al mÈtodo DeleteAndDetachShaders() y borra el programa shader guardado en el identificador _programHandle.
	DeleteAndDetachShaders();
	glDeleteProgram(_programHandle);
	

}
