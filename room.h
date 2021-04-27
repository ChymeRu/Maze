#include <math.h>
#include <fstream>

class Room{
    public:
        Room(){
            row = 0;
            col = 0;
        }

        Room(int walls[4]){
            for(int i = 0; i < 4; i++){
                this->walls[i] = walls[i];
            }
        }
        //create room from encoded int
        Room(int encode){
            for(int i = 0; i < 4; i++){
                int num = pow(2, (3-i));
                if((encode & num) != 0){
                    walls[i] = 1;
                }else{
                    walls[i] = 2;
                }
            }
        }
        
        int getVisited(){
            return visited;
        }
        void setVisited(int val){
            visited = val;
        }
        int getWall(int dir){
            return walls[dir];
        }
        void changeWall(int dir, int val){
            walls[dir] = val;
        }
        int getRow(){
            return row;
        }
        void setRow(int row){
            this->row = row;
        }
        int getCol(){
            return col;
        }
        void setCol(int col){
            this->col = col;
        }

        int encode(){
            int encode = 0;
            for(int i = 0; i < 4; i++){
                if(walls[i] != 2){
                    encode += pow(2,(3-i)) * walls[i];
                }
            }
            return encode;
        }

        static void encodeToFile(Room rooms[10][25], int size1, int size2){
            std::ofstream myfile;
            myfile.open("maze.txt");
            myfile << hex;
            for(int i = 0; i < size1; i ++){
                for(int j = 0; j < size2; j++){
                    myfile << rooms[i][j].encode();
                }
            }
            myfile.close();
        }

        // int * decode(int encode){
        //     int nums[4];
        //     for(int i = 0; i < 4; i++){
        //         int num = pow(2, (3-i));
        //         if(encode & num != 0){
        //             nums[i] = 1;
        //         }else{
        //             nums[i] = 2;
        //         }
        //     }
        //     return nums;
        // }
        
    private:
    //opening is 2 wall is 1 uninitialized is 0
        int walls[4]; // East, West, South, North = 0,1,2,3 
        int row;
        int col;
        int visited = 0;
};