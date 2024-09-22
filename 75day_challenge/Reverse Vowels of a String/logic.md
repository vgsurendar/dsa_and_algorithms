
### Algorithm: Reverse Vowels of a String

#### **Objective:**
Given a string `s`, reverse only the vowels and return the modified string.


**Improved Explanation:**

The algorithm for reversing vowels in a string involves the following steps:

1.  **Initialize pointers:** Start with two pointers:  `left` at the beginning of the string and `right` at the end.
2.  **Iterate until pointers meet:**
    -   **Find next vowel from left:** Move the `left` pointer until it points to a vowel.
    -   **Find next vowel from right:** Move the `right` pointer until it points to a vowel.
    -   **Swap vowels:** If both pointers point to vowels, swap the characters at those positions.
    -   **Update pointers:** Increment `left` and decrement `right` to continue the process.
3.  **Repeat:** Continue iterating until the `left` and `right` pointers meet.

This approach efficiently swaps vowels while avoiding unnecessary comparisons and ensuring that each vowel is swapped only once.

#### **Steps:**

1. **Initialization:**
   - Set two pointers, `left` starting at the beginning of the string (index 0) and `right` starting at the end of the string (index `strlen(s) - 1`).
   
2. **Move the Left Pointer:**
   - Traverse the string from the left (`left++`) until you find a vowel or the pointers meet. Continue this for each character that isn't a vowel.
   
3. **Move the Right Pointer:**
   - Traverse the string from the right (`right--`) until you find a vowel or the pointers meet. Continue this for each character that isn't a vowel.
   
4. **Swap the Vowels:**
   - Once both `left` and `right` pointers point to vowels, swap the characters at the positions `left` and `right`.

5. **Update Pointers:**
   - After the swap, move the `left` pointer one step to the right and the `right` pointer one step to the left.

6. **Continue Swapping:**
   - Repeat steps 2-5 until the two pointers cross each other (`left >= right`).

7. **Return the Modified String.**

#### **Example:**

Let's take the string **"hello"** as input:

- **Initial String:** `hello`
- **Vowels:** e, o

**Step-by-Step Execution:**

- **Step 1:**
  - `left` points to 'h' (non-vowel), so move `left` to 1.
  - `right` points to 'o' (vowel), so keep `right` at 4.

- **Step 2:**
  - `left` points to 'e' (vowel), keep `left` at 1.
  - Swap 'e' at index 1 with 'o' at index 4.

- **Step 3:**
  - Move `left` to 2 (`l` is non-vowel), move `left` to 3.
  - Move `right` to 3 (`l` is non-vowel), move `right` to 2.

- **Step 4:**
  - Since `left >= right`, the loop ends.

**Final Output:**
- **Modified String:** `holle`

#### **Flowchart:**

```text
Start
  |
Initialize left = 0, right = strlen(s) - 1
  |
While left < right
  |
Is s[left] a vowel? --> No --> Increment left
  |
Is s[right] a vowel? --> No --> Decrement right
  |
If both s[left] and s[right] are vowels
  |
Swap s[left] and s[right]
  |
Increment left, Decrement right
  |
End Loop
  |
Return modified string
```

### Key Notes:

- The function modifies the string in-place.
- It ensures that non-vowel characters remain in their original position, and only the vowels are reversed.
- The algorithm uses two-pointer approach to optimize the search for vowels from both ends, making it more efficient than a brute-force approach.