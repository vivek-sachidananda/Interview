//
// Created by Meghana on 04-02-2018.
//

#include <iostream>
#include "Ms.hpp"
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


bool Ms::findCheese(IMaze iMaze)
{
    std::cout << "calling the find cheese" << std::endl;

    if (iMaze.isFoundCheese())
        return true;

    {
        if (iMaze.tryMouseMove(Left) && findCheese(iMaze) == true)
            return true;

        if (iMaze.tryMouseMove(Right) && findCheese(iMaze) == true)
            return true;

        if (iMaze.tryMouseMove(Up) && findCheese(iMaze) == true)
            return true;

        if (iMaze.tryMouseMove(Down) && findCheese(iMaze) == true)
            return true;
    }

    return false;
}

