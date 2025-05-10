// [+] 1. Згадаємо інкапсуляцію
// [+] 2. Згадаємо наслідування
// [+] 3. Що таке поліморфізм?
// [+] 4. Визначення поліморфізму
// [ ] 5. Які є типи поліморфізму?
// [ ] 5. Що таке параметризований поліморфізм?
// [ ] 6. Що таке Ad - hoc поліморфізм?
// [ ] 7. Що таке поліморфізм підтипів?
// [ ] 8. Віртуальні функції
// [ ] 9. Поліморфізм і конструктори
// [ ] 10. Поліморфізм і деструктори
// [ ] 11. Ключове слово override
// [ ] 12. Ключове слово final
// [ ] 13. Що таке раннє і пізнє зв'язування?
// [ ] 14. Таблиця віртуальних функцій

#include <iostream>
#include <windows.h>
#include "Bow.h"
#include "Archer.h"
#include "Sword.h"
#include "Swordsman.h"
#include "Team.h"
#include "Position.h"
#include "Array.h"
#include "IPrint.h"

int main()
{
	srand(time(nullptr));
	Bow Bow1("Strong Bow", 10);
	Sword Sword1("Sharp Sword", 20);

	Archer archer1("Bob", 100, 30, &Bow1);
	Swordsman shwordman1("Rex1", 10, &Sword1);
	Swordsman shwordman2("Rex2", 20, &Sword1);
	Swordsman shwordman3("Rex3", 30, &Sword1);
	Swordsman shwordman4("Rex4", 40, &Sword1);

	archer1.print();
	//archer1.Attack(shwordman1);
	//shwordman1.Attack(archer1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);
	//archer1.Attack(shwordman1);

	//Team team1;

	//Team team2;
	//team1.Add(archer1);
	//team2.Add(shwordman1);
	//team2.Add(shwordman2);
	//team2.Add(shwordman3);
	//team2.Add(shwordman4);

	//team1.Attack(team2);
	//team2.Attack(team1);

	//Position p1(0, 5);
	//Position p2(10, 20);
	//int distance;
	//do
	//{
	//	distance = p1.Distance(p2);
	//	std::cout << p1.Distance(p2) << '\n';
	//	p1.MoveTowards(p2);
	//	p2.print();
	//	p1.print();
	//	//system("pause");
	//	Sleep(1000);
	//	system("cls");
	//} while (distance > 0);

	IPrint* p;
	Array<int> arr = { 1,2,3,4,5 };
	p = &arr;
	p->print();
	std::cout << "size = " << arr.get_size() << std::endl;
	arr.erase(2);
	p->print();
	std::cout << "size = " << arr.get_size() << std::endl;
	return 0;
}