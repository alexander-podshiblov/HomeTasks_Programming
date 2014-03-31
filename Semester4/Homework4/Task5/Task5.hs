addInSort :: Int -> [Int] -> [Int]
addInSort value [] = [value]
addInSort value (x:m) | value <= x = value:x:m
                      | otherwise = x:(addInSort value m)

remove :: Int -> [Int] -> [Int]
remove value [] = []
remove value (x:m) | value == x = m
                        | otherwise = x:(remove value m)

doLoop :: [Int] -> IO ()
doLoop m = do
    putStrLn "////////////////////////////"
    putStrLn "Enter a command:"
    putStrLn "0 - exit"
    putStrLn "1 - add value to sorted list"
    putStrLn "2 - remove value from list"
    putStrLn "3 - print list"
    command <- getLine
    case command of
        '0':[] -> putStrLn "End of work"
        '1':[] -> do putStrLn ("Enter value:")
                     value <- readLn
                     doLoop $ addInSort value m
        '2':[] -> do putStrLn "Enter value:"
                     value <- readLn
                     doLoop $ remove value m
        '3':[] -> do putStrLn $ show m
                     doLoop m
        _      -> doLoop m

main = doLoop []