f :: Integer -> Integer -> Integer -> Integer
f = \x -> (\y -> (\z -> x * (y + z))) 

main = print (f 3 2 6)