#include "pch.h"
#include "design.h"
#include "optionsHndler.h"
int main(void) {
	int option;

	

	do {
		openScreen();
		option = options();
		HandleOptions(option);
		system("cls");
	} while (option != -1);

	return 0;
}