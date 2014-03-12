sumD :: Integer -> Integer
sumD n | n == 0 = 0
       | n < 0 = (sumD.abs) n
       | otherwise = (mod n 10) + sumD (div n 10)