#include <stdio.h>
#include <stdlib.h>
#include <iostream>

//Hallo Welt!

typedef struct liste {
	int element;
	liste* next;
	liste* vor;
};

liste* appendback(int element, liste* list) {
	
	if (list == NULL) {
		list = new liste;
		list->next = NULL;
		list->vor = NULL;
		list->element = element;
		return list;
	}
	else {
		liste* hilfsliste = list;
		while (hilfsliste->next != NULL) {
			hilfsliste = hilfsliste->next;
		}
		liste *help = new liste;
		help->element = element;
		help->next = NULL;
		help->vor = hilfsliste;
		hilfsliste->next = help;
	}
	return list;
}

void ausgeben(liste* list) {
	if (list == NULL) {
		std::cout << "Leere liste";
		return;
	}
	int counter = 0;
	liste *help = list;
	while (help != NULL) {
		std::cout << counter << ": " << help->element << std::endl;
		help = help->next;
		counter++;
	}
	
}

liste* appendfront(liste* list, int el) {
	if (list == NULL) {
		list = new liste;
		list->next = NULL;
		list->vor = NULL;
		list->element = el;
		return list;
	}
	liste* neues_element = new liste;
	neues_element->next = list;
	neues_element->vor = NULL;
	neues_element->element = el;
	list->vor = neues_element;
	return neues_element;
}

liste* deleteback(liste* list) {
	if (list == NULL) {
		std::cout << "Leere Liste" << std::endl;
		return NULL;
	}
	if (list->next == NULL) {
		delete list;
		return NULL;
	}
	liste* helper = list;
	while (helper->next->next != NULL) {
		helper = helper->next;
	}
	delete helper->next;
	helper->next = NULL;
	return list;
}
int main(){

	liste *list = NULL;
	
	char eingabe;
	do {
		printf("e: Ende\na: Ausgabe\nu: AppendBack\nk: Appendfront\nb: Deleteback\n");
		std::cin >> eingabe;

		switch (eingabe) {
		case 'a':
		case 'A':
			ausgeben(list);
			break;
		case 'u':
		case 'U':
			int el;
			printf("Zahl eingeben: ");
			std::cin >> el;
			list = appendback(el, list);
			break;
		case 'k':
		case 'K':
			printf("Zahl eingeben: ");
			std::cin >> el;
			list = appendfront(list, el);
			break;
		case 'b':
		case 'B':
			list = deleteback(list);
			break;
		}
	} while (eingabe != 'e' || eingabe != 'e');
	ausgeben(list);

	system("pause");
	return 0;
}