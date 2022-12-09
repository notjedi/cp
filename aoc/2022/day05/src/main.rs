use std::io::{self, Read};

#[derive(Debug, Clone)]
struct ParsedInput {
    crates: Vec<Vec<char>>,
    instructions: Vec<(i32, usize, usize)>,
}

fn transpose(v: Vec<Vec<char>>) -> Vec<Vec<char>> {
    assert!(!v.is_empty());
    let len = v[0].len();
    let mut iters: Vec<_> = v.into_iter().map(|n| n.into_iter()).collect();
    (0..len)
        .map(|_| {
            iters
                .iter_mut()
                .map(|n| n.next().unwrap())
                .collect::<Vec<char>>()
        })
        .collect()
}

fn parse(input: String) -> ParsedInput {
    let mut found = false;
    let mut instructions = vec![];
    let mut crates = vec![];

    for line in input.lines() {
        if line.is_empty() {
            found = true;
            continue;
        } else if line.chars().nth(1).unwrap() == '1' {
            continue;
        }

        if found {
            instructions.push(String::from(line));
        } else {
            let crate_item = line
                .as_bytes()
                .chunks(4)
                .map(|chunk| chunk[1] as char)
                .collect::<Vec<char>>();
            crates.push(crate_item);
        }
    }

    // clean up crate items
    let mut crates = transpose(crates);
    for crate_item in crates.iter_mut() {
        crate_item.reverse();
    }
    let crates = crates
        .into_iter()
        .map(|crate_item| {
            crate_item
                .into_iter()
                .filter(|item| !item.is_whitespace())
                // .filter(|item| matches!(item, 'A'..='Z')) // another way to filter whitespaces
                .collect::<Vec<char>>()
        })
        .collect::<Vec<Vec<char>>>();

    // parse instructions to numbers
    let instructions = instructions
        .into_iter()
        .map(|instruction| {
            let mut chunks = instruction
                .split(' ')
                .filter_map(|ins| match ins.parse::<i32>() {
                    Ok(x) => Some(x),
                    Err(_) => None,
                });
            let qty = chunks.next().unwrap();
            let from = chunks.next().unwrap() as usize - 1;
            let to = chunks.next().unwrap() as usize - 1;
            (qty, from, to)
        })
        .collect::<Vec<(i32, usize, usize)>>();

    ParsedInput {
        crates,
        instructions,
    }
}

fn part1(parsed_input: ParsedInput) {
    let (mut crates, instructions) = (parsed_input.crates, parsed_input.instructions);

    instructions.into_iter().for_each(|(qty, from, to)| {
        for _ in 0..qty {
            let item = crates[from].pop().unwrap();
            crates[to].push(item);
        }
    });

    let answer = crates
        .into_iter()
        .map(|crate_item| *crate_item.last().unwrap())
        .collect::<String>();
    println!("Part 1: {}", answer);
}

fn part2(parsed_input: ParsedInput) {
    let (mut crates, instructions) = (parsed_input.crates, parsed_input.instructions);

    instructions.into_iter().for_each(|(qty, from, to)| {
        let mut move_items = (0..qty)
            .map(|_| crates[from].pop().unwrap())
            .collect::<Vec<char>>();
        move_items.reverse();

        crates[to].append(&mut move_items);
    });

    let answer = crates
        .into_iter()
        .map(|crate_item| *crate_item.last().unwrap())
        .collect::<String>();
    println!("Part 2: {}", answer);
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let parsed_input = parse(input);

    part1(parsed_input.clone());
    part2(parsed_input);
}
