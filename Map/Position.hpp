#ifndef POSITION_HPP_
#define POSITION_HPP_
class Position
{
protected:
    int x;
    int y;

public:
    Position();
    Position(int coordinate_x, int coordinate_y);
    Position(const Position &);
    ~Position();
    Position &operator=(const Position &pos);
    bool operator==(const Position &pos) const;
    int getXCoordinate();
    int getYCoordinate();
    void setXCoordinate(int _x);
    void setYCoordinate(int _y);
};
#endif