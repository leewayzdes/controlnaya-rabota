
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

/*Task 3
void fill_array(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 50 + 1;
    }
}


void show_array(int* array, int size) {
    std::cout << "Array: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

void equal_sum(int* array, int size, int sum) {
    std::cout << "Pairs with sum " << sum << ": " << std::endl;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (array[i] + array[j] == sum) {
                std::cout << "(" << array[i] << ", " << array[j] << ")" << std::endl;
            }
        }
    }
}

int main() {
    
    std::srand(std::time(0));
    
    std::cout << "Size of array: ";
    int size;
    std::cin >> size;

    int* array = new int[size];// выделяем память под массив

    fill_array(array, size);//заполняем числами
    show_array(array, size);//показываем получившийся массив

    std::cout << "What sum should be find among numbers? ";
    int number_sum;
    std::cin >> number_sum;
    equal_sum(array, size, number_sum);

    delete[] array;
    return 0;
}*/
/*Example:
Size of array: 6
Array: 2 6 45 18 30 48
What sum should be find among numbers? 8
Pairs with sum 8:
(2, 6)*/

/*Task 4 */
struct Contact {
    std::string name;
    std::string phone_number;
};

void add_contact(Contact* contacts, int& size) {
    Contact newContact;
    std::cout << "Enter name ";
    std::cin >> newContact.name;
    std::cout << "Enter number ";
    std::cin >> newContact.phone_number;

    Contact* newContacts = new Contact[size + 1];
    for (int i = 0; i < size; ++i) {
        newContacts[i] = contacts[i];
    }
    newContacts[size] = newContact;
    delete[] contacts;
    contacts = newContacts;
    ++size;
}

void delete_contact(Contact* contacts, int& size) {
    std::string name_del;
    std::cout << "Enter name ";
    std::cin >> name_del;
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name_del) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            contacts[i] = contacts[i + 1];
        }
        --size;
    }
    else {
        std::cout << "Contact " << name_del << " not found" << std::endl;
    }
}

void update_contact(Contact* contacts, int size) {
    std::string name_upd;
    std::cout << "Enter name: ";
    std::cin >> name_upd;

    for (int i = 0; i < size; ++i) {
        if (contacts[i].name == name_upd) {
            std::cout << "Enter new number " << contacts[i].name << ": ";
            std::cin >> contacts[i].phone_number;
            return;
        }
    }

    std::cout << "Contact " << name_upd << " not found" << std::endl;
}

void display_contacts(const Contact* contacts, int size) {
    if (size == 0) {
        std::cout << "Empty" << std::endl;
    }
    else {
        std::cout << "Book of contacts" << std::endl;
        for (int i = 0; i < size; ++i) {
            std::cout << "Name " << contacts[i].name << ", Number " << contacts[i].phone_number << std::endl;
        }
    }
}

int main() {
    Contact* book_phone = nullptr;
    int size = 0;

    while (true) {
        std::cout << "Choose action:" << std::endl;
        std::cout << "1. Add contact" << std::endl;
        std::cout << "2. Delete contact" << std::endl;
        std::cout << "3. Update contact" << std::endl;
        std::cout << "4. Show info about contact" << std::endl;
        std::cout << "0. Go out" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1:
            add_contact(book_phone, size);
            break;
        case 2:
            delete_contact(book_phone, size);
            break;
        case 3:
            update_contact(book_phone, size);
            break;
        case 4:
            display_contacts(book_phone, size);
            break;
        case 0:
            // Освобождение выделенной памяти перед выходом
            delete[] book_phone;

            return 0;
        default:
            std::cout << "Repeat" << std::endl;
            continue;
        }
    }

    return 0;
}