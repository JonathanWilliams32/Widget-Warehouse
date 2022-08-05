#include "warehouse.h"

#include <iostream>
#include <iomanip>

using namespace std;

int Warehouse::orderNum = 0;
int Warehouse::shipmentNum = 0;

Warehouse::Warehouse()
{
	invCount = 0;
	orderCount = 0;
	orderNum = 0;

	try
	{
		order = new Order[MAX];
		heap = new Order[MAX + 1];
		inventory = new Inventory[MAX];
	}
	catch (bad_alloc exeption)
	{
		cout << "Memory full with backorders.\n";
	}
}

Warehouse::~Warehouse()
{
	delete[] order;
	delete[] heap;
	delete[] inventory;
}

//Pushes a shipment into the array on top of the previous new shipment.
//PRE: Warehouse should not be at a full capacity.
//POST: A new shipments will be added.
void Warehouse::inventoryPush()
{
	try
	{
		if (inventoryIsFull()) throw 1;
		inventoryInfo();
	}
	catch (int)
	{
		cout << "Warehouse full.\n";
	}
}


//Pushes a shipment into the array on top of the previous new shipment.
//PRE: Warehouse should not be at a full capacity.
//POST: A new shipments will be added.
void Warehouse::inventoryPush(int q, double p)
{

	try
	{
		if (inventoryIsFull()) throw 1;

		inventory[invCount].qty = q;
		inventory[invCount].qtyLeft = q;
		inventory[invCount].price = p;
		invCount++;
	}
	catch (int)
	{
		cout << "Warehouse full.\n";
	}


}


//Pops the newest shipment.
//PRE: Shipment cannot be empty.
//POST: Warehouse is now 1 less of a shipment.
void Warehouse::inventoryPop()
{
	try
	{
		if (inventoryIsEmpty()) throw 1;
		invCount--;
	}
	catch (int)
	{
		cout << "Warehouse is already empty.\n";
	}
}

void Warehouse::inventoryInfo()
{

	do
	{
		cout << "Enter quantity of units in this Shipment: ";
		cin >> inventory[invCount].qty;

		if (inventory[invCount].qty <= 0)
		{
			cout << "Invalid quantity of units.\n";
		}
	} while (inventory[invCount].qty <= 0);


	inventory[invCount].qtyLeft = inventory[invCount].qty;

	do
	{
		cout << "Enter price for each unit: ";
		cin >> inventory[invCount].price;

		if (inventory[invCount].price <= 0)
		{
			cout << "Invalid price.\n ";
		}

	} while (inventory[invCount].price <= 0);

	shipmentNum++;
	inventory[invCount].shipmentNum = shipmentNum;
	invCount++;
}


bool Warehouse::inventoryIsFull()
{
	return (invCount >= (MAX - 1));
}

bool Warehouse::inventoryIsEmpty()
{
	return (invCount <= 0);
}

void Warehouse::inventoryShow()
{
	cout << endl << setw(20) << right << "\nShipment Quantity\t" << setw(15) << right << "Unit price" << setw(20) << "Shipment #" << endl;
	if (inventoryIsEmpty())
	{
		cout << setw(16) << right << 0 << setw(17) << right << 0.0 << setw(20) << right << 0 << endl;
	}

	for (int tempInv = (invCount - 1); tempInv >= 0; tempInv--)
	{
		cout << setw(16) << right << inventory[tempInv].qtyLeft << setw(17) << right << inventory[tempInv].price << setw(20) << right << inventory[tempInv].shipmentNum << endl;
	}

	cout << endl << setw(20) << right << "\nOrder Quantity\t" << setw(15) << right << "Order #" << setw(20) << "Order Status" << endl;
	if (isEmptyOrder())
	{
		cout << setw(13) << right << 0 << setw(17) << right << 0 << setw(20) << right << "N/A" << endl;
	}

	for (int tempOrder = (orderCount - 1); tempOrder >= 0; tempOrder--)
	{
		cout << setw(13) << right << order[tempOrder].qtyLeft << setw(17) << right << order[tempOrder].orderNum << setw(20) << right;

		if (order[tempOrder].status == EXT)
		{
			cout << "Extreme" << endl;
		}
		else if (order[tempOrder].status == EXP)
		{
			cout << "Expidited" << endl;
		}
		else //(order[tempOrder].status == STAND
		{
			cout << "Standard" << endl;
		}
	}

}



void Warehouse::orderPush(int i, rush menuOption)
{
	try
	{
		if (isFullOrder()) throw 1;

		orderNum++;
		order[orderCount].orderNum = orderNum;
		order[orderCount].qty = i;
		order[orderCount].qtyLeft = i;
		order[orderCount].status = menuOption;

		orderCount++;
	}
	catch (int)
	{
		cout << "Max orders reached." << endl;
	}
}


void Warehouse::orderPush()
{
	try
	{
		if (isFullOrder()) throw 1;
		orderInfo();
	}
	catch (int)
	{
		cout << "Max orders reached." << endl;
	}
}


void Warehouse::orderPop()
{
	try
	{
		if (isEmptyOrder()) throw 1;
		orderCount--;
	}
	catch (int)
	{
		cout << "No Orders Available." << endl;
	}
}

void Warehouse::orderInfo()
{
	int temp;

	do
	{
		cout << "Enter the number of widgets: ";

		cin >> order[orderCount].qty;

		if (order[orderCount].qty <= 0)
		{
			cout << "Invalid number of widgets.\n";
		}
	} while (!cin || order[orderCount].qty <= 0);

	order[orderCount].qtyLeft = order[orderCount].qty;

	do
	{
		cout << "[1]Extreme\n"
			<< "[2]Expedite\n"
			<< "[3]Standard\n"
			"Choose Delivery Option: ";
		cin >> temp;

		if (temp < 1 || temp > 3)
		{
			cout << "Please only enter [1-3].\n";
		}

	} while (!cin || temp < 1 || temp > 3);


	switch (temp)
	{
	case 1:
		order[orderCount].status = EXT;
		break;
	case 2:
		order[orderCount].status = EXP;
		break;
	case 3:
		order[orderCount].status = STAND;
		break;
	default:
		break;
	}

	orderNum++;
	order[orderCount].orderNum = orderNum;

	orderCount++;
}


bool Warehouse::isFullOrder()
{
	return (orderCount >= (MAX - 1));
}

bool Warehouse::isEmptyOrder()
{
	return (orderCount <= 0);
}


//Outputs orders
void Warehouse::orderShow()
{
	int temp = orderCount;

	cout << endl << setw(15) << right << "Order Number" << setw(15) << right << "Qty Order" << setw(15) << right << "Rush Status" << endl;
	if (isEmptyOrder()) cout << setw(15) << right << 0 << setw(15) << right << 0 << setw(15) << right << "--" << endl;

	for (int i = 0; i < orderCount; i++)
	{
		cout << setw(15) << right << order[i].orderNum << setw(15) << right << order[i].qtyLeft;

		if (order[i].status == EXT)
			cout << setw(20) << right << "EXTREME" << endl;
		else if (order[i].status == EXP)
			cout << setw(20) << right << "EXPEDITE" << endl;
		else if (order[i].status == STAND)
			cout << setw(20) << right << "STANDARD" << endl;
	}

}


// i starts at 1
//Creates a tree for the order list
void Warehouse::heapCreate(int i)
{
	if (i <= orderCount)
	{
		heap[i] = order[i - 1];

		if (i > 1)
		{
			swapFromParent(i);
		}
		heapCreate(i + 1);
	}
}


//reheaps up
//Swaps the newly added node to its parent if neccessary
void Warehouse::swapFromParent(int j)

{
	Order temp;

	if (j > 1)
	{
		if (heap[j].status < heap[j / 2].status) //if the children(order) has a faster priority => swap the parent and the children. 
		{
			temp = heap[j];
			heap[j] = heap[j / 2];
			heap[j / 2] = temp;
			swapFromParent(j / 2);
		}
		else if (heap[j].status == heap[j / 2].status) //if the children(order) came first than its parent => swap the two
		{
			if (heap[j].orderNum < heap[j / 2].orderNum)
			{
				temp = heap[j];
				heap[j] = heap[j / 2];
				heap[j / 2] = temp;
				swapFromParent(j / 2);
			}
		}
	}

}

void Warehouse::heapSort(int k)
{
	if (k > 1)
	{
		swapFirstLast(k);
		reheapDown(1, k - 1);
		heapSort(k - 1);
	}
}

void Warehouse::reheapDown(int f, int bottom)
{
	int leftChild, rightChild;

	Order temp;

	leftChild = f * 2;
	rightChild = f * 2 + 1;

	if (leftChild <= bottom && rightChild <= bottom)
	{
		if (heap[f].status > heap[leftChild].status && heap[f].status > heap[rightChild].status && heap[leftChild].status == heap[rightChild].status)
		{
			if (heap[leftChild].orderNum < heap[rightChild].orderNum)
			{
				temp = heap[f];
				heap[f] = heap[leftChild];
				heap[leftChild] = temp;



				reheapDown(leftChild, bottom);
			}
			else if (heap[leftChild].orderNum > heap[rightChild].orderNum)
			{
				temp = heap[f];
				heap[f] = heap[rightChild];
				heap[rightChild] = temp;


				reheapDown(rightChild, bottom);


			}
		}
		else if ((heap[f].status > heap[leftChild].status && heap[f].status == heap[rightChild].status) || (heap[f].status == heap[leftChild].status && heap[f].status > heap[rightChild].status))
		{
			if (heap[leftChild].status < heap[rightChild].status)
			{
				temp = heap[f];
				heap[f] = heap[leftChild];
				heap[leftChild] = temp;


				reheapDown(leftChild, bottom);
			}
			else if (heap[leftChild].status > heap[rightChild].status)
			{
				temp = heap[f];
				heap[f] = heap[rightChild];
				heap[rightChild] = temp;


				reheapDown(rightChild, bottom);


			}

		}
		else if (heap[f].status > heap[leftChild].status && heap[f].status > heap[rightChild].status && heap[leftChild].status != heap[rightChild].status)
		{

			if (heap[leftChild].status < heap[rightChild].status)
			{
				temp = heap[f];
				heap[f] = heap[leftChild];
				heap[leftChild] = temp;



				reheapDown(leftChild, bottom);
			}
			else if (heap[leftChild].status > heap[rightChild].status)
			{
				temp = heap[f];
				heap[f] = heap[rightChild];
				heap[rightChild] = temp;


				reheapDown(rightChild, bottom);


			}


		}
		else if (heap[f].status == heap[leftChild].status && heap[f].status == heap[rightChild].status)
		{

			if (heap[leftChild].orderNum < heap[rightChild].orderNum)
			{
				if (heap[f].orderNum > heap[leftChild].orderNum)
				{
					temp = heap[f];
					heap[f] = heap[leftChild];
					heap[leftChild] = temp;


					reheapDown(leftChild, bottom);
				}
			}
			else if (heap[leftChild].orderNum > heap[rightChild].orderNum)
			{
				if (heap[f].orderNum > heap[leftChild].orderNum)
				{
					temp = heap[f];
					heap[f] = heap[rightChild];
					heap[rightChild] = temp;

					reheapDown(rightChild, bottom);
				}


			}

		}
	}
	else if (leftChild <= bottom && rightChild > bottom)
	{
		if ((heap[f].status > heap[leftChild].status) || heap[f].orderNum > heap[leftChild].orderNum)
		{
			temp = heap[f];
			heap[f] = heap[leftChild];
			heap[leftChild] = temp;

			reheapDown(leftChild, bottom);
		}
	}

}

void Warehouse::swapFirstLast(int m)
{
	Order temp;
	temp = heap[1];
	heap[1] = heap[m];
	heap[m] = temp;
}

void Warehouse::heapCopy()
{
	for (int i = orderCount; i >= 0; i--)
	{
		order[i] = heap[i + 1];
	}
}



void Warehouse::deliver()
{
	int temp = invCount - 1;
	double WareCost = 0;
	int cost2Cost = 0;
	int qtyShipped = 0;
	int qty2Bshipped = 0;
	int shipmentShipped = 0;

	int numOfDelivered = order[orderCount - 1].orderNum;

	try
	{


		if (isEmptyOrder() && inventoryIsEmpty()) throw 2.2;
		if (isEmptyOrder()) throw 1;
		if (inventoryIsEmpty()) throw 'j';



		while (order[orderCount - 1].qtyLeft > 0 && invCount > 0)
		{
			if (inventory[invCount - 1].qtyLeft >= order[orderCount - 1].qtyLeft)
			{

				inventory[invCount - 1].qtyLeft -= order[orderCount - 1].qtyLeft;
				qtyShipped += order[orderCount].qtyLeft;

				WareCost += (inventory[invCount - 1].price * order[orderCount - 1].qtyLeft);

				if (order[orderCount - 1].status == EXT)
					cost2Cost += ((inventory[invCount - 1].price * order[orderCount - 1].qtyLeft) * MARKUP_EXTREME);
				else if (order[orderCount - 1].status == EXP)
					cost2Cost += ((inventory[invCount - 1].price * order[orderCount - 1].qtyLeft) * MARKUP_EXPEDITE);
				else if (order[orderCount - 1].status == STAND)
					cost2Cost += ((inventory[invCount - 1].price * order[orderCount - 1].qtyLeft) * MARKUP_STANDARD);


				order[orderCount - 1].qtyLeft = 0;
				if (inventory[invCount - 1].qtyLeft == 0)
					inventoryPop();

			}
			else
			{

				order[orderCount - 1].qtyLeft -= inventory[invCount - 1].qtyLeft;
				qtyShipped += inventory[invCount - 1].qtyLeft;

				WareCost += (inventory[invCount - 1].price * inventory[invCount - 1].qtyLeft);

				if (order[orderCount - 1].status == EXT)
					cost2Cost += ((inventory[invCount - 1].price * inventory[invCount - 1].qtyLeft) * 1.5);
				else if (order[orderCount - 1].status == EXP)
					cost2Cost += ((inventory[invCount - 1].price * inventory[invCount - 1].qtyLeft) * 1.2);
				else if (order[orderCount - 1].status == STAND)
					cost2Cost += ((inventory[invCount - 1].price * inventory[invCount - 1].qtyLeft) * 1.1);

				inventory[invCount - 1].qtyLeft = 0;
				inventoryPop();

			}
		}

		shipmentReport(temp, WareCost, cost2Cost);

		if (order[orderCount - 1].qtyLeft == 0) orderPop();
		inventory[invCount - 1].qty = inventory[invCount - 1].qtyLeft;
	}
	catch (double)
	{
		cout << "Orders and Shipments are Empty.\n";
	}
	catch (int)
	{
		cout << "No Orders Placed.\n";
	}
	catch (char)
	{
		cout << "Warehouse is Empty.\n";
	}

}

void Warehouse::shipmentReport(int temp, double WareCost, double CustCost)
{
	cout << "\n\n\t  Order #" << order[orderCount - 1].orderNum << " Filled Details" << endl;

	cout << setw(30) << left << "Order Number:" << setw(10) << right << order[orderCount - 1].orderNum << endl
		<< setw(30) << left << "Quantity Ordered:" << setw(10) << right << order[orderCount - 1].qty << endl
		<< setw(30) << left << "Quantity Shipped:" << setw(10) << right << (inventory[temp].qty - inventory[temp].qtyLeft) << endl;


	if (order[orderCount - 1].status == EXT)
	{
		cout << setw(30) << left << "Rush Status:" << setw(10) << right << "Extreme" << endl
			<< setw(30) << left << "Rercent Markup:" << setw(10) << right << "50%" << endl;

	}
	else if (order[orderCount - 1].status == EXP)
	{
		cout << setw(30) << left << "Rush Status:" << setw(10) << right << "Expedited" << endl
			<< setw(30) << left << "Rercent Markup:" << setw(10) << right << "20%" << endl;
	}
	else
	{
		cout << setw(30) << left << "Rush Status:" << setw(10) << right << "Standard" << endl
			<< setw(30) << left << "Rercent Markup:" << setw(10) << right << "10%" << endl;
	}

	cout << setw(30) << left << "Markup Amount:" << setw(10) << right << fixed << setprecision(2) << CustCost - WareCost << endl
		<< setw(30) << left << "Total Warehouse Cost:" << setw(10) << right << fixed << setprecision(2) << WareCost << endl
		<< setw(30) << left << "Total Customer Cost:" << setw(10) << right << fixed << setprecision(2) << CustCost << endl
		<< setw(30) << left << "Profit from Shipment:" << setw(10) << right << fixed << setprecision(2) << CustCost - WareCost << endl;

}




void Warehouse::menu()
{
	int menuOption;
	do
	{
		cout << "\n[1] Place an Order\n"
			<< "[2] Receive Shipment\n"
			<< "[3] Display Warehouse and Orders\n"
			<< "[4] Close Day and Fill Orders\n"
			<< "[5] End Program\n"
			<< "Select an option [1-5]: ";
		cin >> menuOption;
		cout << endl;


		switch (menuOption)
		{
		case 1:
			orderPush();
			break;
		case 2:
			inventoryPush();
			break;
		case 3:
			inventoryShow();
			break;
		case 4:
			heapCreate(1);
			heapSort(orderCount);
			heapCopy();
			while (orderCount > 0 && invCount > 0)
			{
				deliver();
			}

			break;
		case 6:
			heapCreate(1);
			heapCopy();
			orderShow();
			system("pause");
			heapSort(orderCount);
			heapCopy();
			orderShow();
			break;
		default:
			break;
		}


	} while (menuOption != 5);

}
