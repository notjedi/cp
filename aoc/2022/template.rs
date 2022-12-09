use std::io::{self, Read};

fn part1(input: String) {}
fn part2(input: String) {}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input);
}
