// Code of ShenZhou
// /d/gaibang/underxs.c

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ѩ��");
        set("long", @LONG
���Ǵ�ѩɽ���µ�һ��ѩ�ӡ������˸������ ����ؤ���
���ռ�����ͭ�����ȡ��ӱ�����һ��С����
LONG
        );
	 switch(random(3)){
	case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }
	set("exits", ([
		"up" : "d/xueshan/shanlu7",
		"enter":__DIR__"xsandao2",
	]));


	set("cost", 2);
	setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="enter" ) {
            if (!myfam || myfam["family_name"] != "ؤ��")
                return notify_fail("����С�Ķ���ר�ý�ȥ��\n");

        return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}



