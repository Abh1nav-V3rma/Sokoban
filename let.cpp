#include<bits/stdc++.h>
#include<unistd.h>
#include "working.h"
using namespace std;


#define MAP_WIDTH 14
#define MAP_HEIGHT 10
#define PLAYER_POSITION pos_y * MAP_WIDTH + pos_x


// this is basic MAP without any dynamic location
// should change in future for different MAPs at different times
// first implementation so using basic MAP

// 1D map --->  2D map mein change karna hai


char MAP[] = {
    
    "**************\n"
    "*      # xB  *\n"
    "*  x   # xB  *\n"
    "*   B  # xB  *\n"
    "*      ####  *\n"
    "*     @   #  *\n"
    "*         #  *\n"
    "*    B    #  *\n"
    "*     x      *\n"
    "**************\n"

};

int dest_squares[10];

int GetDestinationSquare(){
    // returns no of locations were blocks are to be placed
    // checks if the location is filled(by O) or not (by x) and returns total no of such locations

    int count=0, cell;

    for(int row = 0; row < MAP_HEIGHT; row++){
        for(int col = 0; col < MAP_WIDTH; col++){
            cell = row * MAP_WIDTH + col;

            if(MAP[cell] == 'x' || MAP[cell] == 'O')
                dest_squares[count++] = cell;
        }
    }

    return count -1;
}

void GetPosition(int *pos_x, int *pos_y)
{
    int cell;                                                           // current cell index

    for(int row = 0; row < MAP_HEIGHT; row++)                           // loop ower MAP rows
    {
        for(int col = 0; col < MAP_WIDTH; col++)                        // loop ower MAP columns
        {
            cell = row * MAP_WIDTH + col;                               // init current cell index
        
            if(MAP[cell] == '@')                                        // if current cell on the MAP contains player
            {
                *pos_x = col;                                           // store player's x coordinate
                *pos_y = row;                                           // store player's y coordinate
            }
        }
    }
}


void MoveCharacter(int pos_x, int pos_y, int offset)
{
    if(MAP[PLAYER_POSITION + offset] != '#')                            // if player doesn't hit the wall
    {
        if(((MAP[PLAYER_POSITION + offset] == 'B') ||                   // if player hits the box
            (MAP[PLAYER_POSITION + offset] == 'O')) &&                  // or the box on 'x' cell
            (MAP[PLAYER_POSITION + offset * 2] != '#' ||                // and box doesn't hit a wall
             MAP[PLAYER_POSITION + offset * 2] != 'B' ||                // or another box
             MAP[PLAYER_POSITION + offset * 2] != 'O'))                 // or box on 'x' cell
        {
            MAP[PLAYER_POSITION] = ' ';                                 // clear previous player's position
            pos_x += offset;                                            // update player's coordinate

            if(MAP[PLAYER_POSITION + offset] == ' ')                    // if the square next to the box is empty
                MAP[PLAYER_POSITION + offset] = 'B';                    // push the box

            else if(MAP[PLAYER_POSITION + offset] == 'x')               // if the square next to the box is 'x'  
                MAP[PLAYER_POSITION + offset] = 'O';                    // mark the box is on it's place

            else
            {
                MAP[PLAYER_POSITION - offset] = '@';                    // if box hits the wall or another box
                return;                                                 // don't push it any further
            }

            MAP[PLAYER_POSITION] = '@';                                 // draw the player in the new position
        }

        else                                                            // if the square next to the player is empty                                                        
        {
            MAP[PLAYER_POSITION] = ' ';                                 // clear previous player position
            pos_x += offset;                                            // update player's coordinate
            MAP[PLAYER_POSITION] = '@';                                 // draw the player in the new position
        }
    }   
} 


int main(){
    
    int key;
    int pos_x, pos_y;
    int dest_count;

    int dest_num = GetDestinationSquare();
    
    cout<<MAP;

    while(true){
        char x = getch();
        // cout<<x;
        int center_x = SCREEN_WIDTH /2 - MAP_WIDTH/2;
        int center_y = SCREEN_HEIGHT /2 - MAP_HEIGHT/2;
        
        
        GetPosition(&pos_x, &pos_y);
        
        switch(x){

            case 'w': MoveCharacter(pos_x,pos_y, -MAP_WIDTH-1); break;
            case 's': MoveCharacter(pos_x, pos_y, MAP_WIDTH+1); break;
            case 'a': MoveCharacter(pos_x, pos_y, - 1); break;
            case 'd': MoveCharacter(pos_x, pos_y, 1); break;
        }

        dest_count = 0;

        for(int i=0;i<10;i++){
            if(MAP[dest_squares[i]] == 'O') dest_count++;

            if(MAP[dest_squares[i]] == ' ')
                MAP[dest_squares[i]] = 'x';
        }
        
        PrintMap(MAP);

        if(dest_num == dest_count)
        {
            cout<<"YOU WIN";
            getch();
            break;
        }

        if(x == 65){
            exit(0);
        }
    }

    cout<<"Exiting...";

    
    system("clear");

    return 0;
}