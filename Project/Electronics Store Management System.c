#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>


#define CUSTOMERS 100
#define MODELS 5
#define PHONE_NUMBER 20

struct LaptopModel {
    char name[50];
    float price;
};
struct LaptopBrand {
    char name[20];
    struct LaptopModel models[MODELS];
};

typedef struct
{
    char name[20];
    float price;

}mobmodel;
typedef struct
{
    char name[30];
    mobmodel models[20];
}mobbrand;
struct AccessoriesModel {
    char name[50];
    float price;
};


struct AccessoriesBrand {
    char name[20];
    struct AccessoriesModel models[MODELS];

};

struct ProductModel{
    char name[50];
    float price;};

struct Customer {
    char phoneNum[PHONE_NUMBER];
    struct ProductModel purchasedModel;
    int hasPurchased;
};



void displayLaptopBrands(struct LaptopBrand brands[], int numBrands);
void displayLaptopModels(struct LaptopModel models[], int numModels);
void purchaseLaptop(struct Customer customers[], int *numCustomers, struct LaptopBrand brands[], int numBrands);


void displaymobb(mobbrand[]);
void displaymobm(mobmodel[]);
void purchasemobile(struct Customer customers[],int *numCustomers, mobbrand[]);


void displayaccessoriesbrands(struct AccessoriesBrand abrands[], int numBrands);
void displayaccessoriesmodels(struct AccessoriesModel models[], int numModels);
void purchaseAccessories(struct Customer customers[], int *numCustomers, struct AccessoriesBrand abrands[], int numBrands);


void repairProduct(struct Customer customers[], int numCustomers);

int main() {
    system("color 0A");
    struct LaptopBrand brands[5] = {
            {"HP", {{"HP Spectre x360", 72000.00}, {"HP Envy", 63000.00}, {"HP Pavilion", 80000.00},{"HP EliteBook",50000.00},{"HP Chromebook",55000.00}}},
            {"DELL", {{"Dell XPS", 70000.00}, {"Dell Inspiron", 52000.00}, {"Dell Latitude", 62200.00},{"Dell Alienware",73000.00},{"Dell Precision", 45000.00}}},
            {"Apple", {{"MacBook Air M1", 100000.00}, {"MacBook Pro M1", 150000.00}, {"MacBook Air M2", 130000.00},{"Macbook Pro M2",180000.00},{"MacBook Air M3",210000.00}}},
            {"Asus", {{"Asus ZenBook", 70000.00},{"Asus VivoBook",40000.00},{"Asus ROG Gaming",120000.00},{"Asus TUF Gaming",70000.00},{"ASUS ChromeBook",30000.00}}},
            {"Lenovo",{{"Lenovo ThinkPad",50000.00},{"Lenovo Yoga",45000.00},{"Lenovo Legion",70000.00},{"Lenovo IdeaPad",35000.00},{"Lenovo ThinkBook", 50000.00}}}};

    mobbrand mbrands[5]= {
            {"Apple", {{"iPhone 15", 99900.00}, {"iPhone 14", 89900.00}, {"iPhone 13", 79900.00},{"iPhone 12", 69900.00},{"iPhone 11", 59900.00}}},
            {"Samsung", {{"S23", 140000.00}, {"S22", 100000.00}, {"S21", 80000.00},{"S20", 70000.00},{"S19", 60000.00}}},
            {"Google", {{"Pixel 6",399.00}, {"Pixel 5", 299.00}, {"Pixel 4", 199.00},{"Pixel 3", 40000.00},{"Pixel 2", 35000.00}}},
            {"Realme", {{"GT",22000.00}, {"GT Neo", 19900.00}, {"GT Master Edition", 39900.00},{"C53", 16000.00},{"Note 50", 50000.00}}},
            {"Walton", {{"Primo GH11",10000.00}, {"Primo R10", 19900.00}, {"Xanon X20", 29900.00},{"NEXG N9", 13000.00},{"Orbit Y70", 8000.00}}}
    };
    struct AccessoriesBrand abrands[5] = {
            {"Razer", {{"Razer Viper", 2400}, {"Razer Cobra", 4600.00}, {"Razer Blackwidow", 9900.00},{"Razer Huntsman V2",26000},{"Razer Baracudda",12100}}},
            {"Logitech", {{"Logitech M90", 420}, {"Logitech K120", 770.00}, {"Logitach MK240", 2500.00},{"Logitech K380",3200.00},{"Logitech H110",1000.00}}},
            {"Rapoo", {{"Rapoo M10Plus", 700}, {"Rapoo VPRO VT9", 5000.00}, {"Rapoo X130", 1150.00},{"Rapoo VH310",2200.00},{"Rapoo V700Pro",5200.00}}},
            {"A4Tech",{{"A4Tech OP-720",420},{"A4Tech Bloody A70",2200.00},{"A4Tech Fstyler",1950.00},{"A4Tech HS19",1200.00},{"A4Tech Bloody G220",7790.00}}},
            {"Anker",{{"Charger",5000.00},{"USB Type-A",500.00},{"USB Type-C",1200.00},{"Power Bank",3000.00},{"USB Port",3000.00}}}};

    struct Customer customers[CUSTOMERS];
    int numCustomers = 0;

    int choice, choice1;
    do {
        printf("\n\n\t\t\tWelcome to RYANS COMPUTERS!\n");
        printf("How can we help you?\n\n");
        printf("\n\n1. Buy a Product\n");
        printf("\n\n2. Repair a product\n");
        printf("\n\n3. Exit\n");
        printf("\n\nEnter your choice: ");
        printf("\n");
        printf("\n");
        scanf("%d",&choice);
        switch (choice) {case 1:  printf("\n\n1. Buy a laptop\n");
                printf("\n2. Buy a Smartphone\n");
                printf("\n3. Buy Accessories\n");
                printf("\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);
                switch (choice1) {
                    case 1:
                        purchaseLaptop(customers, &numCustomers, brands, 5);
                        break;
                    case 2:
                        purchasemobile(customers, &numCustomers, mbrands);
                        break;
                    case 3:
                        purchaseAccessories(customers, &numCustomers, abrands, 5);
                        break;
                    case 4:
                        printf("\033[91mExiting the program.\n");
                        break;
                    default:
                        printf("\033[94mInvalid choice. Please try again.\n");
                }break;
            case 2:
                repairProduct(customers, numCustomers);
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


void displayLaptopBrands(struct LaptopBrand brands[], int numBrands) {
    printf("\n");
    printf("\n");

    printf("\033[94mAvailable Laptop Brands:\n");
    for (int i = 0; i < numBrands; i++) {
            printf("\n");
    printf("\n");
        printf("%d. %s\n", i + 1, brands[i].name);
    }
}

void displayLaptopModels(struct LaptopModel models[], int numModels) {
    printf("\n");
    printf("\n");
    printf("\033[95mAvailable Laptop Models:\n");
    for (int i = 0; i < numModels; i++) {
            printf("\n");
    printf("\n");
        printf("%d. %s - BDT%.2f\n", i + 1, models[i].name, models[i].price);
    }
}

void purchaseLaptop(struct Customer customers[], int *numCustomers, struct LaptopBrand brands[], int numBrands) {
    if (*numCustomers >= CUSTOMERS) {
            printf("\n");
    printf("\n");
        printf("Maximum number of customers reached. Cannot accept more purchases.\n");
        return;
    }
    struct Customer *customer = &customers[*numCustomers];
    (*numCustomers)++;
    displayLaptopBrands(brands, numBrands);

    int brandChoice;
printf("\n");
printf("\n");

    printf("Which Brand Would You Like To Buy From? ");
    while(1){
            scanf("%d", &brandChoice);
        brandChoice--;

        if (brandChoice >= 0 && brandChoice < numBrands) {
            break;}
        else {
                printf("\n");
        printf("\n");
        printf("Invalid Choice. Try Again");
    }
    }
    struct LaptopBrand chosenBrand = brands[brandChoice];
    displayLaptopModels(chosenBrand.models, MODELS);

    int modelChoice;
    printf("Enter the number of Model you wish to purchase: ");
    while(1){scanf("%d",&modelChoice);
        modelChoice--;

        if (modelChoice >= 0 && modelChoice < MODELS) {
            break;}
        else{
                printf("\n");
                printf("\n");
        printf("Invalid Choice. Try Again");
    }
    }

    struct LaptopModel chosenModel = chosenBrand.models[modelChoice];


    strcpy(customer->purchasedModel.name, chosenModel.name);
    customer->purchasedModel.price = chosenModel.price;
    customer->hasPurchased = 1;

printf("\n");
printf("\n");

    printf("\033[91mEnter your phone number for future queries: ");
    scanf("%s", customer->phoneNum);
printf("\n");
printf("\n");
    printf("Added To your Cart, Successfully!! :) Thanks for coming\n\n");
}


void displaymobb (mobbrand brands[]) {

    printf("\n");
    printf("\n");

    printf("\033[96mAvailable Mobile Brands:\n");
    for (int i = 0; i < 5; i++) {
            printf("\n");

        printf("%d. %s\n", i + 1, brands[i].name);
    }
}
void displaymobm(mobmodel models[]) {
    printf("\033[93mAvailable Mobile Models:\n");
    for (int i = 0; i < 5; i++) {
            printf("\n");
        printf("%d. %s - BDT%.2f\n", i + 1, models[i].name, models[i].price);
    }
}

void purchasemobile(struct Customer customers[], int *numCustomers, mobbrand brands[]) {
    if (*numCustomers >= 100) {
            printf("\n");
    printf("\n");
        printf("Maximum number of customers reached. Cannot accept more purchases.\n");
        return;
    }
    struct Customer *customer = &customers[*numCustomers];
    (*numCustomers)++;

    displaymobb(brands);

    int brandChoice;

    printf("Which Brand Would You Like To Buy From? ");
    while(1){scanf("%d", &brandChoice);
        brandChoice--;

        if (brandChoice >= 0 && brandChoice < 5) {
            break;}
        else {
                printf("\n");
        printf("\n");

        printf("Invalid Choice. Try Again");
    }
    }

    mobbrand chosenBrand = brands[brandChoice];
    displaymobm(chosenBrand.models);

    int modelChoice;
    printf("\n");
    printf("\n");

    printf("Enter the number of Model you wish to purchase: ");
    while(1){scanf("%d",&modelChoice);
        modelChoice--;

        if (modelChoice >= 0 && modelChoice < 5) {
            break;}
        else {
                printf("\n");
        printf("\n");

        printf("Invalid Choice. Try Again");
    }
    }

    mobmodel chosenModel = chosenBrand.models[modelChoice];


    strcpy(customer->purchasedModel.name, chosenModel.name);
    customer->purchasedModel.price = chosenModel.price;
    customer->hasPurchased = 1;


    printf("\n");
    printf("\n");

    printf("Enter your phone number for future queries: ");
    scanf("%s", customer->phoneNum);

    printf("\n");
    printf("\n");

    printf("Added to your cart,Successfully!! :) Thank you!");
    printf("\n");
    printf("\n");

}

void displayaccessoriesbrands(struct AccessoriesBrand brands[], int numBrands) {

    printf("\n");
    printf("\n");

    printf("\033[91mAvailable Accessories Brands:\n");
    for (int i = 0; i < numBrands; i++) {

            printf("\n");
        printf("%d. %s\n", i + 1, brands[i].name);
    }
}

void displayaccessoriesmodels(struct AccessoriesModel models[], int numModels) {
    printf("\n");
    printf("\n");

    printf("\033[95mAvailable Laptop Models:\n");
    for (int i = 0; i < numModels; i++) {
            printf("\n");
        printf("%d. %s - BDT%.2f\n", i + 1, models[i].name, models[i].price);
    }
}
void purchaseAccessories(struct Customer customers[], int *numCustomers, struct AccessoriesBrand brands[], int numBrands) {
    if (*numCustomers >= CUSTOMERS) {
            printf("\n");
    printf("\n");
        printf("Maximum number of customers reached. Cannot accept more purchases.\n");
        return;
    }
    struct Customer *customer = &customers[*numCustomers];
    (*numCustomers)++;
    displayaccessoriesbrands(brands, numBrands);

    int brandChoice;

printf("\n");
printf("\n");

    printf("Which Brand Would You Like To Buy From? ");
    while(1){scanf("%d", &brandChoice);
        brandChoice--;

        if (brandChoice >= 0 && brandChoice < numBrands) {
            break;}
        else {
                printf("\n");
        printf("\n");
                printf("\033[91mInvalid Choice. Try Again");
    }
    }

    struct AccessoriesBrand chosenBrand = brands[brandChoice];
    displayaccessoriesmodels(chosenBrand.models, 5);

    int modelChoice;

    printf("\n");
    printf("\n");

    printf("Enter the number of Model you wish to purchase: ");
    while(1){scanf("%d",&modelChoice);
        modelChoice--;

        if (modelChoice >= 0 && modelChoice < MODELS) {
            break;}
        else {
                printf("\n");
        printf("\n");
                printf("Invalid Choice. Try Again");
    }
    }

    struct AccessoriesModel chosenModel = chosenBrand.models[modelChoice];


    strcpy(customer->purchasedModel.name, chosenModel.name);
    customer->purchasedModel.price = chosenModel.price;
    customer->hasPurchased = 1;

printf("\n");
printf("\n");

    printf("Enter your phone number for future queries: ");
    scanf("%s", customer->phoneNum);

    printf("\n");
    printf("\n");

    printf("Added to your cart, Successfully!! :) Thank you!!");

    printf("\n");
    printf("\n");
}



void repairProduct(struct Customer customers[], int numCustomers) {
    char phoneNum[PHONE_NUMBER];

    printf("\n");
    printf("\n");

    printf("Enter your phone number to verify yourself as our Returning Customer: ");
    scanf("%s", phoneNum);

    int found = 0;
    for (int i = 0; i < numCustomers; i++) {
        if (strcmp(customers[i].phoneNum, phoneNum) == 0) {
            if (customers[i].hasPurchased) {
                found = 1;
                int repairDays;

                printf("\n");
                printf("\n");

                printf("Please provide the number of days you have had the product: ");
                scanf("%d", &repairDays);

                if (repairDays <= 180) {
                        printf("\n");
                printf("\n");

                    printf("Your product falls under the 6 months warranty period. Repair service is free!");
                } else {
                    printf("\n");
                    printf("\n");
                    printf("Your product does not fall under the 6 months warranty period.");
                    printf("\n");
                    printf("A convenience fee of %.2f%% of the product's price will be charged.\n", 5.0);
                    float convenienceFee;
                    convenienceFee = customers[i].purchasedModel.price * 0.05;
                    printf("\n");
                    printf("Convenience Fee: BDT%.2f\n", convenienceFee);
                }
            } else {
                printf("\n");
                printf("\n");

                printf("\033[0;33mNo purchase found for the provided phone number.\n\033[0m");
            }
            break;
        }
    }
    if (found == 0) {
            printf("\n");
    printf("\n");

        printf("\033[0;33mCustomer with provided phone number not found.\n\033[92m");
        printf("\n");
        printf("\n");
    }

}

