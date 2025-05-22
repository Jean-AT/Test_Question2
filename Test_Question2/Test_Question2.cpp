#include <iostream>
#include "Pruebas.h"
#include "Alumnos.h"
#include "Lista.h"
#define MAX_NAME_LEN 60

Lista<ExamenEscritos*>* Exam_List = new Lista<ExamenEscritos*>();
Lista<Practicas*>* Pc_List = new Lista<Practicas*>();
Lista<Alumnos*>* Alum_List = new Lista<Alumnos*>();

int menu() {
	int op;
	cout << "1.Agregar Alumno\n";
	cout << "2.Examen con Menores Preguntas Divisibles por 3\n";
	cout << "3.Practica Mayor Dificultad Multiplo de 5\n";
	cout << "4.Registrar Examen\n";
	cout << "5.Registrar Practica\n";
	cout << "6.Salir\n";
	cin >> op;
	return op;
}

void agregarAlumno(int i) {
	string nombre;
	int mat;
	char gru;
	cout << "Ingrese su nombre completo: "; cin >> nombre;
	cout << "Ingrese su numero de matricula: "; cin >> mat;
	cout << "Ingrese el grupo(A,B,C): "; cin >> gru;

	Alumnos* nuevo = new Alumnos(mat, nombre, gru);
	Alum_List->agregaPos(nuevo, i);
}

void agregarExamen(int i) {
	int fecha, nroDepreguntas, calificacion;
	cout << "Ingrese la fecha(DDMMAÑO): "; cin >> fecha;
	cout << "Ingrese el numero de preguntas : "; cin >> nroDepreguntas;
	cout << "Ingrese la calificacion: "; cin >> calificacion;
	ExamenEscritos* nuevo = new ExamenEscritos(fecha, calificacion, nroDepreguntas);
	Exam_List->agregaPos(nuevo, i);
}

void agregarPractica(int i) {
	int codigo, grado;
	string titulo;

	cout << "Ingrese el codigo de la PC: "; cin >> codigo;
	cout << "Ingrese el grado de la PC:"; cin >> grado;
	cout << "Ingrese el titulo de la PC: "; cin >> titulo;
	Practicas* nuevo = new Practicas(codigo, titulo, grado);
	Pc_List->agregaPos(nuevo, i);
}

void practicaMayorDificultadMultiplode5() {
	for (int i = 0; i < Pc_List->longitud(); i++)
	{
		if (Pc_List->obtenerPos(i)->gerGrado() % 5 == 0) {
			cout << "La practica con mayor dificultad multiplo de 5 es : " << Pc_List->obtenerPos(i)->gerGrado() << endl;
		}
	}
}

void examenMenorCantidadPreguntasDivisiblespor3() {
	for (int i = 0; i < Exam_List->longitud(); i++)
	{
		if (Exam_List->obtenerPos(i)->getNropreguntas() % 3 == 0) {
			cout << "El menor numero de preguntas divisibles por 3 son: " << Exam_List->obtenerPos(i)->getNropreguntas() << endl;
		}
	}
}
int main()
{
	int nroAlum = 0;
	int nroExam = 0;
	int nroPc = 0;
	while (true)
	{
		int opcion = menu();
		switch (opcion)
		{
		case 1:
			agregarAlumno(nroAlum);
			nroAlum++;
			break;
		case 2:
			examenMenorCantidadPreguntasDivisiblespor3();
			break;
		case 3:
			practicaMayorDificultadMultiplode5();
			break;
		case 4:
			agregarExamen(nroExam);
			nroExam++;
			break;
		case 5:
			agregarPractica(nroPc);
			nroPc++;
			break;
		case 6:
			exit(0);
			break;
		default:
			break;
		}
	}
}
