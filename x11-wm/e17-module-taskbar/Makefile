# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	taskbar
PORTVERSION=	20130510
PORTREVISION=	1
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	LOCAL/gblach/e17/modules/
PKGNAMEPREFIX=	e17-module-

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Classic taskbar module for e17

LICENSE=	GPLv2

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig tar:bzip2
USE_EFL=	edje libtool_hack modarch_hack

BROKEN=		Don't build with Enlightenment 0.19
DEPRECATED=	Broken and updates aren't available
EXPIRATION_DATE=2014-12-31

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
