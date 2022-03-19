###
 # @Date: 2020-09-21 08:38:38
 # @LastEditors: Rustle Karl
 # @LastEditTime: 2021-01-11 11:24:57
### 

# Ubuntu 20.04 LTS

echo "# 阿里源
deb http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-security main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-updates main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-proposed main restricted universe multiverse
deb http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse
deb-src http://mirrors.aliyun.com/ubuntu/ focal-backports main restricted universe multiverse

# 中科大
deb http://mirrors.ustc.edu.cn/ubuntu/ focal main restricted universe multiverse
deb-src http://mirrors.ustc.edu.cn/ubuntu/ focal main restricted universe multiverse
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb-src http://mirrors.ustc.edu.cn/ubuntu/ focal-updates main restricted universe multiverse
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb-src http://mirrors.ustc.edu.cn/ubuntu/ focal-backports main restricted universe multiverse
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-security main restricted universe multiverse
deb-src http://mirrors.ustc.edu.cn/ubuntu/ focal-security main restricted universe multiverse
deb http://mirrors.ustc.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse
deb-src http://mirrors.ustc.edu.cn/ubuntu/ focal-proposed main restricted universe multiverse

# 官方源
# deb http://archive.ubuntu.com/ubuntu focal main restricted universe multiverse
# deb http://archive.ubuntu.com/ubuntu focal-security main restricted universe multiverse
# deb http://archive.ubuntu.com/ubuntu focal-updates main restricted universe multiverse
# deb http://archive.ubuntu.com/ubuntu focal-proposed main restricted universe multiverse
# deb http://archive.ubuntu.com/ubuntu focal-backports main restricted universe multiverse
# deb-src http://archive.ubuntu.com/ubuntu focal main restricted universe multiverse
# deb-src http://archive.ubuntu.com/ubuntu focal-security main restricted universe multiverse
# deb-src http://archive.ubuntu.com/ubuntu focal-updates main restricted universe multiverse
# deb-src http://archive.ubuntu.com/ubuntu focal-proposed main restricted universe multiverse
# deb-src http://archive.ubuntu.com/ubuntu focal-backports main restricted universe multiverse
" >/etc/apt/sources.list
