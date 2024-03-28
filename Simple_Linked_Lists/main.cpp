#include <iostream>
#include <iomanip>
#include "includes/list_simple/list_simple.h"
#include "includes/linked_list_functions/linked_list_functions.h"
#include "includes/node/node.h"

using namespace std;

int random_number(int size = 50)
{
    return rand() % size; // random number from 0 to size
}

void *init(List<int> &main)
{
    for (int i = 0; i < 5; i++)
    {
        main.insert_head(random_number());
    }
}

// print just for main
void _main_print(List<int> &main, node<int> *cursor)
{
    node<int> *head = main.begin();
    for (node<int> *walker = head; walker != nullptr; walker = walker->_next)
    {
        // if it is the cursor
        if (walker == cursor)
            cout << "{" << walker->_item << "}->";

        else
            cout << "[" << walker->_item << "]->";
    }

    cout << "|||\n";
}

int main(int argv, char **argc)
{
    cout << "=====================\n\n\n"
         << endl;

    List<int> main_list;
    init(main_list);
    // cursor to the current node
    node<int> *cursor = main_list.begin();

    char response;

    do
    {
        _main_print(main_list, cursor);
        cout << "[R]andom [A]fter  [B]efore [D]elete [S]earch  [P] Previous  [N] Next  [H]ome  [E]nd ";
        cin >> response;

        switch (tolower(response))
        {
        case 'n':
        {
            if (main_list.begin() == nullptr)
                break;
            else if (cursor->_next != nullptr)
                cursor = cursor->_next;
            break;
        }

        case 'p':
        {
            if (main_list.begin() == nullptr)
                break;

            node<int> *prev = main_list.prev(cursor);
            if (prev != nullptr)
                cursor = prev;
            break;
        }

        case 'r':
        {
            cursor = main_list.insert_after(random_number(), cursor);
            break;
        }

        case 'a':
        {
            int item;
            cout << ": ";
            cin >> item;
            cursor = main_list.insert_after(item, cursor);
            break;
        }

        case 'b':
        {
            int item;
            cout << ": ";
            cin >> item;
            cursor = main_list.insert_before(item, cursor);
            break;
        }

        case 's':
        {
            int item;
            cout << ": ";
            cin >> item;
            node<int> *found = main_list.search(item);

            if (found)
                cursor = found;

            break;
        }

        case 'd':
        {
            // if the list is empty
            if (cursor == nullptr)
                break;

            main_list.Delete(cursor);
            // no break here because it's cool
        }

        case 'h':
        {
            cursor = main_list.begin();
            break;
        }

        case 'e':
        {
            cursor = main_list.last_node();
            break;
        }
        }
    } while (tolower(response) != 'x');

    cout << "\n\n\n=====================" << endl;
    return 0;
}
