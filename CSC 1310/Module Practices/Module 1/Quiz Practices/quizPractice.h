#ifndef PRACTICE_H
#define PRACTICE_H
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Pickle{
    private:
        int size;
        string color;
        bool tasty;
    public:
        Pickle(){
            size = 4;
            color = "pink";
            tasty = false;
        }
        Pickle(int s, string c, bool t){
            size = s;
            color = c;
            tasty = t;
        }
        void setSize(int s){
            size = s;
        }
        void setColor(string c){
            color = c;
        }
        void setTasty(bool t){
            tasty = t;
        }
        int getSize(){
            return size;
        }
        string getColor(){
            return color;
        }
        bool getTasty(){
            return tasty;
        }
        friend ostream & operator << (ostream &strm, Pickle &a){
            strm << "Hello. My pickle is " << a.size << " inches!" << endl;
            strm << "It is also " << a.color << "." << endl;
            strm << "Here is how BIG my ";
            if(a.tasty == true){
                strm << " TASTY";
            }else{
                strm << " NASTY";
            }
            strm << " pickle is!\n" << 
                 "()()" << endl;

            for(int i = 0; i < a.size; i++){
                strm << " ||\n";
            }
            strm << " U\n";
            return strm;
        }

};


#endif
