# Ubuntu 14.04 LTS

echo "
# 清华大学
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty main restricted
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-updates main restricted
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty universe
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-updates universe
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty multiverse
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-updates multiverse
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-backports main restricted universe multiverse
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-security main restricted
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-security universe
deb http://mirrors.tuna.tsinghua.edu.cn/ubuntu/ trusty-security multiverse

# 阿里云
# deb http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse
# deb http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse
# deb http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse
# deb http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse
# deb http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse
# deb-src http://mirrors.aliyun.com/ubuntu/ trusty main restricted universe multiverse
# deb-src http://mirrors.aliyun.com/ubuntu/ trusty-security main restricted universe multiverse
# deb-src http://mirrors.aliyun.com/ubuntu/ trusty-updates main restricted universe multiverse
# deb-src http://mirrors.aliyun.com/ubuntu/ trusty-proposed main restricted universe multiverse
# deb-src http://mirrors.aliyun.com/ubuntu/ trusty-backports main restricted universe multiverse
" >/etc/apt/sources.list
