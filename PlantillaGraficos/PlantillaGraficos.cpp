// PlantillaGraficos.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <math.h>

#include <iostream>

#include "Shader.h"
#include "Vertice.h"
#include <vector>
using namespace std;
//Cada elemento que queramos renderear necesita un vertex array y un buffer
vector<Vertice> arboles;
GLuint vertexArrayArbolesID;
GLuint bufferArbolesID;

vector<Vertice> cuadrado;
GLuint vertexArrayCuadradoID;
GLuint bufferCuadradoID;

vector<Vertice> suelo;
GLuint vertexArraySueloID;
GLuint bufferSueloID;
//Instancia de shader
Shader *shader;
//Identificadores para mapeo de atributos de entrada del vertex shader
GLuint posicionID;
GLuint colorID;

//Paleta de colores
float piramideCafeBase_R = 0.9f,
piramideCafeBase_G = 0.6f,
piramideCafeBase_B = 0.2f;
float piramideCafeBaseSombra_R = 0.8f,
piramideCafeBaseSombra_G = 0.4f,
piramideCafeBaseSombra_B = 0.1f;

float pisoTierra_R = 0.97f,
pisoTierra_G = 0.858f,
pisoTierra_B = 0.619f;

float pisoPasto_R = 0.2f,
pisoPasto_G = 0.9f,
pisoPasto_B = 0.23f;

void inicializarPiramide() {
	//nivel 1
	Vertice v1 = {
		vec3(-0.85f, -0.4f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v2 = {
		vec3(0.85f, -0.4f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v3 = {
		vec3(0.9f, -0.5f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v4 = {
		vec3(-0.9f, -0.5f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	//nivel 2
	Vertice v5 = {
		vec3(-0.75f, -0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v6 = {
		vec3(0.75f, -0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v7 = {
		vec3(0.8f, -0.4f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v8 = {
		vec3(-0.8f, -0.4f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 3
	Vertice v9 = {
		vec3(-0.65f, -0.2f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v10 = {
		vec3(0.65f, -0.2f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v11 = {
		vec3(0.7f, -0.3f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v12 = {
		vec3(-0.7f, -0.3f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 4
	Vertice v13 = {
		vec3(-0.55f, -0.1f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v14 = {
		vec3(0.55f, -0.1f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v15 = {
		vec3(0.6f, -0.2f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v16 = {
		vec3(-0.6f, -0.2f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 5
	Vertice v17 = {
		vec3(-0.45f, 0.0f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v18 = {
		vec3(0.45f, 0.0f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v19 = {
		vec3(0.5f, -0.1f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v20 = {
		vec3(-0.5f, -0.1f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 6
	Vertice v21 = {
		vec3(-0.35f, 0.1f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v22 = {
		vec3(0.35f, 0.1f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v23 = {
		vec3(0.4f, 0.0f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v24 = {
		vec3(-0.4f, 0.0f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 7
	Vertice v25 = {
		vec3(-0.25f, 0.2f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v26 = {
		vec3(0.25f, 0.2f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v27 = {
		vec3(0.3f, 0.1f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v28 = {
		vec3(-0.3f, 0.1f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//nivel 8
	Vertice v29 = {
		vec3(-0.15f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v30 = {
		vec3(0.15f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v31 = {
		vec3(0.2f, 0.2f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v32 = {
		vec3(-0.2f, 0.2f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//cuarto superior

	Vertice v33 = {
		vec3(-0.10f, 0.45f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v34 = {
		vec3(0.10f, 0.45f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v35 = {
		vec3(0.1f, 0.3f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v36 = {
		vec3(-0.1f, 0.3f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//cuarto superior dala

	Vertice v37 = {
		vec3(-0.115f, 0.38f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v38 = {
		vec3(0.115f, 0.38f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v39 = {
		vec3(0.115f, 0.35f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v40 = {
		vec3(-0.115f, 0.35f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	Vertice v41 = {
		vec3(-0.115f, 0.45f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v42 = {
		vec3(0.115f, 0.45f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v43 = {
		vec3(0.115f, 0.42f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v44 = {
		vec3(-0.115f, 0.42f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};

	//escaleras

	Vertice v45 = {
		vec3(-0.07f, 0.3f, 0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v46 = {
		vec3(0.07f, 0.3f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v47 = {
		vec3(0.1f, -0.5f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};
	Vertice v48 = {
		vec3(-0.1f, -0.5f,0.0f),
		vec4(piramideCafeBaseSombra_R,piramideCafeBaseSombra_G,piramideCafeBaseSombra_B,1.0f)
	};


	Vertice v49 = {
		vec3(-0.07f, 0.3f, 0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v50 = {
		vec3(-0.09f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v51 = {
		vec3(-0.12f, -0.5f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v52 = {
		vec3(-0.1f, -0.5f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};

	Vertice v53 = {
		vec3(0.07f, 0.3f, 0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v54 = {
		vec3(0.09f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v55 = {
		vec3(0.12f, -0.5f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v56 = {
		vec3(0.1f, -0.5f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};

	Vertice v57 = {
		vec3(-0.05f, 0.34f, 0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v58 = {
		vec3(0.05f, 0.34f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v59 = {
		vec3(0.05f, 0.3f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};
	Vertice v60 = {
		vec3(-0.05f, 0.3f,0.0f),
		vec4(0.0f,0.0f,0.0f,1.0f)
	};

	//pilares

	Vertice v61 = {
		vec3(-0.035f, 0.35f, 0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v62 = {
		vec3(-0.02f, 0.35f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v63 = {
		vec3(-0.02f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v64 = {
		vec3(-0.035f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};


	Vertice v65 = {
		vec3(0.02f, 0.35f, 0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v66 = {
		vec3(0.035f, 0.35f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v67 = {
		vec3(0.035f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};
	Vertice v68 = {
		vec3(0.02f, 0.3f,0.0f),
		vec4(piramideCafeBase_R,piramideCafeBase_G,piramideCafeBase_B,1.0f)
	};

	//push
	cuadrado.push_back(v1);
	cuadrado.push_back(v2);
	cuadrado.push_back(v3);
	cuadrado.push_back(v4);

	cuadrado.push_back(v5);
	cuadrado.push_back(v6);
	cuadrado.push_back(v7);
	cuadrado.push_back(v8);

	cuadrado.push_back(v9);
	cuadrado.push_back(v10);
	cuadrado.push_back(v11);
	cuadrado.push_back(v12);

	cuadrado.push_back(v13);
	cuadrado.push_back(v14);
	cuadrado.push_back(v15);
	cuadrado.push_back(v16);

	cuadrado.push_back(v17);
	cuadrado.push_back(v18);
	cuadrado.push_back(v19);
	cuadrado.push_back(v20);

	cuadrado.push_back(v21);
	cuadrado.push_back(v22);
	cuadrado.push_back(v23);
	cuadrado.push_back(v24);

	cuadrado.push_back(v25);
	cuadrado.push_back(v26);
	cuadrado.push_back(v27);
	cuadrado.push_back(v28);

	cuadrado.push_back(v29);
	cuadrado.push_back(v30);
	cuadrado.push_back(v31);
	cuadrado.push_back(v32);

	cuadrado.push_back(v33);
	cuadrado.push_back(v34);
	cuadrado.push_back(v35);
	cuadrado.push_back(v36);

	cuadrado.push_back(v37);
	cuadrado.push_back(v38);
	cuadrado.push_back(v39);
	cuadrado.push_back(v40);

	cuadrado.push_back(v41);
	cuadrado.push_back(v42);
	cuadrado.push_back(v43);
	cuadrado.push_back(v44);

	cuadrado.push_back(v45);
	cuadrado.push_back(v46);
	cuadrado.push_back(v47);
	cuadrado.push_back(v48);

	cuadrado.push_back(v49);
	cuadrado.push_back(v50);
	cuadrado.push_back(v51);
	cuadrado.push_back(v52);

	cuadrado.push_back(v53);
	cuadrado.push_back(v54);
	cuadrado.push_back(v55);
	cuadrado.push_back(v56);

	cuadrado.push_back(v57);
	cuadrado.push_back(v58);
	cuadrado.push_back(v59);
	cuadrado.push_back(v60);

	cuadrado.push_back(v61);
	cuadrado.push_back(v62);
	cuadrado.push_back(v63);
	cuadrado.push_back(v64);

	cuadrado.push_back(v65);
	cuadrado.push_back(v66);
	cuadrado.push_back(v67);
	cuadrado.push_back(v68);
}

void inicializarArboles() {
	Vertice v1 = {
		vec3(-1.0f,0.5f,0.0f),
		vec4(0.2f,0.8f,0.2f,1.0f)
	};
	Vertice v2 = {
		vec3(1.0f,0.5f,0.0f),
		vec4(0.2f,0.8f,0.2f,1.0f)
	};
	Vertice v3 = {
		vec3(1.0f,-1.0f,0.0f),
		vec4(0.2f,0.8f,0.2f,1.0f)
	};
	Vertice v4 = {
		vec3(-1.0f, -1.0f, 0.0f),
		vec4(0.2f,0.8f,0.2f,1.0f)
	};
	arboles.push_back(v1);
	arboles.push_back(v2);
	arboles.push_back(v3);
	arboles.push_back(v4);
}

void inicializarSuelo() {
	Vertice v1 = {
		vec3(-1.0f,-0.5f,0.0f),
		vec4(pisoPasto_R,pisoPasto_G,pisoPasto_B,1.0f)
	};
	Vertice v2 = {
		vec3(1.0f,-0.5f,0.0f),
		vec4(pisoTierra_R,pisoTierra_G,pisoTierra_B,1.0f)
	};
	Vertice v3 = {
		vec3(1.0f,-1.0f,0.0f),
		vec4(pisoTierra_R,pisoTierra_G,pisoTierra_B,1.0f)
	};
	Vertice v4 = {
	vec3(-1.0f,-1.0f,0.0f),
	vec4(pisoPasto_R,pisoPasto_G,pisoPasto_B,1.0f)
	};

	suelo.push_back(v1);
	suelo.push_back(v2);
	suelo.push_back(v3);
	suelo.push_back(v4);
}

void dibujar() {
	//Elegir shader
	shader->enlazar();
	//Elegir el vertex array
	glBindVertexArray(vertexArrayArbolesID);
	//Dibujar
	glDrawArrays(GL_QUADS, 0, arboles.size());
	//Proceso dibujo de Cuadrado
	glBindVertexArray(vertexArrayCuadradoID);
	glDrawArrays(GL_QUADS, 0, cuadrado.size());

	glBindVertexArray(vertexArraySueloID);
	glDrawArrays(GL_QUADS, 0, suelo.size());
	//Soltar vertex array
	glBindVertexArray(0);
	//Desenlazar shader
	shader->desenlazar();

}

int main()
{
	//Declarar una ventana
	GLFWwindow* window;

	//Si no se pudo iniciar GLFW
	//Terminamos la ejecución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//Inicializamos la ventana
	window = glfwCreateWindow(600, 600, "Ventana", NULL, NULL);

	//Si no se pudo crear la ventana
	//Terminamos la ejecución
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos la ventana como contexto
	glfwMakeContextCurrent(window);
	//una vez establecido el contexto
	//se activan las funciones "modernas" (gpu)
	glewExperimental = true;

	GLenum errores = glewInit();
	if (errores != GLEW_OK) {
		glewGetErrorString(errores);
	}

	const GLubyte* versionGL = glGetString(GL_VERSION);
	cout << "Version OpenGL: " << versionGL;

	inicializarArboles();
	inicializarPiramide();
	inicializarSuelo();

	const char* rutaVertexShader = "VertexShader.shader";
	const char* rutaFragmentShader = "FragmentShader.shader";
	shader = new Shader(rutaVertexShader,rutaFragmentShader);
	//Mapeo de atributos
	posicionID = glGetAttribLocation(shader->getID(), "posicion");
	colorID = glGetAttribLocation(shader->getID(), "color");

	shader->desenlazar();

	glGenVertexArrays(1, &vertexArrayArbolesID);
	glBindVertexArray(vertexArrayArbolesID);
	glGenBuffers(1, &bufferArbolesID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferArbolesID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * arboles.size(), arboles.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));

	//Proceso de inicializar Vertex Array para el cuadrado
	glGenVertexArrays(1, &vertexArrayCuadradoID);
	glBindVertexArray(vertexArrayCuadradoID);
	glGenBuffers(1, &bufferCuadradoID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferCuadradoID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * cuadrado.size(), cuadrado.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	//Suelo
	glGenVertexArrays(1, &vertexArraySueloID);
	glBindVertexArray(vertexArraySueloID);
	glGenBuffers(1, &bufferSueloID);
	glBindBuffer(GL_ARRAY_BUFFER, bufferSueloID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertice) * suelo.size(), suelo.data(), GL_STATIC_DRAW);
	glEnableVertexAttribArray(posicionID);
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(posicionID, 3, GL_FLOAT, GL_FALSE, sizeof(Vertice), 0);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, sizeof(Vertice), (void*)sizeof(vec3));
	//Soltar el vertex array y el buffer
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Ciclo de dibujo (DrawLoop)
	while (!glfwWindowShouldClose(window)) {
		//Establecer región de dibujo
		glViewport(00, 0, 600, 600);
		//Establecemos el color de borrado
		//Valores RGBA
		glClearColor(0.4f, 0.643f, 0.945, 1);
		//Borrar
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Actualizar valores y dibujar
		dibujar();
		glfwPollEvents();
		glfwSwapBuffers(window);

	}
	//Después del ciclo de dibujo
	//Eliminamos ventana y procesos de GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

}