# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	gitdb
PORTVERSION=	0.5.4
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Pure Python git object database

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}async>=0.6.1:${PORTSDIR}/devel/py-async \
		${PYTHON_PKGNAMEPREFIX}smmap>=0.8.0:${PORTSDIR}/devel/py-smmap

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
