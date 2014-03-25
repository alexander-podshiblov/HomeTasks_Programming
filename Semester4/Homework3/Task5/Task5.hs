data Tree a = Leaf a
            | Branch (Tree a) a (Tree a)

depth :: Tree a -> Int
depth (Leaf a) = 0
depth (Branch lTree _ rTree) = 1 + max (depth lTree) (depth rTree)


minDist :: Tree a -> Int
minDist (Leaf a) = 0
minDist (Branch lTree _ rTree) = 1 + min (minDist lTree) (minDist rTree) 