# $FreeBSD$

PORTNAME=	nxcomp
PORTVERSION=	3.5.0.28
MASTER_SITES=	http://code.x2go.org/releases/source/nx-libs/
CATEGORIES=	x11 devel
DISTNAME=	nx-libs-${PORTVERSION}-lite

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	NX X11 protocol compression libraries

WRKSRC=		${WRKDIR}/nx-libs-${PORTVERSION}/${PORTNAME}

USE_AUTOTOOLS=	autoconf
USE_XORG=	xproto
GNU_CONFIGURE=	yes
LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

post-patch:
	@${REINPLACE_CMD} -e "s,libdir}/nx,libdir},g" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|/usr/NX/bin:/opt/NX/bin:/usr/local/NX|${PREFIX}|" \
		${WRKSRC}/Children.cpp

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXcomp.so.3.5*

.include <bsd.port.mk>
