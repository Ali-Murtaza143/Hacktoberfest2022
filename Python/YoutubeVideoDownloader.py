# pip install pytube
# pip install tk

from pytube import YouTube
import tkinter as tk
 
root = tk.Tk()
root.geometry('500x300')
root.resizable(0,0)
root.title("TheEngineerGuyy's YouDownloader")

tk.Label(root, text ='Youtube Video Downloader', font ='arial 20 bold').pack()

# enter link
link = tk.StringVar()
 
tk.Label(root, text ='Paste Link Here:', font ='arial 15 bold').place(x= 160, y = 60)
link_enter = tk.Entry(root, width = 70, textvariable = link).place(x = 32, y = 90)
 
#function to download video
 
def Downloader(): 
    url =YouTube(str(link.get()))
    video = url.streams.first()
    video.download()  # The video gets downloaded in the directory where your python files are present
    tk.Label(root, text ='DOWNLOADED', font ='arial 15').place(x= 180, y = 210)
 
 
tk.Button(root, text ='DOWNLOAD', font ='arial 15 bold', bg ='blue', padx = 2, command = Downloader).place(x=180, y = 150)
 
root.mainloop()
 