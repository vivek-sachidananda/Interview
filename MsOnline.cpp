/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>

enum Direction
{
    Left,
    Right,
    Up,
    Down
};

class IMaze
{
public:
    IMaze()
    {
        _maze[0][0] = 0;
        _maze[0][1] = -9;
        _maze[0][2] = 100;
        _maze[0][3] = 0;
        _maze[1][0] = 0;
        _maze[1][1] = -9;
        _maze[1][2] = -9;
        _maze[1][3] = 0;
        _maze[2][0] = 0;
        _maze[2][1] = 0;
        _maze[2][2] = -9;
        _maze[2][3] = 0;
        _maze[3][0] = 0;
        _maze[3][1] = 0;
        _maze[3][2] = 0;
        _maze[3][3] = 0;

        _x = _y = 0;

        _height = _width = 4;

        for(size_t i = 0; i < _width; i++){
            for(size_t j = 0; j < _height; j++){
                _wasHere[i][j]=false;
            }
        }

        _wasHere[_x][_y] = true;
    }

    bool isFoundCheese();
    bool tryMouseMove(const Direction iDir);

private:
    int _maze[4][4];
    bool _wasHere[4][4];
    int _x, _y;
    unsigned _width, _height;
};

class Ms {
public:
    bool findCheese(IMaze iMaze, Direction iDir);
};

bool IMaze::isFoundCheese()
{
    return (_maze[_x][_y] == 100);
}

bool IMaze::tryMouseMove(Direction iDir)
{
    bool isBoundProb = false;

    unsigned aTemp_x, aTemp_y;
    aTemp_x = _x;
    aTemp_y = _y;

    std::cout << "Try Mouse Move : " << iDir << " current (_x , _y)" << "(" << aTemp_x << "," << aTemp_y << ")" << std::endl;

    switch (iDir)
    {
        case Left :
            if (aTemp_y > 0)
                aTemp_y -= 1;
            else
                isBoundProb = true;
            break;
        case Right :
            if (aTemp_y < (_width - 1))
                aTemp_y += 1;
            else
                isBoundProb = true;
            break;
        case Up :
            if (aTemp_x > 0)
                aTemp_x -= 1;
            else
                isBoundProb = true;
            break;
        case Down :
            if (aTemp_x < (_height - 1))
                aTemp_x += 1;
            else
                isBoundProb = true;
            break;
    }

    if (isBoundProb)
    {
        std::cout << "Try Mouse Move : Ret " << false << " bound problem" << std::endl;
        return false;
    }

    // There can be a possible move, as its within the maze bounds
    {
        // Check if we have hit a wall or obstacle
        if (_maze[aTemp_x][aTemp_y] == -9 || _maze[aTemp_x][aTemp_y] == -1 || _wasHere[aTemp_x][aTemp_y])
        {
            std::cout << "Try Mouse Move : Ret " << false << " wall or already visited" << std::endl;

            return false;
        }

        std::cout << "Try Mouse Move : Ret " << true << std::endl;

        //We have a empty space for a move
        _wasHere[aTemp_x][aTemp_y] = true;

        _x = aTemp_x;
        _y = aTemp_y;
    }

    std::cout << "Path : " << "(" << _x << "," << _y <<  ")" << std::endl;

    return true;
}


bool Ms::findCheese(IMaze iMaze, Direction iDir)
{
    std::cout << "calling the find cheese" << std::endl;

    if (iMaze.isFoundCheese())
    {
        std::cout << "Found cheese" << std::endl;
        return true;
    }

    if (iMaze.tryMouseMove(iDir))
    {
        if (findCheese(iMaze, Left) == true)
            return true;

        if (findCheese(iMaze, Right) == true)
            return true;

        if (findCheese(iMaze, Up) == true)
            return true;

        if (findCheese(iMaze, Down) == true)
            return true;
    }

    return false;
}

int main()
{
    std::cout<<"Hello World";

    Ms aFinder;
    IMaze aMaze;
    
    
    if (!aFinder.findCheese(aMaze, Left))
        if(!aFinder.findCheese(aMaze, Right))
            if(!aFinder.findCheese(aMaze, Up))
                if(!aFinder.findCheese(aMaze, Down))
                {
                    std::cout << "Did not find the cheese :(" << std::endl;
                }
    
    return 0;
}
