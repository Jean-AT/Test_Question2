#pragma once
#include <iostream>
using namespace std;

class Alumnos
{
public:
	Alumnos() {
		Matricula = 0;
		nombreCompleto = "";
		Grupo = ' ';
	}
	Alumnos(int m, string nmbre, char g) {
		Matricula = m;
		nombreCompleto = nmbre;
		Grupo = g;
	}
	~Alumnos(){}

	int getMatricula() { return Matricula; }
	string getNombre() { return nombreCompleto; }
	char getGrupo() { return Grupo; }
	void mostrar() {
		cout << "Nombre: " << nombreCompleto << endl;
		cout << "Nro De Matricula: " << Matricula << endl;
		cout << "Grupo: " << Grupo << endl;
	}
private:
	int Matricula;
	string nombreCompleto;
	char Grupo;
};