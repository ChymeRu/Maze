#ifndef ROOM_H
#define ROOM_H

class Room{
    public:
        Room();
        Room(int walls[4]);
        //create room from encoded int
        Room(int encode);
        
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

        int encode();

        static void encodeToFile(Room rooms[10][25], int size1, int size2);

        static int * decode(char hex);
        
    private:
    //opening is 2 wall is 1 uninitialized is 0
        int walls[4]; // East, West, South, North = 0,1,2,3 
        int row;
        int col;
        int visited = 0;
};

#endif