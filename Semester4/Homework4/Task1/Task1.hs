data Tree a = Leaf a
            | Branch (Tree a) a (Tree a)

search :: (a -> Bool) -> Tree a -> [a]
search = search' []
         where search' m cond (Leaf value) = if cond value then value : m else m
               search' m cond (Branch left value right) = if cond value
                                                          then search' (value : (search' m cond left)) cond right
                                                          else search' (search' m cond left) cond right