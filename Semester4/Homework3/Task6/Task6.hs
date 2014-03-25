isPair :: Char -> Char -> Bool
isPair '(' ')' = True
isPair '{' '}' = True
isPair '[' ']' = True
isPair '<' '>' = True
isPair _ _ = False

stack [] x = [x]
stack (c:s) x | isPair c x = s
              | otherwise = (x:c:s)

bFilter = filter (`elem` "(){}[]<>")

check :: [Char] -> Bool
check = (== []) . foldl (stack) [] . bFilter