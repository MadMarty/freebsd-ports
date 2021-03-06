# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	ntopng
PORTVERSION=	1.2.1
CATEGORIES=	net
MASTER_SITES=	SF/ntop/${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Network monitoring tool with command line and web interfaces

LICENSE=	GPLv3

BROKEN=		Fails to link

LIB_DEPENDS=	librrd.so:${PORTSDIR}/databases/rrdtool \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libndpi.so:${PORTSDIR}/net/ndpi \
		libzmq.so:${PORTSDIR}/net/libzmq4

USE_AUTOTOOLS=	autoheader aclocal libtoolize
USE_SQLITE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
USES=	 	gmake libtool pathfix pkgconfig
SUB_FILES=	ntopng-geoipupdate.sh

OPTIONS_DEFINE=	GEOIP NLS
OPTIONS_DEFAULT=	GEOIP
GEOIP_BUILD_DEPENDS=	geoiplookup:${PORTSDIR}/net/GeoIP
NLS_USES=	gettext

USE_RC_SUBR=	ntopng

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900000
BROKEN=	Does not build on 8.X due to *ENDIAN implementations
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "*~" -delete
	@${RMDIR} ${WRKSRC}/httpdocs/ssl
	@${RMDIR} ${WRKSRC}/httpdocs/geoip

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} ${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	cd ${WRKSRC} && ${INSTALL_MAN} ${PORTNAME}.8 ${STAGEDIR}${PREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${DATADIR}/httpdocs
	${MKDIR} ${STAGEDIR}${DATADIR}/scripts
	cd ${WRKSRC}/httpdocs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/httpdocs
	cd ${WRKSRC}/scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/scripts

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/ntopng-geoipupdate.sh ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
