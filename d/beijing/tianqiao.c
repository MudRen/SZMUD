//Cracked by Roath
// Room: /d/beijing/tianqiao.c

#include "beijing_defs.h"
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǳ�����������ֵĵط������߻��ӣ����̾���������������������
��������ģ�˵�鳪���ģ��ٻ�С�ԣ��������У�������������Ի�������Ҳ��
����ز�¶����ʿ���ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
        	"south" : __DIR__"kedian",
		"north" : __DIR__"quanjude",
		"west" : __DIR__"caishikou",
		"east" : __DIR__"zhengyangdajie",
		"northwest": __DIR__"chouzhuang",
//		"northeast": __DIR__"zhubaodian",
                "southwest": __DIR__"majiu",
                "southeast": __DIR__"chaguan",
	]));
	
 	set("objects", ([
	__DIR__"npc/funseller.c": 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 4);
	setup();
}

void init()
{
    if (random(8) == 1) 
	HELPER->clonehere_with_limit(this_object(), "/d/beijing/npc/randomnpc", 8);
}

