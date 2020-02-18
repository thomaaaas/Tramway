#ifndef TRAMWAY_STATION_H
#define TRAMWAY_STATION_H
class Station{
public:
    Station(int x, int y);
    int getX() const;
    int getY() const;
    void setPosition(int x, int y);
private:
    int d_X, d_Y;
};
#endif //TRAMWAY_STATION_H
