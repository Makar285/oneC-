#include <iostream>
#include <string>
#include <vector>
#include <format>

// Массив доступных операторов
const std::vector<std::string> opes = {"+", "-", "*", "/"};

bool checkOpe(std::string ope) {
    bool isIn = false;

    // 4 Это длина opes
    for(std::string n : opes) {
        if(n == ope) {
            isIn = true;
            break;
        };
    };

    return isIn;
};

float calculations(float n1, float n2, std::string ope) {
    if(ope == "+") {
        return n1 + n2;
    } else if(ope == "-") {
        return n1 - n2;
    } else if(ope == "*") {
        return n1 * n2;
    } else if(ope == "/") {
        return n1 / n2;
    };
};

void end(std::vector<std::string> results) {
    short localN = 1;
    for(short i = 0; i < results.size(); i += 3) {
        float res = calculations(results[i], results[i+1], results[i+2]);
        std::format("Пример{localN}: {resuls[i]} {results[i+2]} {results[i+1] = {res}}\n");
        localN++;
    };
};

int main() {
    setlocale(0, "");
    short globalN{1};

    // Масив результатов
    std::vector<std::string> results = {};

    while (true) {
        // One number
        std::cout << "Enter one number for " << n << " примера или end что бы закончить: ";
        std::string c1{};
        std::cin >> c1;
        if(c1 == "end") {
            end(results);
            break;
        };
        float n1{};
        try {
            n1 = std::stoi(c1);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.";
            continue;
        } catch(const std::out_of_range) {
            std::cout << "Вы ввели слишком большое число.";
            continue;
        };

        // Two number
        std::cout << "\n\nEnter one number for " << n << " примера или end что бы закончить: ";
        std::string c2{};
        std::cin >> c2;
        if(c2 == "end") {
            end(results);
            break;
        };
        float n2{};
        try {
            n1 = std::stoi(c2);
        } catch(const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.";
            continue;
        } catch(const std::out_of_range) {
            std::cout << "Вы ввели слишком большое число.";
            continue;
        };

        // Operator
        std::cout << "\n\nEnter operator или end что бы закончить: ";
        std::string ope;
        std::cin >> ope;
        if(ope == "end") {
            end(results);
            break;
        };
        if(ope.size() > 1 || checkOpe(ope) == false) {
            std::cout << "\nВы ввели невалидный оператор.\n";
            continue;
        };

        if(ope == "/" && n2 == 0) {
            std::cout << "Нельзя делить на ноль";
            continue;
        };

        // Если выполнение дошло до сюда значит оба числа и оператор валидные и их можно добавлять в results
        results.push_back(std::to_string(n1));
        results.push_back(std::to_string(n2));
        results.push_back(ope);
        float res = calculations(n1, n2, ope);

        std::cout << std::format("Пример{globalN}: {n1} {ope} {n2} = {res}\n");
        globalN++;
    };

    return 0;
}
