# lucky_numbers = [4,8,15,16,23,42]
friends = ["Atul" , "Akash" , "Mummy" , "Papa" , "Atul" , "Atul"]


# friends.extend(lucky_numbers)
friends.append("Creed")
friends.insert(2,"Done")
friends.remove("Creed")
friends.pop()
# friends.clear()
friends.sort()

print(friends.index("Atul"))
print(friends.count("Atul"))

friends.reverse()

friends2 = friends.copy()

print(friends2)