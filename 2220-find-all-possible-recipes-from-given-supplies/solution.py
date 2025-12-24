class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        # Build adjacency list: ingredient/supply -> list of recipes that need it
        ingredient_to_recipes = defaultdict(list)
      
        # Track in-degree (number of ingredients needed) for each recipe
        recipe_indegree = defaultdict(int)
      
        # Build the graph relationships
        for recipe, recipe_ingredients in zip(recipes, ingredients):
            for ingredient in recipe_ingredients:
                # This ingredient is needed by this recipe
                ingredient_to_recipes[ingredient].append(recipe)
            # Count total ingredients needed for this recipe
            recipe_indegree[recipe] = len(recipe_ingredients)
      
        # Initialize queue with available supplies (these have indegree 0)
        available_items = supplies.copy()
        makeable_recipes = []
      
        # Process items using BFS/topological sort
        for current_item in available_items:
            # For each recipe that needs this item
            for dependent_recipe in ingredient_to_recipes[current_item]:
                # Decrease the count of needed ingredients
                recipe_indegree[dependent_recipe] -= 1
              
                # If all ingredients are now available (indegree becomes 0)
                if recipe_indegree[dependent_recipe] == 0:
                    # This recipe can be made
                    makeable_recipes.append(dependent_recipe)
                    # Add it to available items for further processing
                    available_items.append(dependent_recipe)
      
        return makeable_recipes
        
