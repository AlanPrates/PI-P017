/*
Crie uma classe chamada Ponto que represente um ponto no plano cartesiano com
coordenadas x e y. Inclua construtores, métodos para definir e obter as coordenadas,
e um método para calcular a distância até a origem (0,0).
*/

#include <iostream>
#include <cmath>

using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    // Construtor padrão
    Ponto() : x(0.0), y(0.0) {}

    // Construtor com coordenadas iniciais
    Ponto(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    // Métodos para definir as coordenadas
    void setCoordenadas(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    // Métodos para obter as coordenadas
    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    // Método para calcular a distância até a origem (0,0)
    double calcularDistancia() const {
        return sqrt(x * x + y * y);
    }
};

int main() {
    // Exemplo de uso da classe Ponto
    Ponto ponto1;  // Cria um ponto na origem (0,0)
    Ponto ponto2(3.0, 4.0);  // Cria um ponto com coordenadas (3,4)

    // Obtém e imprime as coordenadas dos pontos
    cout << "Coordenadas do ponto1: (" << ponto1.getX() << ", " << ponto1.getY() << ")\n";
    cout << "Coordenadas do ponto2: (" << ponto2.getX() << ", " << ponto2.getY() << ")\n";

    // Calcula e imprime a distância até a origem
    cout << "Distância até a origem (ponto1): " << ponto1.calcularDistancia() << "\n";
    cout << "Distância até a origem (ponto2): " << ponto2.calcularDistancia() << "\n";

    return 0;
}
