data Exp a = Const a |
             Variable |
             Addition (Exp a) (Exp a) |
             Subtraction (Exp a) (Exp a) |
             Multiplication (Exp a) (Exp a) |
             Division (Exp a) (Exp a) |
             Degree (Exp a) Int

instance Show a => Show (Exp a) where
    show (Const a) = show a
    show (Variable) = "x"
    show (Addition p q) = "(" ++ show p ++ "+" ++ show q ++ ")"
    show (Subtraction p q) = "(" ++ show p ++ "-" ++ show q ++ ")"
    show (Multiplication p q) = "(" ++ show p ++ "*" ++ show q ++ ")"
    show (Division p q) = "(" ++ show p ++ "/" ++ show q ++ ")"
    show (Degree p q) = "(" ++ show p ++ ")^" ++ show q




simp (Addition p (Const 0)) = p
simp (Addition (Const 0) p) = p

simp (Subtraction p (Const 0)) = p
simp (Subtraction (Const 0) p) =  Multiplication (Const (-1)) p

simp (Multiplication p (Const 1)) = p
simp (Multiplication (Const 1) p) = p
simp (Multiplication _ (Const 0)) = Const 0
simp (Multiplication (Const 0) _) = Const 0
simp (Multiplication (Const a) (Const b)) = Const (a * b)

simp (Division p (Const 1)) = p
simp (Division (Const 0) _) = Const 0 

simp (Degree p 1) = p
simp (Degree (Const 0) _) = (Const 0)
simp (Degree _ 0) = (Const 1)
simp (Degree (Const 1) _) = (Const 1)

simp p = p



simpExp (Addition p q) = simp (Addition (simpExp p) (simpExp q))
simpExp (Subtraction p q) = simp (Subtraction (simpExp p) (simpExp q))
simpExp (Multiplication p q) = simp (Multiplication (simpExp p) (simpExp q))
simpExp (Division p q) = simp (Division (simpExp p) (simpExp q))
simpExp (Degree p q) = simp (Degree (simpExp p) q)
simpExp p = p

	
der (Const _) = Const 0
der Variable = Const 1
der (Addition p q) = Addition (der p) (der q)
der (Subtraction p q) = Subtraction (der p) (der q)
der (Multiplication p q) = Addition (Multiplication (der p) q) (Multiplication (der p) q)
der (Division p q) = Division (Subtraction (Multiplication (der p) q) (Multiplication (der q) p)) (Degree q 2)
der (Degree Variable 1) = (Const 1)
der (Degree Variable n) = Multiplication (Const n) (Degree (Variable) (n - 1))
der (Degree p n) = Multiplication ( Const (n - 1) ) ( Multiplication (Degree p (n - 1)) (der p) )


derivative = simpExp.der


