Copiar código
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#include <iostream>
#include <vector>
#include <cmath>

const int WIDTH = 100;
const int HEIGHT = 100;
const int RADIUS = 20;  // Radio de los bordes redondeados

struct Pixel {
    uint8_t r, g, b, a;
};

std::vector<std::vector<Pixel>> canvas(WIDTH, std::vector<Pixel>(HEIGHT));

// Función para dibujar un píxel en el canvas
void setPixel(int x, int y, Pixel color) {
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
        canvas[x][y] = color;
    }
}

// Función para calcular la distancia euclidiana
float distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - y1) + (y2 - y1) * (y2 - y1));
}

// Función para dibujar un cuadrado con bordes redondeados
void drawRoundedRect(int x, int y, int width, int height, int radius, Pixel color) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            // Calcular la distancia a las esquinas
            float d1 = distance(i, j, radius, radius);
            float d2 = distance(i, j, width - radius, radius);
            float d3 = distance(i, j, radius, height - radius);
            float d4 = distance(i, j, width - radius, height - radius);

            // Determinar si el píxel está dentro del radio
            if ((i >= radius && i < width - radius) || (j >= radius && j < height - radius) ||
                (d1 <= radius) || (d2 <= radius) || (d3 <= radius) || (d4 <= radius)) {
                
                Pixel pixel = color;

                // Aplicar degradado de alpha en las esquinas
                if (d1 < radius || d2 < radius || d3 < radius || d4 < radius) {
                    float minDist = std::min({d1, d2, d3, d4});
                    pixel.a = static_cast<uint8_t>((minDist / radius) * color.a);
                }

                setPixel(x + i, y + j, pixel);
            }
        }
    }
}

// Guardar el canvas como una imagen PNG
void saveToPNG(const char* filename) {
    std::vector<uint8_t> imageData(WIDTH * HEIGHT * 4);  // 4 canales por píxel (RGBA)
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int index = (y * WIDTH + x) * 4;
            imageData[index + 0] = canvas[x][y].r;
            imageData[index + 1] = canvas[x][y].g;
            imageData[index + 2] = canvas[x][y].b;
            imageData[index + 3] = canvas[x][y].a;
        }
    }
    stbi_write_png(filename, WIDTH, HEIGHT, 4, imageData.data(), WIDTH * 4);
}

int main() {
    Pixel red = {255, 0, 0, 255};  // Color rojo con alpha completo

    // Dibujar un cuadrado con bordes redondeados
    drawRoundedRect(10, 10, WIDTH - 20, HEIGHT - 20, RADIUS, red);

    // Guardar la imagen como PNG
    saveToPNG("rounded_square.png");

    std::cout << "Imagen guardada como rounded_square.png" << std::endl;
    return 0;
}