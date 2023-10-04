#include<iostream>
#include<cmath>
using namespace std;

// Classe Ponto
class Ponto {
    private:
        double x, y;
    public:
        // Construtor
        Ponto(double x = 0, double y = 0) : x(x), y(y) {}

        // Métodos para definir as coordenadas
        void setX(double x) {
            this->x = x;
        }

        void setY(double y) {
            this->y = y;
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
            return sqrt(x*x + y*y);
        }
};

int main() {
    // Criação de um ponto
    Ponto p(3, 4);

    // Exibição das informações do ponto
    cout << "Ponto: (" << p.getX() << ", " << p.getY() << ")" << endl;
    cout << "Distância até a origem: " << p.calcularDistancia() << endl;

    return 0;
}
