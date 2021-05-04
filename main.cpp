#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <ctime>
#include "room.h"

using namespace std;

Room rooms[10][25];
void drunkenWalk(int row, int col);
int visited = 0;

int main()
{
    int seed;
    cout << "enter seed: ";
    cin >> seed;
    srand(seed);
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 25; j++){
            rooms[i][j].setCol(j);
            rooms[i][j].setRow(i);
        }
    }
    drunkenWalk(0,0);
    
    // std::cout << "Hello World!";

    Room::encodeToFile(rooms, 10, 25);

    int *foo = Room::decode('a');
    cout << dec << "1: " << foo[0] << endl;
    cout << "2: " << foo[1] << endl;
    cout << "3: " << foo[2] << endl;
    cout << "4: " << foo[3] << endl;

    return 0;
}

template <typename T>
void shuffle_array(T* begin, T* end){
    for(int i = 0; i <= end-begin; i++){
        int num = rand() % (end-begin + 1);
        T temp = *(begin + i);
        *(begin+i) = *(begin+num);
        *(begin+num) = temp;
    }
}



void drunkenWalk(int row, int col){
    visited++;
    // std::cout << "Visited: " << visited << "\n";
    // std::cout << "Row: " << row << "  Col: " << col << "\n";
    Room* r = &rooms[row][col];
    r->setVisited(1);
    // std::cout << "Visited: " << r->getVisited() << "\n";
    int dirs[4] = {0,1,2,3}; // East, West, South, North = 0,1,2,3
    int dir_offsetrow[4] = {0, 0, 1, -1};
    int dir_offsetcol[4] = {1, -1, 0, 0};
    shuffle_array(&dirs[0], &dirs[3]);
    // std::cout <<"Confirm random order: ";
    // std::cout << dirs[0] << dirs[1] << dirs[2] << dirs[3] << "\n";
    for(int i = 0; i < 4; i++){
        int dir = dirs[i];
        if(row + dir_offsetrow[dir] >= 10 || row + dir_offsetrow[dir] < 0
        || col + dir_offsetcol[dir] >= 25 || col + dir_offsetcol[dir] < 0){
            r->changeWall(dir, 1);
        }else{
            Room* neighbor = &rooms[row + dir_offsetrow[dir]]
            [col + dir_offsetcol[dir]];
            
            // std::cout << "Visited Neighbor: " << neighbor->getVisited() << "\n";
            if(neighbor->getVisited() == 0){
                // std::cout << "recurse" << "\n";
                r->changeWall(dir, 2);
                drunkenWalk(neighbor->getRow(), neighbor->getCol());
            }
            else{
                int opposite_dir = (dir >= 2)? dir-2 : dir+2;
                
                if(neighbor->getWall(opposite_dir) != 0){
                    r->changeWall(dir, neighbor->getWall(opposite_dir));
                }else{
                    r->changeWall(dir, 1);
                }
            }
        }
    }
    
}
