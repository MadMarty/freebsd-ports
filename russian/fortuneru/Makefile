# Created by: bestia@iptcom.net
# $FreeBSD$

PORTNAME=	fortuneru
PORTVERSION=	20090524
CATEGORIES=	russian
MASTER_SITES=	ftp://bestia.kiev.ua/pub/files/ ftp://hosting.cvu.kiev.ua/pub/files/
DISTNAME=	fortune.ru-${PORTVERSION}

MAINTAINER=	obezpalko@gmail.com
COMMENT=	Fortunes in Russian

NO_BUILD=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message

STRCMD=		/usr/games/strfile

do-install:
	@${SETENV} STRCMD=${STRCMD} ${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/games/fortune/rus
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/games/fortune/rus

pre-install:
.if !exists(${STRCMD})
	@${ECHO_MSG}   "Please install the games distribution"
	@exit 1
.endif

post-install:
	@for fortune in ${STAGEDIR}${PREFIX}/share/games/fortune/rus/* ; do \
		${STRCMD} $$fortune >/dev/null 2>/dev/null ; \
		done
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Usage:"
	@${ECHO_MSG} "/usr/games/fortune ${PREFIX}/share/games/fortune/rus"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
