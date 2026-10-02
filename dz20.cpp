#include <iostream>
#include "Player.h"

int main() {
    std::cout << "Гравців на сервері: " << Player::getPlayerCount() << "\n\n";

    Player p1("Arthur", 100, 5);
    Player p2;

    std::cout << "Гравців після створення p1 та p2: " << Player::getPlayerCount() << "\n\n";

    std::cout << "--- Початковий стан ---\n";
    p1.printStats();
    p2.printStats();

    std::cout << "--- Зміна імені для p2 (перевиділення пам'яті) ---\n";
    p2.setName("ShadowNinja");
    p2.printStats();

    std::cout << "--- Тест ігрової логіки для p1 ---\n";
    p1.takeDamage(40);
    std::cout << "Після отримання 40 шкоди:\n";
    p1.printStats();

    p1.heal(25);
    std::cout << "Після лікування на 25 HP:\n";
    p1.printStats();

    p1.levelUp();
    std::cout << "Після підняття рівня:\n";
    p1.printStats();

    std::cout << "--- Тест граничних значень здоров'я ---\n";
    p2.takeDamage(150);
    std::cout << "Після 150 шкоди (здоров'я не має впасти нижче 0):\n";
    p2.printStats();

    p2.heal(200);
    std::cout << "Після лікування на 200 HP (максимум 100):\n";
    p2.printStats();

    {
        Player p3("TemporaryPlayer", 80, 2);
        std::cout << "Створено тимчасового гравця p3. Гравців на сервері: "
            << Player::getPlayerCount() << "\n";
    }

    std::cout << "Тимчасовий гравець p3 вийшов з області видимості.\n";
    std::cout << "Загальна кількість гравців зараз: " << Player::getPlayerCount() << "\n";

}