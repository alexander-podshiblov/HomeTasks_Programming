f :: Int -> [[Int]]
f n = f' n n
      where f' n max | n > 0 = [1..max] >>= (\x -> map (x:) (f' (n - x) $ min x (n - x)))
                     | otherwise = [[]]

