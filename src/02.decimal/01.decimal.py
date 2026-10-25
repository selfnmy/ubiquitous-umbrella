from decimal import Decimal, getcontext
from fractions import Fraction
getcontext().prec = 50

a1 = Decimal('0.1')
b1 = Decimal('0.2')
c1 = Decimal('3')
s1 = a1 + b1
d1 = c1 / Decimal('7')
e1 = a1 ** 2

# bad = Decimal(0.1) # float -> decimal
print(a1 + b1 == Decimal('0.3')) # True

# bad: print(a + 0.2) # TypeError
one_third = Decimal(1) / Decimal(3)
print(one_third)

a2 = Fraction(1, 3)
b2 = Fraction('2/5')
c2 = Fraction(0.25)
d2 = Fraction(6, 9)
s2 = a2 + b2 # 11/15
p2 = a2 * b2 # 2/15
q2 = a2 / b2 # 5/6
r2 = a2 ** 2 # 1/9

print(d2.numerator) # 2
print(d2.denominator) # 3

print(a2 == Fraction('1/3')) # True
# bad: Fraction(0.1) != Fraction('1/10') 
# float != Fractions
