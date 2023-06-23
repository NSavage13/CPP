//
//  main.cpp
//  RecipeMaps
//
//  Created by Nico Savage on 6/20/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class recipeCard {
private:
    string recipeName;
    vector<pair<string, string>> ingredients;
    queue<string> directions;

public:
    recipeCard(const string& name) : recipeName(name) {}
    void addIngredient(const string& ingredient, const string& amount) {
        ingredients.push_back(make_pair(ingredient, amount));
    }
    void addDirection(const string& direction) {
        directions.push(direction);
    }
    string getRecipeName() const {
        return recipeName;
    }
    const vector<pair<string, string>>& getIngredients() const {
        return ingredients;
    }
    void displayRecipe() const {
        cout << "Recipe: " << recipeName << endl;
        cout << "Ingredients: " << endl;
        for (const auto& ingredient : ingredients) {
            cout << "- " << ingredient.first << ": " << ingredient.second << endl;
        }
        cout << "Directions: " << endl;

        queue<string> copyDirections = directions;

        while (!copyDirections.empty()) {
            cout << copyDirections.front() << endl;
            copyDirections.pop();
        }
        cout << endl;
    }
};

void displayRecipeNames(const map<string, recipeCard>& recipeMap) {
    cout << "Recipe Names:" << endl;
    for (const auto& recipe : recipeMap) {
        cout << "- " << recipe.first << endl;
    }
    cout << endl;
}

void addRecipe(map<string, recipeCard>& recipeMap) {
    string recipeName;
    cout << "Enter recipe name: ";
    getline(cin, recipeName);

    recipeCard newRecipe(recipeName);

    cout << "Enter ingredients (Enter 'done' when finished):" << endl;
    while (true) {
        string ingredient;
        cout << "Ingredient: ";
        getline(cin, ingredient);
        if (ingredient == "done")
            break;

        string amount;
        cout << "Amount: ";
        getline(cin, amount);

        newRecipe.addIngredient(ingredient, amount);
    }

    cout << "Enter directions (Enter 'done' when finished):" << endl;
    while (true) {
        string direction;
        cout << "Direction: ";
        getline(cin, direction);
        if (direction == "done")
            break;

        newRecipe.addDirection(direction);
    }

    recipeMap.insert(make_pair(newRecipe.getRecipeName(), newRecipe));
    cout << "Recipe added successfully!" << endl;
}

void searchByIngredient(const map<string, recipeCard>& recipeMap, const string& ingredient) {
    bool found = false;

    cout << "Recipes containing " << ingredient << ":" << endl;
    for (const auto& recipe : recipeMap) {
        for (const auto& ingredientPair : recipe.second.getIngredients()) {
            if (ingredientPair.first == ingredient) {
                cout << "- " << recipe.first << endl;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << "No recipes found with " << ingredient << "." << endl;
    }
    cout << endl;
}

void displayChosenRecipe(const map<string, recipeCard>& recipeMap, const string& recipeName) {
    auto it = recipeMap.find(recipeName);
    if (it != recipeMap.end()) {
        it->second.displayRecipe();
    } else {
        cout << "Recipe not found." << endl;
    }
}

int main() {
    map<string, recipeCard> recipeMap;

    while (true) {
        cout << "====== Recipe Manager ======" << endl;
        cout << "1. Display recipe names" << endl;
        cout << "2. Add a recipe" << endl;
        cout << "3. Search by ingredient" << endl;
        cout << "4. Display a chosen recipe" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            displayRecipeNames(recipeMap);
        } else if (choice == 2) {
            addRecipe(recipeMap);
        } else if (choice == 3) {
            string ingredient;
            cout << "Enter ingredient to search: ";
            getline(cin, ingredient);
            searchByIngredient(recipeMap, ingredient);
        } else if (choice == 4) {
            string recipeName;
            cout << "Enter recipe name to display: ";
            getline(cin, recipeName);
            displayChosenRecipe(recipeMap, recipeName);
        } else if (choice == 5) {
            cout << "Exiting... Thank you!" << endl;
            return 0;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }


        cout << endl;
    }

    return 0;
}

