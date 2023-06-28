// Multtable
// A collection of multiplication table generators written in various languages

pub(crate) use std::io::{self, Write};

pub struct Table {
    columns: usize,
    rows: usize,
}

/// Traits for the `Table` struct
impl Table {
    /// Prints the whole `table`
    fn print(&self) {
        self.header();
        for i in 1..(self.rows + 1) {
            self.row(i);
        }
    }

    /// Spacing of each column
    fn max_space_columns(&self) -> usize {
        get_num_len(self.columns * self.rows) + 2
    }

    /// Spacing of the factor column
    fn max_space_rows(&self) -> usize {
        get_num_len(self.rows) + 1
    }

    /// Prints the whole `header`
    fn header(&self) {
        // Get the combined_length of the header to print the dashes at the bottom
        let combined_length = {
            let empty_cell = self.max_space_rows();
            let columns = self.max_space_columns() * self.columns;
            columns + empty_cell + 3 // Extra 3 is to account for padding
        };

        // Print the top left empty corner
        print!("{}|", " ".repeat(self.max_space_rows() + 1));

        // Print the header numbers
        for i in 1..(self.columns + 1) {
            let number_length = get_num_len(i);
            print!(
                "{0}{1}",
                " ".repeat(self.max_space_columns() - number_length),
                i
            )
        }

        // Print the dashes at the bottom
        print!("\n{}", "-".repeat(combined_length));

        let _ = io::stdout().flush(); // Terminals are weird
    }

    /// Prints a row
    fn row(&self, row_number: usize) {
        // Print the row of the factor column
        print!(
            "\n{0}{1} |",
            " ".repeat(self.max_space_rows() - get_num_len(row_number)),
            row_number
        );

        // Print the products
        for i in 1..(self.columns + 1) {
            let product = i * row_number;
            print!(
                "{0}{1}",
                " ".repeat(self.max_space_columns() - get_num_len(product)),
                product
            );
        }
    }
}

/// Get the length of a number
fn get_num_len(number: usize) -> usize {
    number.to_string().len()
}

/// Get user's input as a number from a text prompt using `message`
fn get_input_number(message: &str) -> usize {
    print!("{message}");
    let _ = io::stdout().flush(); // Terminals are weird
    let mut input = String::new();
    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");
    input.trim().parse().expect("Input is not a number")
}

fn main() {
    let table = Table {
        columns: get_input_number("Input the number of columns: "),
        rows: get_input_number("Input the number of rows: "),
    };
    table.print();
}
