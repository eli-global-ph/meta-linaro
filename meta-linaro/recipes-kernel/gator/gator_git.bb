DESCRIPTION = "Target-side daemon gathering data for ARM Streamline Performance Analyzer."
SUMMARY  = "DS-5 Gator daemon"

LICENSE = "GPL-2"
LIC_FILES_CHKSUM = "file://driver/LICENSE;md5=b234ee4d69f5fce4486a80fdaf4a4263"

inherit update-rc.d

SRC_URI = "git://git.linaro.org/arm/ds5/gator.git;protocol=http \
           file://gator.init "

SRCREV = "33bef9ed7feca41e7cd6de8bf5d80052669278d3"

S = "${WORKDIR}/git"

PV = "5.15+git${SRCPV}"
PR = "r1"

do_compile() {
    cd daemon
    # aarch64 makefile will work just fine for any arch
    make -f Makefile_aarch64 CROSS_COMPILE=${TARGET_PREFIX} SYSROOT=${STAGING_DIR_TARGET}
}

do_install() {
    install -D -p -m0755 daemon/gatord ${D}/${sbindir}/gatord
    install -D -p -m0755 ${WORKDIR}/gator.init ${D}/${sysconfdir}/init.d/gator

}

INITSCRIPT_NAME = "gator"
INITSCRIPT_PARAMS = "defaults 66"

