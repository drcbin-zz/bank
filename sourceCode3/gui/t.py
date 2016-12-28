from tkinter import *
root = Tk()
root.title('Bank')

lTop = Label(root,
        width = 100,
        height = 15,
        bg = 'yellow',
        )
lTop.pack()

#window1
w1 = Label(lTop,
        width = 25,
        height = 15,

        bg = 'blue'
        )
w1.pack()
#window2
w2 = Label(lTop,
        width = 25,
        height = 15,
        bg = 'black'
        )
w2.pack()
#window3
w3 = Label(lTop,
        width = 25,
        height = 15,
        bg = 'blue'
        )
w3.pack()
#window4
w4 = Label(lTop,
        width = 25,
        height = 15,
        bg = 'black'
        )
w3.pack()





lBottom = Label(root,
        width = 100,
        height = 20,
        bg = 'green',
        )
lBottom.pack()

root.mainloop()
