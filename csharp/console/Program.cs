using System;

namespace multtable {
	public static class Program {
		public static void Main() {
			Console.Write("Input the number of columns: ");

			if (!int.TryParse(Console.ReadLine() ?? "5", out int columns))
				columns = 5;

			Console.Write("Input the number of rows: ");
			if (!int.TryParse(Console.ReadLine() ?? "5", out int rows))
				rows = 5;

			Console.WriteLine(multtable.MultTable(columns, rows));
		}
	}
}