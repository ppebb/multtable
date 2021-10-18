# Python.

def main():
	table = MultTable(int(input("Input the number of columns: ")), int(input("Input the number of rows: ")))
	table.print_table()

class MultTable:

	def __init__(self, width: int, height: int):
		self.table_width = width + 1
		self.table_height = height + 1
		# Python has no array class built in, and that requires a 3rd-party library (I don't feel like downloading it) so we are using lists
		self.table = []
		for i in range(1, self.table_width):
			self.table.append([])
			for j in range(1, self.table_height):
				self.table[i - 1].append(i * j)

	def get_required_spaces_for_column(self, column_index: int) -> str:
		"""Returns a string that is the required amount of spaces to properly adjust the printed output numbers on the top line of the table."""
		the_spaces = ""
		longest_num_length = len(str(self.table[column_index][self.table_height - 2]))

		for i in range(0, longest_num_length - len(str(column_index + 1)) + 1):
			the_spaces += " "

		return the_spaces

	def get_required_spaces_for_outer_column(self, this_row_number: int, biggest_row_number: int) -> str:
		"""Returns a string that is the required amount of spaces to properly adjust the row index numbers on the left side of the table."""
		the_spaces = ""
		longest_num_length = len(str(biggest_row_number))

		for i in range(0, longest_num_length - len(str(this_row_number))):
			the_spaces += " "

		return the_spaces

	def get_required_spaces_for_index(self, column_index: int, row_index: int) -> str:
		"""Returns a string that is the required amount of spaces to properly adjust the printed outputted number at the given index."""
		the_spaces = ""
		longest_num_length = len(str(self.table[column_index][self.table_height - 2]))

		for i in range(0, longest_num_length - len(str(self.table[column_index][row_index]))):
			the_spaces += " "

		return the_spaces

	def print_table(self):
		this_line = " " + self.get_required_spaces_for_outer_column(0, self.table_height - 1) + " |"
		for i in range(0, self.table_width - 1):
			this_line += self.get_required_spaces_for_column(i) + str(i + 1)
		print(this_line)

		table_character_length = len(this_line)
		this_line = ""
		for i in range(0, table_character_length):
			this_line += "-"
		print(this_line)

		this_line = ""
		for i in range(0, self.table_height - 1):
			this_line = self.get_required_spaces_for_outer_column(i + 1, self.table_height - 1) + str(i + 1) + " | "
			for j in range(0, self.table_width - 1):
				this_line += self.get_required_spaces_for_index(j, i) + str(self.table[j][i]) + " "
			print(this_line)


# For those who don't know Python, all this does is just run the main method
if __name__ == "__main__":
	main()
