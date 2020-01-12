# cut 命令

> 按行比较多个文本文件的内容差异

## 格式

```bash
diff [OPTION]... FILES
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| --normal | output a normal diff (the default) |
| -q, --brief | report only when files differ |
| -s, --report-identical-files | report when two files are the same |
| -c, -C NUM, --context[=NUM] | output NUM (default 3) lines of copied context |
| -u, -U NUM, --unified[=NUM] | output NUM (default 3) lines of unified context |
| -e, --ed | output an ed script |
| -n, --rcs | output an RCS format diff |
| -y, --side-by-side | output in two columns |
| -W, --width=NUM | output at most NUM (default 130) print columns |
| --left-column | output only the left column of common lines |
| --suppress-common-lines | do not output common lines |
| -p, --show-c-function | show which C function each change is in |
| -F, --show-function-line=RE | show the most recent line matching RE |
| --label LABEL | use LABEL instead of file name and timestamp (can be repeated) |
| -t, --expand-tabs | expand tabs to spaces in output |
| -T, --initial-tab | make tabs line up by prepending a tab |
| --tabsize=NUM | tab stops every NUM (default 8) print columns |
| --suppress-blank-empty | suppress space or tab before empty output lines |
| -l, --paginate | pass output through 'pr' to paginate it |
| -r, --recursive | recursively compare any subdirectories found |
| --no-dereference | don't follow symbolic links |
| -N, --new-file | treat absent files as empty |
| --unidirectional-new-file | treat absent first files as empty |
| --ignore-file-name-case | ignore case when comparing file names |
| --no-ignore-file-name-case | consider case when comparing file names |
| -x, --exclude=PAT | exclude files that match PAT |
| -X, --exclude-from=FILE | exclude files that match any pattern in FILE |
| -S, --starting-file=FILE | start with FILE when comparing directories |
| --from-file=FILE1 | compare FILE1 to all operands; FILE1 can be a directory |
| --to-file=FILE2 | compare all operands to FILE2; FILE2 can be a directory |
| -i, --ignore-case | ignore case differences in file contents |
| -E, --ignore-tab-expansion | ignore changes due to tab expansion |
| -Z, --ignore-trailing-space | ignore white space at line end |
| -b, --ignore-space-change | ignore changes in the amount of white space |
| -w, --ignore-all-space | ignore all white space |
| -B, --ignore-blank-lines | ignore changes where lines are all blank |
| -I, --ignore-matching-lines=RE | ignore changes where all lines match RE |
| -a, --text | treat all files as text |
| --strip-trailing-cr | strip trailing carriage return on input |
| -D, --ifdef=NAME | output merged file with '#ifdef NAME' diffs |
| --GTYPE-group-format=GFMT | format GTYPE input groups with GFMT |
| --line-format=LFMT | format all input lines with LFMT |
| --LTYPE-line-format=LFMT | format LTYPE input lines with LFMT |
| -d, --minimal | try hard to find a smaller set of changes |
| --horizon-lines=NUM | keep NUM lines of the common prefix and suffix |
| --speed-large-files | assume large files and many scattered small changes |
| --color[=WHEN] | colorize the output; WHEN can be 'never', 'always', or 'auto' (the default) |
| --palette=PALETTE | the colors to use when --color is active; PALETTE is a colon-separated list of terminfo capabilities |
| --help | display this help and exit |
| -v, --version | output version information and exit |

### 格式化输出

针对 `--GTYPE-group-format`, `--line-format`, `--LTYPE-line-format` 三个参数的格式化输出。

- LTYPE is 'old', 'new', or 'unchanged'.  
- GTYPE is LTYPE or 'changed'. 

GFMT (only) may contain:

`%<`  lines from FILE1
`%>`  lines from FILE2
`%=`  lines common to FILE1 and FILE2
`%(A=B?T:E)`  if A equals B then T else E
`%[-][WIDTH][.[PREC]]{doxX}LETTER`  printf-style spec for LETTER

LETTERs are as follows for new group, lower case for old group:

`F`  first line number
`L`  last line number
`N`  number of lines = L-F+1
`E`  F-1
`M`  L+1

LFMT (only) may contain:
`%L`  contents of line
`%l`  contents of line, excluding any trailing newline
`%[-][WIDTH][.[PREC]]{doxX}n`  printf-style spec for input line number

Both GFMT and LFMT may contain:
`%%`  %
`%c'C'`  the single character C
`%c'\OOO'`  the character with octal code OOO
`C`    the character C (other characters represent themselves)

## 示例

1. 比较文件内容是否一致

```bash
$ diff -q c.txt b.txt
```

2. 详细输出文件内容差异部分

```bash
$ diff -c c.txt b.txt
```
