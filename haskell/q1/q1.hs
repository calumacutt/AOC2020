convStrToInt :: [String] -> [Integer]
convStrToInt [] = []
convStrToInt (x:xs) = (read x :: Integer) : convStrToInt(xs)

isElementOf :: Integer -> [Integer] -> Bool
isElementOf _ [] = False
isElementOf e (x:xs) = (e == x) || (isElementOf e xs)

partA :: Integer -> [Integer] -> Integer
partA _ [] = -1
partA e (x:xs) = if (isElementOf (e - x) xs)
    then (e - x) * x
    else partA e xs

partB :: [Integer] -> Integer
partB [] = -1
partB (x:xs) = if (partA (2020 - x) xs) /= -1
    then x * (partA (2020 - x) xs)
    else partB xs

main :: IO ()
main = do
    listOfStrings <- lines <$> readFile "input.txt"
    let listOfIntegers = convStrToInt listOfStrings
    print (partA 2020 listOfIntegers)
    print (partB listOfIntegers)
