reverse :: [a] -> [a]
reverse m = foldl (\x y -> y:x) [] m