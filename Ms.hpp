//
// Created by Meghana on 04-02-2018.
//

#ifndef C_MS_HPP
#define C_MS_HPP

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
    bool findCheese(IMaze iMaze);
};


#endif //C_MS_HPP
