#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function declarations
void makeSandwichStack(stack<string>& SandwichStack);
bool checkSandwichStack(stack<string>& SandwichStack);

int main() {
    stack<string> mySandwichStack;
    makeSandwichStack(mySandwichStack);

    if (checkSandwichStack(mySandwichStack)) {
        cout << "Yum! This is a perfect sandwich stack stack!" << endl;
    }
    else {
        cout << "Uh-oh, this sandwich is all wrong!" << endl;
    }

    return 0;
}

// Function to build a pancake stack using a stack
void makeSandwichStack(stack<string>& SandwichStack) {
    string topping;
    cout << "Enter meal items one by one to build your stack (type 'done' to finish): \n";
    while (true) {
        cout << "Add item: ";
        getline(cin, topping);
        if (topping == "done") break;
        SandwichStack.push(topping);
    }
}

// Function to check if the pancake stack matches the perfect stack
bool checkSandwichStack(stack<string>& SandwichStack) {
    stack<string> perfectStack;
    perfectStack.push("Bread");
    perfectStack.push("Pickle");
    perfectStack.push("Chicken");
    perfectStack.push("Lettuce");
    perfectStack.push("Tomato");
    perfectStack.push("Sauce");
    perfectStack.push("Bread");

    // Compare each element of both stacks
    while (!SandwichStack.empty() && !perfectStack.empty()) {
        if (SandwichStack.top() != perfectStack.top()) return false;
        SandwichStack.pop();
        perfectStack.pop();
    }

    // Check both stacks separately for better clarity
    if (SandwichStack.empty() && perfectStack.empty()) {
        return true;  // Both stacks are empty, so they match
    }
    else {
        return false; // One stack still has elements, so they don't match
    }
}
