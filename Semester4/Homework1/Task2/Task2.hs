fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n | n > 0 = fib (n - 1) + fib (n - 2)
fib n | n < 0 = error "argument must be non-negative"
