degOfTwo :: Integer -> [Integer] -> [Integer]
degOfTwo n m | n == 0 = 1:m
             | n < 0 = error "argument must be non-negative"
             | n > 0 = degOfTwo (n - 1) (2^n:m)