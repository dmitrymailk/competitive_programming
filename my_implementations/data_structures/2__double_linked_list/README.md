## 1.2 Doubly Linked List

### Мотивация и почему была придумана эта структура

Singly linked list имеет существенный недостаток, находясь на каком-то элементе мы не имеем доступ к прошлому, поэтому нам бы хотелось иметь иногда двунаправленный доступ к элементам

### Общее описание структуры

Кроме того что каждый элемент списка ссылается на другой, никаких новых существенных отличий нет.

### Детальное описание свойств структуры

Добавление и удаление также должно осуществляться за O(1), и суть удаления и добавления ничем не отличается от **Singly Linked List** кроме того, что надо учитывать двусвязность каждого элемента.
