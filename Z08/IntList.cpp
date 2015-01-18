#include "IntList.h"
#include <iostream>

IntList::IntList() {
    this->count = 0;
    this->first = 0;
};

IntList::IntList(const IntList &other) {
    this->count = 0;
    this->first = 0;

    IntListElem *el;
    el = other.first;
    while (el) {
        this->insert(el->value, -1);
        el = el->next;
    }
};

IntList &IntList::operator=(const IntList &other) {
    if (this != &other) {
        while (this->getCount()) {
            this->remove(0);
        }

        IntListElem *el;
        el = other.first;
        while (el) {
            this->insert(el->value, -1);
            el = el->next;
        }
    }
    return *this;
};

IntList::~IntList() {
    if (this->getCount() > 0 && this->first != 0) {
        IntListElem *cur = this->first;
        IntListElem *next = cur->next;
        while (next) {
            cur->value = 0;
            delete cur;
            cur = next;
            next = cur->next;
        }
    }
};

int IntList::getCount() {
    return this->count;
};

bool IntList::isEmpty() {
    return this->getCount() > 0;
};


void IntList::print() {
    if (this->getCount()) {
        IntListElem *el = this->first;
        std::cout << "[" << el->value;
        el = el->next;
        while (el) {
            std::cout << "," << el->value;
            el = el->next;
        }
        std::cout << "]" << std::endl;
    } else {
        std::cout << "empty list" << std::endl;
    }
};

void IntList::insert(int element, int position) {
    if (position > 0 && position < this->getCount()) {
        IntListElem *elmToMod = this->first;
        for (int i = 0; i < position; i++) {
            elmToMod = elmToMod->next;
        }
        elmToMod->value = element;
    } else if (position == this->getCount()) {
        IntListElem *elmToInsert = new IntListElem;
        elmToInsert->value = element;
        elmToInsert->next = 0;
        IntListElem *elmAfter = this->first;
        if (position == 0) {
            this->first = elmToInsert;
        } else {
            while (elmAfter->next) {
                elmAfter = elmAfter->next;
            }
            elmAfter->next = elmToInsert;
        }
        this->count++;
    } else if (position == -1) {
        this->insert(element, this->getCount());
    }
};

void IntList::remove(int position) {
    IntListElem *elToDel, *elPrev;
    elToDel = findElement(position);
    if (position == 0) {
        if (elToDel) {
            this->first = elToDel->next;
            this->count--;
        }
    } else if (position > 0 && position < this->getCount()) {

        findElement(position - 1)->next = elToDel->next;
        this->count--;
    }
    delete elToDel;

};

int IntList::getElement(int position) {
    IntListElem *el = findElement(position);
    return el ? el->value : 0;
};

IntList::IntListElem *IntList::findElement(int position) {
    IntListElem *el = this->first;
    for (int i = 0; i < position && el; i++) {
        el = el->next;
    }
    return el;
};
