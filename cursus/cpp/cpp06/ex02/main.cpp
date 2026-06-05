#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main() {
    // Inicializar la semilla de aleatoriedad
    std::srand(static_cast<unsigned int>(time(NULL)));

    std::cout << "--- Generando objetos aleatorios ---" << std::endl;
    
    for (int i = 0; i < 5; ++i) {
        Base* obj = Base::generate();
        
        std::cout << "Test " << i + 1 << ":" << std::endl;
        std::cout << "  Identify (Puntero):    ";
        Base::identify(obj);
        
        std::cout << "  Identify (Referencia): ";
        Base::identify(*obj);
        
        // ¡Importante para no tener leaks!
        delete obj;
        std::cout << std::endl;
    }
    
    return 0;
}
