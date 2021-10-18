using System;
using System.Text;

namespace multtable {
	class Program {
		static void Main(string[] args) {
			Console.Write("Input the number of columns: ");
			int columns = int.Parse(Console.ReadLine());

			Console.Write("Input the number of rows: ");
			int rows = int.Parse(Console.ReadLine());

			int length = (columns * rows).ToString().Length + 1;
			StringBuilder sb = new();

			AppendCharRepeatedly(sb, rows.ToString().Length + 1, ' ');
			sb.Append(" |");

			for (int i = 0; i < columns; i++) {
				AppendCharRepeatedly(sb, length - (i + 1).ToString().Length, ' ');
				sb.Append(i + 1);
			}
			sb.AppendLine();

			int sbLength = sb.Length;

			AppendCharRepeatedly(sb, sb.Length, '-');
			sb.AppendLine();

			for (int i = 0; i < rows; i++) {
				AppendCharRepeatedly(sb, rows.ToString().Length + 1 - (i + 1).ToString().Length, ' ');
				sb.Append(i + 1);
				sb.Append(" |");

				for (int j = 0; j < columns; j++) {
					int currentNumber = ((i + 1) * (j + 1));
					AppendCharRepeatedly(sb, length - currentNumber.ToString().Length, ' ');
					sb.Append(currentNumber);
				}
				if (i + 1 != rows)
					sb.AppendLine();
			}

			Console.WriteLine(sb.ToString());
		}

		static void AppendCharRepeatedly(StringBuilder sb, int limiter, char c) {
			for (int i = 0; i < limiter; i++)
				sb.Append(c);
		}
	}
}
