DESCRIPTION = "Linaro Stable Kernel For Vexpress/KVM"

PV = "3.10+git${SRCPV}"
SRCREV_kernel="05f74e8baccb60882ace4d0165887368e8143f3f"
SRC_URI:append = " git://git.linaro.org/git/kernel/linux-linaro-stable.git;protocol=http;branch=linux-linaro-lsk;name=kernel "
require linaro-kernel.inc

KERNEL_DEVICETREE = "vexpress-v2p-ca15-tc1.dtb"
BOOTARGS_COMMON = "root=/dev/mmcblk0p2 console=ttyAMA0 consolelog=9 mem=1024M rw rootwait"
COMPATIBLE_HOST = "arm.*"
KERNEL_IMAGETYPE = "zImage"

do_configure:prepend() {
    . ../ubuntu-ci/configs/lsk-vexpress.cfg
    ARCH=arm scripts/kconfig/merge_config.sh -m $linaro_base_config_frags $ubuntu_config_frag $board_config_frags
}
