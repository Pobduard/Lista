#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Nodo.cpp"

using namespace std;
int main(){

	cout << "Try it" << endl;
	Nodo<int>* arr = new Nodo<int>(69);
	arr->listar();
	cout << "Current size == " << arr->getSize() << endl;

	// for(int i = 0; i < 21; i++){
	// 	arr->add(i);
	// }
	
	// arr->listar();
	// cout << "===[0 test of value]===" << endl;
	// cout << arr->siguiente->anterior->value << endl;


	cout << "===[1 Append]===" << endl;
	for (int i = 0; i < 10; i++){
		arr->append(arr, i);
	}
	cout << "Current size == " << arr->getSize() << endl;
	arr->listar();

	// cout << "===[2 Next & Delete]===" << endl;
	// auto newerNext = arr->getNodeAt(3);
	// cout << "Adress(3): "<<newerNext << endl;
	// cout << "Value(3): "<<newerNext->value << endl;
	// cout << "Adress(4): "<<newerNext->siguiente << endl;
	// cout << "Value(4): "<<newerNext->siguiente->value << endl;
	// cout << "deleted value \"" << arr->getValueAt(3) <<"\"" << endl;
	// arr->deleteNode(arr->siguiente->siguiente, 0);
	// cout << "deleted value \"" << arr->getValueAt(3) <<"\"" << endl;
	// arr->deleteNode(3);
	// cout << "Current size after deleteds == " << arr->getSize() << endl;
	// arr->listar();


	cout << "===[3 Anterior]===" << endl;
	// auto newerAnt = arr->getNodeAt(3);
	// cout << "Adress(3): "<<newerAnt << endl;
	// cout << "Value(3): "<<newerAnt->value << endl;
	// cout << "Adress(2): "<<newerAnt->anterior << endl;
	// cout << "Value(2): "<<newerAnt->anterior->value << endl;
	// cout << "Adress(1): "<<newerAnt->anterior->anterior << endl;
	// cout << "Value(1): "<<newerAnt->anterior->anterior->value << endl;
	// arr->listar();
	// cout << "idk: " << arr->getValueAt(2) << endl;
	// auto fixLastLink = arr->getNodeAt(1);
	// auto fixNextLink = arr->getNodeAt(2);
	// fixNextLink->anterior = fixLastLink;
	cout << "Current size on Reverso == " << arr->getSize() << endl;
	auto newerReverso = arr->getNodeAt((arr->getSize()-1));
	newerReverso->listarReverso();


	cout << "\\\\\\\\" << endl;
	arr->deleteNode(0);
	cout << "Current size after deleting head 1 times == " << arr->size << endl;
	auto sizeTest2 = arr->getNodeAt(0);
	cout << "Adress: "<< sizeTest2 << endl;
	cout << "Value: "<< sizeTest2->value << endl;

	arr->deleteNode(0);
	cout << "Current size after deleting head 2 times == " << arr->getSize() << endl;
	sizeTest2 = arr->getNodeAt(0);
	cout << "Adress: "<< sizeTest2 << endl;
	cout << "Value: "<< sizeTest2->value << endl;
	auto sizeTest = arr->getNodeAt(5);
	sizeTest->listarReverso();

	
	// cout << "===[4 Value of '1' & '9' Not Linked]===" << endl;
	// auto newerCheck = arr->getNodeAt(1);
	// cout << "Adress(3): "<<newerCheck << endl;
	// cout << "Value(3): "<<newerCheck->value << endl;
	// cout << "Adress(2): "<<newerCheck->anterior << endl;
	// cout << "Value(2): "<<newerCheck->anterior->value << endl;
	// cout << "Adress(1): "<<newerCheck->anterior->anterior << endl;
	// cout << "Value(1): "<<newerCheck->anterior->anterior->value << endl;
	// arr->listar();

	return 0;
}