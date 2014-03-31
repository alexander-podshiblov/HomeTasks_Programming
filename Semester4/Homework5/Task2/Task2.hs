checkCond :: (a -> Bool) -> [a] -> Bool
checkCond _ [] = True
checkCond cond (x:m) = (cond x) && (checkCond cond m)