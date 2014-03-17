posOfElem :: [Int] -> Int -> Int
posOfElem [] _ = error "element is not exist"
posOfElem (x:m) n | x == n  = 1
                  | otherwise = posOfElem m n + 1

maxElem :: [Int] -> Int -> Int
maxElem [] n = n
maxElem (x:m) n | x > n = maxElem m x
                | otherwise = maxElem m n

maxSumPos :: [Int] -> Int
maxSumPos (x:m) = posOfElem sumList (maxElem sumList 0)
          where sumList = zipWith (+) (x:m) m