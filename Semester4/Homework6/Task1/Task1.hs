data Tree a = Empty | Node (Tree a) Char (Tree a)

toString :: Tree a -> String
toString (Empty) = "e"
toString (Node left a right) = "n" ++ [a] ++ toString left ++ toString right

toTree = fst.parse
    where parse ('n':x:s) = (Node left x right, rightRest)
                                where (right, rightRest) = parse leftRest
                                      (left, leftRest) = parse s
          parse ('e':s) = (Empty, s)

