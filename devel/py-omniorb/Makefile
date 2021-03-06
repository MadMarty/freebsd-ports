# Created by: Johann Visagie <johann@egenetics.com>
# $FreeBSD$

PORTNAME=	omniorb
PORTVERSION=	4.2.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/omniORBpy/omniORBpy-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	omniORBpy-${PORTVERSION}

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Python bindings for omniORB4, a CORBA 2.6 ORB

LICENSE=	LGPL21

LIB_DEPENDS=	libomniORB4.so:${PORTSDIR}/devel/omniORB
RUN_DEPENDS=	omniidl:${PORTSDIR}/devel/omniORB
# parts of omniORB4 source tree is required to build omniORBpy;
# see also the "post-extract" target below.
BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/omniORB:patch

CONFLICTS=	py*-orbit-2* py${PYTHON_SUFFIX}-omniorb3-3*

OPTIONS_DEFINE=	DOCS EXAMPLES

PLIST_SUB=	SONUM=2

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
OMNIORB_WRKSRC!=	cd ${.CURDIR}/../omniORB && ${MAKE} -V WRKSRC

USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
USE_LDCONFIG=	yes
USES=		gmake tar:bzip2 python

CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} --with-omniorb=${LOCALBASE}

.include <bsd.port.options.mk>

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}
	@cd ${OMNIORB_WRKSRC} && ${FIND} idl | ${CPIO} --quiet -pdum ${WRKSRC}

post-install:
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('CosNaming/__init__.py',None,'CosNaming/__init__.pyc',True)"
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('CosNaming__POA/__init__.py',None,'CosNaming__POA/__init__.pyc',True)"
	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('omniidl_be/python.py',None,'omniidl_be/python.pyc',True)"
#	cd ${STAGEDIR}${PYTHON_SITELIBDIR} && ${PYTHON_CMD} -c "import py_compile;py_compile.compile('omniidl_be/python.py',None,'omniidl_be/python.pyc',True)"
	@${RM} ${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl_be/__init__.py
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_omnipymodule.so.4.2
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_omniZIOPmodule.so.4.2
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_omniConnMgmtmodule.so.4.2
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_omnicodesetsmodule.so.4.2
	@${STRIP_CMD} ${STAGEDIR}/${PYTHON_SITELIBDIR}/_omnisslTPmodule.so.4.2
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/tex
	${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy.* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/omniORBpy/* ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/tex/* ${STAGEDIR}${DOCSDIR}/tex
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${FIND} . \
	  | ${CPIO} --quiet -pdum -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
