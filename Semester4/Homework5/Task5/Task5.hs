f :: [Int] -> Maybe Int
f [] = Nothing
f [_] = Nothing
f [_, _] = Nothing
f (x:y:z:m) = return m >>= \m2 -> if (y > x) && (y > z)
                                  then Just y
                                  else f (y:z:m2)