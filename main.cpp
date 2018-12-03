#include "math.h"
#include <iostream>
#include <string>
using namespace std;

class Window {
private:
	float height, width;
public:
	void getParams() {		
		cout << "Введите высоту окна: ";
		cin >> height;
		cout << "Введите ширину окна: ";
		cin >> width;
	}

	float getWindowSurface() {
		return height * width;
	}


};

class Parket {
private:
	float length, width;
public:
	void getParams() {
		cout << "Введите длину паркета: ";
		cin >> length;
		cout << "Введите ширину паркета: ";
		cin >> width;
	}

	float getParketSurface() {
		return length * width;

};

class Room {
private:
	float length, width, height;
	int numWindows;
	string color;
	float LperM2;
	Window window;
	Parket parket;
	
public:
	float getFloorSurface() {
		return length * width;
	}

	float getWallSurface() {
		return height * (length + width) * 2;
	}

	float getVollume() {
		return height * length * width;
	}

	float getPaintAmount() {
		return (getWallSurface() - getGlassAmount()) * LperM2;
	}

	float getGlassAmount() {
		return window.getWindowSurface() * numWindows;
	}

	int getParketAmount() {
		return ceil(getFloorSurface() / parket.getParketSurface());
	}

	void getParams() {
		cout << endl << "Введите высоту комнаты: ";
		cin >> height;
		cout << "Введите ширину комнаты: ";
		cin >> width;
		cout << "Введите длину комнаты: ";
		cin >> length;
		cout << "Введите количество окон: ";
		cin >> numWindows;
		cout << "Цвет стен: ";
		cin >> color;
		cout << "Объём на кв. метр: ";
		cin >> LperM2;
		cout << endl;
		window.getParams();
		cout << endl;
		parket.getParams();
	}

	void printRoomAmounts() {
		cout << "Количество паркетных досок: " << getParketAmount() << endl;
		cout << "Стекла для окон: " << getGlassAmount() << endl;
		cout << "Количество краски цвета " << color << ": " << getPaintAmount() << endl;
		cout << "Объем комнаты: " << getVollume() << endl;
	}

};

class Flat {
private:
	int numRooms;
	Room* rooms;
	float flatVoll = 0;
	float paintAmount = 0;
	int parketAmount = 0;
	float glassAmount = 0;
public:

	void getParams() {
		cout << endl << "Введите число комнат: ";
		cin >> numRooms;
		rooms = new Room[numRooms];
		for(int i = 0; i < numRooms; ++i) {
			cout << endl << "Комната номер " << i + 1;
			rooms[i].getParams();
			rooms[i].printRoomAmounts();
		}
	}

	float getFlatVoll() {
		for (int i = 0; i < numRooms; ++i) {
			flatVoll += rooms[i].getVollume();
		}
		return flatVoll;
	}


	float getPaintAmount() {
		for (int i = 0; i < numRooms; ++i) {
			paintAmount += rooms[i].getPaintAmount();
		}
		return paintAmount;
	}

	float getGlassAmount() {
		for (int i = 0; i < numRooms; ++i) {
			glassAmount += rooms[i].getGlassAmount();
		}
		return glassAmount;
	}

	int getParketAmount() {
		for (int i = 0; i < numRooms; ++i) {
			parketAmount += rooms[i].getParketAmount();
		}
		return parketAmount;
	}

	void printFlatAmounts() {
		cout << endl << "Количество паркетных досок: " << getParketAmount() << endl;
		cout << "Количество стекла для окон: " << getGlassAmount() << endl;
		cout << "Количество краски: " << getPaintAmount() << endl;
		cout << "Объем квартиры: " << getFlatVoll() << endl;
	}

	void destructor() {
		delete[] rooms;
	}
};

class House {
private:
	int numFloors;
	int numFlats;
	Flat* flats;
	float houseVoll = 0;
	float paintAmount = 0;
	int parketAmount = 0;
	float glassAmount = 0;
public:
	void getParams() {
		cout << "Введите количество этажей: ";
		cin >> numFloors;
		cout << "Введите количество квартир на этаже: ";
		cin >> numFlats;
		flats = new Flat[numFloors * numFlats];
		for (int i = 0; i < numFloors * numFlats; ++i) {
			cout << endl << "Квартира номер " << i + 1;
			flats[i].getParams();
		}
	}

	float getHouseVoll() {
		for (int i = 0; i < numFloors * numFlats; ++i) {
			houseVoll += flats[i].getFlatVoll();
		}
		return houseVoll;
	}


	float getPaintAmount() {
		for (int i = 0; i < numFloors * numFlats; ++i) {
			paintAmount += flats[i].getPaintAmount();
		}
		return paintAmount;
	}

	float getGlassAmount() {
		for (int i = 0; i < numFloors * numFlats; ++i) {
			glassAmount += flats[i].getGlassAmount();
		}
		return glassAmount;
	}

	int getParketAmount() {
		for (int i = 0; i < numFloors * numFlats; ++i) {
			parketAmount += flats[i].getParketAmount();
		}
		return parketAmount;
	}

	void printHouseAmounts() {
		cout << endl << "------------------------------------------------------------------" << endl;
		cout << endl << "Количество паркетных досок: " << getParketAmount() << endl;
		cout << "Количество стекла для окон: " << getGlassAmount() << endl;
		cout << "Количество краски: " << getPaintAmount() << endl;
		cout << "Объем дома: " << getHouseVoll() << endl;
	}

	void destructor() {
		delete[] flats;
	}
};

int main(){
	
	House house;
	house.getParams();
	house.printHouseAmounts();
	system("pause");
	return 0;
}
