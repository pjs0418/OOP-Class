#ifndef PROB1_H
#define PROB1_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Class for displaying initial page and select menu page
 * When user selects a one of menus, it can display next page by RecipeManager and PlanManager class.
 */
class Greeter
{
private:
    RecipeManager recipeManager;
    PlanManager PlanManager;

public:
    Greeter();
    void displayInitPage();
    void displayMenuPage();
};

/**
 * Class for managing recipes
 * void displayRecipePage(): function for displaying search bar, add button and recipes(depending on the existence of searchRecipeList)
 * void searchRecipes(string searchInput): function for searching recipes by searchInput parameter and storing into searchRecipeList
 * void displayAddRecipePage(): function for displaying add recipe page
 * void addRecipe(...): function for adding recipe
 * void printPage(): function for printing page
 */
class RecipeManager
{
private:
    vector<Recipe> searchRecipeList;

public:
    RecipeManager();
    void displayRecipePage();
    void searchRecipes(string searchInput);
    void displayAddRecipePage();
    void addRecipe(string recipeName, vector<string> groceryList, vector<string> prepSteps, int prepTime);
    void printPage();
};

/**
 * Class for each recipe object
 * void displayRecipeInfo(): function for displaying detailed recipe information
 * void displayEditRecipePage(): function for displaying edit recipe page
 * void editRecipe(...): function for editing recipe
 * void deleteRecipe(): function for deleting recipe
 * vector<string> getGroceryList(): function for returning grocery list used in recipe
 * void printPage(): function for printing page
 */
class Recipe
{
private:
    string recipeName;
    vector<string> groceryList;
    vector<string> prepSteps;
    int prepTime;

public:
    Recipe(string recipeName, vector<string> groceryList, vector<string> prepSteps, int prepTime);
    void displayRecipeInfo();
    void displayEditRecipePage();
    void editRecipe(string recipeName, vector<string> groceryList, vector<string> prepSteps, int prepTime);
    void deleteRecipe();
    vector<string> getGroceryList();
    void printPage();
};

/**
 * Class for managing plans
 * void displayPlanPage(): function for displaying all plan list
 * void displayAddPlanPage(): function for displaying add plan page including add meal button and function(using Plan class member function)
 * void addPlan(...): function for adding plan
 * void printPage(): function for printing page
 */
class PlanManager
{
private:
    vector<Plan> planList;

public:
    PlanManager();
    void displayPlanPage();
    void displayAddPlanPage();
    void addPlan(string planName, string period, vector<Meal> mealList);
    void printPage();
};

/**
 * Class for plan object
 * void displayPlanInfo(): function for displaying detailed plan information
 * void displayAddMealPage(): function for displaying add meal page including add recipe button and function(using Meal class member function)
 * vector<Meal> addMeals(...): function for returning meal list to add meals into plan
 * void editPlan(...): function for editing plan
 * void deletePlan(): function for deleting plan
 * void setPlanGroceryList(): function for storing grocery list used in plan
 * void printPage(): function for printing page
 */
class Plan
{
private:
    string planName;
    string period;
    vector<Meal> mealList;
    vector<string> planGroceryList;

public:
    Plan(string planName, string period, vector<Meal> mealList);
    void displayPlanInfo();
    void displayAddMealPage();
    vector<Meal> addMeals(string mealName, vector<Recipe> recipeList);
    void editPlan(string planName, string period, vector<Meal> mealList);
    void deletePlan();
    void setPlanGroceryList();
    void printPage();
};

/**
 * Class for meal object
 * vector<Recipe> addRecipes(): function for returning recipes by RecipeManager class for using in Plan class member function
 * void editMeal(...): function for editing meal
 * void deleteMeal(): function for deleting meal
 * void setMealGroceryList(): function for storing grocery list used in meal
 * vector<string> getMealGroceryList(): function for returning grocery list used in meal
 */
class Meal
{
private:
    string mealName;
    vector<Recipe> recipeList;
    RecipeManager recipeManager;
    vector<string> mealGroceryList;

public:
    Meal(string mealName, vector<Recipe> recipeList);
    vector<Recipe> addRecipes();
    void editMeal(string mealName, vector<Recipe> recipeList);
    void deleteMeal();
    void setMealGroceryList();
    vector<string> getMealGroceryList();
};

#endif