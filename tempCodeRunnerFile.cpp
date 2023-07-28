#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "Nodo.cpp"
using namespace std;

//& [TO-DO List]
//! Proyecto hecho por:
//! > Jaiber E. Arellano I.		C.I: 30.338.584
//! > Williangel. A Quevedo V.		C.I: 32.115.376

void agregar();
void eliminar();
void modificar();

Nodo<string>* lista = new Nodo<string>();
bool reversa = false;


int main(){

	cout << "Bienvenido a la To-Do List, basicamente una lista de tareas, a la cual agregar, eliminar, o modificar tareas ya agregadas" << endl;
	cout << "Al mismo tiempo que ver que tareas han sido agregadas, cual es la posterior/anterior y demas" << endl;
	cout << "Hecho Por: " << endl;
	cout << "Jaiber E. Arellano I.		C.I: 30.338.584" << endl;
	cout << "Williangel. A Quevedo V.		C.I: 32.115.376" << endl;
	system("PAUSE");
	system("cls");


	bool exit = false;
	int action = 0;
	while(!exit){
		system("cls");
		cout << setiosflags(ios::left);
		cout << "==================== [Tareas Actuales] ====================" << endl << endl;
		(!reversa) ? lista->listar() : lista->listarReverso();
		cout << endl;
		cout << "==================== [Cant Tareas:"
			<< setw(3) << lista->size
			<< "] ====================" << endl;
		cout << "Pulse una tecla para llevar a cabo la accion: " << endl;
		cout << "1) Agregar Tarea." << endl;
		cout << "2) Modificar Tarea." << endl;
		cout << "3) Eliminar Tarea." << endl;
		cout << "4) Poner en Reversa/Revertir Reversa." << endl;
		cout << "5) Salir del Programa." << endl;
		cout << "Eleccion: ";
		fflush(stdin);
		cin >> action;
		switch(action){
			case 1:
				agregar();
				break;
			case 2:
				modificar();
				break;
			case 3:
				eliminar();
				break;
			case 4:
				reversa = !reversa;
				break;
			case 5:
				cout << "Cerrando ..." << endl;
				system("PAUSE");
				exit = true;
				break;
			default:
				cout << "No una opcion disponible." << endl;
				system("PAUSE");
				break;
		}
	}


	return EXIT_SUCCESS;
}

void agregar(){
	system("cls");
	string txt;
	int action = 0;
	int pos = 0;
	cout << "Que mensaje desea Poner en su tarea?" << endl;
	fflush(stdin);
	getline(cin, txt);


	while(action == 0){
	cout << "De que forma desea agregar la Tarea?" << endl;
	cout << "1) Al Inicio" << endl;
	cout << "2) Despues de [Posicion]" << endl;
	cout << "3) Al Final" << endl;
	fflush(stdin);
	cin >> action;
	if(action == 2){
			cout << "Posicion la desea agregar?" << endl;
			fflush(stdin);
			cin >> pos;
			pos--;
			if(pos > lista->size){
				action = 3;
			}
		}

	switch(action){
		case 1:
			lista->push(lista, txt);
			break;
		case 2:
			lista->insertarDespues(lista, pos, txt);
			break;
		case 3:
			lista->append(lista, txt);
			break;
		default:
			cout << "No una opcion disponible." << endl;
			action = 0;
			system("PAUSE");
			break;
		}
	}
}

void eliminar(){
	system("cls");
	int pos = 0;
	cout << "Posicion Desea Eliminar?" << endl;
	fflush(stdin);
	cin >> pos;
	pos--;
	cout << "now pos: " << pos << endl;
	if(pos > lista->size){
		cout << "Posicion Mayor a la cantida de tareas disponibles ... volviendo al menu" << endl;
		system("PAUSE");
		return;
	}
	lista->deleteNode(lista, pos);
}

void modificar(){
	system("cls");
	string txt;
	int pos = 0;
	cout << "Que Posicion Desea Modificar?" << endl;
	fflush(stdin);
	cin >> pos;
	pos--;
	if(pos > lista->size){
		cout << "Posicion Mayor a la cantida de tareas disponibles ... volviendo al menu" << endl;
		system("PAUSE");
		return;
	}
	cout << "Que mensaje desea Poner en su tarea?" << endl;
	fflush(stdin);
	getline(cin, txt);
	lista->modifyValue(pos, txt);
}
