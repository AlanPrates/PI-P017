#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Produto {
private:
    string nome;
    double preco;
    int codigo;

public:
    Produto(string nome, double preco, int codigo)
        : nome(nome), preco(preco), codigo(codigo) {}

    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }

    int getCodigo() const {
        return codigo;
    }
};

class Estoque {
private:
    vector<Produto> produtos;
    vector<int> quantidades;

public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        produtos.push_back(produto);
        quantidades.push_back(quantidade);
    }

    void removerProduto(int codigo, int quantidade) {
        for (size_t i = 0; i < produtos.size(); ++i) {
            if (produtos[i].getCodigo() == codigo) {
                if (quantidade >= quantidades[i]) {
                    produtos.erase(produtos.begin() + i);
                    quantidades.erase(quantidades.begin() + i);
                } else {
                    quantidades[i] -= quantidade;
                }
                break;
            }
        }
    }

    void exibirEstoque() const {
        cout << "Estoque:\n";
        for (size_t i = 0; i < produtos.size(); ++i) {
            cout << "Código: " << produtos[i].getCodigo()
                      << ", Nome: " << produtos[i].getNome()
                      << ", Preço: " << produtos[i].getPreco()
                      << ", Quantidade: " << quantidades[i] << "\n";
        }
    }
};

class CarrinhoDeCompras {
private:
    vector<Produto> produtosNoCarrinho;

public:
    void adicionarProduto(const Produto& produto) {
        produtosNoCarrinho.push_back(produto);
    }

    void removerProduto(int codigo) {
        for (size_t i = 0; i < produtosNoCarrinho.size(); ++i) {
            if (produtosNoCarrinho[i].getCodigo() == codigo) {
                produtosNoCarrinho.erase(produtosNoCarrinho.begin() + i);
                break;
            }
        }
    }

    double calcularValorTotal() const {
        double total = 0.0;
        for (const Produto& produto : produtosNoCarrinho) {
            total += produto.getPreco();
        }
        return total;
    }

    void exibirCarrinho() const {
        cout << "Carrinho de Compras:\n";
        for (const Produto& produto : produtosNoCarrinho) {
            cout << "Código: " << produto.getCodigo()
                      << ", Nome: " << produto.getNome()
                      << ", Preço: " << produto.getPreco() << "\n";
        }
    }
};

int main() {
    Produto produto1("Arroz", 5.99, 101);
    Produto produto2("Feijão", 3.99, 102);
    Produto produto3("Macarrão", 2.49, 103);

    Estoque estoque;
    estoque.adicionarProduto(produto1, 50);
    estoque.adicionarProduto(produto2, 40);
    estoque.adicionarProduto(produto3, 30);

    CarrinhoDeCompras carrinho;

    carrinho.adicionarProduto(produto1);
    carrinho.adicionarProduto(produto2);
    carrinho.adicionarProduto(produto3);

    cout << "Conteúdo do Carrinho:\n";
    carrinho.exibirCarrinho();

    cout << "Valor Total do Carrinho: R$" << carrinho.calcularValorTotal() << "\n";

    return 0;
}
