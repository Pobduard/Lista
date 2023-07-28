#ifndef NODO
#define NODO
#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
class Nodo{
	private:
		Nodo<T>* siguiente = NULL;
		Nodo<T>* anterior = NULL;
	public:
		static int size;
		static Nodo<T>* start;
		static Nodo<T>* end;
		T value;
		Nodo(){};
		Nodo(T value){append(value);};
		~Nodo(){};
		Nodo<T>* getNodeAt(int index);
		T getValueAt(int index);
		void append(T value);
		void append(Nodo<T> *&head, T value);
		void insertarDespues(Nodo<T>*& node,int index, T value);
		void insertarDespues(Nodo<T> *&prev_node, T value);
		void push(Nodo<T> *&head, T value);
		void deleteNode(Nodo<T> *&head, int position);
		void listar();
		void listarDesde(Nodo<T> *lista);
		void listarReverso();
		void listarReversoDesde(Nodo<T> *lista);
		void modifyValue(int index, T new_value);
		//& Retorna el tamano de toda la lista, sin contar el 0 de programacion
		int getSize(){return size;}
/* 		//! Eliminar estas funciones:
		void deleteNode(int position);
		void add(T value);
		void add(Nodo<T> *&nodo);
		void deleteThis(Nodo<T> *arr);
		void show(Nodo<T> *arr, int index); */
};

template <typename T>
//& Cantidad total de Elementos
int Nodo<T>::size = 0;

template <typename T>
//& 1er Elemento de toda la lista
Nodo<T>* Nodo<T>::start = NULL;

template <typename T>
//& Ultimo elemento de toda la lista
Nodo<T>* Nodo<T>::end = NULL;

template <typename T>
//& Retorna el NODO en la posicion pasada
Nodo<T>* Nodo<T>::getNodeAt(int index){
	Nodo<T>* temp = new Nodo<T>();
	temp = this;

	for(int i = 0; temp != NULL && i < (index); i++){	//& Mientras que no sea nulo y que ademas no pase el limite
		temp = temp->siguiente;
	};

	//& al salir del for, deberiamos de tener el valor que deseamos, por lo tanto retornamos
	return temp;
};

template <typename T>
//& Retorna el Valor del nodo en la posicion pasada
T Nodo<T>::getValueAt(int index){
	Nodo<T>* temp = new Nodo<T>();
	temp = this;

	for(int i = 0; temp != NULL && i < (index); i++){	//& Mientras que no sea nulo y que ademas no pase el limite
		temp = temp->siguiente;
	};

	//& al salir del for, deberiamos de tener el valor que deseamos, por lo tanto retornamos
	return temp->value;
};

template <typename T>
//& Añade dato al final de la lista
void Nodo<T>::append(T value){
	Nodo<T>* new_node = new Nodo<T>();		//& Nuevo a añadir
	Nodo<T>* head = this;					//& Para iterar despues sin modificar el valor original
	Nodo<T>* last = head;					//& Para iterar despues sin modificar el valor original

	//& Datos del nuevo a añadir
	new_node->value = value;
	new_node->siguiente = NULL;

	//& Si estaba vacio, osea se acabo de crear la lista, le vamos a poner valor al 1er elemento
	if(head == NULL){
		cout << "Lista Completamente vacia, llenamos el [0] elemento" << endl;
		head = new_node;
		size++;
		return;
	}

	//& Si estaba vacio, osea se acabo de crear la lista, le vamos a poner valor al 1er elemento
	if(head->siguiente == NULL){
		cout << "Lista estaba vacia, llenamos el 1er elemento" << endl;
		head->siguiente = new_node;
		new_node->anterior = head;
		size++;
		return;
	}



	while(last->siguiente != NULL){	//& s el puntero es igual a NULL, salimos
		//& Buscamos hasta que encontremos el nodo final, osease, el que apunta a NULL
		last = last->siguiente;		//& Vamos cambiando el puntero constantemente
	}

	last->siguiente = new_node;	//& Añadimos en la pos final el nuevo nodo
	new_node->anterior = last;
	size++;
	end = new_node;
	return;
};

template <typename T>
//& Añade dato al final de la lista del Nodo que se le envio (cuando el ->siguiente sea == NULL)
void Nodo<T>::append(Nodo<T> *&head, T value){
	Nodo<T>* new_node = new Nodo<T>();		//& Nuevo a añadir
	Nodo<T>* last = head;					//& Para iterar despues sin modificar el valor original

	//& Datos del nuevo a añadir
	new_node->value = value;
	new_node->siguiente = NULL;

	//& Si estaba vacio, osea se acabo de crear la lista, le vamos a poner valor al 1er elemento
	if(head == NULL){
		cout << "Lista (Append de Nodo) Completamente vacia, llenamos el [0] elemento" << endl;
		head = new_node;
		size++;
		return;
	}

	//& Si estaba vacio, osea se acabo de crear la lista, le vamos a poner valor al 1er elemento
	if(head->siguiente == NULL){
		head->siguiente = new_node;
		new_node->anterior = head;
		cout << "Lista(Append de Nodo) estaba vacia, llenamos el 1er elemento" << endl;
		size++;
		return;
	}


	while(last->siguiente != NULL){
		//& Buscamos hasta que encontremos el nodo final, osease, el que apunta a NULL
		last = last->siguiente;		//& Vamos cambiando el puntero constantemente
	}

	last->siguiente = new_node;	//& Añadimos en la pos final el nuevo nodo
	new_node->anterior = last;

	if(size == 0){
		start = new_node;
		new_node->anterior = NULL;
		}
	size++;
	end = new_node;
	return;
};

template <typename T>
//& Añade dato despues de la posicion pasada
void Nodo<T>::insertarDespues(Nodo<T>*& node, int index, T value){
	Nodo<T>* prev_node = new Nodo<T>();
	prev_node = start;

	if(index >= size){
		append(node, value);
	}

	for(int i = 0; prev_node != NULL && i < (index); i++){	//& Mientras que no sea nulo y que ademas no pase el limite
		prev_node = prev_node->siguiente;
	};

	if(prev_node == NULL){
		cout << "El Nodo no existe, ya que es Nulo" << endl;
		return;
	}


	Nodo<T>* new_node = new Nodo<T>();		//& Nuevo a añadir
	//& Datos del nuevo a añadir
	new_node->value = value;

	Nodo<T>* next_node = prev_node->siguiente;		//& Nuevo a añadir

	//& hacemos que el anterior apunte al nuevo
	prev_node->siguiente = new_node;
	new_node->anterior = prev_node;

	//& Metemos el nodo nuevo a apuntar lo mismo que el anterior
	new_node->siguiente = next_node;
	next_node->anterior = new_node;
	size++;
};

template <typename T>
//& Añade dato despues del nodo pasado
void Nodo<T>::insertarDespues(Nodo<T> *&prev_node, T value){

	if(prev_node == NULL){
		cout << "El Nodo no existe, ya que es Nulo" << endl;
		return;
	}

	if(prev_node == end){
		append(prev_node, value);
	}

	Nodo<T>* new_node = new Nodo<T>();		//& Nuevo a añadir
	//& Datos del nuevo a añadir
	new_node->value = value;

	Nodo<T>* next_node = prev_node->siguiente;		//& Nuevo a añadir

	//& Metemos el nodo nurvo a apuntar lo mismo que el anterior
	new_node->siguiente = next_node;
	next_node->anterior = new_node;

	//& hacemos que el anterior apunte al nuevo
	prev_node->siguiente = new_node;
	new_node->anterior = prev_node;
	size++;
};

template <typename T>
//& Añade dato al inicio de la lista
void Nodo<T>::push(Nodo<T> *&head, T value){
	Nodo<T>* new_node = new Nodo<T>();		//& Nuevo a añadir

	//& Datos del nuevo a añadir
	new_node->value = value;

	//& Metemos el nodo nuevo a apuntar lo que era la cabeza/1er valor
	new_node->siguiente = (head);
	new_node->anterior = NULL;
	head->anterior = new_node;

	//& hacemos que la cabeza anterior sea reemplazada por el nuevo
	head = new_node;
	if(size == 0){
		end = new_node;
		head->siguiente = NULL;
		}
	size++;
	start = new_node;
};

template <typename T>
//& Eliminar nodo de la posicion pasada *, partiendo del nodo enviado
void Nodo<T>::deleteNode(Nodo<T> *&head, int position){
	if(head == NULL){	//& Estaba vacia
		cout << "Empty List" << endl;
		return;
	}
	Nodo<T>* temp = head;

	//& Si se desea eliminar la cabeza
	if(position == 0){
		if(size > 1){
			temp = start;
			head = temp->siguiente;		//& Modificamos la cabeza
			head->anterior = NULL;
			start = head;
			cout << "deleted pos 0" << endl;
			size--;
			system("PAUSE");
			delete temp;
			return;
		}
		if(size == 1){
			temp = start;
			temp->siguiente = NULL;
			temp->anterior =NULL;
			start = NULL;
			end = NULL;
			cout << "deleted Head" << endl;
			size--;
			system("PAUSE");
			delete temp;
			return;
		}
		if(size == 0){
			cout << "Already Empty, Nothing to delete" << endl; 
			system("PAUSE");
			return;
			}
	}

	if(position == size){
		cout << "pos=size" << endl;
	}
	if(position == size){
		cout << "pos=size" << endl;
		temp = end->anterior;
		end = temp;
		delete temp->siguiente;
		return;
	}

	//& Buscamos el valor PREVIO al de la posicion que deseamos eliminar
	for(int i = 0; temp !=NULL && i < (position-1); i++){
		temp = temp->siguiente;
	}

	//& Si el valor que buscamos no existia en la lista/array
	if(temp == NULL || temp->siguiente == NULL){
		cout << "no exitia" << endl;
		return;
	}

	//& LLegados a este punto, sabemos que el " temp->siguiente " es el nodo a eliminar
	//& Por ello guardamos sus pointer en la variable anterior (razon de encontrarla)

	//& Guardamos el puntero siguiente, al nodo que vamos a eliminar, para reasignarlo despues
	Nodo<T>* next = temp->siguiente->siguiente;		//& 2 veces el -> para guardar el valor que le sigue, al que deseamos eliminar

	size--;
	delete temp->siguiente;		//& Eliminamos el valor ->siguiente

	temp->siguiente = next; 	//& reasignamos el puntero guardado antes (doble ->), para no romper la lista
	next->anterior = temp;
	if(position == size){
		end = temp;
	}

};

template <typename T>
//& Lista todos los valores de la lista que lo incovo, hasta que se encuentre con "NULL"
void Nodo<T>::listar(){
	Nodo<T>* actual;
	int i = 0;

	actual = start;
	while(actual != NULL){
		i++;
		cout << i << ") " << actual->value << endl;
		actual = actual->siguiente;
	}
};

template <typename T>
//& recibe puntero a un valor, con el objetivo de listar a partir de este mismo
void Nodo<T>::listarDesde(Nodo<T> *lista){
	Nodo<T>* actual;
	actual = lista;
	while (actual != NULL){
		cout << actual->value << endl;
		actual = actual->siguiente;
	}
};

template <typename T>
//& Lista todos los valores de la lista que lo incovo, en reversa, hasta que se encuentre con "NULL"
void Nodo<T>::listarReverso(){
	Nodo<T>* actual;

	actual = end;
	int i = size;

	while (actual != NULL){
		cout << i << ") " << actual->value << endl;
		actual = actual->anterior;
		i--;
	}
};

template <typename T>
//& recibe puntero a un valor, con el objetivo de listar a partir de este mismo, en reversa, hasta que se encuentre con "NULL"
void Nodo<T>::listarReversoDesde(Nodo<T> *lista){
	Nodo<T>* actual;

	actual = lista;
	while (actual != NULL){
		cout << actual->value << endl;
		actual = actual->anterior;
	}
};

template <typename T>
//& Modifica el valor del Nodo que se encuentre en la posicion pasada, con el valor pasado
void Nodo<T>::modifyValue(int index, T new_value){
	Nodo<T>* temp = new Nodo<T>();
	temp = this;

	for(int i = 0; temp != NULL && i < (index); i++){	//& Mientras que no sea nulo y que ademas no pase el limite
		temp = temp->siguiente;
	};

	//& al salir del for, deberiamos de tener el valor que deseamos, por lo tanto cambiamos valor
	temp->value = new_value;
}


/*
template <typename T>
//! Eliminar, ya que no encuentro como hacer que el "this" cambie el valor real de la cabeza/index 0,cuando la pos es 0 pues
//& Eliminar nodo de la posicion pasada *
void Nodo<T>::deleteNode(int position){
	Nodo<T>* head = this;
	if(head == NULL){	//& Estaba vacia
		cout << "Empty List" << endl;
		return;
	}
	Nodo<T>* temp = head;

	//& Si se desea eliminar la cabeza
	if(position == 0){
		this = (temp->siguiente);		//& Modificamos la cabeza
		this->anterior = NULL;
		cout << "deleted Head" << endl;
		size--;
		delete temp;
		return;
	}

	//& Buscamos el valor PREVIO al de la posicion que deseamos eliminar
	for(int i = 0; temp !=NULL && i < (position-1); i++){
		temp = temp->siguiente;
	}

	//& Si el valor que buscamos no existia en la lista/array
	if(temp == NULL || temp->siguiente == NULL){
		return;
	}

	//& LLegados a este punto, sabemos que el " temp->siguiente " es el nodo a eliminar
	//& Por ello guardamos sus pointer en la variable anterior (razon de encontrarla)

	//& Guardamos el puntero siguiente, al nodo que vamos a eliminar, para reasignarlo despues
	Nodo<T>* next = temp->siguiente->siguiente;		//& 2 veces el -> para guardar el valor que le sigue, al que deseamos eliminar

	size--;
	delete temp->siguiente;		//& Eliminamos el valor ->siguiente

	temp->siguiente = next; 	//& reasignamos el puntero guardado antes (doble ->), para no romper la lista
	next->anterior = temp;
};


//! Eliminar
template <typename T>
void Nodo<T>::add(T value){
	this->value = value;
	this->siguiente = NULL;
	this->anterior = NULL;
	size++;
};

//! Eliminar
template <typename T>
void Nodo<T>::add(Nodo<T> *&nodo){
	Nodo<T>* temp = new Nodo<T>();
	temp = this;
	
	while(temp->siguiente != NULL){
		temp = temp->siguiente;
	}

	temp->siguiente = nodo;
	nodo->anterior = temp;
	size++;
};


//! Eliminar
template <typename T>
void Nodo<T>::deleteThis(Nodo<T> *arr){
	Nodo<T>* past = (arr)->anterior;
	Nodo<T>* actual = arr;
	Nodo<T>* next = (arr)->siguiente;
	past->siguiente = next;
	next->anterior = past;
	size--;
	delete actual;
};

//! Eliminar
template <typename T>
void Nodo<T>::show(Nodo<T> *arr, int index){
	Nodo<T>* actual = arr+index;
	cout << actual->value << endl;
};
*/

#endif // !NODO