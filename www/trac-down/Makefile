# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	down
PORTVERSION=	0.0.1.r11
PORTREVISION=	4
CATEGORIES=	www devel python
MASTER_SITES=	http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracDown-${PORTVERSION:E}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Trac plugin for listing released downloads

RUN_DEPENDS=	tracd:${PORTSDIR}/www/trac

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
