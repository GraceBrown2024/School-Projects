/*
Name        : Grace Brown
Last Edited : October 19 2026
File Name   : LinkedList.h
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Track.h"
#include <list>
#include <string>
using namespace std;

class LinkedList{
    private:
        struct Node{
           Track song;
           Node *next; 
        };
        Node *head;
        Node *tail;
    public:
        LinkedList(){   //default constructor 
            head = NULL;
            tail = NULL;
        }
        void appendNode(Track song){  //
            Node *newNode;  // To point to a new node

            // Allocate a new node and store num there.
            newNode = new Node;
            newNode->song = song;
            newNode->next = NULL;

            if (!head ){
                head = newNode; //newNode set as head if there is no nodes
                tail = newNode;
            }
            else{  // Otherwise, insert newNode at end.
            
                //sets the current node as newNode
                tail->next = newNode;
                
                //tail is the new node
                tail = newNode;
            }
        }

        void displayNode(int pos){
            Node *nodePtr;
            if(!head){
                cout << "No songs in the list!\n";
                return;
            }
            else{
                nodePtr = head;
                int currentPos = 0;
                while(nodePtr != NULL && pos >= currentPos){
                    if(pos == currentPos)
                        cout << nodePtr->song << "\n";
                    currentPos++;
                    nodePtr = nodePtr->next;				
                }
            }
            return;
        }

        int getLength(){
            int counter = 0;
            Node *nodePtr;

            nodePtr = head;

            while(nodePtr != tail){
                counter++;
                nodePtr = nodePtr->next;
                if (nodePtr == tail)
                    counter++;
            }
            return counter;
        }

        ~LinkedList(){
            Node *nodePtr;   // To traverse the list
            Node *nextNode;  // To point to the next node
            int numDeleted = 0;

            cout << "\nRemoving all remaining Songs...\n";
            // Position nodePtr at the head of the list.
            nodePtr = head;

            // While nodePtr is not at the end of the list...
            while (nodePtr != NULL){
                // Save the address of the next node.
                nextNode = nodePtr->next;
                delete nodePtr;

                // Position nodePtr at the next node.
                nodePtr = nextNode;
                numDeleted++;
            }
            cout << numDeleted << " songs deleted!\n";
        }


};

#endif