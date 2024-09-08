Here's a step-by-step explanation of the algorithm used in the `kidsWithCandies` function:

### Problem:
You have an array `candies[]` where each element represents the number of candies a child has. You also have an integer `extraCandies`, which represents the additional candies you can give to each child. The goal is to determine which children can have the **greatest number of candies** among all the kids if they receive the extra candies.

### Algorithm Breakdown:

1. **Input:**
   - `candies[]`: an array where each element represents how many candies a particular child has.
   - `candiesSize`: the size of the `candies[]` array.
   - `extraCandies`: the number of additional candies that can be given to each child.
   - `returnSize`: a pointer where the function stores the size of the result array.

2. **Step-by-Step Execution:**

   1. **Find the Maximum Number of Candies (`findMaxofArray`):**
      - The helper function `findMaxofArray` scans through the `candies[]` array to find the child who currently has the **maximum** number of candies.
      - This is needed because we need to compare each child's candies (after adding the extra candies) to see if they would have more candies than this maximum.

      Example:  
      - If `candies[] = [2, 3, 5, 1, 3]`, the maximum number of candies is `5`.

   2. **Memory Allocation for the Result Array:**
      - Allocate memory for a boolean array `result[]` of size `candiesSize`. Each element in this array will be `true` or `false` depending on whether the corresponding child can have the most candies after receiving the extra candies.

      Example:
      - If `candiesSize = 5`, the function allocates memory for a `bool` array of size 5.

   3. **Determine if Each Child Can Have the Maximum Candies:**
      - For each child, the algorithm checks whether the number of candies they have, plus the `extraCandies`, is greater than or equal to the maximum number of candies (`maxCandy`).
      - If `candies[i] + extraCandies >= maxCandy`, then this child can have the greatest number of candies. The corresponding element in `result[]` is set to `true`.
      - Otherwise, it is set to `false`.

      Example:
      - `candies[] = [2, 3, 5, 1, 3]`, `extraCandies = 3`.
      - Maximum candies is `5`.
      - For each child:
        - Child 0: `2 + 3 = 5` (can have the maximum), so `result[0] = true`.
        - Child 1: `3 + 3 = 6` (greater than the maximum), so `result[1] = true`.
        - Child 2: `5 + 3 = 8` (greater than the maximum), so `result[2] = true`.
        - Child 3: `1 + 3 = 4` (less than the maximum), so `result[3] = false`.
        - Child 4: `3 + 3 = 6` (greater than the maximum), so `result[4] = true`.

   4. **Set the Return Size:**
      - The function sets `*returnSize` to `candiesSize` so that the caller knows the size of the result array.

   5. **Return the Result:**
      - The function returns the `result[]` array, which contains `true` or `false` for each child, indicating whether they can have the greatest number of candies after receiving the extra candies.

### Final Example:

Input:
- `candies[] = [2, 3, 5, 1, 3]`
- `extraCandies = 3`

Execution:
1. Find `maxCandy = 5`.
2. Compare each child's candies + extraCandies with `maxCandy`:
   - Child 0: `2 + 3 = 5`, can have the maximum → `true`.
   - Child 1: `3 + 3 = 6`, can have the maximum → `true`.
   - Child 2: `5 + 3 = 8`, can have the maximum → `true`.
   - Child 3: `1 + 3 = 4`, cannot have the maximum → `false`.
   - Child 4: `3 + 3 = 6`, can have the maximum → `true`.

Output:
- `result[] = [true, true, true, false, true]`

This array indicates that children 0, 1, 2, and 4 can have the most candies after getting the extra candies.
