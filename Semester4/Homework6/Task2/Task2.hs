import Data.Function (on)
import Data.List (sortBy)

data Monom a = Monom (a, Int)
    deriving Eq

instance (Show a, Num a, Eq a) => Show (Monom a) where
    show (Monom (0, _)) = "0"
    show (Monom (k, 0)) = show k
    show (Monom (1, 1)) = "x"
    show (Monom (k, 1)) = show k ++ "x"
    show (Monom (1, n)) = "x^" ++ show n
    show (Monom (k, n)) = show k ++ "x^" ++ show n

data Polynom a = Polynom [Monom a]
    deriving Eq

instance (Show a, Num a, Eq a) => Show(Polynom a) where
    show (Polynom []) = "0"
    show (Polynom (p:[])) = show p
    show (Polynom (p:m)) = show p ++ "+" ++ show (Polynom m)

getList (Polynom m) = m
    
simp (Polynom []) = Polynom []
simp (Polynom (Monom p : [])) | fst p == 0 = Polynom []
                              | otherwise = Polynom [Monom p]
simp (Polynom (Monom p : m)) | fst p == 0 = simp (Polynom m)
                             | otherwise = Polynom ((Monom p) : getList(simp(Polynom m)))

powerOfM (Monom p) = snd p
coefOfM (Monom p) = fst p

simp2 (Polynom []) = Polynom []
simp2 (Polynom (p:[])) = Polynom [p]
simp2 (Polynom ((Monom p) : (Monom q) : m)) | snd p == snd q = simp2 $ Polynom (Monom (fst p + fst q, snd p) : m)
                                            | otherwise = Polynom $ Monom p : getList ( simp2 $ Polynom (Monom q : m))
                                                
sortP (Polynom m) = Polynom $ sortBy (compare `on` powerOfM) (m)

simplifyP :: (Num a, Eq a) => Polynom a -> Polynom a
simplifyP a = simp2 (sortP (simp a))

sumP (Polynom p) (Polynom q) = simplifyP (Polynom (p ++ q))

multP (Polynom p) (Polynom q) = simplifyP (Polynom [Monom ((coefOfM mp) * (coefOfM mq), (powerOfM mp) + (powerOfM mq)) | mp <- p, mq <- q])