READ ME

Rayyan Faisal, 501196760

Brief Summary: 
  In this lab we focused on implementing Insertion sort and Merge sort algorithms. We also analyzed each 
  sorting algorithms using equations.Both sorting methods have been fully implemented, and everything works.

Insertion Sort Analysis:
  - Best Case: The array is already sorted. The algorithm makes `n` comparisons and no swaps or 
  copies, resulting in O(n) time complexity.
  - Average Case: The array is in a random order. The expected number of comparisons is `(n(n- 
  1)/2)`, with the same number of swaps, and `n-1` copies. This results in O(n^2) time complexity.
  - Worst Case: The array is in reverse order. The number of comparisons and swaps is `(n(n- 
  1)/2)`, with `n-1` copies, leading to O(n^2) time complexity.

Merge Sort Analysis:
  - Best Case: The array is already sorted. The algorithm makes approximately `n log n` 
  comparisons and a similar number of copies. The time complexity is O(n log n).
  - Average Case: The array is in a random order. The number of comparisons is also `n log n`, 
  with a similar number of copies. The time complexity remains O(n log n).
  - Worst Case: The array is in reverse order. The number of comparisons and copies is the same as 
  in the best and average cases, maintaining the O(n log n) time complexity.
