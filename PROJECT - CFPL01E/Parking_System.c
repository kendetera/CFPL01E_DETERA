#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_PARKING_SPOTS 10 // Maximum parking spots available

// Structure to store information about vehicles
typedef struct
{
    int id;                 // Vehicle ID
    char vehicleNumber[15]; // Vehicle Number (e.g., "ABC1234")
    time_t entryTime;       // Entry time
    time_t exitTime;        // Exit time
    int isParked;           // 1 if parked, 0 if not
} Vehicle;

// Structure to store information about parking spots
typedef struct
{
    int spotId;      // Parking Spot ID
    int isOccupied;  // 1 if occupied, 0 if free
    Vehicle vehicle; // Vehicle information for the parked vehicle
} ParkingSpot;

// Function prototypes
void showMenu();
int findEmptySpot(ParkingSpot parkingLot[], int totalSpots);
double calculateParkingFee(time_t entryTime, time_t exitTime);
void parkVehicle(ParkingSpot parkingLot[], int totalSpots);
void leaveVehicle(ParkingSpot parkingLot[], int totalSpots);
void displayParkingRates();
void generateReport(ParkingSpot parkingLot[], int totalSpots);

int main()
{
    ParkingSpot parkingLot[MAX_PARKING_SPOTS]; // Array of parking spots
    for (int i = 0; i < MAX_PARKING_SPOTS; i++)
    {
        parkingLot[i].spotId = i + 1;
        parkingLot[i].isOccupied = 0; // Initially, all spots are free
    }

    int choice;
    while (1)
    {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            parkVehicle(parkingLot, MAX_PARKING_SPOTS);
            break;
        case 2:
            leaveVehicle(parkingLot, MAX_PARKING_SPOTS);
            break;
        case 3:
            displayParkingRates();
            break;
        case 4:
            generateReport(parkingLot, MAX_PARKING_SPOTS);
            break;
        case 5:
            printf("Exiting the Parking Management System...\n");
            return 0;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Function to display the menu
void showMenu()
{
    printf("\n--- Parking Management System ---\n");
    printf("1. Park a vehicle\n");
    printf("2. Remove a vehicle\n");
    printf("3. Display Parking Rates\n");
    printf("4. Generate Parking Report\n");
    printf("5. Exit\n");
}

// Function to find an empty parking spot
int findEmptySpot(ParkingSpot parkingLot[], int totalSpots)
{
    for (int i = 0; i < totalSpots; i++)
    {
        if (!parkingLot[i].isOccupied)
        {
            return i;
        }
    }
    return -1; // No empty spot available
}

// Function to calculate the parking fee
double calculateParkingFee(time_t entryTime, time_t exitTime)
{
    double fixedRate = 25.0;                                         // Hourly rate
    double overnightFee = 200.0;                                     // Overnight fee
    double parkingDuration = difftime(exitTime, entryTime) / 3600.0; // Duration in hours
    double fee = parkingDuration * fixedRate;

    if (parkingDuration > 24)
    {
        fee += overnightFee;
    }
    return fee > 0 ? fee : 0;
}

// Function to park a vehicle
void parkVehicle(ParkingSpot parkingLot[], int totalSpots)
{
    int emptySpot = findEmptySpot(parkingLot, totalSpots);

    if (emptySpot == -1)
    {
        printf("Sorry, no available parking spots!\n");
        return;
    }

    ParkingSpot *spot = &parkingLot[emptySpot];
    spot->isOccupied = 1;
    spot->vehicle.id = emptySpot + 1;

    printf("Enter vehicle number: ");
    scanf("%s", spot->vehicle.vehicleNumber);

    spot->vehicle.entryTime = time(NULL); // Record the current time as entry time
    spot->vehicle.isParked = 1;

    printf("Vehicle parked in spot %d at %s", spot->spotId, ctime(&spot->vehicle.entryTime));
}

// Function to remove a vehicle
void leaveVehicle(ParkingSpot parkingLot[], int totalSpots)
{
    int vehicleId;

    printf("Enter the parking spot number to remove vehicle from: ");
    scanf("%d", &vehicleId);

    if (vehicleId < 1 || vehicleId > totalSpots || !parkingLot[vehicleId - 1].isOccupied)
    {
        printf("Invalid spot or no vehicle parked in this spot!\n");
        return;
    }

    ParkingSpot *spot = &parkingLot[vehicleId - 1];
    spot->vehicle.exitTime = time(NULL); // Record the current time as exit time

    double fee = calculateParkingFee(spot->vehicle.entryTime, spot->vehicle.exitTime);

    printf("Vehicle with number %s has exited from spot %d.\n", spot->vehicle.vehicleNumber, spot->spotId);
    printf("Entry time: %sExit time: %s", ctime(&spot->vehicle.entryTime), ctime(&spot->vehicle.exitTime));
    printf("Parking fee: P%.2f\n", fee);

    // Reset the spot
    spot->isOccupied = 0;
    spot->vehicle.isParked = 0;
}

// Function to display parking rates
void displayParkingRates()
{
    printf("\n----- Parking Rates ------\n");
    printf("Fixed Rate Fee: P%.2f\n", 25.00);
    printf("Overnight Parking Fee: P%.2f\n", 200.00);
    printf("Lost Ticket Fee: P%.2f\n", 300.00);
}

// Function to generate parking report
void generateReport(ParkingSpot parkingLot[], int totalSpots)
{
    int parkedCount = 0;
    double totalRevenue = 0;

    printf("\n--- Parking Report ---\n");

    for (int i = 0; i < totalSpots; i++)
    {
        if (parkingLot[i].isOccupied)
        {
            parkedCount++;

            double fee = calculateParkingFee(parkingLot[i].vehicle.entryTime, parkingLot[i].vehicle.exitTime);
            totalRevenue += fee;

            printf("Spot %d: Vehicle %s\nEntry time: %sExit time: %sFee: P%.2f\n",
                   parkingLot[i].spotId, parkingLot[i].vehicle.vehicleNumber, ctime(&parkingLot[i].vehicle.entryTime),
                   ctime(&parkingLot[i].vehicle.exitTime), fee);
        }
    }
    printf("\nTotal parked vehicles: %d\n", parkedCount);
    printf("Total revenue generated: P%.2f\n", totalRevenue);
}