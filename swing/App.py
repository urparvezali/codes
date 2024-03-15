import tkinter as tk
import tkinter.messagebox as messagebox

class App(tk.Tk):
	def __init__(self):
		super().__init__()
		self.title("Student Information App")
		self.geometry("800x400")

		self.name_label = tk.Label(self, text="    Name")
		self.roll_label = tk.Label(self, text="    Roll Number")
		self.marks_label = tk.Label(self, text="   Marks")

		self.name_field = tk.Entry(self)
		self.roll_field = tk.Entry(self)
		self.marks_field = tk.Entry(self)

		self.name_label.grid(row=0, column=0)
		self.name_field.grid(row=0, column=1)
		self.roll_label.grid(row=1, column=0)
		self.roll_field.grid(row=1, column=1)
		self.marks_label.grid(row=2, column=0)
		self.marks_field.grid(row=2, column=1)

		self.submit_button = tk.Button(self, text="Submit", command=self.submit)
		self.exit_button = tk.Button(self, text="Exit", command=self.quit)

		self.submit_button.grid(row=3, column=0)
		self.exit_button.grid(row=3, column=1)

	def submit(self):
		name = self.name_field.get()
		roll = self.roll_field.get()
		marks = self.marks_field.get()

		try:
			with open("student_info.txt", "a") as file:
				file.write("Name: " + name + "\n")
				file.write("Roll Number: " + roll + "\n")
				file.write("Marks: " + marks + "\n")
				file.write("\n")  # Add an empty line to separate entries
			messagebox.showinfo("Success", "Student information saved to file.")
		except IOError:
			messagebox.showerror("Error", "Failed to save student information to file.")

if __name__ == "__main__":
	app = App()
	app.mainloop()
