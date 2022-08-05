 #ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <iostream>
#include <iomanip>


const int MAX = 50;
const double MARKUP_EXTREME = 1.5;
const double MARKUP_EXPEDITE = 1.2;
const double MARKUP_STANDARD = 1.1;


using namespace std;

enum rush { EXT, EXP, STAND };

struct Inventory
{
	int qty;
	int qtyLeft;
	int shipmentNum;
	double price;
};

struct Order
{
	int qty;
	int qtyLeft;
	int orderNum;
	rush status;
};


class Warehouse
{
public:
	int invCount;

	Inventory* inventory;

	int orderCount;
	Order* order, * heap;
	static int orderNum;
	static int shipmentNum;

	Warehouse();
	~Warehouse();

	void orderPush(int, rush);
	void orderPush();
	void orderPop();
	void orderInfo();
	bool isFullOrder();
	bool isEmptyOrder();
	void orderShow();

	void inventoryPush(int, double);
	void inventoryPush();
	void inventoryPop();
	void inventoryInfo();
	bool inventoryIsFull();
	bool inventoryIsEmpty();
	void inventoryShow();

	void heapCreate(int);
	void swapFromParent(int);
	void heapSort(int);
	void swapFirstLast(int);
	void heapCopy();
	void reheapDown(int, int);
	void deliver();
	void shipmentReport(int, double, double);
	void menu();
};


#endif // !WAREHOUSE_H


