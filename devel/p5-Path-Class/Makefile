# Created by: Elvis Chiang <elvis@sslab.cs.ccu.edu.tw>
# $FreeBSD$

PORTNAME=	Path-Class
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:KWILLIAMS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Cross-platform path specification manipulation

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	DOCS

USES=		perl5
USE_PERL5=	modbuild

PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
