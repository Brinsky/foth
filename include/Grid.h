#ifndef GRID_H
#define GRID_H

#include <vector>
#include <algorithm>

template<typename T, T default_t>
class Grid 
{
    public:
        Grid(int width, int height)
        {
            this->width = width; 
            this->height = height;
            grid.resize(width);
            for (auto x = grid.begin(); x != grid.end(); ++x)
            {
                x->resize(height);
                std::fill(x->begin(), x->end(), default_t);
            }
        }
        ~Grid() {}
        bool setNode(int x, int y, T t)
        {
            if (inBounds(x, y))
            {            
                grid[x][y] = t;
                return true;    
            }
            else
            {
                return false;
            }
        }
        T getNode(int x, int y)
        {
            if (inBounds(x, y))
                return grid[x][y];   
            else
                return default_t;
        }
    protected:
        int width;
        int height;
        std::vector<std::vector<T>> grid;
        bool inBounds(int x, int y)
        {
            return x >= 0 && x < width && y >= 0 && y < height;
        }
};

#endif
