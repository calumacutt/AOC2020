checkForTree :: String -> Int -> Bool
checkForTree xs index = (xs !! index) == '#'

mapToTree :: [String] -> (Int, Int) -> Int -> [Bool]
mapToTree [] _ _ = []
mapToTree (x : xs) (r, d) n
    | d == 1 = checkForTree x (r * n) : (mapToTree xs (r, d) (n + 1))
    | d == 2 = if odd n
        then False : (mapToTree xs (r, d) (n + 1))
        else checkForTree x (r * n `div` 2) : (mapToTree xs (r, d) (n + 1))



main :: IO ()
main = do
    listOfStrings <- lines <$> readFile "input.txt"
    print $ sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (3, 1) 0
    let a = sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (1, 1) 0
    let b = sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (3, 1) 0
    let c = sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (5, 1) 0
    let d = sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (7, 1) 0
    let e = sum $ map (\x -> if x == True then 1 else 0) $ mapToTree (map cycle listOfStrings) (1, 2) 0
    print (a * b * c * d * e)