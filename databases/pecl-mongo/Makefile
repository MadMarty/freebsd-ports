# Created by: wen
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	1.5.2
CATEGORIES=	databases pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PECL classes for Mongo Database Driver

LICENSE=	APACHE20

USE_PHP=	spl
USE_PHP_BUILD=	yes
USE_PHPEXT=	yes
CONFIGURE_ARGS=	--enable-mongo
SUB_FILES=	pkg-message

.include <bsd.port.mk>
