#include <iostream>

typedef uint32_t ui32;
typedef uint16_t ui16;
typedef uint8_t  ui8;

constexpr ui8  AGE_REP = 2;
constexpr ui16 STEP    = 0;

class Reptile {
    protected:
        ui8 its_age;
        ui16 count_step;
    
    public:
        Reptile() : its_age(AGE_REP), count_step(STEP)
        { 
            std::cout << "Reptile-constructor" << "\n";
        }

        virtual ~Reptile() {
            std::cout << "Reptile-destructor" << "\n";
        }

        // Non-virtual, will call Reptile::move even from a Frog pointer. 
        void move(ui16 step) { 
            std::cout << "Reptile is moving.." << "\n";
            count_step += step;
            std::cout << "Steps: " << count_step << "\n";
        }

        // Use virtual allow make able Dynamic dispatch
        virtual void speak(ui16 times = 0) const {
            std::cout << "Reptile is speaking" << "\n" ;
        }
};

class Frog : public Reptile {
    public:
        Frog() {
            std::cout << "Frog-constructor" << "\n";
        }

        virtual ~Frog() {
            std::cout << "Frog-destructor" << "\n";
        }

        void move(ui16 step) {
            std::cout << "Frog is moving.." << "\n";
            count_step += step;
            std::cout << "Steps: " << count_step << "\n";
        }

        // Use "override" to ensure the signature matches with base class.
        void speak(ui16 times) const override {
            for (auto i = 0; i < times; ++i) {
                std::cout << "Croack!" << "\n" ;
            }
        }

};

int main() {
    Reptile* p_frog = new Frog;
    p_frog->move(2);
    p_frog->move(1);
    p_frog->speak(3);
    delete p_frog;
    return 0;
}