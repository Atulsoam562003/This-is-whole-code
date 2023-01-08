#  a means appending the file without deleting the previous data
employee_file = open("employees1.txt" ,"w")

# employee_file.write("Toby - Human Resources")
employee_file.write("\nKelly - Customer Service")

employee_file.close()
