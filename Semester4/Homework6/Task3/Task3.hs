data BST a = Empty | Node (BST a) a (BST a)
    deriving (Eq)

insert :: Ord a => a -> BST a -> BST a
insert k Empty = Node Empty k Empty
insert k (Node left x right) | k < x = insert k left
                             | k > x = insert k right
                             | otherwise = error ("Already Exist")

remove :: Ord a => a -> BST a -> BST a
remove _ Empty = Empty
remove k (Node left x right) | k < x = Node (remove k left) x right
                             | k > x = Node left x (remove k right)
                             | otherwise = removing
    where removing | (left == Empty) && (right == Empty) = Empty
                   | (left == Empty) && (right /= Empty) = right
                   | (left /= Empty) && (right == Empty) = left
                   | otherwise = Node left (minElem right) (remove (minElem right) right)
                       where minElem (Node left x right) | left == Empty = x
                                                         | otherwise = minElem left

isExist :: Ord a => a -> BST a -> Bool
isExist _ Empty = False
isExist k (Node left x right) | k < x = isExist k left
                              | k > x = isExist k right
                              | otherwise = True

size :: BST a -> Int
size Empty = 0
size (Node left x right) = (size left) + 1 + (size right)

height :: BST a -> Int
height Empty = 0
height (Node left x right) = 1 + max (height left) (height right)