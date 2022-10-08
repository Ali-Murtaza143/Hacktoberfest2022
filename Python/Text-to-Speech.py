################## import libraries ##############

from tkinter import *
from gtts import gTTS
import os


################### Initialized window####################

root = Tk()

root.geometry('400x350')

#root.resizable(0, 0)

root.config(bg='ghost white')

root.title('TEXT TO SPEECH')


#############   heading #################

Label(root , text='TEXT TO SPEECH',
      font='arial 20 bold underline ', bg='white smoke').pack()

Label(root , text='made by Ankit', font='arial 10 bold',
      bg='white smoke').pack(side=BOTTOM)


############### label #################
Label(root , text='Enter Text', font='arial 15 bold',
      bg='white smoke').place(x=40, y=100)




################## text variable ############

Msg = StringVar()

# Entry

entry_field = Entry(root, textvariable=Msg, width='50')

entry_field.place(x=40, y=140)


################### define function ##############################

def Text_to_speech():
    
    Message = entry_field.get()
    
    speech = gTTS(text=Message)
    
    speech.save('ankit.mp3')
    
    os.system('ankit.mp3')
    
    

def Exit():
    
    root.destroy()


def Reset():
    
    Msg.set("")
    


 ############### Button ###############

Button(root , text="PLAY", font='arial 15 bold',
       command=Text_to_speech, width=4).place(x=45, y=240)

Button(root , text='EXIT', font='arial 15 bold',
       command=Exit, bg='OrangeRed1').place(x=120, y=240)

Button(root , text='RESET', font='arial 15 bold',
       command=Reset).place(x=195, y=240)


# infinite loop to run program

root.mainloop()
