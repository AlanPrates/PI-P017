/*Sistema de Cadastro de Produtos
Crie um sistema de cadastro de produtos em um supermercado. Cada grupo deve 
projetar as classes Produto, Estoque e CarrinhoDeCompras. O Produto deve ter 
atributos como nome, preço e código. O Estoque deve controlar a quantidade de cada 
produto. O CarrinhoDeCompras deve permitir adicionar e remover produtos, calcular 
o valor total e exibir o conteúdo.*/

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Produto {
private:
    string nome;
    double preco;

public:
    Produto(string nome, double preco) : nome(nome), preco(preco) {}

    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }
};

class CarrinhoDeCompras {
private:
    vector<Produto> produtosNoCarrinho;
    vector<int> quantidadesNoCarrinho;

public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        produtosNoCarrinho.push_back(produto);
        quantidadesNoCarrinho.push_back(quantidade);
    }

    bool removerProduto(const Produto& produto, int quantidade) {
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            if (produtosNoCarrinho[i].getNome() == produto.getNome()) {
                if (quantidade >= quantidadesNoCarrinho[i]) {
                    produtosNoCarrinho.erase(produtosNoCarrinho.begin() + i);
                    quantidadesNoCarrinho.erase(quantidadesNoCarrinho.begin() + i);
                } else {
                    quantidadesNoCarrinho[i] -= quantidade;
                }
                return true;
            }
        }
        return false;
    }

    void esvaziarCarrinho() {
        produtosNoCarrinho.clear();
        quantidadesNoCarrinho.clear();
    }

    int getQuantidadeProduto(const Produto& produto) const {
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            if (produtosNoCarrinho[i].getNome() == produto.getNome()) {
                return quantidadesNoCarrinho[i];
            }
        }
        return 0;
    }

    void exibirCarrinho() const {
        cout << "Carrinho de Compras:" << endl;
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            cout << "- " << produtosNoCarrinho[i].getNome() << " (" << produtosNoCarrinho[i].getPreco() << ") x "
                 << quantidadesNoCarrinho[i] << endl;
        }
    }

    double calcularValorTotal() const {
        double valorTotal = 0.0;
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            valorTotal += produtosNoCarrinho[i].getPreco() * quantidadesNoCarrinho[i];
        }
        return valorTotal;
    }
};

int main() {
    Produto p1("Maçã", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);

    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total da compra: " << valorTotal << endl;

    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após remoção: " << valorTotal << endl;

    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após esvaziar o carrinho: " << valorTotal << endl;

    Produto p4("Chocolate", 3.0);
    carrinho.adicionarProduto(p4, 10); 
    cout << "Quantidade de chocolates no carrinho: " << carrinho.getQuantidadeProduto(p4) << endl;

    carrinho.exibirCarrinho();

    return 0;
}
