import random

def read_stirng(prompt): # Same like c++ to the read string , reads the string prompt and returns it
    return input(prompt)

def read_integer(prompt): #Like c++ read integer, read the string prompt and returns
  line =read_stirng(prompt)
  while not line.isdigit():
     print("Please enter a whole number") # if the input is not an integer, then the program will ask the user to enter an integer
     line = read_stirng(prompt)
  return int(line)
def test_name():
      name = read_stirng("What is your name: ") #ask your name

      if name == "yi": #if user input yi, then print welcome back yi
        print("Welcome back yi...")
      
      #same like else 
      elif name == "zhao":
        print("Hi zhao") #if user input zhao, then print I've been waitting for you
      
      elif name == "yizheng":
        print("I've been waiting for you...")
      
      elif name not in ['yi', 'zhao', 'yi']: #if user input name was not recording, then print who are you
        print("who are you?... ")

def playing_guessing_number():
      guess_number = read_integer("Guess a number valued between 1 and 100: ")
      target = random.randrange(1, 100)

      # exit loop if guess_number == target
      while guess_number != target:
        if guess_number > target: # if guess_number great than targer, then show "try again"
          print("less than", guess_number)
          guess_number = read_integer("Try again: ")

        elif guess_number < target:    # if guess_number less than targer, then show "try again"
          print("Greater than", guess_number)
          guess_number = read_integer("Try again ")

      # loop exited so that means guess_number == target
      print("Wow, you got it", target)
      print("My target is ", target)
      

def main():
  name =read_stirng("Enter name: ") #Like c++ ask user to enter name as read_string
  age = read_integer("Enter your age: ") #Like c++ ask user to enter age as read_integer

  print("Hello", name) #output the name and age
  print("You are", age)

  menu = """ 
  1. Play Guessing Game
  2. Play Test Name
  3. Exit
  """
  # initialize choice
  choice = None

  # Set the Loop
  while choice != 3:
    # display the menu
    print(menu)

    # ask user choice
    choice = read_integer("Please select an option: ")

    # check user choice

    # number game
    if choice == 1:
      playing_guessing_number()

    # test name
    elif choice == 2:
       test_name()

if __name__ == '__main__':
  main()









