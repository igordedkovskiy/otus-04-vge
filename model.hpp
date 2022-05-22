#pragma once

// Coordinates - graph, where every vertex represents a coordinates of a point of a shape 
class Coordinates
{
//    using coord_t = std::pair<unsigned long, unsigned long>;
//private:
//    coord_t m_current;
//    std::vector<coord_t> 
};

class Shape
{
private:
    virtual void draw() = 0;
    virtual set_coordinates(const Coordinates& coord) = 0;
    Coordinates m_coord;
};

class Document
{
public:
    virtual void create(const Shape& sh) = 0;
    virtual void remove(const Shape& sh) = 0;
private:
    std::vector<std::unique_ptr<Shape>> m_shapes;
};

