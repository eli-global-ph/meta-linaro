inherit core-image

IMAGE_FEATURES += "ssh-server-openssh nfs-server package-management"

HUGETLB:armv7a = "libhugetlbfs-tests"
HUGETLB:aarch64 = "libhugetlbfs-tests"
HUGETLB ?= ""

FWTS:armv7a = ""
FWTS:armv7ab = ""
FWTS ?= "fwts"

IMAGE_INSTALL += " \
    bash \
    e2fsprogs-e2fsck \
    kexec-tools \
    linaro-lava-tests \
<<<<<<< Updated upstream
    procps \
    stress \
    stress-dbg \
    sudo \
    util-linux-fsck \
    ${@bb.utils.contains("MACHINE_FEATURES", "optee", "optee-test optee-client", "", d)} \
   "

SDK_IMAGE_INSTALL += "\
    acpica \
    acpitests \
    bc \
=======
    powertop \
    sudo \
    stress-dbg \
    nss-myhostname \
    bash \
    "

IMAGE_INSTALL_append_aarch64 += "perf"

SDK_IMAGE_INSTALL += "\
    ltp \
>>>>>>> Stashed changes
    bison \
    boost-date-time \
    boost-filesystem \
    boost-graph \
    boost-iostreams \
    boost-program-options \
    boost-regex \
    boost-signals \
    boost-system \
    boost-thread \
    cmake \
    curl \
    elfutils-dev \
    expat \
    flex \
<<<<<<< Updated upstream
    ${FWTS} \
    gator \
=======
>>>>>>> Stashed changes
    gd \
    git \
    glog \
    icu \
    idlestat \
    iozone3 \
    libbz2 \
    uw-imap-dev \
    libcap \
    libdwarf-dev \
    libevent \
    libmcrypt \
    libmemcached \
    libmysqlclient-r \
    libpam \
    libpcre \
    libunwind \
    libxml2 \
    ncurses \
    onig \
    openldap \
    openssl \
<<<<<<< Updated upstream
    perf \
    pm-qa \
    powerdebug \
    powertop \
    python \
    python-misc \
    python-multiprocessing \
    python-numpy \
    python-scons \
    python-shell \
    python-threading \
    qemu \
=======
>>>>>>> Stashed changes
    readline \
    rt-tests \
    sshfs-fuse \
<<<<<<< Updated upstream
    tbb \
    trace-cmd \
    xserver-xorg-xvfb \
    xz \
    zlib \
    ${HUGETLB} \
=======
    "

LAMP_IMAGE_INSTALL += "\
    apache2 \
    mysql5-server \
    mysql5-client \
    php-fpm \
    php-fpm-apache2 \
>>>>>>> Stashed changes
    "

ROOTFS_POSTPROCESS_COMMAND += "do_systemd_network ; do_hacknfs ;"

# The boot will fail if you have (k)NFSD disabled or no nfs modules installed
do_hacknfs () {
	rm -f ${IMAGE_ROOTFS}/lib/systemd/system/sysinit.target.wants/proc-fs-nfsd.mount
}

do_systemd_network () {
        install -d ${IMAGE_ROOTFS}${sysconfdir}/systemd/network
        cat << EOF > ${IMAGE_ROOTFS}${sysconfdir}/systemd/network/10-en.network
[Match]
Name=en*

[Network]
DHCP=yes
EOF

        cat << EOF > ${IMAGE_ROOTFS}${sysconfdir}/systemd/network/11-eth.network
[Match]
Name=eth*

[Network]
DHCP=yes
EOF
}

