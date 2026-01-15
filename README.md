# Valid Anagram Checker

A C program to determine if two strings are anagrams of each other.

## Problem Statement

Write a function to determine if two provided strings are anagrams of each other.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Examples
- Input: `s = "listen"`, `t = "silent"` → Output: `True`
- Input: `s = "rat"`, `t = "car"` → Output: `False`

## How to Compile and Run
```bash
# Compile the program
gcc anagram.c -o anagram

# Run the program
./anagram
```

## Expected Output
```
=== Valid Anagram Checker ===

Test 1:
Input: s = "listen", t = "silent"
Output: True

Test 2:
Input: s = "rat", t = "car"
Output: False

Test 3:
Input: s = "anagram", t = "nagaram"
Output: True

Test 4:
Input: s = "hello", t = "world"
Output: False

Test 5:
Input: s = "Listen", t = "Silent"
Output: True
```

## Logic

I used the **character frequency counting** method to solve this problem efficiently.

### Algorithm Steps:

1. **Length Check (Optimization)**
   - First, I compare the lengths of both strings
   - If lengths are different, they cannot be anagrams → return `false` immediately
   - This saves unnecessary computation

2. **Character Frequency Array**
   - I create an array of size 26 (for letters a-z)
   - Initialize all counts to 0

3. **Single Pass Counting**
   - Loop through both strings simultaneously
   - For each position `i`:
     - **Increment** the count for the character in string `s`
     - **Decrement** the count for the character in string `t`
   - Convert characters to lowercase for case-insensitive comparison

4. **Verification**
   - Loop through the count array
   - If any count is **not zero**, the strings have different character frequencies
   - If **all counts are zero**, the strings are anagrams

### Why This Works

If two strings are anagrams:
- They use the exact same letters
- Each letter appears the same number of times
- When we add counts from one and subtract from the other, everything balances to zero

### Example Walkthrough

For `s = "listen"` and `t = "silent"`:
```
Initial: count = [0, 0, 0, ..., 0]

Processing each character:
i=0: 'l' (+1), 's' (-1) → count[l]=1, count[s]=-1
i=1: 'i' (+1), 'i' (-1) → count[i]=0
i=2: 's' (+1), 'l' (-1) → count[s]=0, count[l]=0
i=3: 't' (+1), 'e' (-1) → count[t]=1, count[e]=-1
i=4: 'e' (+1), 'n' (-1) → count[e]=0, count[n]=-1
i=5: 'n' (+1), 't' (-1) → count[n]=0, count[t]=0

Final: All counts = 0 → Anagrams!
```

## Complexity Analysis

### Time Complexity: **O(n)**
- `strlen()` to get lengths: O(n)
- Single loop through both strings: O(n)
- Loop through fixed array of 26: O(26) = O(1)
- **Total: O(n)** where n is the length of the string

### Space Complexity: **O(1)**
- Fixed array of 26 integers (for a-z)
- A few integer variables
- Space does not grow with input size
- **Total: O(1)** - constant space

## Solution is Optimal

**Efficient:** Linear time complexity, only one pass through the data  
**Memory Efficient:** Uses constant extra space  
**Handles Edge Cases:** Empty strings, different lengths, case insensitivity  

## Technologies Used

- **Language:** C (C99 standard)
- **Compiler:** GCC
- **Platform:** Linux (Arch Linux)
- **Editor:** Neovim

---

**Author:** Nirpesh Bhattarai  
**Email:** nirpeshbhattarai551@gmail.com  
**Date:** January 2026  
**Purpose:** DevOps Assessment
