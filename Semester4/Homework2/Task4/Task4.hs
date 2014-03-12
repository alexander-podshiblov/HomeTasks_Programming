pos :: Int -> [Int] -> Int
pos n (x:m) | n == x = 1
            | otherwise = pos n m + 1