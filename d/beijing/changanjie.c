//Cracked by Roath
// Room: /d/beijing/changanjie.c

#include "beijing_defs.h"
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���Ƿ������ֵĳ����֣���ֱ����������ɭ�ϵ��Ͻ���
�����찲���ˡ�����ʱ����Ѳ�ߵ������̲��·�����ˡ����
�����Ǹ��ֵ��̣��㿴���۶����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north"  : "/d/beijing/zijin/tianansquare",
  "south" : __DIR__"zhengyangmen",
  "east"  : __DIR__"changanjie_e",
  "west"  : __DIR__"changanjie_w",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
}

void init()
{
    if (random(5) == 1) 
	HELPER->clonehere_with_limit(this_object(), "/d/beijing/npc/randomnpc.c", 8);
}
