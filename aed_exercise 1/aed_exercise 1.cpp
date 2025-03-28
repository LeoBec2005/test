#include <iostream>
#include <chrono>
#include <random>

bool compare(int a, int b) {
    return a >= b;
}

struct Polymorphism {
    virtual void bubble_sort_polymorphism() = 0;
};

struct Compare {
    bool operator()(int a, int b) {
        return a >= b;
    }
};

struct Bubble_sort : public Polymorphism {
    int* arr;
    int size;

    Bubble_sort(int size_h) {
        size = size_h;
        arr = new int[size_h];
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dis(0, 100);
        for (int i = 0; i < size_h; i++) {
            arr[i] = dis(gen);
        }
    }

    ~Bubble_sort() {
        delete[] arr;
    }

    void swap(int& a, int& b) {
        int aux = b;
        b = a;
        a = aux;
    }

    void bubble_sort() {
        int* start = arr;
        int* end = arr + size;
        while (end != start) {
            int* first = arr;
            int* second = arr + 1;
            while (second != end) {
                if (*first >= *second) {
                    swap(*first, *second);
                }
                first++;
                second++;
            }
            end--;
        }
    }

    void bubble_sort_polymorphism() override {
        bubble_sort();
    }

    void bubble_sort_functor() {
        Compare compare;
        int* start = arr;
        int* end = arr + size;
        while (end != start) {
            int* first = arr;
            int* second = arr + 1;
            while (second != end) {
                if (compare(*first, *second)) {
                    swap(*first, *second);
                }
                first++;
                second++;
            }
            end--;
        }
    }

    void bubble_sort_pointer() {
        bool (*ptr)(int, int) = compare;
        int* start = arr;
        int* end = arr + size;
        while (end != start) {
            int* first = arr;
            int* second = arr + 1;
            while (second != end) {
                if (ptr(*first, *second)) {
                    swap(*first, *second);
                }
                first++;
                second++;
            }
            end--;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << " ( " << arr[i] << " ) ";
        }
        std::cout << std::endl;
    }
};

void measure_time(void (Bubble_sort::* sort_method)(), const std::string& method_name, int size) {
    Bubble_sort obj(size);

    auto start = std::chrono::high_resolution_clock::now();
    (obj.*sort_method)();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> duration = end - start;
    std::cout << method_name << " took " << duration.count() << " µs\n";
    std::cout << std::endl;
}

int main() {
    int size = 5000;


    measure_time(&Bubble_sort::bubble_sort, "Bubble Sort (Normal)", size);
    measure_time(&Bubble_sort::bubble_sort_polymorphism, "Bubble Sort (Polymorphism)", size);
    measure_time(&Bubble_sort::bubble_sort_functor, "Bubble Sort (Functor)", size);
    measure_time(&Bubble_sort::bubble_sort_pointer, "Bubble Sort (Pointer to Function)", size);

    return 0;
}
