# Class Books

## Member variables

The book
   * Author
   * Price
   * publisher
   * Title
   * Copies available
   * Cost per book
   * vector of books

## Member functions

`Book(string author, string publisher, string title, double price, int copies);`
- custom constructor that constructs a book object

`void addBook(string title, string author, string publisher, double price, int
copies);` - receives details of a book. Constructs a book object and adds it to
the `m_books` vector. Then this function prints an confirmation message in the
form `title by author added`

`int search(string title, string author);` - takes in title and author and
returns the number of copies available. If the book does not exist, return -1

`void buy(string title, string author, int bought);` - buys x number of copies
of the book. Receives the title and author of a book. If book does not exist,
print `book by author does not exist`.

`int search(string title, string author);` - adds inventory for a certain title.
Receives the title and author of a book.  If the book does not exist, print
`book by author does not exist`.

`void buy(string title, string author, int bought);` - receives details of a
book. Makes sure that book exist, then subtract the `int bought` from the book
copies. And print confirmation message.

`void addInventory(string title, string author, int bought);` - Receives the
details of a book. Makes sure the book exist, and add the inventory passed in to
the book copies. And print confirmation message.

`void display();` - displays the details of a book
