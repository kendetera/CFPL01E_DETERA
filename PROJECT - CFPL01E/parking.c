#include "parking.h"

// Function to show the menu
void showMenu() {
    printf("\nParking System Menu:\n");
    printf("1. Park Vehicle\n");
    printf("2. Remove Vehicle\n");
    printf("3. Display Parking Rates\n");
    printf("4. Remove Parking History by Vehicle Number\n");
    printf("5. Remove All Parking History\n");
    printf("6. Exit\n");
}

// Function to initialize parking spots
void initializeParkingSpots(ParkingSpot parkingLot[], int totalSpots) {
    for (int i = 0; i < totalSpots; i++) {
        parkingLot[i].spotId = i + 1;
        parkingLot[i].isOccupied = 0;
    }
}

// Function to park a vehicle
void parkVehicle(ParkingSpot parkingLot[], int totalSpots, sqlite3 *db) {
    int spotFound = 0;

    for (int i = 0; i < totalSpots; i++) {
        if (!parkingLot[i].isOccupied) {
            parkingLot[i].isOccupied = 1;
            parkingLot[i].vehicle.id = i + 1;
            printf("Enter vehicle number: ");
            scanf("%s", parkingLot[i].vehicle.vehicleNumber);
            parkingLot[i].vehicle.entryTime = time(NULL);
            parkingLot[i].vehicle.isParked = 1;
            spotFound = 1;
            printf("Vehicle parked at spot %d.\n", parkingLot[i].spotId);

            // Insert parking history into the database
            insertParkingHistory(db, parkingLot[i].vehicle.vehicleNumber, parkingLot[i].spotId, parkingLot[i].vehicle.entryTime, 0, 0.0);
            break;
        }
    }

    if (!spotFound) {
        printf("No free parking spots available.\n");
    }
}

// Function to remove a vehicle and store the history in the database
void removeVehicle(ParkingSpot parkingLot[], int totalSpots, sqlite3 *db) {
    char licensePlate[15];
    printf("Enter vehicle license plate to exit: ");
    scanf("%s", licensePlate);

    int found = 0;
    for (int i = 0; i < totalSpots; i++) {
        if (parkingLot[i].isOccupied && strcmp(parkingLot[i].vehicle.vehicleNumber, licensePlate) == 0) {
            // Vehicle found, process exit
            time(&parkingLot[i].vehicle.exitTime); // Capture the exit time

            // Calculate parking fee
            double fee = calculateParkingFee(parkingLot[i].vehicle.entryTime, parkingLot[i].vehicle.exitTime);

            // Update parking history in the database
            insertParkingHistory(db, parkingLot[i].vehicle.vehicleNumber, parkingLot[i].spotId, parkingLot[i].vehicle.entryTime, parkingLot[i].vehicle.exitTime, fee);

            printf("Vehicle with license plate %s exited from spot %d.\n", licensePlate, parkingLot[i].spotId);
            printf("Parking duration: %.2f hours. Fee: $%.2f\n", difftime(parkingLot[i].vehicle.exitTime, parkingLot[i].vehicle.entryTime) / 3600.0, fee);
            parkingLot[i].isOccupied = 0; // Mark the spot as available
            parkingLot[i].vehicle.isParked = 0;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Vehicle with license plate %s not found.\n", licensePlate);
    }
}

// Function to calculate parking fee
double calculateParkingFee(time_t entryTime, time_t exitTime) {
    double hours = difftime(exitTime, entryTime) / 3600.0;

    if (hours < 24) {
        return FIXED_PARKING_RATE;
    } else {
        return FIXED_PARKING_RATE + OVERNIGHT_FEE;
    }
}

// Function to create the parking history table
void createTable(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "CREATE TABLE IF NOT EXISTS ParkingHistory ("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "VehicleNumber TEXT NOT NULL,"
                      "SpotNumber INTEGER NOT NULL,"
                      "EntryTime INTEGER NOT NULL,"
                      "ExitTime INTEGER,"
                      "ParkingFee REAL);";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Table created successfully\n");
    }
}

// Function to insert parking history into the database
void insertParkingHistory(sqlite3 *db, const char *vehicleNumber, int spotNumber, time_t entryTime, time_t exitTime, double parkingFee) {
    char *errMsg = 0;
    char sql[256];
    char entryTimeStr[20];
    char exitTimeStr[20];

    // Convert Unix timestamps to human-readable format
    strftime(entryTimeStr, sizeof(entryTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&entryTime));
    strftime(exitTimeStr, sizeof(exitTimeStr), "%Y-%m-%d %H:%M:%S", localtime(&exitTime));

    snprintf(sql, sizeof(sql), "INSERT INTO ParkingHistory (VehicleNumber, SpotNumber, EntryTime, ExitTime, ParkingFee) "
                               "VALUES ('%s', %d, '%s', '%s', %.2f);",
             vehicleNumber, spotNumber, entryTimeStr, exitTimeStr, parkingFee);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Record inserted successfully\n");
    }
}

// Function to remove a specific parking history by vehicle number
void removeParkingHistory(sqlite3 *db, const char *vehicleNumber) {
    char *errMsg = 0;
    char sql[256];
    snprintf(sql, sizeof(sql), "DELETE FROM ParkingHistory WHERE VehicleNumber = '%s';", vehicleNumber);

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "Parking history for vehicle %s removed successfully\n", vehicleNumber);
    }
}

// Function to remove all parking history
void removeAllParkingHistory(sqlite3 *db) {
    char *errMsg = 0;
    const char *sql = "DELETE FROM ParkingHistory;";

    int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    } else {
        fprintf(stdout, "All parking history removed successfully\n");
    }
}

// Function to display parking rates
void displayParkingRates() {
    printf("Parking Rates:\n");
    printf("1. Fixed Rate: $%d\n", FIXED_PARKING_RATE);
    printf("2. Overnight Fee: $%d\n", OVERNIGHT_FEE);
    printf("3. Lost Ticket Fee: $%d\n", LOST_TICKET_FEE);
}