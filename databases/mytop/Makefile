# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mytop
PORTVERSION=	1.7
CATEGORIES=	databases

MAINTAINER=	matthew@FreeBSD.org
COMMENT=	Top clone for MySQL

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBD-mysql>1.0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-DBI>=1.13:${PORTSDIR}/databases/p5-DBI \
		p5-Term-ReadKey>=2.10:${PORTSDIR}/devel/p5-Term-ReadKey

USE_GITHUB=	yes
GH_ACCOUNT=	jzawodn
GH_PROJECT=	mytop
GH_COMMIT=	437f2ef
GH_TAGNAME=	${GH_COMMIT}

NO_ARCH=	yes
CONFLICTS=	mariadb-scripts-[0-9]*

USES+=		perl5
USE_PERL5=	configure

PLIST_FILES=	bin/mytop \
		man/man1/mytop.1.gz

.include <bsd.port.mk>
