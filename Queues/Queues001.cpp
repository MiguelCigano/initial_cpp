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
    struct Node *next;
};

struct Bank{
    int queueLong;
    struct Node *first;
};

Bank *queue = nullptr;

struct Node *create_node()
{
    Node *auxNode = new Node;

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
        Node *auxNode = queue->first;
        while (auxNode->next != nullptr){
            auxNode = auxNode->next;
        }
        auxNode->next = create_node();
        queue->queueLong = (queue->queueLong) + 1;
    }
}

/* All customer added is put in the end of the queue */
void show_first_client()
{
    if (queue == nullptr){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Empty queue"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else{
        Node *auxNode = queue->first;
        //while(auxNode != nullptr)
        //{
            std::cout << "Customer name: " << auxNode->name << std::endl;
            std::cout << "Request service: " << auxNode->requestService << std::endl;
        //    auxNode = auxNode->next;
        //}
    }
}

void eliminate_client()
{
    if (queue == nullptr){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Empty queue"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else if(queue->first->next == nullptr){
        delete queue->first;
        delete queue;
        queue=nullptr;
    }
    else{
        Node *auxNode = queue->first->next; // save on aux the next node
        delete queue->first;
        queue->first = auxNode;
        queue->queueLong = (queue->queueLong)-1;
    }
}

void show_all_clients()
{
    if (queue == nullptr){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Empty queue"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else{
        Node *auxNode = queue->first;
        while(auxNode != nullptr)
        {
            std::cout << "Customer name: " << auxNode->name << std::endl;
            std::cout << "Request service: " << auxNode->requestService << std::endl;
           auxNode = auxNode->next;
        }
    }
}

void eliminate_queue()
{   
    if (queue == nullptr){
        std::cout << "+---------------------+" << std::endl;
        std::cout <<     "Empty queue"    << std::endl;
        std::cout << "+---------------------+" << std::endl;
    }
    else{
        Node *auxNode = queue->first;
    
        while(auxNode != nullptr){
            Node *auxNodeTwo = auxNode->next;
            delete auxNode;
            auxNode = auxNodeTwo;
        }
        delete queue->first;
        delete queue;
        queue = nullptr;
    }
}

int main(int argc, char **argv)
{
    int operation = 0;
    bool flg = true;
    while(flg == true)
    {
        std::cout << "Operation you wish to perform"    << std::endl;
        std::cout << "1) Add cliente"                   << std::endl;
        std::cout << "2) Show first client"             << std::endl;
        std::cout << "3) Eliminate customer"            << std::endl;
        std::cout << "4) Show all clients"              << std::endl;
        std::cout << "5) Eliminate all queue"           << std::endl;
        std::cout << "6) Output..."                     << std::endl;
        std::cin >> operation;
        switch(operation)
        {
            case 1: add_client();        break;
            case 2: show_first_client(); break;
            case 3: eliminate_client();  break;
            case 4: show_all_clients();  break;
            case 5: eliminate_queue();   break;
            case 6: flg = false;         break; 
            default: std::cout << "Invalid operation" << std::endl; break; 
        }
        std::cin.get();
        std::cin.get();
        system("clear");
    }
}