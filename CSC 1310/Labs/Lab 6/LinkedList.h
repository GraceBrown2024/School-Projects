/*
Name        : Grace Brown
Last Edited : October 19 2026
File Name   : Track.h
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "Track.h"
#include <list>

class LinkedList{
    private:
        struct Node{
           Track song;
           Node *next; 
        };
        Node *head;
        Node *tail;
    public:
        

};

#endif