import tkinter as tk
from chatbot import process
def chat():
    chat_log.tag_config("user",justify="right",foreground="green")
    chat_log.tag_config("bot",justify="left",foreground="blue")
    usr_input=user_input.get()
    if(usr_input.strip()==""):
        return
    chat_log.config(state=tk.NORMAL)
    chat_log.insert(tk.END,"You >> "+usr_input+" \n ","user")
    if(usr_input.lower() in ["bye","exit","quit"]):
        chat_log.insert(tk.END,"Bot >> "+"Thanks for visiting us!Goodbye!","bot")
        root.after(2000,root.destroy)
        return
    response=process(usr_input.lower())
    chat_log.insert(tk.END,"Bot >> "+response+" \n ","bot")
    user_input.delete(0,tk.END)
    chat_log.config(state=tk.DISABLED)
root=tk.Tk()
root.title("Restaurant chatbot")
root.geometry("400x500")
chat_log=tk.Text(root)
chat_log.config(state=tk.DISABLED)
chat_log.pack(pady=5)
user_input=tk.Entry(root)
user_input.pack(pady=5)
send_button=tk.Button(root,text="Send",command=chat)
send_button.pack(pady=5)
root.mainloop()
