--- programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c.orig	Tue Oct 29 16:19:13 2002
+++ programs/Xserver/hw/xfree86/os-support/bsd/alpha_video.c	Sat Feb 21 00:26:25 2004
@@ -33,7 +33,10 @@
 #include <sys/param.h>
 #ifndef __NetBSD__
 #  include <sys/sysctl.h>
-# else
+#  ifdef __FreeBSD__
+#     include <machine/sysarch.h>
+#  endif
+#else
 #  include <machine/sysarch.h>
 #endif
 #include "xf86Axp.h"
@@ -51,6 +54,8 @@
 #define MAP_FAILED ((caddr_t)-1)
 #endif
 
+axpDevice bsdGetAXP(void);
+
 #ifndef __NetBSD__
 extern unsigned long dense_base(void);
 
@@ -260,10 +265,10 @@
 #endif /* __OpenBSD__ */
 	   
            xf86ErrorF("\tlinear framebuffer access unavailable\n");
+#endif
 	}
 	useDevMem = FALSE;
 	return;
-#endif
 }
 
 void
@@ -475,7 +480,7 @@
 writeSparse32(int Value, pointer Base, register unsigned long Offset);
 
 #ifdef __FreeBSD__
-extern int sysarch(int, char *);
+extern int sysarch(int, void *);
 #endif
 
 struct parms {
