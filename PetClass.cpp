//Завдання №1
//cтворити базовий клас «Домашня тварина» і похідні класи «Собака», «Кішка», «Папуга».
//За допомогою конструктора встановити ім’я кожної тварини і її характеристики.


#include <iostream>

using namespace std;

class IAnimal // класс "млекопитающие" - описывает способ перемещения, питание
{
public:
	virtual void Feed() = 0;
	virtual void Move() = 0;
	virtual void Print() = 0;
	virtual ~IAnimal() {};
};

class IMammal // класс "млекопитающие" - описывает специфические функции класса
{
public:
	virtual void Pregnancy() = 0;
	virtual ~IMammal() {};
};

class IBirds  // класс "Птицы"  - описывает специфические функции класса
{
public:
	virtual void WingFunction() = 0;
	virtual ~IBirds() {};
};



class Pet : public IAnimal // базовый класс
{
protected:
	string name;
	string feed;
	string gender;
	int weight;
public:
	Pet(string name, string feed, string gender, int weight) : name(name), feed(feed), gender(gender), weight(weight)
	{
		//cout << endl << "Pet constructor";
	}

	void Print()
	{
		cout << endl << endl << "Pet: " << this->name << "\tFeed: " << this->feed << "\tGender: " << this->gender << "\tWeight: " << this->weight << endl;
	}
	virtual ~Pet() {}// cout << endl << "Pet destructor";
};



class Cat : public Pet, IMammal
{
public:
	Cat(string feed, string gender, int weight) : Pet("Cat", feed, gender, weight)
	{
		//cout << endl << "Cat constructor";
	}
	void Move() override { cout << "Cat walks"; }
	void Feed() override { cout << "Cat eats meat"; }
	void Pregnancy() override { cout << endl << "Cat gestation period is 65 days"; }
	~Cat() { }//cout << endl << "Cat destructor"; }
};



class Dog : public Pet, public IMammal//, public IAnimal
{
public:
	Dog(string feed, string gender, int weight) : Pet("Dog", feed, gender, weight)
	{
		//cout << endl << "Dog constructor";
	}
	void Move() override { cout << "Dog walks"; }
	void Feed() override { cout << "Dog eats meat"; }
	void Pregnancy() override { cout << "Dog gestation period is 60 days"; }
	~Dog() {} //cout << endl << "Dog destructor"; }
};


class Parrot : public Pet, public IBirds
{
public:
	Parrot(string feed, string gender, int weight) : Pet("Parrot", feed, gender, weight)
	{
		//cout << endl << "Parrot constructor";
	}
	void Move() override { cout << "Parrot flies"; }
	void Feed() override { cout << "Parrot eats cereal"; }
	void WingFunction() override { cout  << "Parrot uses wings to fly"; }
	~Parrot() { }//cout << endl << "Parrot destructor";

};



class MyPetsCatalog
{
public:
	void AnimalMoving(IAnimal& animal)
	{
		{ cout << endl << "The way of moving the animal: "; }
		animal.Move();
	}
	void PrintInfo(IAnimal& animal)
	{
		cout << endl << "________________________________________________________________________________ "; 
		cout << endl << "info about animal: ";
		animal.Print();
	}
	void AnimalFeeding(IAnimal& animal)
	{
		{ cout << endl << "The animal feeding: "; }
		animal.Feed();
	}
	void AnimalWingFunction(IBirds& animal)
	{
		{ cout << endl << "The animal WingFunction: "; }
		animal.WingFunction();
	}
	void AnimalPregnancy(IMammal& animal)
	{
		{ cout << endl << "The animal pregnancy: "; }
		animal.Pregnancy();
	}

};



int main()
{
	Pet* pets[3] = { new Cat("parrots", "male", 6) , new Dog("cats", "male", 12) , new Parrot("cereal", "female", 1) }; //создание объектов через указатель на базовый класс
	MyPetsCatalog MyPets;
	for (size_t i = 0; i < 3; i++)
	{
		MyPets.PrintInfo(*pets[i]);
		MyPets.AnimalMoving(*pets[i]);
		MyPets.AnimalFeeding(*pets[i]);
	}



	cout << endl << "________________________________________________________________________________ ";
	cout << endl << "creating an object directly:";
	Parrot parrot = Parrot("cereal", "female", 1); //создание объекта напрямую
	MyPets.PrintInfo(parrot);
	MyPets.AnimalWingFunction(parrot);

	cout << endl << "________________________________________________________________________________ ";
	cout << endl << "creating an object directly:";
	Dog* dog = new Dog("cats", "female", 10);//создание объекта через интерфейс
	MyPets.PrintInfo(*dog);
	MyPets.AnimalPregnancy(*dog);

	for (size_t i = 0; i < 3; i++)
	{
		delete pets[i];
		pets[i] = nullptr;
	}

	delete dog;
}






