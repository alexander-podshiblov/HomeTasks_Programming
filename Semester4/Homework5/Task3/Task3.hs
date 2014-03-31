comb123 :: Int -> [[Int]]
comb123 n | n == 1 = [[1], [2], [3]]
          | otherwise = [first ++ tail | first <- [[1], [2], [3]], tail <- comb123 (n - 1)]