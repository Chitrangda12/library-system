Library-system
A simple console-based application written in C for managing a collection of books, organized by the first letter of the author's name using a 2D array and a hash function.
Features: Add one or more books, View all books, grouped alphabetically by author's first letter, Count total books, Easy-to-use menu-driven interface
Concepts used: Structures, Arrays, Hashing, String handling

Data Structure:-
struct Book: Represents each book with id, title, and author
library[26][MAX_BOOKS]: 2D array where each row stores books by authors starting with a particular letter (A to Z)
bookCount[26]: Tracks the number of books in each alphabetical row

Hash Function:-
int hashFunction(char *author);
Maps the first character of the author’s name (case-insensitive) to an index 0–25
Index corresponds to A–Z

Menu Options:-
Add Book(s): Add multiple books in one go
Display All Books: Shows books sorted/grouped by author's initial
Count Total Books: Displays how many books are stored
Exit: Ends the program
