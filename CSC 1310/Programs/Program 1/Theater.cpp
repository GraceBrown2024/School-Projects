/*
Name        : Grace Brown
File        : Theater.cpp
Created     : 9/8/2026
Last Updated: 9/8/2026
Purpose     :
*/

#include "Theater.h"

int Theater::getNumMovies(){
    return numMovies;
}
int Theater::getNumShowings(){
    return numShowings;
}
void Theater::addMovie(){
    
}
void Theater::editMovie(){
    if(numMovies == 0){
        cout << "No movies present in your list!";
    }else{
        bool confirm = true;
        int arrayIndex;
        do{
            int x;
            cout << "Which movie would you like to edit?\n";
            for(int i = 0; i < numMovies; i++){
                cout << i+1 << ".) " << movieArray[i]->getTitle() << endl;
            }
            cin >> x;
            while(!cin || (x < 1 || x > numMovies)){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid number: ";
                cin >> x;
            }
            cin.ignore(100, '\n');

        
            char yn;
            cout << "Are you sure you want to edit " << movieArray[x - 1]->getTitle() << "?\n"
                 << "[Y/N]: ";
            cin >> yn;
            yn = toupper(yn);
            while(!cin || (yn != 'Y' && yn != 'N')){
                cin.clear();
                cin.ignore(100, '\n');
                cout << "Please enter a valid answer: ";
                cin >> yn;
                yn = toupper(yn);
            }
            cin.ignore(100, '\n');

            if(yn == 'N'){
                confirm = false;
            }else{
                arrayIndex = x - 1;
            }

        }while(!confirm);

        movieArray[arrayIndex]->editMovie();
        
    }
}
void Theater::addShowing(){

}
void Theater::editShowing(){

}
void Theater::printMovies(){

}
void Theater::printShowings(){

}
void Theater::printMovieNames(){

}
void Theater::printShowingNames(){

}