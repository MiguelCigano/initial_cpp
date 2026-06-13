#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, listNode *next) : val(x), next(next) {}
 * };
 *
 *  Given the head of a linked list and an integer val, remove all the
 *  nodes of the linked list that has Node.val == val, and return the new Head
 */


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, listNode *next) : val(x), next(next) {}
};

void trimLeftTrailingSpaces(std::string &input)
{
    input.erase(input.begin(), std::find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(std::string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
    std::vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(std::string input) {
    // Generate list from the input
    std::vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      std::cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    std::cout << node->val << std::endl;
  } 
  else {
    std::cout << "Empty LinkedList" << std::endl;
  }
}

int main() {
    std::string line;
    while (getline(std::cin, line)) {
        ListNode* head = stringToListNode(line);
        prettyPrintLinkedList(head);
    }
    return 0;
}