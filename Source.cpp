#include <iostream>
#include <windows.h>
using namespace std;
class knight {
	//Данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
public:
	//setter,функции - сеттеры(заменяют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string setName() { return m_name; }
	//вместо сеттеров один конструктор
	knight(string name, double hp, double damage) {
		m_hp = hp;
		m_damage = damage;
		m_name = name;
	}

	//увелечение дамага
	void increaseDamage() {
		m_damage *= 1.1;
	}
	void attack(mage &m1){
		m1.setHp(m1.getHp() - getDamage());
	}
	void print() {
		
		cout << "Knight name " << m_name << endl;
		cout << "Knight hp " << m_hp << endl;
		cout << "Knight damage " << m_damage << endl;
	}
};
class mage {
	//Данные объекта
private:
	double m_hp;
	double m_damage;
	string m_name;
	//методы класса(функции,определяющие поведение объекта)
public:
	//setter,функции - сеттеры(заменяют присваивание)
	void setHp(double hp) { m_hp = hp; }
	void setDamage(double damage) { m_damage = damage; }
	void setName(string name) { m_name = name; }
	//геттер
	double getHp() { return m_hp; }
	double getDamage() { return m_damage; }
	string setName() { return m_name; }

	//увелечение дамага
	void increaseHp(double addHp) {
		m_hp += addHp;
	}
	void print() {
		cout << "Mage name " << m_name << endl;
		cout << "Mage hp " << m_hp << endl;
		cout << "Mage damage " << m_damage << endl;
	}
};


int main() {

	knight k1("Valera",100,20);
	//записали данные
	/*k1.setName("Valera");
	k1.setHp(100);
	k1.setDamage(20);
	k1.print();*/
	mage m1;
	m1.setName("Travis");
	m1.setHp(50);
	m1.setDamage(20);
	m1.print();
	//основной игровой цикл
	while (true) {
		//ход рыцаря
		cout << "knight hit mage" << endl;
		k1.attack(m1);
		m1.print();
		if (m1.getHp() <= 0) {
			cout << "knight win" << endl;
			break;
		}
		//рыцарь увеличил дамаг
		k1.increaseDamage();
		Sleep(3000);
		//ход мага
		cout << "mage hit knight" << endl;
		k1.setHp(k1.getHp() - m1.getDamage());
		k1.print();
		if (k1.getHp() <= 0) {
			cout << "mage win" << endl;
			break;
		}
		m1.increaseHp(50);
		Sleep(3000);
	}
	return 0;
}