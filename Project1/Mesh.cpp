#include "Mesh.h"

<<<<<<< HEAD

/*********************************************************
Materia: Gráficas Computacionales
Fecha: 16 de agosto del 2017
Autor: A01370699 Abraham Soto
Autor: A01374645 Javier Esponda
*********************************************************/

Mesh::Mesh() {
=======
Mesh::Mesh(){//El constructor inicializa los valores por default de las variables.
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
	_vertexArrayObject = 0;
	_positionsVertexBufferObject= 0;
	_colorsVertexBufferObject = 0;
	_vertexCount = 0;

	_indexCount = 0;
	_indexBufferObject = 0;

}

<<<<<<< HEAD
Mesh::~Mesh() {
	glDeleteBuffers(1, &_positionsVertexBufferObject);
	glDeleteBuffers(1, &_colorsVertexBufferObject);
=======
Mesh::~Mesh(){
	//El destructor borra el VAO y todos los VBOs. (Opcional +2 puntos)
	//Tenemos que borrar el vao, las posiciones y los colores
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
	glDeleteVertexArrays(1, &_vertexArrayObject);
}

<<<<<<< HEAD
void Mesh::CreateMesh(GLuint vertexCount) {
=======
void Mesh::CreateMesh(GLint vertexCount){
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
	_vertexCount = vertexCount;
	glGenVertexArrays(1, &_vertexArrayObject);
}

<<<<<<< HEAD
void Mesh::Draw(GLenum primitive) {
	glBindVertexArray(_vertexArrayObject);
	if (_indexCount == 0) {
		glDrawArrays(primitive, 0, _vertexCount);
	}
	else {
		(_vertexArrayObject);
		glDrawElements(primitive, _indexCount, GL_UNSIGNED_INT, nullptr);
	}
	glBindVertexArray(0);
}

void Mesh::SetPositionAttribute(vector<vec2> positions, GLenum usage, GLuint locationIndex) {
	if (positions.size() == 0 || positions.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_positionsVertexBufferObject, sizeof(vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
	}
}

void Mesh::SetPositionAttribute(vector<vec3> positions, GLenum usage, GLuint locationIndex) {
	if (positions.size() == 0 || positions.size() != _vertexCount) {
		return;
	}
	else {
		SetAttributeData(_positionsVertexBufferObject, sizeof(vec3) * positions.size(), positions.data(), usage, locationIndex, 3);
	}
}

void Mesh::SetColorAttribute(vector<vec3> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
=======
void Mesh::Draw(GLenum primitive){
	glDrawArrays(primitive, 0, _vertexCount);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec2> positions, GLenum usage, GLuint locationIndex){
	if (positions.size() == 0 || positions.size() != _vertexCount){
		return;
	}	

	SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec2) * positions.size(), positions.data(), usage, locationIndex, 2);
}

void Mesh::SetPositionAttribute(std::vector<glm::vec3> positions, GLenum usage, GLuint locationIndex){
	if (positions.size() == 0 || positions.size() != _vertexCount){
		return;
	}	

	SetAttributeData(_positionsVertexBufferObject, sizeof(glm::vec3) * positions.size(), positions.data(), usage, locationIndex, 3);
}

void Mesh::SetColorAttribute(std::vector<glm::vec3> colors, GLenum usage, GLuint locationIndex){
	if (colors.size() == 0 || colors.size() != _vertexCount){
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
		return;
	}
	else {
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec3) * colors.size(), colors.data(), usage, locationIndex, 3);
	}
}

<<<<<<< HEAD
void Mesh::SetColorAttribute(vector<vec4> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount) {
=======
void Mesh::SetColorAttribute(std::vector<glm::vec4> colors, GLenum usage, GLuint locationIndex) {
	if (colors.size() == 0 || colors.size() != _vertexCount){
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
		return;
	}
	else {
		SetAttributeData(_colorsVertexBufferObject, sizeof(vec4) * colors.size(), colors.data(), usage, locationIndex, 4);
	}
}

void Mesh::SetIndices(vector<unsigned int> indices, GLenum usage) {
	_indexCount = indices.size();

	if (_indexCount > 0) {
		glBindVertexArray(_vertexArrayObject);
		glGenBuffers(1, &_indexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int)* indices.size(), indices.data(), GL_STATIC_DRAW);
		glBindVertexArray(0);
	}
}

<<<<<<< HEAD
void Mesh::SetAttributeData(GLuint & buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLuint components) {
	if (buffer != 0) {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	glBindVertexArray(_vertexArrayObject);
	glGenBuffers(1, &buffer);
	// Activamos el buffer de posiciones para poder utilizarlo, este buffer ES UN ATRIBUTO (GL ARRAY BUFFER)
=======
void Mesh::SetAttributeData(GLuint& buffer, const GLsizeiptr size, const void * data, GLenum usage, GLuint locationIndex, const GLint components){
	glDeleteBuffers(1, &buffer);
	glGenBuffers(1, &buffer);
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	// Creamos la memoria y la inicializamos con los datos del atributo de posiciones
	glBufferData(GL_ARRAY_BUFFER, size, data, usage);
	// Activamos el atributo en la tarjeta de video
	glEnableVertexAttribArray(locationIndex);
	// Configuramos los datos del atributo en la tarjeta de video
	glVertexAttribPointer(locationIndex, components, GL_FLOAT, GL_FALSE, 0, nullptr);
	// Ya no vamos a utilizar este Vertex Buffer Object en este momento
	glBindBuffer(GL_ARRAY_BUFFER, 0);
<<<<<<< HEAD
	glBindVertexArray(0);

}
=======
}
>>>>>>> 480ad849081d5f13c666b4ebc2401ab4f448d68f
