use regex::Regex;
use std::io::{self, Read};

fn part1(input: String) {
    let re = Regex::new(r"([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)").unwrap();

    let score = input
        .lines()
        .map(|line| {
            let capture = re.captures(line).unwrap();
            assert!(capture.len() == 5);
            let (x_start, x_end) = (
                capture[1].parse::<i32>().unwrap(),
                capture[2].parse::<i32>().unwrap(),
            );
            let (y_start, y_end) = (
                capture[3].parse::<i32>().unwrap(),
                capture[4].parse::<i32>().unwrap(),
            );
            i32::from(
                (x_start <= y_start && x_end >= y_end) || (y_start <= x_start && y_end >= x_end),
            )
        })
        .sum::<i32>();
    println!("Part 1: {}", score);
}

fn part2(input: String) {
    let re = Regex::new(r"([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)").unwrap();

    let score = input
        .lines()
        .map(|line| {
            let capture = re.captures(line).unwrap();

            let (x_start, x_end) = (
                capture[1].parse::<i32>().unwrap(),
                capture[2].parse::<i32>().unwrap(),
            );
            let (y_start, y_end) = (
                capture[3].parse::<i32>().unwrap(),
                capture[4].parse::<i32>().unwrap(),
            );

            i32::from(
                (y_start >= x_start && y_start <= x_end)
                    || (y_end >= x_start && y_end <= x_end)
                    || (x_start >= y_start && x_start <= y_end)
                    || (x_end >= y_start && x_end <= y_end),
            )
        })
        .sum::<i32>();
    println!("Part 2: {}", score);
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input.clone());
}
