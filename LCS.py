def LCS(X, Y):
  """
  This function calculates the Longest Common Subsequence (LCS) of two strings.

  Args:
    X: The first string.
    Y: The second string.

  Returns:
    A tuple containing the length of the LCS and the LCS itself.
  """
  n, m = len(X), len(Y)
  dp = [[0 for _ in range(m + 1)] for _ in range(n + 1)]

  for i in range(1, n + 1):
    for j in range(1, m + 1):
      if X[i - 1] == Y[j - 1]:
        dp[i][j] = dp[i - 1][j - 1] + 1
      else:
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

  lcs = ""
  i, j = n, m
  while i > 0 and j > 0:
    if X[i - 1] == Y[j - 1]:
      lcs += X[i - 1]
      i -= 1
      j -= 1
    else:
      if dp[i - 1][j] >= dp[i][j - 1]:
        i -= 1
      else:
        j -= 1

  return dp[n][m], lcs[::-1]

# Example usage
X = "wildfire"
Y = "fireworks"

lcs_length, lcs = LCS(X, Y)

# Calculate the string similarity score
similarity_score = (2 * lcs_length) / (len(X) + len(Y))

print(f"Length of LCS: {lcs_length}")
print(f"LCS: {lcs}")
print(f"String similarity score: {similarity_score}")