#include <iostream>
#include <chrono>

using namespace std;

class lazy_cahe {
    public:
        lazy_cahe() : has_approx_(false), approx_(0.0) {}
        
        double lazy_operation() const 
        {
            if (not has_approx_) {
                approx_     = pi_as_double();
                has_approx_ = true;
            }
            return approx_;
        }

    private:
        double pi_as_double() const
        {
            double sum = 0.0;
            long int     it = 2000000000;

            for (int i = 0; i < it; ++i) {
                sum = sum + (i % 2 == 0 ? 1.0 : -1.0) / (2 * i + 1);
            }

            return sum * 4;
        }
        mutable double approx_;
        mutable bool   has_approx_;
};

int main(int argc, char **argv)  
{

    auto start = std::chrono::high_resolution_clock::now();
    
    lazy_cahe get_pi;

    cout << "First calculation of pi: " << get_pi.lazy_operation() << endl;
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    cout << "Calculation time: " << duration.count() << " seconds" << endl;
    
    start = chrono::high_resolution_clock::now();
    cout << "Obtaining the value (cache): " << get_pi.lazy_operation() << endl;
    end = chrono::high_resolution_clock::now();
    duration = end - start;
    cout << "Obtaining ti: " << duration.count() << " seconds" << endl;

    return 0;
}