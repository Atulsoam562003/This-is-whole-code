
employee_file = open("employees.txt" , "r");

# print(employee_file.readable())
# print(employee_file.read())
# print(employee_file.readline())
# print(employee_file.readline())

# for employee in employee_file :
#     print(employee)
# temp = employee_file.readlines()
# for i in range(len(temp)) :
#     print(employee_file.readlines()[i])

print(employee_file.readlines()[2])

employee_file.close()