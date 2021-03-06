// Code of ShenZhou
// room: /d/baituo/btgate
// Jay 3/27/96
// maco 2/17/2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"白驼山山门"NOR);
	set("long",
"这是就是传说中神秘的〖"+HIW"白驼山庄"NOR+"〗。远远望去，两座
白沙堆积形成的山峰好像一只骆驼的脊背。一座山门立在你的眼前。山门后
一条大道通向一座山腰上的山庄。那里是「西毒」欧阳锋的白驼山庄。另有
一条小路曲折通往西北。\n"
	);
	set("exits", ([ 
		"east" : __DIR__"xiaolu",
		"south" : __DIR__"tuopeng",
		"northwest" : "/d/baituo/road3",
		"westup" : __DIR__"btyard",
		]));
	
	set("objects", ([ 
          //      CLASS_D("baituo")+"/yin" : 1,
		"/d/baituo/npc/jiading" : 2,
		]) );
	
	set("outdoors","baituo");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir =="westup" && me->query("family/family_name")!="白驼山" ) 
	{
		if (objectp(present("jiading", environment(me))))
			return notify_fail("家丁挡住了你的去路：老爷正在练功，请改日再来。\n");
	}      
	return ::valid_leave(me, dir);
}

