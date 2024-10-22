#include <iostream>
#include <limits>
#include <memory>

/*
* Crear un programa que simule el funcionamiento de atencioni a clientes en un banco.
* Tomando como base el orden en que van llegando.
* First input <-> First Output (FIFO)
*/

struct Node{
    std::string name;
    std::string requestService;
    struct std::unique_ptr<Node> next;
};

struct Bank{
    int queueLong;
    struct std::unique_ptr<Node> first;
};

Bank *queue = nullptr;

std::unique_ptr<Node> create_node()
{
    std::unique_ptr<Node> auxNode(new Node);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Name: " << std::endl;
    std::getline(std::cin, auxNode->name);
    std::cout<< "Service: " << std::endl;
    std::getline(std::cin, auxNode->requestService);

    auxNode->next = nullptr;
    return auxNode;
}

void add_client()
{
    if (queue == nullptr){
        queue = new Bank;
        queue->first = create_node();
        queue->queueLong = 1;
    }
    else{
        Node *auxNode = queue->first.get();
        while (auxNode->next != nullptr){
            auxNode = auxNode->next.get();
        }
        auxNode->next = create_node();
        queue->queueLong = (queue->queueLong) + 1;
    }
}

void show_first_client()
{
    if (queue == nullptr){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Empty queue"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else{

    }
}

int main(int argc, char **argv)
{
    int operation = 0;
    bool flg = true;
    while(flg = 1)
    {
        std::cout << "Operation you wish to perform" << std::endl;
        std::cout << "1) Add cliente" << std::endl;
        std::cout << "2) Show first client" << std::endl;
        std::cout << "5) Output..." << std::endl;
        std::cin >> operation;
        switch(operation)
        {
            case 1: add_client();        break;
            case 2: show_first_client(); break;
            case 5: flg = false;         break; 
            default: std::cout << "Invalid operation" << std::endl; break; 
        }
        std::cin.get();
        std::cin.get();
        system("clear");
    }
}