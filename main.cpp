#include <iostream>

// Рекурсивная функция для перемещения колец
void rearrangeHanoiTowers(const int n, const int current_pole, const int to_pole, const int buffer_pole) {
    if (n == 1) {
        // Критический случай, когда осталось одно кольцо, перекладываем его, начинаю выход из рекурсии
        std::cout << "Кольцо номер " << n << " перекладываем на стойку " << to_pole << std::endl;
        return;
    }

    // Перемещаю n-1 кольцо с начальной стойки на вспомогательную
    rearrangeHanoiTowers(n - 1, current_pole, buffer_pole, to_pole);

    // Перемещаю большое с номером n кольцо на последнюю стойку
    std::cout << "Кольцо номер " << n << " перекладываем на стойку " << to_pole << std::endl;

    // Перемещаю кольцо чуть меньше с вспомогательной стойки на конечную
    rearrangeHanoiTowers(n - 1, buffer_pole, to_pole, current_pole);
}

int main() {
    // Я работаю в CLion и у меня в консоли какая-то бяка вместо кириллицы.
    system("chcp 65001"); // Эта строка решает мою проблему

    int n;
    std::cout << "Введите количество колец: ";
    std::cin >> n;

    // Тут я перекладываю башню с первой стойки на третью, а вторая у меня вспомогательная
    rearrangeHanoiTowers(n, 1, 3, 2);
    return 0;
}
