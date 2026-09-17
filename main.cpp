#include <iostream>
#include <string>
#include <vector>
#include <format>

// Массив доступных операторов
const std::vector<std::string> opes = { "+", "-", "*", "/" };

bool checkOpe(std::string ope) {
    bool isIn = false;

    // Аналог for ... of из js
    for (std::string n : opes) {
        if (n == ope) {
            isIn = true;
            break;
        };
    };

    return isIn;
};

float calculations(float n1, float n2, std::string ope) {
    if (ope == "+") {
        return n1 + n2;
    }
    else if (ope == "-") {
        return n1 - n2;
    }
    else if (ope == "*") {
        return n1 * n2;
    }
    else if (ope == "/") {
        return n1 / n2;
    };
};

void end(std::vector<std::string> results) {
    short localN = 1;
    for (short i = 0; i < results.size(); i += 3) {
        float res = calculations(std::stof(results[i]), std::stof(results[i + 1]), results[i + 2]);
        std::cout << "Пример" << localN << ": " << results[i] << " " << results[i + 2] << " " << results[i + 1] << " = " << res << "\n";
        localN++;
    };
};

int main() {
    setlocale(0, "");
    short globalN{ 1 };

    // Масив результатов
    std::vector<std::string> results = {};

    while (true) {
        // One number
        std::cout << "Enter one number for " << globalN << " примера или end что бы закончить: ";
        std::string c1{};
        std::cin >> c1;
        if (c1 == "end") {
            end(results);
            break;
        };
        float n1{};
        try {
            n1 = std::stof(c1);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.";
            continue;
        }
        catch (const std::out_of_range) {
            std::cout << "Вы ввели слишком большое число.";
            continue;
        };
        // Очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Two number
        std::cout << "\n\nEnter one number for " << globalN << " примера или end что бы закончить: ";
        std::string c2{};
        std::cin >> c2;
        if (c2 == "end") {
            end(results);
            break;
        };
        float n2{};
        try {
            n2 = std::stof(c2);
        }
        catch (const std::invalid_argument& e) {
            std::cout << "Вы ввели не число.";
            continue;
        }
        catch (const std::out_of_range) {
            std::cout << "Вы ввели слишком большое число.";
            continue;
        };
        // Очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Operator
        std::cout << "\n\nEnter operator или end что бы закончить: ";
        std::string ope;
        std::cin >> ope;
        if (ope == "end") {
            end(results);
            break;
        };
        if (ope.size() > 1 || checkOpe(ope) == false) {
            std::cout << "\nВы ввели невалидный оператор.\n";
            continue;
        };

        if (ope == "/" && n2 == 0) {
            std::cout << "Нельзя делить на ноль";
            continue;
        };
        // Очистка буфера ввода
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        // Если выполнение дошло до сюда значит оба числа и оператор валидные и их можно добавлять в results
        results.push_back(std::to_string(n1));
        results.push_back(std::to_string(n2));
        results.push_back(ope);
        float res = calculations(n1, n2, ope);
        std::cout << "Пример" << globalN << ": " << n1 << " " << ope << " " << n2 << " = " << res << "\n";
        globalN++;
    };

    return 0;
}



/*
#include <iostream>
#include <string>
#include <limits>
#include <format>

int main() {
  setlocale(LC_ALL, "");


  std::cout << "Enter number 1: ";
  std::string c1;
  float n1;
  std::cin >> c1;
  try {
      n1 = std::stof(c1);
  } catch (std::out_of_range& e) {
      std::cout << "big number.\n";
      return 0;
  } catch (std::invalid_argument& e) {
      std::cout << "not number\n";
      return 0;
  };
  std::cout << "\n";
  // Очистка буфера ввода
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


  std::cout << "Enter number 2: ";
  std::string c2;
  float n2;
  std::cin >> c2;
  try {
      n2 = std::stof(c2);
  }
  catch (std::out_of_range& e) {
      std::cout << "gi number.\n";
      return 0;
  }
  catch (std::invalid_argument& e) {
      std::cout << "Вnot number\n";
      return 0;
  };
  std::cout << "\n";
  // Очистка буфера ввода
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  std::cout << "Enter operator(+, -, *, /): ";
  std::string ope;
  std::cin >> ope;
  if (ope == "+") {
	  std::cout << "Result: " << n1 << " " << ope << " " << n2 << " = " << n1 + n2 << "\n";
  } else if (ope == "-") {
      std::cout << "Result: " << n1 << " " << ope << " " << n2 << " = " << n1 - n2 << "\n";
  } else if (ope == "*") {
	  std::cout << "Result: " << n1 << " " << ope << " " << n2 << " = " << n1 * n2 << "\n";
  } else if (ope == "/") {
	  if (n2 == 0) {
		  std::cout << "not / 0.\n";
	  }
	  else {
		  std::cout << "Result: " << n1 << " " << ope << " " << n2 << " = " << n1 / n2 << "\n";
	  };
  }
  else {
	  std::cout << "ne znay takoi operator\n";
  };

  return 0;
};
*/
