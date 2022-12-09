use std::collections::HashSet;
use std::collections::VecDeque;
use std::fmt;
use std::io::{self, Read};

#[derive(Debug, Clone)]
struct InvalidInputError;

impl fmt::Display for InvalidInputError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "invalid input")
    }
}

fn solve(input: String, marker_length: usize) -> Result<usize, InvalidInputError> {
    let input = format!("{} ", input.trim());
    let mut chars = input.chars();
    let mut deque: VecDeque<char> = VecDeque::with_capacity(marker_length);

    (0..marker_length).for_each(|_| {
        deque.push_back(chars.next().unwrap());
    });

    for (i, ch) in chars.enumerate() {
        let mut unique = HashSet::new();
        deque.iter().for_each(|item| {
            unique.insert(item);
        });
        if unique.len() == marker_length {
            return Ok(i + marker_length);
        }
        deque.push_back(ch);
        deque.pop_front();
    }
    Err(InvalidInputError)
}

fn part1(input: String) {
    let position = solve(input, 4);
    match position {
        Ok(val) => println!("Part 1: {}", val),
        Err(why) => println!("{}", why),
    }
}

fn part2(input: String) {
    let position = solve(input, 14);
    match position {
        Ok(val) => println!("Part 1: {}", val),
        Err(why) => println!("{}", why),
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input);
}
