def say_hi(name ,age) :
    print("Hello",name , "you are " , age)

say_hi("Atul",19)

def power(first,second ) :
    return pow(first,second)

print(power(3,2))

is_male = True
is_tall = False

if is_male and is_tall:
    print("You are male")
elif is_male and not(is_tall) :
    print("You are male but small one")
else :
    print("you are neither male nor female")
