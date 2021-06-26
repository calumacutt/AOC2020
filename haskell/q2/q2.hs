import Data.List.Split

data Policy = Policy Int Int Char String
    deriving Show

-- IO to get Policies

convLineToPolicy :: String -> Policy
convLineToPolicy line = conv3StringsToPolicy (splitOn " " line)

conv3StringsToPolicy :: [String] -> Policy
conv3StringsToPolicy (a : b : c : []) = convRangeCharStringToPolicy (convRangeStringToRange a) (head b) c

convRangeCharStringToPolicy :: (Int, Int) -> Char -> String -> Policy
convRangeCharStringToPolicy (lower, upper) char string = Policy lower upper char string

convRangeStringToRange :: String -> (Int, Int)
convRangeStringToRange string = convStringsToRange (splitOn "-" string)

convStringsToRange :: [String] -> (Int, Int)
convStringsToRange (a : b : []) = (read a, read b)

--

checkIfPolicyValid1 :: Policy -> Bool
checkIfPolicyValid1 (Policy lower upper letter password) = if ((countLetterInPassword letter password)>=lower)&&((countLetterInPassword letter password)<=upper)
    then True
    else False

countLetterInPassword :: Char -> String -> Int
countLetterInPassword letter password = foldr (\x y -> if (x == letter) then y + 1 else y) 0 password

--

checkIfPolicyValid2 :: Policy -> Bool
checkIfPolicyValid2 (Policy lower upper letter password) = if ((password!!(lower-1) == letter) /= (password!!(upper-1) == letter))
    then True
    else False

main :: IO ()
main = do
    listOfStrings <- lines <$> readFile "input.txt"
    -- print(checkIfPolicyValid (convLineToPolicy (head listOfStrings)))
    -- print(foldr (\x y -> if checkIfPolicyValid1 (convLineToPolicy x) then y + 1 else y) 0 listOfStrings)
    print(foldr (\x y -> if checkIfPolicyValid2 (convLineToPolicy x) then y + 1 else y) 0 listOfStrings)
