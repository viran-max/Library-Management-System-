#include <iostream>
using namespace std;
class book {
    string title;
    string author;
    int ISBN;
    int Quantity;
    public:
        void setTitle(string t){ title = t;}
        string getTitle(){return title;}
        void setAuthor(string a) {author = a;}
        string getAuthor() {return author;}
        void setISBN(int i){ISBN = i;}
        int getISBN(){return ISBN;}
        void setQuantity(int q) {Quantity = q;}
        int getQuantity(){return Quantity;}

};

class Member {
    string name;
    int id;
    int ContactInfo;

    public:
        void setname(string n){name = n;}
        string getname(){return name;}
        void setid(int id){this->id = id;}
        int getid() {return id;}
        void setContact(int contact){ContactInfo = contact;}
        int getContact(){return ContactInfo;}
};

class Transaction {
    int BookISBN;
    int MemberId;
    string IssueDate;
    string returnDate;

    public:
        void setBookISBN(int ISBN){BookISBN = ISBN;}
        int getBookISBN(){return BookISBN;}
        void setid(int id){MemberId = id;}
        int getid() {return MemberId;}
        void setIssueDate(string Issue){IssueDate = Issue;}
        string getissue() {return IssueDate;}
        void setReturnDate(string rd){returnDate = rd;}
        string getReturnDate(){return returnDate;}
        

};

class Library {
    private:
        static const int MAX_BOOKS = 100;
        static const int MAX_MEMBERS = 100;
        static const int MAX_TRANSACTIONS = 100;
    
        book books[MAX_BOOKS];
        Member members[MAX_MEMBERS];
        Transaction transactions[MAX_TRANSACTIONS];
    
        int bookCount = 0;
        int memberCount = 0;
        int transactionCount = 0;
    
    public:
        void addBook() {
            if (bookCount < MAX_BOOKS) {
                string title, author;
                int isbn, qty;
                cout << "Enter title: "; 
                getline(cin,title);
                if(title.empty()){
                    cout << "The title cannot be Empty Try again !";
                    return;
                }
                cout << "Enter author: ";
                getline(cin , author);
                if(author.empty()){
                    cout << "The author cannot be Empty Try again !";
                    return;
                }
                cout << "Enter ISBN: "; cin >> isbn;
                cout << "Enter quantity: "; cin >> qty;
                if(qty < 0) {
                    cout << "Qunatity Cannot be Negative value ! assign a positive value "<<endl;
                    return;
                }
                books[bookCount].setTitle(title);
                books[bookCount].setAuthor(author);
                books[bookCount].setISBN(isbn);
                books[bookCount].setQuantity(qty);
                bookCount++;
                cout << "Book added successfully!" << endl;
            } else {
                cout << "Cannot add more books. Library is full!" << endl;
            }
        }
    
        void displayBooks() {
            for (int i = 0; i < bookCount; i++) {
                cout << "Title: " << books[i].getTitle() << ", Author: " << books[i].getAuthor() << ", ISBN: " << books[i].getISBN() << ", Quantity: " << books[i].getQuantity() << endl;
            }
        }

        void addMember(){
            if(memberCount < MAX_MEMBERS){
                string name;
                int id;
                int ContactInfo;
                cout <<"Enter Name :";
                getline(cin,name);
                if (name.empty()) {
                    cout << "The name Cannot be Empty! Try again.\n";
                    return;
                }
                cout << "Enter ID :";
                cin >> id;
                cin.ignore();
                if(id < 0){
                    cout << "A id cannot be negative !"; return ;
                }
                cout << "Enter Contact Info :";
                cin >> ContactInfo;
                cin.ignore();

                members[memberCount].setname(name);
                members[memberCount].setid(id);
                members[memberCount].setContact(ContactInfo);
                memberCount++;
                cout << "Member Added SuccessFully!"<<endl;
            }
            else {
                cout << "Cannot add more members. Library is full!" << endl;
            }
        }
        void displayMembers() {
            for (int i = 0; i < memberCount; i++) {
                cout << "Name: " << members[i].getname() << ", ID: " << members[i].getid() << ", Contact: " << members[i].getContact() << endl;
            }
        }
        void issueBook() {
            if (transactionCount < MAX_TRANSACTIONS) {
                int isbn, memberId;
                string issueDate;
                cout << "Enter ISBN of the book: "; cin >> isbn; cin.ignore();
                cout << "Enter member ID: "; cin >> memberId; cin.ignore();
                cout << "Enter issue date (DD/MM/YYYY): "; getline(cin,issueDate);
                if(issueDate.empty()){
                    cout << "Issue Date can't be enpty."<<endl;
                    return;
                }
                transactions[transactionCount].setBookISBN(isbn);
                transactions[transactionCount].setid(memberId);
                transactions[transactionCount].setIssueDate(issueDate);
                transactionCount++;
                cout << "Book issued successfully!" << endl;
            } else {
                cout << "Cannot issue more books. Transaction limit reached!" << endl;
            }
        }
        void displayTransactions() {
            for (int i = 0; i < transactionCount; i++) {
                cout << "Book ISBN: " << transactions[i].getBookISBN() << ", Member ID: " << transactions[i].getid() << ", Issue Date: " << transactions[i].getissue() << endl;
            }
        }
        void searchBook(){
            string SearchTerm;
            cout << "Enter Title or ISBN to search : ";
            getline(cin, SearchTerm);
            bool found = false;
            for(int i = 0 ; i < bookCount ; i++){
                if(books[i].getTitle() == SearchTerm || to_string(books[i].getISBN())== SearchTerm){
                    cout << "Book Found : ," << " Book title :" <<books[i].getTitle() << ", Book ISBN : " << ", Book Author : " << books[i].getAuthor() << ", Book ISBN : "<<books[i].getISBN() << ", Book Quantity : " <<books[i].getQuantity()<<endl;
                    found = true;
                    break;
                }
                
            }
            if(!found){
                cout << "Sorry Didn't found the book."<<endl;
            }
        }

        void searchMember(){
            string SearchTerm;
            cout << "Enter name or id to search : ";
            getline(cin, SearchTerm);
            bool found = false;
            for(int i = 0 ; i < memberCount ; i++){
                if (members[i].getname() == SearchTerm || to_string(members[i].getid()) == SearchTerm){
                    cout << "Member Found : ," << " Member Name :" <<members[i].getname() << ", Member Id : "<< members[i].getid() << ", Member Contact Info : "<< members[i].getContact()<<endl;
                    found = true;
                    break;
                }
            }
            if(!found){
                cout << "Sorry Didn't found the Member."<<endl;
            }
        }
        void deleteBook() {
            int isbn;
            cout << "Enter ISBN of the book to delete: ";
            cin >> isbn;
            cin.ignore();
        
            bool found = false;
            for (int i = 0; i < bookCount; i++) {
                if (books[i].getISBN() == isbn) {
                    // Shift all books after the deleted book one position to the left
                    for (int j = i; j < bookCount - 1; j++) {
                        books[j] = books[j + 1];
                    }
                    bookCount--;
                    cout << "Book deleted successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book not found!" << endl;
            }
        }
        void deleteMember() {
            int id;
            cout << "Enter ID of the member to delete: ";
            cin >> id;
            cin.ignore();
        
            bool found = false;
            for (int i = 0; i < memberCount; i++) {
                if (members[i].getid() == id) {
                    // Shift all members after the deleted member one position to the left
                    for (int j = i; j < memberCount - 1; j++) {
                        members[j] = members[j + 1];
                    }
                    memberCount--;
                    cout << "Member deleted successfully!" << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Member not found!" << endl;
            }
        }
    };
int main(){
    Library library;
    int choice;
    while (true){
        cout << "===== Library Management System =====\n";
        cout << "---Book Management---\n";
        cout << "1  Add Book\n";
        cout << "2  Display Books\n";
        cout << "3  Search Book\n";
        cout << "4  Delete Book\n";
        cout << "---Member Management---\n";
        cout << "5  Add Member\n";
        cout << "6  Display Members\n";
        cout << "7  Search Member\n";
        cout << "8  Delete Member\n";
        cout << "---Transaction Management---\n";
        cout << "9  Issue Book\n";
        cout << "10 Display Transactions\n";
        cout << "11 Exit\n";
        cout << "=====================================\n";
        cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice)
    {
    case 1:
        library.addBook();
        break;
    case 2:
        library.displayBooks();
        break;
    
    case 3:
        library.searchBook();
        break;
    
    case 4:
        library.deleteBook();
        break;
    
    case 5:
        library.addMember();
        break;
    case 6:
        library.displayMembers();
        break;
    case 7:
        library.searchMember();
        break;
    case 8:
        library.deleteMember();
        break;
    case 9:
        library.issueBook();
        break;
    case 10:
        library.displayTransactions();
        break;
    case 11:
        return 0;
    
    default:
        cout << "Invalid Choice ! try Again.";
        break;
    }
}
    return 0;
}
