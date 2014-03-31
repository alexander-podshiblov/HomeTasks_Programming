checkOne :: (Eq a) => a -> [a] -> Bool
checkOne _ [] = True
checkOne value (x:m) = (value /= x) && (checkOne value m)

check :: (Eq a) => [a] -> Bool
check (x:m) | m == [] = True
            | otherwise = (checkOne x m) && (check m) 