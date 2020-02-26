#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Node.hpp"

template <class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList &obj);

    ~LinkedList();

    Node<T> *getFirstNode() const;
    int getNumberOfNodes();
    bool isEmpty();

    void insertAtTheFront(const T &data);
    void insertAtTheEnd(const T &data);
    void insertAfterGivenNode(const T &data, Node<T> *prev);

    void removeNode(Node<T> *node);
    void removeAllNodes();

    Node<T> *findNode(const T &data);

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void printAllNodes();

    LinkedList &operator=(const LinkedList &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *head;
    Node<T> *tail;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */

    head = NULL;
    tail = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList &obj) {
    /* TODO */
	head = new Node<T>(T(), NULL, NULL);

	*this = obj;

}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */

    while (head)
    	removeAllNodes();
}

template<class T>
Node<T> * LinkedList<T>::getFirstNode() const {
    /* TODO */
    if (head == NULL && tail == NULL) 
    	return NULL;   
    else 
    	return head;
    
}

template<class T>
int LinkedList<T>::getNumberOfNodes() {
    /* TODO */

    int i = 0;

    Node<T> *current = head;
    
    while (current) {
        i++;    
        current = current -> next;
    }

    return i;
}

template<class T>
bool LinkedList<T>::isEmpty() {
    /* TODO */

    if (head == NULL && tail == NULL) 
    	return true;
    else 
    	return false;
    
}

template<class T>
void LinkedList<T>::insertAtTheFront(const T &data) {
    /* TODO */
    if (head == NULL && tail == NULL) {
    	head = new Node<T>(data, NULL, NULL);
    	tail = head;
    }
    else {
    	head = new Node<T>(data, NULL, head);
    	head -> next -> prev = head;
    }
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    if (head == NULL && tail == NULL) {
    	head = new Node<T>(data, NULL, NULL);
    	tail = head;
    }
    else {
    	Node<T> *current = head;
    	while (current -> next != NULL) {
    		current = current -> next;
    	}
    	tail = new Node<T>(data, current, NULL);
    	current -> next = tail;
    }

}

template<class T>
void LinkedList<T>::insertAfterGivenNode(const T &data, Node<T> *prev) {
    /* TODO */

    Node<T> *gez = head;

    while (gez != prev && gez != NULL) {
        gez = gez -> next;
    }

    if (gez == NULL) {
        return ;
    }

    else if (gez -> next == NULL) {
    	Node<T> *new_node = new Node<T>(data, gez, NULL);
    	gez -> next = new_node;
    	tail = new_node;
    }
    else {
        Node<T> *new_node = new Node<T>(data, gez, gez -> next);
        new_node -> prev -> next = new_node;
        new_node -> next -> prev = new_node;
    }
    
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node) {
    /* TODO */

    if (head == NULL || tail == NULL)
    	return;

	else if (head == node) {

		Node<T> *temp = head;
		if (head -> next == NULL && head -> prev == NULL) {
			delete temp;
			head = NULL;
			tail = NULL;
		}
		else {
			head = head -> next;
			head -> prev = NULL;
			delete temp;
		}		

	}
	else if (tail == node) {

		Node <T> *temp = tail;
		tail = tail -> prev;
		tail -> next = NULL;
		delete temp;

	}
	else if (node != head && node != tail) {

    	Node<T> *gez = head;

    	while (gez -> next != node) {
    		gez = gez -> next;
    	}

    	Node<T> *temp = gez -> next;
    	gez -> next = temp -> next;
    	temp -> next -> prev = gez;
    	delete temp;
    }
    else
    	return;
}

template<class T>
void LinkedList<T>::removeAllNodes() {
    /* TODO */
    if (head == NULL && tail == NULL) {
		return ;
	}
	else {
    	while (head != NULL) {
    		Node<T> *tmp = head;
    		head = head -> next;
    		delete tmp;
    	}
	}

	tail = NULL;

}

template<class T>
Node<T> * LinkedList<T>::findNode(const T &data) {
    /* TODO */

    Node<T> *gez = head;

    if (gez == NULL)
        return NULL;
 
    while (gez != NULL && gez -> element != data) {
    	gez = gez -> next;
    }

    if (gez == tail -> next)
        return NULL;
    else
        return gez;
    
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    /* TODO */
    Node<T> *gez1 = head;
    Node<T> *gez2 = head;
    
    while (gez1 != NULL && gez1 != node1) {
    	gez1 = gez1 -> next;
    }

    while (gez2 != NULL && gez2 != node2) {
    	gez2 = gez2 -> next;
    }

    if (gez1 == NULL || gez2 == NULL || gez1 == gez2) {
    	return ;
    }
    if (gez1 -> prev == NULL && gez2 -> next == NULL) {
 		gez1 -> next -> prev = gez2;
 		gez2 -> prev -> next = gez1;

 		Node<T> *temp = gez2 -> next;

 		gez2 -> next = gez1 -> next;
 		gez1 -> next = temp;

 		temp = gez2 -> prev;
 		gez2 -> prev = gez1 -> prev;
 		gez1 -> prev = temp;
 		head = gez2;
 		tail = gez1; 

    }
    else if (gez2 -> prev == NULL && gez1 -> next == NULL) {
    	gez1 -> prev -> next = gez2;

 		gez2 -> next -> prev = gez1;

 		Node<T> *temp = gez2 -> next;

 		gez2 -> next = gez1 -> next;
 		gez1 -> next = temp;

 		temp = gez2 -> prev;
 		gez2 -> prev = gez1 -> prev;
 		gez1 -> prev = temp;
 		head = gez1;
 		tail = gez2; 

    }
    else if (gez1 -> prev == NULL && gez1 -> next != NULL && gez2 -> prev != NULL && gez2 -> next != NULL) { /* gez1 head, gez2 içeri */
    	
        if (gez1 -> next == gez2) {

            gez2 -> prev = gez1 -> prev;
            gez2 -> next -> prev = gez1;
            gez1 -> next = gez2 -> next;

            gez2 -> next = gez1;

            gez1 -> prev = gez2;
            head = gez2;

        }
        else {
    		gez1 -> next -> prev = gez2;
     		gez2 -> prev -> next = gez1;
     		gez2 -> next -> prev = gez1;
        
        	Node<T> *temp = gez2 -> next;

     		gez2 -> next = gez1 -> next;
     		gez1 -> next = temp;

     		temp = gez2 -> prev;
     		gez2 -> prev = NULL;
     		gez1 -> prev = temp; 
     		head = gez2;
        }
    		
    }
    else if (gez2 -> prev == NULL && gez2 -> next != NULL && gez1 -> prev != NULL && gez1 -> next != NULL) {

 		gez1 -> prev -> next = gez2;
 		gez1 -> next -> prev = gez2;
 		gez2 -> next -> prev = gez1;

 		Node<T> *temp = gez2 -> next;

 		gez2 -> next = gez1 -> next;
 		gez1 -> next = temp;

 		temp = gez2 -> prev;
 		gez2 -> prev = gez1 -> prev;
 		gez1 -> prev = NULL;
 		head = gez1;   	
    }

    else if (gez1 -> next == NULL && gez1 -> prev != NULL && gez2 -> prev != NULL && gez2 -> next != NULL) {

 		gez1 -> prev -> next = gez2;
 		gez2 -> prev -> next = gez1;
 		gez2 -> next -> prev = gez1;

 		Node<T> *temp = gez2 -> next;

 		gez2 -> next = gez1 -> next;
 		gez1 -> next = temp;

 		temp = gez2 -> prev;
 		gez2 -> prev = gez1 -> prev;
 		gez1 -> prev = temp; 
 		tail = gez2;

    }
    else if (gez1 -> next != NULL && gez1 -> prev != NULL && gez2 -> next == NULL && gez2 -> prev != NULL) { /*gez2 tail, gez1 içeri*/ 

        if (gez1 -> next == gez2) {

            gez1 -> prev -> next = gez2;
            gez2 -> prev = gez1 -> prev;
            gez1 -> next = gez2 -> next;

            gez2 -> next = gez1;

            gez1 -> prev = gez2; 
            tail = gez1;

        }
        else {
     		gez1 -> prev -> next = gez2;
     		gez1 -> next -> prev = gez2;

     		gez2 -> prev -> next = gez1;

     		Node<T> *temp = gez2 -> next;

     		gez2 -> next = gez1 -> next;
     		gez1 -> next = temp;

     		temp = gez2 -> prev;
     		gez2 -> prev = gez1 -> prev;
     		gez1 -> prev = temp;  
     		tail = gez1;   	
        }
    }

    else {

        if (gez1 -> next == gez2) {

            gez1 -> prev -> next = gez2;
            gez2 -> prev = gez1 -> prev;
            gez2 -> next -> prev = gez1;
            gez1 -> next = gez2 -> next;

            gez2 -> next = gez1;

            gez1 -> prev = gez2; 

        }
        else {
     		gez1 -> prev -> next = gez2;
     		gez1 -> next -> prev = gez2;
     		gez2 -> prev -> next = gez1;
     		gez2 -> next -> prev = gez1;

     		Node<T> *temp = gez2 -> next;

     		gez2 -> next = gez1 -> next;
     		gez1 -> next = temp;

     		temp = gez2 -> prev;
     		gez2 -> prev = gez1 -> prev;
     		gez1 -> prev = temp; 
        }
    } 

}

template<class T>
void LinkedList<T>::printAllNodes() {
    /* TODO */
    if (head == NULL && tail == NULL) {
    	return;
    }
    else {
    	Node<T> *current = head;
    	while (current != NULL) {
    		std::cout << current -> element << std::endl;
    		current = current -> next; 
    	}
    }
}

template<class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList &rhs) {
    /* TODO */
    if (this != &rhs) {
    	removeAllNodes();
    	Node<T> *gez = rhs.head;

    	while (gez != NULL) {
    		insertAtTheEnd(gez -> element);
    		gez = gez -> next;
    	}
    }
    return *this;
}

#endif //LINKED_LIST_HPP
