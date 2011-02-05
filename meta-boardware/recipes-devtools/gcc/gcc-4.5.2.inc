require gcc-common.inc
LICENSE = "GPLv3"

DEPENDS =+ "mpfr gmp libmpc elfutils"
NATIVEDEPS = "mpfr-native gmp-native gettext-native libmpc-native elfutils-native"
LICENSE="GCC RUNTIME LIBRARY EXCEPTION & GPLv2 & GPLv3 & LGPLv2.1 & LGPLv3"

LIC_FILES_CHKSUM = "file://COPYING;md5=59530bdf33659b29e73d4adb9f9f6552 \
                   file://COPYING3;md5=d32239bcb673463ab874e80d47fae504 \
                   file://COPYING3.LIB;md5=6a6a8e020838b23406c81b19c1d46df6 \
                   file://COPYING.LIB;md5=2d5025d4aa3495befef8f17206a5b0a1 \
                  file://COPYING.RUNTIME;md5=fe60d87048567d4fe8c8a0ed2448bcc8"

SRC_URI = "${GNU_MIRROR}/gcc/gcc-${PV}/gcc-${PV}.tar.bz2 \
	   file://gcc-4.3.1-ARCH_FLAGS_FOR_TARGET.patch \
	   file://100-uclibc-conf.patch \
           file://gcc-uclibc-locale-ctype_touplow_t.patch \
	   file://cache-amnesia.patch \
	   file://gcc-flags-for-build.patch \
           file://gcc-4.3.3-SYSROOT_CFLAGS_FOR_TARGET.patch \
	   file://libstdc++-emit-__cxa_end_cleanup-in-text.patch \
	   file://arm-bswapsi2.patch \
           file://fedora/gcc43-c++-builtin-redecl.patch;striplevel=0 \
           file://fedora/gcc43-ia64-libunwind.patch;striplevel=0 \
           file://fedora/gcc43-java-nomulti.patch;striplevel=0 \
           file://fedora/gcc43-ppc32-retaddr.patch;striplevel=0 \
           file://fedora/gcc43-pr32139.patch;striplevel=0 \
           file://fedora/gcc43-pr33763.patch;striplevel=0 \
           file://fedora/gcc43-rh330771.patch;striplevel=0 \
           file://fedora/gcc43-rh341221.patch;striplevel=0 \
           file://fedora/gcc43-java-debug-iface-type.patch;striplevel=0 \
           file://fedora/gcc43-i386-libgomp.patch;striplevel=0 \
           file://fedora/gcc45-no-add-needed.patch;striplevel=0 \
	   file://linaro/gcc-4.5-linaro-r99297.patch \
	   file://linaro/gcc-4.5-linaro-r99298.patch \
	   file://linaro/gcc-4.5-linaro-r99299.patch \
	   file://linaro/gcc-4.5-linaro-r99300.patch \
	   file://linaro/gcc-4.5-linaro-r99301.patch \
	   file://linaro/gcc-4.5-linaro-r99302.patch \
	   file://linaro/gcc-4.5-linaro-r99303.patch \
	   file://linaro/gcc-4.5-linaro-r99304.patch \
	   file://linaro/gcc-4.5-linaro-r99305.patch \
	   file://linaro/gcc-4.5-linaro-r99306.patch \
	   file://linaro/gcc-4.5-linaro-r99307.patch \
	   file://linaro/gcc-4.5-linaro-r99308.patch \
	   file://linaro/gcc-4.5-linaro-r99310.patch \
	   file://linaro/gcc-4.5-linaro-r99312.patch \
	   file://linaro/gcc-4.5-linaro-r99313.patch \
	   file://linaro/gcc-4.5-linaro-r99314.patch \
	   file://linaro/gcc-4.5-linaro-r99315.patch \
	   file://linaro/gcc-4.5-linaro-r99316.patch \
	   file://linaro/gcc-4.5-linaro-r99318.patch \
	   file://linaro/gcc-4.5-linaro-r99319.patch \
	   file://linaro/gcc-4.5-linaro-r99320.patch \
	   file://linaro/gcc-4.5-linaro-r99321.patch \
	   file://linaro/gcc-4.5-linaro-r99322.patch \
	   file://linaro/gcc-4.5-linaro-r99323.patch \
	   file://linaro/gcc-4.5-linaro-r99324.patch \
	   file://linaro/gcc-4.5-linaro-r99325.patch \
	   file://linaro/gcc-4.5-linaro-r99326.patch \
	   file://linaro/gcc-4.5-linaro-r99327.patch \
	   file://linaro/gcc-4.5-linaro-r99332.patch \
	   file://linaro/gcc-4.5-linaro-r99335.patch \
	   file://linaro/gcc-4.5-linaro-r99336.patch \
	   file://linaro/gcc-4.5-linaro-r99337.patch \
	   file://linaro/gcc-4.5-linaro-r99338.patch \
	   file://linaro/gcc-4.5-linaro-r99339.patch \
	   file://linaro/gcc-4.5-linaro-r99340.patch \
	   file://linaro/gcc-4.5-linaro-r99341.patch \
	   file://linaro/gcc-4.5-linaro-r99342.patch \
	   file://linaro/gcc-4.5-linaro-r99343.patch \
	   file://linaro/gcc-4.5-linaro-r99344.patch \
	   file://linaro/gcc-4.5-linaro-r99345.patch \
	   file://linaro/gcc-4.5-linaro-r99346.patch \
	   file://linaro/gcc-4.5-linaro-r99347.patch \
	   file://linaro/gcc-4.5-linaro-r99348.patch \
	   file://linaro/gcc-4.5-linaro-r99349.patch \
#	   file://linaro/gcc-4.5-linaro-r99350.patch \
	   file://linaro/gcc-4.5-linaro-r99351.patch \
	   file://linaro/gcc-4.5-linaro-r99352.patch \
	   file://linaro/gcc-4.5-linaro-r99353.patch \
	   file://linaro/gcc-4.5-linaro-r99354.patch \
	   file://linaro/gcc-4.5-linaro-r99355.patch \
	   file://linaro/gcc-4.5-linaro-r99356.patch \
	   file://linaro/gcc-4.5-linaro-r99357.patch \
	   file://linaro/gcc-4.5-linaro-r99358.patch \
	   file://linaro/gcc-4.5-linaro-r99359.patch \
	   file://linaro/gcc-4.5-linaro-r99360.patch \
	   file://linaro/gcc-4.5-linaro-r99361.patch \
	   file://linaro/gcc-4.5-linaro-r99363.patch \
	   file://linaro/gcc-4.5-linaro-r99364.patch \
	   file://linaro/gcc-4.5-linaro-r99365.patch \
	   file://linaro/gcc-4.5-linaro-r99366.patch \
	   file://linaro/gcc-4.5-linaro-r99367.patch \
	   file://linaro/gcc-4.5-linaro-r99368.patch \
	   file://linaro/gcc-4.5-linaro-r99369.patch \
	   file://linaro/gcc-4.5-linaro-r99371.patch \
	   file://linaro/gcc-4.5-linaro-r99372.patch \
	   file://linaro/gcc-4.5-linaro-r99373.patch \
	   file://linaro/gcc-4.5-linaro-r99374.patch \
	   file://linaro/gcc-4.5-linaro-r99375.patch \
	   file://linaro/gcc-4.5-linaro-r99376.patch \
	   file://linaro/gcc-4.5-linaro-r99377.patch \
	   file://linaro/gcc-4.5-linaro-r99378.patch \
	   file://linaro/gcc-4.5-linaro-r99379.patch \
	   file://linaro/gcc-4.5-linaro-r99380.patch \
	   file://linaro/gcc-4.5-linaro-r99381.patch \
	   file://linaro/gcc-4.5-linaro-r99383.patch \
	   file://linaro/gcc-4.5-linaro-r99384.patch \
	   file://linaro/gcc-4.5-linaro-r99385.patch \
	   file://linaro/gcc-4.5-linaro-r99388.patch \
	   file://linaro/gcc-4.5-linaro-r99391.patch \
	   file://linaro/gcc-4.5-linaro-r99392.patch \
	   file://linaro/gcc-4.5-linaro-r99393.patch \
	   file://linaro/gcc-4.5-linaro-r99395.patch \
	   file://linaro/gcc-4.5-linaro-r99396.patch \
	   file://linaro/gcc-4.5-linaro-r99397.patch \
	   file://linaro/gcc-4.5-linaro-r99398.patch \
	   file://linaro/gcc-4.5-linaro-r99402.patch \
	   file://linaro/gcc-4.5-linaro-r99403.patch \
	   file://linaro/gcc-4.5-linaro-r99404.patch \
	   file://linaro/gcc-4.5-linaro-r99405.patch \
	   file://linaro/gcc-4.5-linaro-r99406.patch \
	   file://linaro/gcc-4.5-linaro-r99407.patch \
	   file://linaro/gcc-4.5-linaro-r99408.patch \
	   file://linaro/gcc-4.5-linaro-r99409.patch \
	   file://linaro/gcc-4.5-linaro-r99410.patch \
	   file://linaro/gcc-4.5-linaro-r99411.patch \
	   file://linaro/gcc-4.5-linaro-r99412.patch \
	   file://linaro/gcc-4.5-linaro-r99413.patch \
	   file://linaro/gcc-4.5-linaro-r99414.patch \
	   file://linaro/gcc-4.5-linaro-r99415.patch \
	   file://linaro/gcc-4.5-linaro-r99416.patch \
	   file://linaro/gcc-4.5-linaro-r99417.patch \
	   file://linaro/gcc-4.5-linaro-r99418.patch \
	   file://linaro/gcc-4.5-linaro-r99419.patch \
	   file://linaro/gcc-4.5-linaro-r99420.patch \
	   file://gcc-scalar-widening-pr45847.patch \
	   file://gcc-arm-qihi-split-PR46883.patch \
           file://103-uclibc-conf-noupstream.patch  \
           file://200-uclibc-locale.patch  \
           file://203-uclibc-locale-no__x.patch;striplevel=1 \
           file://204-uclibc-locale-wchar_fix.patch;striplevel=1 \
           file://205-uclibc-locale-update.patch;striplevel=1 \
           file://301-missing-execinfo_h.patch  \
           file://302-c99-snprintf.patch  \
           file://303-c99-complex-ugly-hack.patch  \
           file://304-index_macro.patch  \
           file://305-libmudflap-susv3-legacy.patch  \
           file://306-libstdc++-namespace.patch  \
           file://740-sh-pr24836.patch  \
           file://800-arm-bigendian.patch  \
           file://904-flatten-switch-stmt-00.patch  \
           file://arm-nolibfloat.patch  \
           file://arm-softfloat.patch \
           file://zecke-xgcc-cpp.patch \
	   file://64bithack.patch \
	   file://optional_libstdc.patch \
	   file://disable_relax_pic_calls_flag.patch \
	   file://GPLUSPLUS_INCLUDE_DIR_with_sysroot.patch \
	   file://gcc-poison-dir-extend.patch \
	  "
	
SRC_URI_append_sh3  = " file://sh3-installfix-fixheaders.patch;patch=1 "

# Language Overrides
FORTRAN = ""
JAVA = ""

#EXTRA_OECONF_BASE = "  --enable-cheaders=c_std \
#			--enable-libssp \
#			--disable-bootstrap \
#			--disable-libgomp \
#			--disable-libmudflap"
EXTRA_OECONF_BASE = " --enable-lto \
			--enable-libssp \
			--disable-bootstrap \
			--disable-libgomp \
			--disable-libmudflap \
			--enable-cheaders=c_global "

EXTRA_OECONF_INITIAL = "--disable-libmudflap \
			--disable-libgomp \
			--disable-libssp \
			--enable-decimal-float=no"

EXTRA_OECONF_INTERMEDIATE = "--disable-libmudflap \
				--disable-libgomp \
				--disable-libssp"

EXTRA_OECONF_append_linux-uclibc = " --disable-decimal-float "
EXTRA_OECONF_append_linux-uclibceabi = " --disable-decimal-float "
EXTRA_OECONF_append_linux-uclibcspe = " --disable-decimal-float "
