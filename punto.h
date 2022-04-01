#ifndef PUNTO_H_INCLUDED
#define PUNTO_H_INCLUDED


struct punto{
    int x;
    int y;

    punto& operator = (const punto &p){
        x=p.x;
        y=p.y;
        return *this;
    }
    bool operator == (const punto &p){
        return (x==p.x && y==p.y);
    }
    friend std::ostream& operator << (std::ostream &o,const punto &p){
        o << "(" << p.x << "," << p.y << ")";
        return o;
    }
};

#endif // PUNTO_H_INCLUDED
