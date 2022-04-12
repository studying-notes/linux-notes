# date 命令

> 打印或者设置系统日期和时间

## 格式

```bash
date [OPTION]... [+FORMAT]
date [-u|--utc|--universal] [MMDDhhmm[[CC]YY][.ss]]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -d, --date=STRING | display time described by STRING, not 'now' |
| -f, --file=DATEFILE | like --date once for each line of DATEFILE |
| -r, --reference=FILE | display the last modification time of FILE |
| 2-R, --rfc-2822334 | output date and time in RFC 2822 format. Example: Mon, 07 Aug 2006 12:34:56 -0600 |
| --rfc-3339=TIMESPEC | output date and time in RFC 3339 format. TIMESPEC='date', 'seconds', or 'ns' for date and time to the indicated precision. Date and time components are separated by a single space: 2006-08-07 12:34:56-06:00 |
| -s, --set=STRING | set time described by STRING |
| -u, --utc, --universal | print or set Coordinated Universal Time |
| --help | display this help and exit |
| --version | output version information and exit |

### 备注

- `--date=STRING` 可以是自由格式的可读性良好的日期字符串，比如 `Sun, 29 Feb 2004 16:21:42 -0800`、`2004-02-29 16:21:42`、`next Thursday`。一个日期字符串可能包含年月日、时分秒、时区、星期、相对日期等。空字符串表示一天的开始。
- `export TZ=[INT]` 可以设置时区环境变量，未设置情况下从 `/etc/localtime` 中获取。

```bash
$ export TZ=0
$ date
Wed Jan  8 06:00:14  2020
```

## 格式化输出

| 占位符 | 含义 |
| --------- | --------- |
| %% | a literal % |
| %a | locale's abbreviated weekday name (e.g., Sun) |
| %A | locale's full weekday name (e.g., Sunday) |
| %b | locale's abbreviated month name (e.g., Jan) |
| %B | locale's full month name (e.g., January) |
| %c | locale's date and time (e.g., Thu Mar 3 23:05:25 2005) |
| %C | century; like %Y, except omit last two digits (e.g., 20) |
| %d | day of month (e.g, 01) |
| %D | date; same as %m/%d/%y |
| %e | day of month, space padded; same as %_d |
| %F | full date; same as %Y-%m-%d |
| %g | last two digits of year of ISO week number (see %G) |
| %G | year of ISO week number (see %V); normally useful only with %V |
| %h | same as %b |
| %H | hour (00..23) |
| %I | hour (01..12) |
| %j | day of year (001..366) |
| %k | hour ( 0..23) |
| %l | hour ( 1..12) |
| %m | month (01..12) |
| %M | minute (00..59) |
| %n | a newline |
| %N | nanoseconds (000000000..999999999) |
| %p | locale's equivalent of either AM or PM; blank if not known |
| %P | like %p, but lower case |
| %r | locale's 12-hour clock time (e.g., 11:11:04 PM) |
| %R | 24-hour hour and minute; same as %H:%M |
| %s | seconds since 1970-01-01 00:00:00 UTC |
| %S | second (00..60) |
| %t | a tab |
| %T | time; same as %H:%M:%S |
| %u | day of week (1..7); 1 is Monday |
| %U | week number of year, with Sunday as first day of week (00..53) |
| %V | ISO week number, with Monday as first day of week (01..53) |
| %w | day of week (0..6); 0 is Sunday |
| %W | week number of year, with Monday as first day of week (00..53) |
| %x | locale's date representation (e.g., 12/31/99) |
| %X | locale's time representation (e.g., 23:13:48) |
| %y | last two digits of year (00..99) |
| %Y | year |
| %z | +hhmm numeric timezone (e.g., -0400) |
| %:z | +hh:mm numeric timezone (e.g., -04:00) |
| %::z | +hh:mm:ss numeric time zone (e.g., -04:00:00) |
| %:::z | numeric time zone with : to necessary precision (e.g., -04, +05:30) |
| %Z | alphabetic time zone abbreviation (e.g., EDT) |
| By default, date pads numeric fields with zeroes. The following optional flags may follow '%':
| - | (hyphen) do not pad the field |
| _ | (underscore) pad with spaces |
| 0 | (zero) pad with zeros |
| ^ | use upper case if possible |
| # | use opposite case if possible |

## 示例

1. 默认格式输出当前时间

```bash
$ date
Wed Jan  8 13:32:00 CST 2020
```

2. 格式化输出当前时间

```bash
$ date +"%Y-%m-%d %H:%M:%S"
2020-01-08 13:32:43

$ date +"%Y.%m.%d %H:%M:%S"
2020.01.08 13:33:39
```

3. 修改系统时间

```bash
$ date -s "20191201 8:30:00"
Sun Dec  1 08:30:00 CST 2019

$ date
Sun Dec  1 08:30:03 CST 2019
```

4. 输出某天是当年第几天

```bash
$ date +%j
335

$ date -d '20200106 8:30:00' +%j
006
```

4. 时间戳转换

```bash
# 输出当前时间戳
$ date +%s
1578461371

# 指定时间转换时间戳
$ date -d '2019-12-27T17:38:04' +%s
1577439484
```

5. 同步网络时间

```bash
$ ntpdate 0.asia.pool.ntp.org
8 Jan 13:45:19 ntpdate[7501]: step time server 202.21.176.62 offset 3301728.210931 sec

$ date
Wed Jan  8 13:45:30 CST 2020
```
