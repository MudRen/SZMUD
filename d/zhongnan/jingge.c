// Code of ShenZhou
// road: /zhongnan/jingge.c
// sdong 08/05/98

#include <ansi.h>
inherit ROOM;

void create()
{
		  set("short",HIM"�ؾ���"NOR);

		  set("long",@LONG
������������ⲻԶ�Ĳؾ��󣬲��ٽ��ڵ������Ǵ���ڴˡ�ֻ��
������ߵĽ������ܽǸ߾������������������Ǿ������ۡ�������һ��
С����
LONG);

		  set("exits",([ "south" : __DIR__"yuanneixiaojing3",
							  "up"	: __DIR__"jingge2.c",
							 ])
			  );
	  set("cost",1);

	  set("objects", ([
				 CLASS_D("quanzhen") + "/li" : 1,
					 ]));

	  setup();

}


