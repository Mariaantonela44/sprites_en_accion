#ifndef SPRITE_H
#define SPRITE_H
#include "raylib.h"

class ventana {
private:
    Texture2D fondoimagen;
    Texture2D player1;
    Texture2D player2;
    int altopantalla;
    Color Color1;
    Color Color2;
    Color auxcolor;


public:
    Vector2 posicion;
    Vector2 posicion1;
    Vector2 posicion2;
    Vector2 auxposicion;
    float velocidad;
    float escala1;
    float escala2;
    float escala3;
    float rotacion1;
    float rotacion2;
    float auxescala;
    float auxrotacion;
    int anchopantalla;
    ventana();
    ~ventana();
    void limpiar();
    void Cargatextura();
    void movimiento();
};



#endif

