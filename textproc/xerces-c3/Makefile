# Created by: gahr
# $FreeBSD$

PORTNAME=	xerces-c3
PORTVERSION=	3.1.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	xerces/c/3/sources
DISTNAME=	xerces-c-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Validating XML parser from the Apache XML Project

CONFLICTS=	xerces-c2-[0-9]* xerces-c2-devel-[0-9]*

USES=		gmake pathfix libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig \
		--enable-transcoder-iconv \
		--enable-netaccessor-socket
MAKE_ENV+=	XERCESCROOT=${WRKSRC}

post-install:
	${LN} -sf libxerces-c-${PORTVERSION:R}.so ${STAGEDIR}${PREFIX}/lib/libxerces-c.so.${PORTVERSION:R:R}

test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} check

.include <bsd.port.mk>
