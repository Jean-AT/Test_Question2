#pragma once
#include <iostream>
using namespace std;

class ExamenEscritos
{
public:
	ExamenEscritos(int f,int c,int p) {
		Fecha = f;
		calificacion = c;
		nroPreguntas = p;
	}
	ExamenEscritos() {
		Fecha = 0;
		calificacion = 0;
		nroPreguntas = 0;
	}
	~ExamenEscritos(){}
	int getFecha() { return Fecha; }
	int getNropreguntas() { return nroPreguntas; }
	int getCalificacion() { return calificacion; }
	void mostrar() {
		cout << "Fecha del Examen: " << Fecha << endl;
		cout << "Calificacion Obtenida: " << calificacion << endl;
	}
private:
	int Fecha;
	int nroPreguntas;
	int calificacion ; //Generar Calificacion con rand
};

class Practicas
{
public:
	Practicas() {
		codigo = 0;
		titulo = "";
		grado = 0;
	}
	Practicas(int c, string t, int g) {
		codigo = c;
		titulo = t;
		grado = g;
	}
	~Practicas(){}
	
	int getCodigo() { return codigo; }
	string getTitulo() { return titulo; }
	int gerGrado() { return grado;}
	
	void mostrar() {
		cout << "Codigo de la Practica: " << codigo << endl;
		cout << "Titulo de la Practica: " << titulo << endl;
		cout << "Grado de la Practica: " << grado << endl;
	}
private:
	int codigo;
	string titulo;
	int grado;
};
