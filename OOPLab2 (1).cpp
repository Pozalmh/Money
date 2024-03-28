#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Book {
    string title;
    string author;
    int publicationYear;
    int uniqueNumber;
public:
    Book(string title, string author, int publicationYear, int uniqueNumber): title(title), author(author), publicationYear(publicationYear), uniqueNumber(uniqueNumber) {}
    string getTitle() const { return title; }string getAuthor() const { return author; }int getPublicationYear() const { return publicationYear; }int getUniqueNumber() const { return uniqueNumber; }
};
class Bookstore {
    vector<Book> books;
    vector<Book> cart; // Добавляем вектор для хранения выбранных книг
public:
    Bookstore() {}
    void addBook(const Book& book) {
        books.push_back(book);
    }
    void displayBooks() {
        for (const auto& book : books) {
            cout << "Название: " << book.getTitle() << endl;
            cout << "Автор: " << book.getAuthor() << endl;
            cout << "Год Публикациии: " << book.getPublicationYear() << endl;
            cout << "номер каталога: " << book.getUniqueNumber() << endl;
            cout << endl;
        }
    }
    bool sellBook(int uniqueNumber) {
        auto it = books.begin();
        while (it != books.end()) {
            if (it->getUniqueNumber() == uniqueNumber) {
                books.erase(it);
                return true;
            }
            ++it;
        }
        return false;
    }
    void addToCart(int uniqueNumber) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getUniqueNumber() == uniqueNumber) {
                cart.push_back(*it); // Добавляем книгу в корзину
                break;
            }
        }
    }
    void displayCart() {
        for (const auto& book : cart) {
            cout << "Название: " << book.getTitle() << endl;
            cout << "Автор: " << book.getAuthor() << endl;
            cout << "Год публикации: " << book.getPublicationYear() << endl;
            cout << "Номер каталога: " << book.getUniqueNumber() << endl;
            cout << endl;
        }
    }
};
int main() {
    Bookstore myBookstore;
    Book book1("The Great Gatsby", "F. Scott Fitzgerald", 1925, 1);Book book2("To Kill a Mockingbird", "Harper Lee", 1960, 2);Book book3("1984", "George Orwell", 1949, 3);Book book4("1984", "George Orwell", 1949, 4);Book book5("The Catcher in the Rye", "J.D. Salinger", 1951, 5);Book book6("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", 1997, 6);Book book7("The Hobbit", "J.R.R. Tolkien", 1937, 7);Book book8("Fahrenheit 451", "Ray Bradbury", 1953, 8);Book book9("Moby Dick", "Herman Melville", 1851, 9);Book book10("Alice's Adventures in Wonderland", "Lewis Carroll", 1865, 10);
    myBookstore.addBook(book1); myBookstore.addBook(book2); myBookstore.addBook(book3); myBookstore.addBook(book4); myBookstore.addBook(book5); myBookstore.addBook(book6); myBookstore.addBook(book7); myBookstore.addBook(book8); myBookstore.addBook(book9); myBookstore.addBook(book10);
    myBookstore.displayBooks();
    int userChoice;
    while(userChoice != 999){
    cout << "Введите номер книги, которую хотите купить: "<<"\n"<<"для окончания покупок введите 999, для выведения корзины 777\n";
    cin >> userChoice;
    if (myBookstore.sellBook(userChoice)) {
        cout << "Прекрасный выбор, Вы купили книгу.\n";
        myBookstore.addToCart(userChoice); // Добавляем выбранную книгу в корзину
    } else {
        cout << "Простите, но книги с выбранным номером нет в наличии.\n";
    }
    if (777){
            cout << "ваша корзина: \n";
            myBookstore.displayCart();// Выводим содержимое корзины (почему-то не работает)
    }
    }
    return 0;
}
