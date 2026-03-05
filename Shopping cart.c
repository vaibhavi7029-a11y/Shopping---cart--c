#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[30];
    float price;
};

struct Cart {
    int id;
    char name[30];
    float price;
    int quantity;
};

struct Product products[5] = {
    {1,"Laptop",50000},
    {2,"Mobile",20000},
    {3,"Headphones",2000},
    {4,"Keyboard",1500},
    {5,"Mouse",800}
};

struct Cart cart[50];
int count = 0;

void productList() {
    printf("\nAvailable Products\n");
    printf("-----------------------\n");

    for(int i=0;i<5;i++) {
        printf("%d %s Rs %.2f\n",products[i].id,products[i].name,products[i].price);
    }
}

void addToCart() {
    int id,qty;

    productList();

    printf("\nEnter Product ID: ");
    scanf("%d",&id);

    printf("Enter Quantity: ");
    scanf("%d",&qty);

    for(int i=0;i<5;i++) {
        if(products[i].id==id) {
            cart[count].id=id;
            strcpy(cart[count].name,products[i].name);
            cart[count].price=products[i].price;
            cart[count].quantity=qty;
            count++;
        }
    }

    printf("Product added to cart\n");
}

void viewCart() {
    printf("\nItems in Cart\n");

    for(int i=0;i<count;i++) {
        printf("%s  Price: %.2f  Qty: %d\n",
        cart[i].name,cart[i].price,cart[i].quantity);
    }
}

void bill() {
    float total=0;

    printf("\n------ BILL RECEIPT ------\n");

    for(int i=0;i<count;i++) {
        float cost=cart[i].price*cart[i].quantity;

        printf("%s x %d = %.2f\n",
        cart[i].name,cart[i].quantity,cost);

        total+=cost;
    }

    printf("-------------------------\n");
    printf("Total Amount = %.2f\n",total);
}

int login() {
    char user[20],pass[20];

    printf("Username: ");
    scanf("%s",user);

    printf("Password: ");
    scanf("%s",pass);

    if(strcmp(user,"admin")==0 && strcmp(pass,"1234")==0)
        return 1;
    else
        return 0;
}

int main() {

    int choice;

    if(!login()) {
        printf("Login Failed\n");
        return 0;
    }

    printf("Login Successful\n");

    while(1) {

        printf("\n---- MENU ----\n");
        printf("1 View Products\n");
        printf("2 Add To Cart\n");
        printf("3 View Cart\n");
        printf("4 Generate Bill\n");
        printf("5 Exit\n");

        printf("Enter Choice: ");
        scanf("%d",&choice);

        switch(choice) {

            case 1: productList(); break;
            case 2: addToCart(); break;
            case 3: viewCart(); break;
            case 4: bill(); break;
            case 5: return 0;
            default: printf("Invalid Choice\n");

        }
    }

    return 0;
}
