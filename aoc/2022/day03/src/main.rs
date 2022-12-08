use std::collections::HashSet;
use std::io::{self, Read};
use std::iter::FromIterator;

fn part1(input: String) {
    let score = input
        .lines()
        .map(|line| {
            let half = line.len() / 2;
            let (comp_1, comp_2) = line.split_at(half);
            let comp_1_hash: HashSet<char> = HashSet::from_iter(comp_1.chars());
            let comp_2_hash: HashSet<char> = HashSet::from_iter(comp_2.chars());

            let common_char = *comp_1_hash.intersection(&comp_2_hash).next().unwrap();

            if common_char.is_uppercase() {
                common_char as i32 - 'A' as i32 + 1 + 26
            } else if common_char.is_lowercase() {
                common_char as i32 - 'a' as i32 + 1
            } else {
                0
            }
        })
        .sum::<i32>();
    println!("Part 1: {}", score);
}

fn part2(input: String) {
    let lines = input.lines().map(String::from).collect::<Vec<String>>();
    let mut score = 0;

    for chunks in lines.chunks(3) {
        let mut sacks: Vec<HashSet<char>> = chunks
            .iter()
            .map(|chunk| chunk.chars().collect::<HashSet<_>>())
            .collect();

        let mut sack = sacks.pop().unwrap();
        for other in sacks {
            sack = sack.intersection(&other).copied().collect();
        }

        let common_char = *sack.iter().next().unwrap();
        if common_char.is_uppercase() {
            score += common_char as i32 - 'A' as i32 + 1 + 26;
        } else if common_char.is_lowercase() {
            score += common_char as i32 - 'a' as i32 + 1;
        }
    }
    println!("Part 2: {}", score);
}

fn main() {
    // https://github.com/rust-lang/rfcs/issues/2023
    //  consider using a `let` binding to create a longer lived value
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    part1(input.clone());
    part2(input.clone());
}
