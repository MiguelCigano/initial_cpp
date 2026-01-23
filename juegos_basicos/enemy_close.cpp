#include <iostream>

constexpr int nn = 3;

class PlayEnemy {
    public:
        PlayEnemy(int *v, int (*pM)[nn], const int ln, int dm);
        ~PlayEnemy();
        void show_play1D();
        void show_play2D();

    private:
        int *vec_;
        int (*vec2D_)[nn];
        int ln_;
        int ln2D_;
};

PlayEnemy::PlayEnemy(int *v, int (*pM)[nn], const int ln, int dim)
    : vec_(v), vec2D_(pM), 
      ln_(ln), ln2D_(dim) {}

PlayEnemy::~PlayEnemy() {}

void PlayEnemy::show_play1D() {
    const int *v  = vec_;       // "this" not use
    const int &ln = ln_;        // "this" not use
    int i = 0;

    while (i < ln) {
        std::cout << v[i] << " ";
        i++;
    }
    std::cout << std::endl;
}

void PlayEnemy::show_play2D() {
    int i = 0;
    int j = 0;
    
    while (i < this->ln2D_) {
        while (j < this->ln2D_) {
            std::cout << this->vec2D_[i][j] << " ";
            j++;
        }
        std::cout << std::endl;
        j = 0;
        i++;
    }
}

int main (int argc, char **argv) {
    int vtr[]       = {1, 1, 1, 1};
    int mtx[][nn]   =  {{1, 0, 1}, 
                        {0, 1, 0},
                        {1, 0, 1}};
    int (*pMtx)[nn];
    pMtx = mtx;
    int length = sizeof(vtr) / sizeof(vtr[0]);
    int dim = sizeof(mtx) / sizeof(*pMtx);

    PlayEnemy Enemy(vtr, pMtx, length, dim);

    std::cout << "Lenght: " << length << std::endl;
    Enemy.show_play1D();
    std::cout << "Dimention: " << dim << std::endl;
    Enemy.show_play2D();
    
    return 0;
}