#!/usr/bin/env python
# coding: utf-8

# In[1]:


import random

##Step 1: Printing out the Tic Tac Toe Game Board
#Prints out the grid using lists

print('---------------------------TIC TAC TOE-----------------------------\n')
print('\t\t\t___|__|___')
print('\t\t\t___|__|___')
print('\t\t\t   |  |   ')
print("Welcome Player; Do you want to be X or O?:\n1.Player1->X\n2.Player2->O\n>>")
print('\t\t\t_7|_8_|_9__')
print('\t\t\t_4|_5_|_6_')
print('\t\t\t 1| 2 | 3 ')

##Step 2: Asks the player if they would like to be player1 'X' or player2 'O'
def player_input():
    marker = ''
    while not (marker == 'X' or marker == 'O'):
        print('Player 1: Do you want to be X or O?')
        marker = input().upper()
    
    if marker == 'X':
        return ['X', 'O']
    else:
        return ['O', 'X']
    
list_Pl1 = []
list_Pl2 = []

list = ['', '', '', '', '', '', '', '', '', '']  #sets the board as 10 empty spaces

##Step 3:
def displayBoard(player, input):     #This function displays the game board with the player's inputs
    
    print('the input is', input)
    ''''''
    print("\t\t\t_", list[7], "_|_", list[8], "_|_", list[9], "_")
    print("\t\t\t_", list[4], "_|_", list[5], "_|_", list[6], "_")
    print("\t\t\t_", list[1], "_|_", list[2], "_|_", list[3], "_")

# here we check if the position entered by user is already taken or not.since we defined it as '' in  beginning
# we only need to check whether the list item is equal to ''  ,if not
# then the position is not free

##Step 6: Checks to see if the space is freely available
def check_input(input_pl):
    if list[input_pl] == '': #checks to see if input is equal to '' which means a blank space
        return True          #returns a boolean either True or False
    else:
        return False

##Step 4: 
#This function checks every possible condition the players could win
def winner(chk):
    return (list[1] == list[2] == list[3] == chk or #checks for a horizontal win on bottom row
            list[4] == list[5] == list[6] == chk or #checks for a horizontal win on middle row
            list[7] == list[8] == list[9] == chk or #checks for a horizontal win on top row
            list[1] == list[4] == list[7] == chk or #checks for a vertical win on the left column
            list[2] == list[5] == list[8] == chk or #checks for a vertical win on the middle column
            list[3] == list[6] == list[9] == chk or #checks for a verrtical win on the right colunm
            list[1] == list[5] == list[9] == chk or #checks for a diagonal win from bottom left to upper right
            list[7] == list[5] == list[3] == chk)   #checks for a diagonal win from bottom right to upper left
player_input()
##Step 10:
#This function is the main function containing the game code
def play():
        # defining a variable list_input so that we can prevent player from
        # entering more than 9 values
    list_input = 1
    # this will be useful when player 2('O') enters the position already
    # occupied
    error_pl2 = 'off'
    while(list_input <= 9):  # loop runs for 9 values from players
        if(list_input % 2 != 0):  # since out list_input starts from 1 so odd(1,3,5,7,9)
                                  #means input from player 1("X") and even means player2("O")
            
               #calls the function from Step 2
            
            ##Step 5:
            def choose_first(players):   #chooses randomly which player will go first
                random_player = 'Player {}'.format(random.randint(1, 2))
                return random_player, players[random_player]
            
            ##Step 8: Asks Player for next position
            print('Player X: Where would you like to place an X?')
            input_Pl1 = int(input(''))  #Stores the input from player 1 in input_Pl1
            if (check_input(input_Pl1)) and (error_pl2 == 'off'):   #Checks to see if position is already filled
                                                                        #Uses the function from Step 6 to see if space is free
                list[input_Pl1] = "X"          #Assigns the player's input to the 'X' character
                displayBoard('X', input_Pl1)   #Displays an X to the space where the player chose on the board

                    # checking for winner. We supply value 'X' and check whether
                    # "x" is winner or not
                    #The following code checks if X is a winner or not
                if(winner('X')):
                    print("X is winner")
                    break
                    # we increase the list_input variable so that we know that
                    # on position has been filled
                list_input += 1 #increments the list_input variable by 1

            else:  # if position is already taken then we continue the loop so again beginning from top
                print('The position is already taken. X\n`')
                continue
        else:
            # this part runs for even value of list_input
            if(list_input != 9):
                print('Player O: Where would you like to place an O?') #Asks player O for next position

                input_Pl2 = int(input(''))  #Checks if space is free
                if check_input(input_Pl2):  

                    list[input_Pl2] = "O"
                    list_Pl2.append(input_Pl2)
                    if(winner("O")):        #Checks if Player O is a winner
                        print("O is winner")
                        break
                    list_input += 1    #increments list_input by 1

                    displayBoard("O", input_Pl2)
                    error_pl2 = 'off'

                else:
                    print(
                        'The position is already taken.\n') #Displays if there is an error in the space
                    # here we assign error_pl2 as on so that for next
                    # iteration we can skip asking input for player 1.
                    error_pl2 = 'on'
    ##Step 9:                 
    repeat = input('do you want to play another game? y for yes and n for no?::') #Asks user if they want to play again
    if(repeat == "y" or repeat == "Y"):    #Loops back to the start if Y is selected
        play() #calls the play function again
play()


# In[ ]:





# In[ ]:





# In[ ]:





# In[ ]:




