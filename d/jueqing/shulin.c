// Filename:   /d/jueqinggu/shulin.c
// Jiuer 08/ 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIM"情花林"NOR);

	set("long",@LONG
转过一个大弯，一大片诱人的树林出现眼前，细看花树，见枝叶上
生满小刺，花瓣的颜色是娇艳无比，似芙蓉而更香，如山茶而增艳，花
朵背后隐藏着小刺，这就是情花林，听说世上并不多见。
LONG);
	
	set("objects", ([
		CLASS_D("jueqing") + "/gongsunle" : 1,
		]));
	
	set("exits",([ 
		"south" : __DIR__"qinghuaao3",
		"east" : __DIR__"shiwu1",
		"northup" : __DIR__"zhulin",
		]));
	 
	set("outdoors","jueqing");
	set("cost",1);

	setup();	  
}

