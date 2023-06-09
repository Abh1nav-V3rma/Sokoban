#include<bits/stdc++.h>
using namespace std;
char map_present[8][10][15] = {
    {
        //  MAP-1
        "##############",
        "#      # xB  #",
        "#  x   # xB  #",
        "#   B  # xB  #",
        "#      ####  #",
        "#     @   #  #",
        "#         #  #",
        "#    B    #  #",
        "#     x      #",
        "##############"

    },
    {
        //  MAP-2
        "##############",
        "#            #",
        "# x  ##     x#",
        "#####x#   ####",
        "#   x ###    #",
        "#     #   B  #",
        "#     #   B  #",
        "#      BBB   #",
        "# @ x        #",
        "##############"

    },
    {
        //  MAP-3
        "##############",
        "#      #     #",
        "#    B #x    #",
        "#      #x #B #",
        "#      #x #  #",
        "#   @  #  #  #",
        "#x     ####  #",
        "#       B B  #",
        "#  B     x   #",
        "##############"

    },
    {
        //  MAP-4
        "##############",
        "# x#    x#####",
        "# x#    B ####",
        "# x#     B ###",
        "#  #      B ##",
        "#   @ B    B #",
        "#            #",
        "#            #",
        "#   x        #",
        "##############"
    },
    {
        //  MAP-5
        "##############",
        "#   #   x #  #",
        "# x#    B #  #",
        "# x#    B #  #",
        "# x#    B #  #",
        "#     B   ####",
        "#            #",
        "#         @  #",
        "#   x        #",
        "##############"
    },
    {
        //  MAP-6
        "##############",
        "#        #   #",
        "#        #   #",
        "#### B@  B   #",
        "#####x####   #",
        "#####x####B###",
        "#    x       #",
        "#     #      #",
        "#     #      #",
        "##############"
    },
    {
        //  MAP-7
        " #############",
        " ###   ##     ",
        " ###x#B ###   ",
        " ## B     ##  ",
        " ##x  x#B ##  ",
        "##x### @ #####",
        "## ### #B#   #",
        "#          B #",
        "#   x    #   #",
        "##############"
    },
    {
        //  MAP-8
        // not used
        "              ",
        "  ##########  ",
        "  ## xxxx ##  ",
        "  ##@B B  ##  ",
        "#####x########",
        "#          ###",
        "#     B B  ###",
        "#######    ###",
        "      ########",
        "              "
    },
};



char** __MAP__()
{   
    srand(time(0));
    int tmp = rand()%7;

    char** m = new char*[10];
    for(int i=0;i<10;i++){
        m[i] = new char[15]; 
        for(int j=0;j<14;j++){
            m[i][j] = map_present[tmp][i][j];
        }
    }

    return m;

}