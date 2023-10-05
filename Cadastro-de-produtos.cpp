#include <iostream>
#include <vector>

class Produto {
public:
    std::string nome;
    double preco;
    int codigo;

    Produto(std::string nome, double preco, int codigo) : nome(nome), preco(preco), codigo(codigo) {}
};

class Estoque {
private:
    std::vector<Produto> produtos;

public:
    void adicionar_produto(Produto produto, int quantidade) {
        for (int i = 0; i < quantidade; i++) {
            produtos.push_back(produto);
        }
    }

    void remover_produto(Produto produto, int quantidade) {
        int count = 0;
        for (auto it = produtos.begin(); it != produtos.end();) {
            if (it->codigo == produto.codigo && count < quantidade) {
                it = produtos.erase(it);
                count++;
            } else {
                ++it;
            }
        }
    }
};

class CarrinhoDeCompras {
private:
    std::vector<Produto> produtos;

public:
    void adicionar_produto(Produto produto, int quantidade) {
        for (int i = 0; i < quantidade; i++) {
            produtos.push_back(produto);
        }
    }

    void remover_produto(Produto produto) {
        for (auto it = produtos.begin(); it != produtos.end(); ++it) {
            if (it->codigo == produto.codigo) {
                produtos.erase(it);
                break;
            }
        }
    }

    double calcular_valor_total() {
        double total = 0.0;
        for (const auto& produto : produtos) {
            total += produto.preco;
        }
        return total;
    }

    void exibir_conteudo() {
        for (const auto& produto : produtos) {
            std::cout << "Produto: " << produto.nome << ", Preço: " << produto.preco << ", Código: " << produto.codigo << std::endl;
        }
    }
};

int main() {
    Produto produto1("Arroz", 5.0, 1001);
    Produto produto2("Feijão", 3.0, 1002);
    Produto produto3("Óleo", 7.0, 1003);

    Estoque estoque;
    estoque.adicionar_produto(produto1, 10);
    estoque.adicionar_produto(produto2, 15);
    estoque.adicionar_produto(produto3, 20);

    CarrinhoDeCompras carrinho;
    carrinho.adicionar_produto(produto1, 2);
    carrinho.adicionar_produto(produto2, 3);
    carrinho.adicionar_produto(produto3, 1);

    carrinho.exibir_conteudo();

    double total = carrinho.calcular_valor_total();
    std::cout << "Valor total do carrinho: R$" << total << std::endl;

    carrinho.remover_produto(produto1);
    carrinho.remover_produto(produto2);

    carrinho.exibir_conteudo();

    total = carrinho.calcular_valor_total();
    std::cout << "Valor total do carrinho: R$" << total << std::endl;

    return 0;
}
