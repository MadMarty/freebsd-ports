# Created by: Sébastien Santoro <dereckson@gmail.com>
# $FreeBSD$

PORTNAME=	astrometry
PORTVERSION=	0.46
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://www.astrometry.net/downloads/
DISTNAME=	${PORTNAME}.net-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Describes an astronomical image

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/numpy:${PORTSDIR}/math/py-numpy
LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo \
		libcfitsio.so:${PORTSDIR}/astro/cfitsio \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libnetpbm.so:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake pkgconfig python tar:bzip2
ALL_TARGET=	all extra
MAKE_ENV=	INSTALL_DIR=${STAGEDIR}${PREFIX}/${PORTNAME}
MAKE_JOBS_UNSAFE=	yes
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -E 's,python (setup|-c),${PYTHON_CMD} \1,' \
		${WRKSRC}/blind/Makefile ${WRKSRC}/libkd/Makefile \
		${WRKSRC}/sdss/Makefile ${WRKSRC}/util/Makefile
# Outwit detection logic that thinks Clang does not support -shared argument
	@${REINPLACE_CMD} -e '/CCTEST/s,\\|warning:,,' \
		${WRKSRC}/util/makefile.common

post-install:
	@${REINPLACE_CMD} -i '' -e 's|${STAGEDIR}||' \
		${STAGEDIR}${PREFIX}/${PORTNAME}/etc/${PORTNAME}.cfg
	@${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME}/bin -type f -not -name "*.py" \
		-exec ${STRIP_CMD} {} \;
	@${FIND} ${STAGEDIR}${PREFIX}/${PORTNAME}/lib -type f -name "*.so" \
		-exec ${STRIP_CMD} {} \;

.include <bsd.port.mk>
