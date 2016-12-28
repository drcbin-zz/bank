from tkinter import *
root = Tk()
root.title("sabi")
# label = Label(root, bitmap = 'question')
e = StringVar()

# 图像和文本的位置关系
label = Label(root, 
        fg = 'green',
        # bg = 'blue',
        width = 100,
        height = 50,
        bitmap = 'error',
        compound = 'center', #image show on the left, and the text can be display
        # text = e.get()

        ).pack()
label = Label(root, 
        fg = 'green',
        bg = 'blue',
        width = 100,
        height = 50,
        bitmap = 'error',
        compound = 'left', #image show on the left, and the text can be display
        text = 'Hello,World!'
        ).pack()
label = Label(root, 
        fg = 'green',
        # bg = 'blue',
        width = 100,
        height = 50,
        bitmap = 'error',
        compound = 'top', #image show on the left, and the text can be display
        text = 'Hello,World!'
        ).pack()
label = Label(root, 
        fg = 'green',
        bg = 'blue',
        width = 100,
        height = 50,
        bitmap = 'error',
        compound = 'bottom', #image show on the left, and the text can be display
        text = 'Hello,World!'
        ).pack()



# 文本的处理,对其方式,自动换行,文本位置等
text = 'Hello, asdfasjdgkasdkfashdjkfhasfkjhasfkjashdfkasjghasdjfhsakdjghaskdjhgfaskjghasdkgjhaskdjfhaskjdfhaskjdfh'
label = Label(root, 
        fg = 'green',
        bg = 'yellow',
        width = 100,
        height = 50,
        wraplength = 100,
        justify = 'right',  #指定多行对其方式
        anchor = 'nw',   # compound操作图像, justify操作文本,可用参数如下

#                                       nw      n       ne
#
#                                       w       center  e
#
#                                       sw      s       se
#
        bitmap = 'error',
        compound = 'bottom', #image show on the left, and the text can be display
        text = text
        ).pack()


#button

#用于处理button事件的函数
def helloButton():
    print(e.get())
Button(root,
        text = "Button",
        command = helloButton
        ).pack()

Button(root,
        text = "FLAT",
        command = helloButton,
        relief = FLAT,    #设置外观
        ).pack()

Button(root,
        text = "GROOVE",
        command = helloButton,
        relief = GROOVE,    #设置外观
        ).pack()

Button(root,
        text = "RAISRD",
        command = helloButton,
        relief = RIDGE,    #设置外观
        ).pack()


#Entry
Entry(root, text = 'Hello').pack()

#绑定字符串
e.set('Hello,Kitty')
Entry(root, 
        textvariable = e
        ).pack()
l = Label(root,
        bg = 'green',
        )
for i in range(10):
    i = input('请出入:')
    e.set(i)
    # label.text = e.get()
root.mainloop()
