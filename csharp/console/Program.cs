using System;
using System.Text;

namespace multtable 
{
	public static class Program 
    {
		public static void Main() {
			Console.Write("Input the number of columns:");
            if (!int.TryParse(Console.ReadLine() ?? "5", out int columns))
                columns = 5;

			Console.Write("Input the number of rows:");
            if (!int.TryParse(Console.ReadLine() ?? "5", out int rows))
                rows = 5;

			int length = (columns * rows).ToString().Length + 1;
			StringBuilder sb = new StringBuilder();

			sb.Append(' ', rows.ToString().Length + 1);
			sb.Append(" |");

			for (int i = 0; i < columns; i++) {
                sb.Append(' ', length - (i + 1).ToString().Length);
				sb.Append(i + 1);
			}

			sb.AppendLine();

            sb.Append('-', sb.Length);
			sb.AppendLine();

			for (int i = 0; i < rows; i++) {
                sb.Append(' ', rows.ToString().Length + 1 - (i + 1).ToString().Length);
				sb.Append(i + 1);
				sb.Append(" |");

				for (int j = 0; j < columns; j++) {
					int currentNumber = (i + 1) * (j + 1);

                    sb.Append(' ', length - currentNumber.ToString().Length);
					sb.Append(currentNumber);
				}

				if (i + 1 != rows)
					sb.AppendLine();
			}

			Console.WriteLine(sb.ToString());
		}
    }
}
