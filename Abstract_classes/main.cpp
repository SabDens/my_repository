#include <iostream>
#include <direct.h>
#include <climits>

class Root
{
public:
	virtual void Root_() const = 0;

};

class linear_equation : public Root
{
private:
	int a;
	int b;
	int c;
public:
	linear_equation(int a1, int b1, int c1) 
		: a(a1), b(b1), c(c1)
	{}
	void Root_() const override {
		std::cout << (c - (b)) / a;
	}
};

class quadratic_equation : public Root
{
private:
	int a;
	int b;
	int c;
public:
	quadratic_equation(int a1, int b1, int c1)
		: a(a1), b(b1), c(c1)
	{}
	void Root_() const override {
		int diskriminant = b * b - 4 * c * a;
		//std::cout << diskriminant;
		if (diskriminant < 0)
		{
			std::cout << "no roots";
			return;

		}
		else if (diskriminant == 0)
		{
			int x = -(b / (a * 2));
			std::cout << x;
			return;
		}
		else
		{
			int x1 = ((-b+diskriminant) / (a * 2));
			int x2 = ((-b - diskriminant) / (a * 2));
			std::cout << "x1 " << x1 <<"\n"<< "x2 "<< x2;
		}
	}
};


//Show() Ч виведенн€ на екран ≥нформац≥њ про ф≥гуру,
//Save() Ч збереженн€ ф≥гури в файл,
//Load() Ч зчитуванн€ ф≥гури з файлу.
class Shape
{
public:
	virtual void Show() const = 0;
	virtual void Save() const = 0;
	virtual void Load()  = 0;
};

class Square : public Shape
{
private:
	char* name;
	int coordinate;
	int side;
public:
	Square(int side1,int coordinate1,const char* name1):side(side1), coordinate(coordinate1){
		size_t temp_size = strlen(name1);
		name = new char[temp_size + 1];
		for (int i = 0; i < temp_size; i++)
		{
			name[i] = name1[i];
		}
		name[temp_size] = '\0';
	}
	void Show() const override {
		
	}
	void Save() const override {
		FILE* file1;
		fopen_s(&file1, "Square.bin", "wb");
		if (file1 != 0) {
			
			fputs("Square\n", file1);
			//у мен€ не получилось сохранить сторону в файл
			//fwrite(&side, sizeof(int), 1, file1);

			fclose(file1);
			std::cout << "Save";
		}
	}
	void Load() override
	{
		FILE* stream;
		fopen_s(&stream, "Square.bin", "rb");
		char buffer[30];
		if (stream)
		{
			size_t res = fread(buffer, sizeof(char), 30, stream);
			//std::cout << "res = " << res << std::endl;
			buffer[res] = '\0';
			delete[] name;
			size_t temp_size = strlen(buffer);
			name = new char[temp_size + 1];
			for (int i = 0; i < temp_size; i++)
			{
				name[i] = buffer[i];
			}
			name[temp_size] = '\0';
			fclose(stream);
		}
	}
};
class Rectangle : public Shape
{
private:
	char* name;
	int coordinate;
	int dimensions;
public:
	Rectangle(int side1, int coordinate1, const char* name1) :dimensions(side1), coordinate(coordinate1) {
		size_t temp_size = strlen(name1);
		name = new char[temp_size + 1];
		for (int i = 0; i < temp_size; i++)
		{
			name[i] = name1[i];
		}
		name[temp_size] = '\0';
	}
	void Show() const override {

	}
	void Save() const override {
		FILE* file1;
		fopen_s(&file1, "Square.bin", "wb");
		if (file1 != 0) {

			fputs("Square\n", file1);
			//у мен€ не получилось сохранить сторону в файл
			//fwrite(&dimensions, sizeof(int), 1, file1);

			fclose(file1);
			std::cout << "Save";
		}
	}
	void Load() override
	{
		FILE* stream;
		fopen_s(&stream, "Square.bin", "rb");
		char buffer[30];
		if (stream)
		{
			size_t res = fread(buffer, sizeof(char), 200, stream);
			//std::cout << "res = " << res << std::endl;
			buffer[res] = '\0';
			delete[] name;
			size_t temp_size = strlen(buffer);
			name = new char[temp_size + 1];
			for (int i = 0; i < temp_size; i++)
			{
				name[i] = buffer[i];
			}
			name[temp_size] = '\0';
			fclose(stream);
		}
	}
};
class Circle : public Shape
{
private:
	char* name;
	int coordinate;
	int radius;
public:
	Circle(int side1, int coordinate1, const char* name1) :radius(side1), coordinate(coordinate1) {
		size_t temp_size = strlen(name1);
		name = new char[temp_size + 1];
		for (int i = 0; i < temp_size; i++)
		{
			name[i] = name1[i];
		}
		name[temp_size] = '\0';
	}
	void Show() const override {

	}
	void Save() const override {
		FILE* file1;
		fopen_s(&file1, "Square.bin", "wb");
		if (file1 != 0) {

			fputs("Square\n", file1);
			//у мен€ не получилось сохранить сторону в файл
			//fwrite(&dimensions, sizeof(int), 1, file1);

			fclose(file1);
			std::cout << "Save";
		}
	}
	void Load() override
	{
		FILE* stream;
		fopen_s(&stream, "Square.bin", "rb");
		char buffer[30];
		if (stream)
		{
			size_t res = fread(buffer, sizeof(char), 200, stream);
			//std::cout << "res = " << res << std::endl;
			buffer[res] = '\0';
			delete[] name;
			size_t temp_size = strlen(buffer);
			name = new char[temp_size + 1];
			for (int i = 0; i < temp_size; i++)
			{
				name[i] = buffer[i];
			}
			name[temp_size] = '\0';
			fclose(stream);
		}
	}
};
class Ellipse : public Shape
{
private:
	char* name;
	int coordinate;
	int radius;
public:
	Ellipse(int side1, int coordinate1, const char* name1) :radius(side1), coordinate(coordinate1) {
		size_t temp_size = strlen(name1);
		name = new char[temp_size + 1];
		for (int i = 0; i < temp_size; i++)
		{
			name[i] = name1[i];
		}
		name[temp_size] = '\0';
	}
	void Show() const override {

	}
	void Save() const override {
		FILE* file1;
		fopen_s(&file1, "Square.bin", "wb");
		if (file1 != 0) {

			fputs("Square\n", file1);
			//у мен€ не получилось сохранить сторону в файл
			//fwrite(&dimensions, sizeof(int), 1, file1);

			fclose(file1);
			std::cout << "Save";
		}
	}
	void Load() override
	{
		FILE* stream;
		fopen_s(&stream, "Square.bin", "rb");
		char buffer[30];
		if (stream)
		{
			size_t res = fread(buffer, sizeof(char), 200, stream);
			//std::cout << "res = " << res << std::endl;
			buffer[res] = '\0';
			delete[] name;
			size_t temp_size = strlen(buffer);
			name = new char[temp_size + 1];
			for (int i = 0; i < temp_size; i++)
			{
				name[i] = buffer[i];
			}
			name[temp_size] = '\0';
			fclose(stream);
		}
	}
};
int main() {
	/*Root* obj1 = new linear_equation(3, 2, 11);
	obj1->Root_();*/
	/*Root* obj2 = new quadratic_equation(1, 3, 0);
	obj2->Root_();*/
	Shape* obj = new Square(12, 5, "Square");
	obj->Save();
	obj->Load();
	return 0;
}