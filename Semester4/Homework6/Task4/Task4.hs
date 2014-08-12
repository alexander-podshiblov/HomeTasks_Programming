import Data.Maybe
-- Vertex - (Number, Distance)
-- Edge - (firstVertex, secondVertex, value)
data Graph v e = Graph [(Int,v)] [(Int,Int,e)]

numAndDistance (a,b) = (a, Just b)

first (a, _, _) = a
second (_, b, _) = b
value (_, _, c) = c

findEdge f s [] = Nothing
findEdge f s (edge:list) | (f == first edge && s == second edge) || (s == first edge && f == second edge) = Just edge
                         | otherwise = findEdge f s list

nextVertex (n1, d1) (n2, d2) | d1 < d2 = (n1, d1)
                             | otherwise = (n2, d2)

dijkstra (Graph vList eList) start = map numAndDistance (step [] (map (\(n, _) -> (n, if n == start then 0 else 1/0)) vList))
    where step visited [] = visited
          step visited unvisited = step (nextUnvisited : visited) (map update (filter (/= nextUnvisited) unvisited))
              where nextUnvisited = foldr nextVertex (head unvisited) (tail unvisited)
                    update (n, d) = update2 (findEdge n (fst nextUnvisited) eList)
                        where update2 Nothing = (n, d)
                              update2 (Just edge) | snd nextUnvisited + value edge < d = (n, snd nextUnvisited + value edge)
                                                  | otherwise = (n, d)                              