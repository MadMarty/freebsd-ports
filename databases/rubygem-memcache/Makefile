# Created by: Mikhail T. <michael@fun-box.ru>
# $FreeBSD$

PORTNAME=	memcache
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby bindings for libmemcached

LIB_DEPENDS=	libmemcached.so:${PORTSDIR}/databases/libmemcached

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

GEM_ENV	+=EXTERNAL_LIB="YES"
CONFIGURE_ARGS=	"--with-opt-dir=${LOCALBASE}"

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 2.1
BROKEN=		Does not build with Ruby 2.1
.endif

.include <bsd.port.post.mk>
