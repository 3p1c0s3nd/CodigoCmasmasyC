#include <iostream>
#include <string>

std::string cifrar(const std::string& texto, int desplazamiento) {
    std::string resultado = "";

    for (char c : texto) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = (c - base + desplazamiento) % 26 + base;
        }
        resultado += c;
    }

    return resultado;
}

std::string descifrar(const std::string& textoCifrado, int desplazamiento) {
    return cifrar(textoCifrado, 26 - desplazamiento);
}

int main() {
    std::string texto = "Hello, World!";
    int desplazamiento = 4;

    std::string textoCifrado = cifrar(texto, desplazamiento);
    std::string textoDescifrado = descifrar(textoCifrado, desplazamiento);

    std::cout << "Texto original: " << texto << std::endl;
    std::cout << "Texto cifrado: " << textoCifrado << std::endl;
    std::cout << "Texto descifrado: " << textoDescifrado << std::endl;

    return 0;
}
