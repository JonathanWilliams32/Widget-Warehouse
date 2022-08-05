//Joanthan  Williams
//CS 136 Th
//Lab 9 Priority Queue

#include "warehouse.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()	// MAIN FUCNTION
{
	Warehouse wareHouse;
	wareHouse.menu();
}





/*
output:

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 2

Enter quantity of units in this Shipment: 100
Enter price for each unit: 10

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 3
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 3

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 5
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 1

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 2
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 1

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 2
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 3

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 4
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 2

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 6
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 1

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 3



Shipment Quantity            Unit price          Shipment #
			 100               10                   1


Order Quantity          Order #        Order Status
			6                6             Extreme
			4                5           Expidited
			2                4            Standard
			2                3             Extreme
			5                2             Extreme
			3                1            Standard

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 3
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 2

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 2

Enter quantity of units in this Shipment: 500
Enter price for each unit: 10

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 1
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 3

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 7
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 2

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 5
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 3

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 1

Enter the number of widgets: 6
[1]Extreme
[2]Expedite
[3]Standard
Choose Delivery Option: 3

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 3



Shipment Quantity            Unit price          Shipment #
			 500               10                   2
			 100               10                   1


Order Quantity          Order #        Order Status
			6               11            Standard
			5               10            Standard
			7                9           Expidited
			1                8            Standard
			3                7           Expidited
			6                6             Extreme
			4                5           Expidited
			2                4            Standard
			2                3             Extreme
			5                2             Extreme
			3                1            Standard

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 4



		  Order #2 Filled Details
Order Number:                          2
Quantity Ordered:                      5
Quantity Shipped:                      5
Rush Status:                     Extreme
Rercent Markup:                      50%
Markup Amount:                     25.00
Total Warehouse Cost:              50.00
Total Customer Cost:               75.00
Profit from Shipment:              25.00


		  Order #3 Filled Details
Order Number:                          3
Quantity Ordered:                      2
Quantity Shipped:                      2
Rush Status:                     Extreme
Rercent Markup:                      50%
Markup Amount:                     10.00
Total Warehouse Cost:              20.00
Total Customer Cost:               30.00
Profit from Shipment:              10.00


		  Order #6 Filled Details
Order Number:                          6
Quantity Ordered:                      6
Quantity Shipped:                      6
Rush Status:                     Extreme
Rercent Markup:                      50%
Markup Amount:                     30.00
Total Warehouse Cost:              60.00
Total Customer Cost:               90.00
Profit from Shipment:              30.00


		  Order #5 Filled Details
Order Number:                          5
Quantity Ordered:                      4
Quantity Shipped:                      4
Rush Status:                   Expedited
Rercent Markup:                      20%
Markup Amount:                      8.00
Total Warehouse Cost:              40.00
Total Customer Cost:               48.00
Profit from Shipment:               8.00


		  Order #7 Filled Details
Order Number:                          7
Quantity Ordered:                      3
Quantity Shipped:                      3
Rush Status:                   Expedited
Rercent Markup:                      20%
Markup Amount:                      6.00
Total Warehouse Cost:              30.00
Total Customer Cost:               36.00
Profit from Shipment:               6.00


		  Order #9 Filled Details
Order Number:                          9
Quantity Ordered:                      7
Quantity Shipped:                      7
Rush Status:                   Expedited
Rercent Markup:                      20%
Markup Amount:                     14.00
Total Warehouse Cost:              70.00
Total Customer Cost:               84.00
Profit from Shipment:              14.00


		  Order #1 Filled Details
Order Number:                          1
Quantity Ordered:                      3
Quantity Shipped:                      3
Rush Status:                    Standard
Rercent Markup:                      10%
Markup Amount:                      3.00
Total Warehouse Cost:              30.00
Total Customer Cost:               33.00
Profit from Shipment:               3.00


		  Order #4 Filled Details
Order Number:                          4
Quantity Ordered:                      2
Quantity Shipped:                      2
Rush Status:                    Standard
Rercent Markup:                      10%
Markup Amount:                      2.00
Total Warehouse Cost:              20.00
Total Customer Cost:               22.00
Profit from Shipment:               2.00


		  Order #8 Filled Details
Order Number:                          8
Quantity Ordered:                      1
Quantity Shipped:                      1
Rush Status:                    Standard
Rercent Markup:                      10%
Markup Amount:                      1.00
Total Warehouse Cost:              10.00
Total Customer Cost:               11.00
Profit from Shipment:               1.00


		  Order #10 Filled Details
Order Number:                         10
Quantity Ordered:                      5
Quantity Shipped:                      5
Rush Status:                    Standard
Rercent Markup:                      10%
Markup Amount:                      5.00
Total Warehouse Cost:              50.00
Total Customer Cost:               55.00
Profit from Shipment:               5.00


		  Order #11 Filled Details
Order Number:                         11
Quantity Ordered:                      6
Quantity Shipped:                      6
Rush Status:                    Standard
Rercent Markup:                      10%
Markup Amount:                      6.00
Total Warehouse Cost:              60.00
Total Customer Cost:               66.00
Profit from Shipment:               6.00

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 6


   Order Number      Qty Order    Rush Status
			  0              0             --
Press any key to continue . . .

   Order Number      Qty Order    Rush Status
			  0              0             --

[1] Place an Order
[2] Receive Shipment
[3] Display Warehouse and Orders
[4] Close Day and Fill Orders
[5] End Program
Select an option [1-5]: 5


C:\Users\badge\OneDrive\Documents\CS136\Labs\Lab 8\Debug\Lab 8.exe (process 7192) exited with code 0.
Press any key to close this window . . .

*/