#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstdlib>
#include <boost/multiprecision/cpp_int.hpp>
using namespace boost::multiprecision;

typedef struct NODE *address;
typedef struct NODECHAR *address_char;

typedef struct NODE
{
    cpp_int data;
    address next;
}tNODE;

typedef struct NODECHAR {
    char data;
    address_char next;
}tNODECHAR;

// working with encrypted data
address alocate(cpp_int data){
    address newNode = (address) malloc(sizeof(tNODE));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNode(address newNode, address *head){

    if(*head == NULL){
        //insert first
        *head = newNode;
    } else {
        address tempHead = *head;

        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        }

        tempHead->next = newNode;
    }
}


// working with char dynamic array (linked list)
address_char alocateChar(char data){
    address_char newNode = (address_char) malloc(sizeof(tNODECHAR));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertNodeChar(address_char newNode, address_char *head){

    if(*head == NULL){
        //insert first
        *head = newNode;
    } else {
        address_char tempHead = *head;
        
        while(tempHead->next != NULL){
            tempHead = tempHead->next;
        }

        tempHead->next = newNode;
    }
}


template <typename TypeAddress> void clearLinkedList(TypeAddress *head){

    if(*head != NULL){
        TypeAddress next = (*head)->next;
        free(*head);
        clearLinkedList(&next);
    }
}

template <typename TypeAddress> void printLinkedList(TypeAddress head){
    TypeAddress tempHead = head;

    while(tempHead != NULL){
        std::cout << tempHead->data << std::endl;

        tempHead = tempHead->next;
    }
}

#endif