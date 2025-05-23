#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>

struct Node {
    int data;
    Node* right = nullptr;
    Node* left = nullptr;
};

struct CTree {
    Node* root = nullptr;

    void insert(int x) {
        Node** new_node;
        if (find(x, new_node)) return;
        *new_node = new Node;
        (*new_node)->data = x;
  
    }

    bool find(int x, Node**& ptr) {
        ptr = &root;
        while (((*ptr) != nullptr) and ((*ptr)->data != x )) {
            if (x >= (*ptr)->data) {
                (ptr) = &((*ptr)->right);
            }
            else if (x < (*ptr)->data) {
                (ptr) = &((*ptr)->left);
            } 
        }
        return ((*ptr) != nullptr);
    }

    void print() {
        in_order(root);
        std::cout << std::endl;
    }

    void in_order(Node* node) {
        if (node == nullptr) return;
        in_order(node->left);
        std::cout << node->data << " ";
        in_order(node->right);
    }

    int previous_number(int x) {
        Node** temp;
        if (!(find(x, temp))) return x;
        temp = &((*temp)->left);
        std::cout << "loop" << std::endl;
        while ((*temp)->right != nullptr) {
            temp = &((*temp)->right);
        }
        return (*temp)->data;
    }

    void remove(int x) {
        Node** ptr;
        if (!(find(x, ptr))) return;
        if (((*ptr)->left == nullptr) and ((*ptr)->right == nullptr)) {

        }
        if (((*ptr)->left != nullptr) xor ((*ptr)->right != nullptr)) {

        }
        if (((*ptr)->left != nullptr) and ((*ptr)->right != nullptr)) {

        }

        
    }

    void generate_random_tree(int size, CTree obj) {
        //srand(time(0));
        for (int i = 0; i <= size; i++) {
            obj.insert((int)rand() % (size * 5));
        }
    }

    void draw_node(sf::RenderWindow& window, Node* node, float x, float y, float offsetX) {
        if (!node) return;

        // draw lines
        if (node->left) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x - offsetX, y + 80), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
            draw_node(window, node->left, x - offsetX, y + 80, offsetX / 2);
        }

        if (node->right) {
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(x, y), sf::Color::Black),
                sf::Vertex(sf::Vector2f(x + offsetX, y + 80), sf::Color::Black)
            };
            window.draw(line, 2, sf::Lines);
            draw_node(window, node->right, x + offsetX, y + 80, offsetX / 2);
        }

        // draw node
        sf::CircleShape circle(20);
        circle.setFillColor(sf::Color::White);
        circle.setOutlineColor(sf::Color::Black);
        circle.setOutlineThickness(2);
        circle.setPosition(x - 20, y - 20);

        static sf::Font font;
        static bool loaded = font.loadFromFile("arial.ttf");
        if (!loaded) {
            std::cerr << "No se pudo cargar la fuente arial.ttf" << std::endl;
            return;
        }

        sf::Text text(std::to_string(node->data), font, 14);
        text.setFillColor(sf::Color::Black);
        text.setPosition(x - 10, y - 10);

        window.draw(circle);
        window.draw(text);
    }


    void draw() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Árbol Binario");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear(sf::Color::White);
            draw_node(window, root, 400, 50, 150);
            window.display();
        }
    }
};


int main()
{
    CTree obj1;
    
    int size = 20;
    //srand(time(0));
    for (int i = 0; i <= size; i++) {
        obj1.insert((int)rand() % (size * 5));
    }

    //std::cout<<obj1.previous_number(36)<<std::endl;
    obj1.draw();

    obj1.print();
}


