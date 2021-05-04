#include "room.h"
#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>

Room::Room(){
    row = 0;
    col = 0;
}
Room::Room(int walls[4]){
    for(int i = 0; i < 4; i++){
        this->walls[i] = walls[i];
    }
}
//create room from encoded int
Room::Room(int encode){
    for(int i = 0; i < 4; i++){
        int num = pow(2, (3-i));
        if((encode & num) != 0){
            walls[i] = 1;
        }else{
            walls[i] = 2;
        }
    }
}

int Room::encode(){
    int encode = 0;
    for(int i = 0; i < 4; i++){
        if(walls[i] != 2){
            encode += pow(2,(3-i)) * walls[i];
        }
    }
    return encode;
}

void Room::encodeToFile(Room rooms[10][25], int size1, int size2){
    std::ofstream myfile;
    myfile.open("maze.txt");
    myfile << std::hex;
    std::cout << std::endl << std::hex;
    for(int i = 0; i < size1; i ++){
        for(int j = 0; j < size2; j++){
            myfile << rooms[i][j].encode();
            std::cout << rooms[i][j].encode();
        }
    }
    std::cout << std::endl;
    myfile.close();
}

int* Room::decode(char hex){
    int encode;
    std::stringstream ss;
    ss << std::hex << hex;
    ss >> std::dec >> encode;
    int nums[4];
    for(int i = 0; i < 4; i++){
        int num = pow(2, (3-i));
        if(encode & num != 0){
            nums[i] = 1;
        }else{
            nums[i] = 2;
        }
    }
    return nums;
}