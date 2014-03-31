eCount1 :: [Int] -> Int
eCount1 = length . filter even

eCount2 :: [Int] -> Int
eCount2 m = length . filter (== 0) $ map (\x -> mod x 2) m

eCount3 :: [Int] -> Int
eCount3 m = (length m) - (foldl (+) 0 $ map (\x -> mod x 2) m)
