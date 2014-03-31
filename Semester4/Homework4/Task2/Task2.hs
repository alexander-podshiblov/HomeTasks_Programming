data Tree a = Leaf a
            | Branch (Tree a) a (Tree a)

toList :: Tree a -> [a]
toList = toList' []
toList' m (Leaf value) = value : m
toList' m (Branch left value right) = toList' (value : (toList' m right)) left


tFoldl :: (a -> b -> a) -> a -> Tree b -> a
tFoldl f elem tree = foldl f elem (toList tree)

tFoldr :: (b -> a -> a) -> a -> Tree b -> a
tFoldr f elem tree = foldr f elem (toList tree)


