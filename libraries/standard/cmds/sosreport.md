# sosreport 命令

> 收集系统配置及架构信息然后输出诊断文档

## 格式

```bash
sosreport [options]
```

## 参数

| 参数 | 作用 |
| --------- | --------- |
| -h, --help | show this help message and exit |
| -l, --list-plugins | list plugins and available plugin options |
| -n NOPLUGINS, --skip-plugins=NOPLUGINS | disable these plugins |
| -e ENABLEPLUGINS, --enable-plugins=ENABLEPLUGINS | enable these plugins |
| -o ONLYPLUGINS, --only-plugins=ONLYPLUGINS | enable these plugins only |
| -k PLUGOPTS, --plugin-option=PLUGOPTS | plugin options in plugname.option=value format (see -l) |
| -a, --alloptions | enable all options for loaded plugins |
| --batch | batch mode - do not prompt interactively |
| --build | keep sos tree available and dont package results |
| -v, --verbose | increase verbosity |
| --quiet | only print fatal errors |
| --debug | enable interactive debugging using the python debugger specify ticket number |
| --name=CUSTOMER_NAME | specify report name |
| --config-file=CONFIG_FILE | specify alternate configuration file |
| --tmp-dir=TMP_DIR | specify alternate temporary directory |
| --report | Enable HTML/XML reporting |
| --profile | turn on profiling |
| -z COMPRESSION_TYPE, --compression-type=COMPRESSION_TYPE | compression technology to use [auto, zip, gzip, bzip2, xz] (default=auto) |
