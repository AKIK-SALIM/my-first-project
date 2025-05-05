#include <stdio.h>
#include <string.h>

// Define a struct for a laptop model
struct accessories_Model {
    char name[50];
    float price;
};

// Define a struct for a laptop brand
struct accessories_Brand {
    char name[20];
    struct accessories_Model models[5];
};

// Define a struct for a customer
struct Customer {
    char phoneNum[20];
    struct accessories_Model purchasedModel;
    int hasPurchased;
};

// Function prototypes
void displayBrands(struct accessories_Brand brands[], int numBrands);
void displayModels(struct accessories_Model models[], int numModels);
void purchaseLaptop(struct Customer customers[], int *numCustomers, struct accessories_Brand brands[], int numBrands);
void repairLaptop(struct Customer customers[], int numCustomers);

int main() {
    // Define laptop brands and models
    struct accessories_Brand brands[4] = {
            {"Razer", {{"Razer Viper", 2400.00}, {"Razer Cobra", 4600.00}, {"Razer Blackwidow", 9900.00},{"Razer Huntsman V2",26000},{"Razer Baracudda",12100}}},
            {"Logitech", {{"Logitech M90", 420.00}, {"Logitech K120", 770.00}, {"Logitach MK240", 2500.00},{"Logitech K380",3200.00},{"Logitech H110",1000.00}}},
            {"Rapoo", {{"Rapoo M10Plus", 700.00}, {"Rapoo VPRO VT9", 5000.00}, {"Rapoo X130", 1150.00},{"Rapoo VH310",2200.00},{"Rapoo V700Pro",5200.00}}},
            {"A4Tech",{{"A4Tech OP-720",420.00},{"A4Tech Bloody A70",2200.00},{"A4Tech Fstyler",1950.00},{"A4Tech HS19",1200.00},{"A4Tech Bloody G220",7790.00}}}

    };

    struct Customer customers[100];
    int numCustomers = 0;

    int choice;
    do {
        printf("\n\t\t\tWelcome to RYANS COMPUTERS!\n");
        printf("How can we help you?\n\n");
        printf("\n1. Buy an Accessories\n");
        printf("2. Repair a product\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                purchaseLaptop(customers, &numCustomers, brands, 3);
                break;
            case 2:
                repairLaptop(customers, numCustomers);
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

// Function to display available laptop brands
void displayBrands(struct accessories_Brand brands[], int numBrands) {
    numBrands=4;
    printf("Available Laptop Brands:\n");
    for (int i = 0; i < numBrands; i++) {
        printf("%d. %s\n", i + 1, brands[i].name);
    }
}

// Function to display available laptop models for a given brand
void displayModels(struct accessories_Model models[], int numModels) {
    printf("Available Laptop Models:\n");
    for (int i = 0; i < numModels; i++) {
        printf("%d. %s - $%.2f\n", i + 1, models[i].name, models[i].price);
    }
}

// Function to handle laptop purchase
void purchaseLaptop(struct Customer customers[], int *numCustomers, struct accessories_Brand brands[], int numBrands) {
    if (*numCustomers >= 100) {
        printf("Maximum number of customers reached. Cannot accept more purchases.\n");
        return;
    }

    struct Customer *customer = &customers[*numCustomers];
    (*numCustomers)++;

    printf("\nWelcome to the laptop store!\n");

    // Simulate user interaction
    displayBrands(brands, numBrands);
    numBrands=4;
    int brandChoice;
    printf("Enter the number corresponding to the brand you are interested in: ");
    scanf("%d", &brandChoice);
    brandChoice--; // Adjust for array indexing

    if (brandChoice < 0 || brandChoice >= numBrands) {
        printf("Invalid brand choice.\n");
        return;
    }

    struct accessories_Brand chosenBrand = brands[brandChoice];
    displayModels(chosenBrand.models, 5);

    int modelChoice;
    printf("Enter the number corresponding to the model you want to purchase: ");
    scanf("%d", &modelChoice);
    modelChoice--; // Adjust for array indexing

    if (modelChoice < 0 || modelChoice >=5 ) {
        printf("Invalid model choice.\n");
        return;
    }

    struct accessories_Model chosenModel = chosenBrand.models[modelChoice];

    // Record purchase information
    strcpy(customer->purchasedModel.name, chosenModel.name);
    customer->purchasedModel.price = chosenModel.price;
    customer->hasPurchased = 1;

    // Get user's phone number
    printf("Enter your phone number for future reference: ");
    scanf("%s", customer->phoneNum);
}

// Function to handle laptop repair
void repairLaptop(struct Customer customers[], int numCustomers) {
    char phoneNum[20];
    printf("\nEnter your phone number to verify your identity: ");
    scanf("%s", phoneNum);

    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].phoneNum, phoneNum) == 0) {
            if (customers[i].hasPurchased) {
                found = 1;
                int repairDays;
                printf("Please provide the number of days you have had the product: ");
                scanf("%d", &repairDays);

                if (repairDays <= 180) { // 180 days = 6 months
                    printf("Your product falls under the warranty period. Repair service is free!\n");
                } else {
                    printf("Your product does not fall under the warranty period.\n");
                    printf("A convenience fee of %.2f%% of the product's price will be charged.\n", 5.0);
                    float convenienceFee = customers[i].purchasedModel.price * 0.05;
                    printf("Convenience Fee: $%.2f\n", convenienceFee);
                }
            } else {
                printf("No purchase found for the provided phone number.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Customer with provided phone number not found.\n");
    }
}
