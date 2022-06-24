# more 命令

> CRT 文件浏览器

## 格式

```bash
more [options] <file>...
```

## 参数

| 参数          | 作用                                            |
| ------------- | ----------------------------------------------- |
| -d            | display help instead of ringing bell            |
| -f            | count logical rather than screen lines          |
| -l            | suppress pause after form feed                  |
| -c            | do not scroll, display text and clean line ends |
| -p            | do not scroll, clean screen and display text    |
| -s            | squeeze multiple blank lines into one           |
| -u            | suppress underlining                            |
| -<number>     | the number of lines per screenful               |
| +<number>     | display file beginning from line number         |
| +/<string>    | display file beginning from search string match |
| --help        | display this help                               |
| -V, --version | display version                                 |


## 示例

1. 输出长文件内容

```bash
more
```
