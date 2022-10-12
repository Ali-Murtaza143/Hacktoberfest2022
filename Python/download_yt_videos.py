from tkinter import *
import pytube

app = Tk()
app.geometry("600x400")
app.title("Youtube video downloader")


Label(app, text="Youtube Video Downloader", font='lucida 30 bold', fg='black').pack()

Label(app, text="Enter YT video link here: ",font='lucida 14 bold').place(x=15, y=60)

link = StringVar()

def downloader():
    save_path = 'Enter your Path where you want to download the video'
    url = pytube.YouTube(str(link.get()))
    video = url.streams.get_highest_resolution()
    video.download(save_path)
    Label(app, text="Video Downloaded", font='helvetica 25 bold',fg='red').place(x=150, y=180)

Entry(app, textvariable=link, width=40).place(x=200, y=60)

Button(app,text="Download", font='helvetica 20 bold',relief= RIDGE, borderwidth=5, fg='black', command=downloader).place(x= 180, y= 108)


app.mainloop()
