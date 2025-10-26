#include "Sprite.h"
#include "raylib.h"

ventana::ventana() {
    player1 = { 0 };
    player2 = { 0 };
    fondoimagen = { 0 };
    anchopantalla = 1080;
    altopantalla = 920;
    escala1 = 0.1f;
    escala2 = 0.1f;
    escala3 = 0.0f;
    auxescala= 0.0f;
	auxrotacion = 0.0f;
	auxposicion = { 0,0 };  
    rotacion1 = 0.0f;
    rotacion2 = 0.0f;
    posicion= { 0,0 };
	posicion1 = { 0,0 };
    posicion2 = {0,0};
    velocidad = 200;
    Color1 = WHITE;
    Color2 = GREEN;
	auxcolor = { 0,0,0,0 }; 
}


void ventana::limpiar() {
    UnloadTexture(fondoimagen);
    UnloadTexture(player1);
    UnloadTexture(player2); 

    CloseWindow();
};

ventana::~ventana() {
	limpiar();
};

void ventana::Cargatextura() {

    SetTargetFPS(60);
    InitWindow(anchopantalla, altopantalla, "MOVIMIENTOS Y SPRITES");
   

    posicion1 = { 200, 300 };
    posicion2 = { 600, 300 };

    //Texturas

    fondoimagen = LoadTexture("imagenes/fondo3.png");
    SetTextureFilter(fondoimagen, TEXTURE_FILTER_BILINEAR);
    player1 = LoadTexture("imagenes/mario1.png");
    SetTextureFilter(player1, TEXTURE_FILTER_BILINEAR);
    player2 = LoadTexture("imagenes/Luigi.png");
    SetTextureFilter(player2, TEXTURE_FILTER_BILINEAR);
}

void ventana::movimiento() {


    while (!WindowShouldClose()) {
        float deltatime = GetFrameTime();

        velocidad = 200.0f;

        //player  1

        if (IsKeyDown(KEY_RIGHT)) {
            posicion1.x = posicion1.x + velocidad * deltatime;
        }
        if (IsKeyDown(KEY_LEFT)) {
            posicion1.x = posicion1.x - velocidad * deltatime;
        }
        if (IsKeyDown(KEY_UP)) {
            posicion1.y = posicion1.y - velocidad * deltatime;
        }
        if (IsKeyDown(KEY_DOWN)) {
            posicion1.y = posicion1.y + velocidad * deltatime;
        }
        //Lo dejo comentado no puedo hacer que no se salga del tamaño de ventana 
        /* //Rotacion de player 1 con tecla X
        if (IsKeyDown(KEY_X)) {
            rotacion1 = rotacion1 + 90.0f * deltatime;
        }*/


        //player 2 
        if (IsKeyDown(KEY_D)) {
            posicion2.x = posicion2.x + velocidad * deltatime;
        }
        if (IsKeyDown(KEY_A)) {
            posicion2.x = posicion2.x - velocidad * deltatime;
        }
        if (IsKeyDown(KEY_W)) {
            posicion2.y = posicion2.y - velocidad * deltatime;
        }
        if (IsKeyDown(KEY_S)) {
            posicion2.y = posicion2.y + velocidad * deltatime;
        }


        //intercambio  con la tecla espaciadora(space)
        if (IsKeyPressed(KEY_SPACE)) {
            auxposicion = posicion1;
            posicion1 = posicion2;
            posicion2 = auxposicion;

            auxescala = escala1;
            escala1 = escala2;
            escala2 = auxescala;

            auxrotacion = rotacion1;
            rotacion1 = rotacion2;
            rotacion2 = auxrotacion;

            auxcolor = Color1;
            Color1 = Color2;
            Color2 = auxcolor;
        }



        //  Verificacion de limites de pantalla para que los players no se salgan

        // Player1  
        if (posicion1.x < 0) {
            posicion1.x = 0;
        }
        if (posicion1.y < 0) {
            posicion1.y = 0;
        }
        if ((posicion1.x + player1.width * escala1) > anchopantalla) {
            posicion1.x = anchopantalla - player1.width * escala1;
        }
        if ((posicion1.y + player1.height * escala1) > altopantalla) {
            posicion1.y = altopantalla - player1.height * escala1;
        }


        // Player2
        if (posicion2.x < 0) {
            posicion2.x = 0;
        }
        if (posicion2.y < 0) {
            posicion2.y = 0;
        }
        if ((posicion2.x + player2.width * escala2) > anchopantalla) {
            posicion2.x = anchopantalla - player2.width * escala2;
        }
        if ((posicion2.y + player2.height * escala2) > altopantalla) {
            posicion2.y = altopantalla - player2.height * escala2;
        }

        BeginDrawing();

        ClearBackground(RAYWHITE);



        //adaptacion del fondo al tamaño de ventana 
        Rectangle rectangulotextura = { 0, 0, (float)fondoimagen.width, (float)fondoimagen.height };
        Rectangle rectangulopantalla = { 0, 0,(float)anchopantalla, (float)altopantalla };
      

        DrawTexturePro(fondoimagen, rectangulotextura, rectangulopantalla, posicion, escala3, WHITE);
        DrawTextureEx(player1, posicion1, rotacion1, escala1, Color1);
        DrawTextureEx(player2, posicion2, rotacion2, escala2, Color2);
   
        DrawText(TextFormat("MARIO BROS Posicion:%.0f, %.0f Escala: %.2f Rotacion: %.2f",posicion1.x, posicion1.y, escala1, rotacion1),10, 40, 20, BLACK);
        DrawText(TextFormat("LUIGI Posicion(%.0f, %.0f Escala: %.2f Rotacion: %.2f",posicion2.x, posicion2.y, escala2, rotacion2),10, 70, 20, BLACK);
        DrawText("MARIO: Movimiento FLECHAS                  |                   LUIGI:Movimiento WASD", 10, 10, 20, BLACK);
         
        EndDrawing();
       
    }
}
