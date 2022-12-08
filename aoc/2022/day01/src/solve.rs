use std::io::{self, Read};

fn part1(input: String) {
    let score = input
        .split("\n\n")
        .map(|part| {
            part.lines()
                .fold(0, |acc, cal| acc + cal.parse::<i32>().unwrap())
        })
        .max()
        .unwrap();
    println!("Part 1: {}", score);
}

fn part2(input: String) {
    let mut sums = input
        .split("\n\n")
        .map(|part| {
            part.lines()
                .fold(0, |acc, cal| acc + cal.parse::<i32>().unwrap())
        })
        .collect::<Vec<i32>>();

    sums.sort_by(|a, b| b.cmp(a));
    let (score, _) = sums.split_at(3);
    println!("Part 2: {}", score.iter().sum::<i32>());
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input.clone());
}
