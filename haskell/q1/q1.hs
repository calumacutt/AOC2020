import System.IO  
import Control.Monad

checkWhereNumberInList :: ([Integer], Integer, Integer) -> (Integer, Integer)
checkWhereNumberInList ([], n, t) = (-1, 0)
checkWhereNumberInList ((x:xs), n, t) = if (x == t) then (n, t) else checkWhereNumberInList (xs, n + 1, t)

turnStringsIntoInts :: [String] -> [Integer]
turnStringsIntoInts [] = []
turnStringsIntoInts (x:xs) = (read x :: Integer) : turnStringsIntoInts(xs)

mapToComplement :: [Integer] -> [(Integer, Integer)]
mapToComplement [] = []
mapToComplement (x:xs) = checkWhereNumberInList (xs, 0, 2020 - x) : mapToComplement xs

main :: IO ()
main = do
    listOfStrings <- lines <$> readFile "input.txt"
    let listOfIntegers = turnStringsIntoInts listOfStrings
    let listOfComplementIndexes = mapToComplement listOfIntegers
    print listOfComplementIndexes
