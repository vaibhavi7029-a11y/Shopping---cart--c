#include <stdio.h>
#include <string.h>

struct Item {
    char name[50];
    float price;
    int quantity;
};

struct Item cart[100];
int count = 0;

void addItem() {
    printf("\nEnter Item Name: ");
    scanf("%s", cart[count].name);

    printf("Enter Price: ");
    scanf("%f", &cart[count].price);

    printf("Enter Quantity: ");
    scanf("%d", &cart[count].quantity);

    count++;
    printf("\nItem added successfully!\n");
}

void viewCart() {
    if (count == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    printf("\n------ Shopping Cart ------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Price: %.2f | Quantity: %d | Total: %.2f\n",
        i + 1,
        cart[i].name,
        cart[i].price,
        cart[i].quantity,
        cart[i].price * cart[i].quantity);
    }
}

void removeItem() {
    int index;

    if (count == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    viewCart();
    printf("\nEnter item number to remove: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("\nInvalid item number!\n");
        return;
    }

    for (int i = index - 1; i < count - 1; i++) {
        cart[i] = cart[i + 1];
    }

    count--;
    printf("\nItem removed successfully!\n");
}

void updateQuantity() {
    int index, qty;

    if (count == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    viewCart();
    printf("\nEnter item number to update quantity: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("\nInvalid item number!\n");
        return;
    }

    printf("Enter new quantity: ");
    scanf("%d", &qty);

    cart[index - 1].quantity = qty;
    printf("\nQuantity updated successfully!\n");
}

void checkout() {
    float total = 0;

    if (count == 0) {
        printf("\nCart is empty!\n");
        return;
    }

    printf("\n========== BILL RECEIPT ==========\n");

    for (int i = 0; i < count; i++) {
        float itemTotal = cart[i].price * cart[i].quantity;
        printf("%s x %d = %.2f\n", cart[i].name, cart[i].quantity, itemTotal);
        total += itemTotal;
    }

    printf("----------------------------------\n");
    printf("Total Bill = %.2f\n", total);
    printf("Thank you for shopping!\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n===== SHOPPING CART SYSTEM =====\n");
        printf("1. Add Item\n");
        printf("2. View Cart\n");
        printf("3. Remove Item\n");
        printf("4. Update Quantity\n");
        printf("5. Checkout\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            addItem();
            break;

        case 2:
            viewCart();
            break;

        case 3:
            removeItem();
            break;

        case 4:
            updateQuantity();
            break;

        case 5:
            checkout();
            break;

        case 6:
            printf("\nExiting program...\n");
            return 0;

        default:
            printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
