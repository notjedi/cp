use std::io::{self, Read};

const TAB: u32 = 2;
const HYPHEN_WIDTH: usize = 2;

#[derive(Debug, Clone)]
enum LineType {
    Command(Command),
    Entry(Entry),
}

#[derive(Debug, Clone)]
enum Command {
    Cd(String),
    Ls,
}

#[derive(Debug, Clone)]
enum Entry {
    Dir(String),
    File(String, usize),
}

#[derive(Debug, Clone)]
struct FsEntry {
    path: String,
    size: usize,
    children: Vec<FsEntry>,
}

impl FsEntry {
    fn new(path: String, size: usize) -> Self {
        Self {
            path,
            size,
            children: vec![],
        }
    }

    fn is_dir(&self) -> bool {
        !self.children.is_empty()
    }

    fn get_dirs(&self) -> Vec<FsEntry> {
        let mut dirs: Vec<FsEntry> = vec![self.clone()];
        dirs.append(
            &mut (self
                .children
                .clone()
                .into_iter()
                .filter(|dir| dir.is_dir())
                .flat_map(|dir| dir.get_dirs())
                .collect::<Vec<FsEntry>>()),
        );
        dirs
    }

    fn size(&self) -> usize {
        self.size
            + self
                .children
                .iter()
                .map(|child| child.size())
                .sum::<usize>()
    }

    fn pretty_print(&self, level: u32) {
        println!(
            "{:>spaces$} (dir)",
            format!("- {}", self.path),
            spaces = (level * TAB) as usize + self.path.len() + HYPHEN_WIDTH
        );
        let tab_length = ((level + 1) * TAB) as usize;

        for child in self.children.as_slice() {
            if child.is_dir() {
                child.pretty_print(level + 1);
            } else {
                println!(
                    "{:>spaces$} (file, {size})",
                    format!("- {}", child.path),
                    spaces = tab_length + child.path.len() + HYPHEN_WIDTH,
                    size = child.size,
                );
            }
        }
    }
}

impl Default for FsEntry {
    fn default() -> Self {
        Self {
            path: "".into(),
            size: 0,
            children: Vec::new(),
        }
    }
}

fn parse(input: String) -> Vec<LineType> {
    return input
        .trim()
        .lines()
        .map(|line| {
            let words = line.split(' ').collect::<Vec<&str>>();
            let line_type: LineType = match (words[0], words[1]) {
                ("$", "cd") => LineType::Command(Command::Cd(words[2].to_string())),
                ("$", "ls") => LineType::Command(Command::Ls),
                ("dir", name) => LineType::Entry(Entry::Dir(name.to_string())),
                (size, name) => LineType::Entry(Entry::File(
                    name.to_string(),
                    size.parse::<usize>().unwrap(),
                )),
            };
            line_type
        })
        .collect::<Vec<_>>();
}

fn build_index(entries: Vec<LineType>) -> FsEntry {
    let mut stack: Vec<FsEntry> = vec![];
    // input guarantees that this will always be replaced by the root dir at the `/` match arm
    let mut node = FsEntry::default();

    for line_type in entries {
        match line_type {
            LineType::Command(cmd) => match cmd {
                Command::Ls => continue,
                Command::Cd(path) => match path.as_str() {
                    "/" => {
                        node = FsEntry::new(path, 0);
                    }
                    ".." => {
                        let child_dir = node;
                        node = stack.pop().unwrap();
                        node.children.push(child_dir);
                    }
                    _ => {
                        stack.push(node);
                        node = FsEntry::new(path, 0);
                    }
                },
            },
            LineType::Entry(entry) => match entry {
                Entry::File(path, size) => node.children.push(FsEntry::new(path, size)),
                Entry::Dir(_) => continue,
            },
        }
    }

    while let Some(mut parent) = stack.pop() {
        parent.children.push(node);
        node = parent;
    }
    node
}

fn part1(root: FsEntry) {
    let total_size = root
        .get_dirs()
        .iter()
        .map(|dir| dir.size())
        .filter(|size| *size < 100000)
        .sum::<usize>();

    println!("Part 1: {}", total_size);
}

fn part2(root: FsEntry) {
    const MIN_NEEDED: usize = 30000000;
    const TOTAL_SPACE: usize = 70000000;
    let total_used = root.size();
    let unused_space = TOTAL_SPACE - total_used;
    let need_to_free = MIN_NEEDED - unused_space;
    assert!(
        MIN_NEEDED > unused_space,
        "Invalid input, we already have enough space"
    );

    let mut candidates = root
        .get_dirs()
        .iter()
        .map(|dir| dir.size())
        .filter(|size| *size > need_to_free)
        .collect::<Vec<usize>>();
    candidates.sort();

    println!("Part 2: {}", candidates.first().unwrap());
}

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let entries = parse(input);
    let root = build_index(entries);

    root.pretty_print(0);
    part1(root.clone());
    part2(root);
}
