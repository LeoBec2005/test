#include <iostream>
#include <iomanip>
#include <bitset>
#include <cstdint>

void mostrarBits(float valor) {
    uint32_t bits;
    std::memcpy(&bits, &valor, sizeof(bits));
    std::cout << std::bitset<32>(bits) << std::endl;
}

void descomponerFloat(float valor, bool& signo, int& exponente, uint32_t& mantisa) {
    uint32_t bits;
    std::memcpy(&bits, &valor, sizeof(bits));

    signo = (bits >> 31) & 1;
    exponente = ((bits >> 23) & 0xFF) - 127;
    mantisa = bits & 0x7FFFFF;
    mantisa |= (1 << 23);
}

float ensamblarFloat(bool signo, int exponente, uint32_t mantisa) {
    uint32_t resultado = 0;
    exponente += 127;
    resultado |= (signo << 31);
    resultado |= (exponente & 0xFF) << 23;
    resultado |= (mantisa & 0x7FFFFF);

    float resultadoFloat;
    std::memcpy(&resultadoFloat, &resultado, sizeof(resultadoFloat));
    return resultadoFloat;
}

float multiplicarFloat(float a, float b) {
    if (a == 0.0f || b == 0.0f) {
        return 0.0f;
    }

    bool signoA, signoB;
    int exponenteA, exponenteB;
    uint32_t mantisaA, mantisaB;

    descomponerFloat(a, signoA, exponenteA, mantisaA);
    descomponerFloat(b, signoB, exponenteB, mantisaB);

    bool signoResultado = signoA ^ signoB;
    int exponenteResultado = exponenteA + exponenteB;

    uint64_t mantisaResultado = (uint64_t)mantisaA * (uint64_t)mantisaB;

    if (mantisaResultado & (1ULL << 47)) {
        mantisaResultado >>= 1;
        exponenteResultado++;
    }

    mantisaResultado = (mantisaResultado >> 23) & 0x7FFFFF;

    if (exponenteResultado >= 128) {
        return std::numeric_limits<float>::infinity();
    }
    else if (exponenteResultado <= -127) {
        return 0.0f;
    }

    return ensamblarFloat(signoResultado, exponenteResultado, (uint32_t)mantisaResultado);
}

int main() {
    float a, b;

    std::cout << "Ingrese el primer valor: ";
    std::cin >> a;
    std::cout << "Ingrese el segundo valor: ";
    std::cin >> b;

    std::cout << "Bits del primer valor: ";
    mostrarBits(a);
    std::cout << "Bits del segundo valor: ";
    mostrarBits(b);

    float resultadoEmulado = multiplicarFloat(a, b);
    float resultadoNativo = a * b;

    std::cout << "Resultado emulado: " << resultadoEmulado << std::endl;
    std::cout << "Resultado nativo: " << resultadoNativo << std::endl;

    std::cout << "Bits del resultado emulado: ";
    mostrarBits(resultadoEmulado);

    std::cout << "Bits del resultado nativo: ";
    mostrarBits(resultadoNativo);

    return 0;
}
