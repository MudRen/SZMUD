// Code of ShenZhou
// Summer 9/25/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "���Ժ");
        set("long", @LONG
������ϰ��ĸ��ײ��ǳ����ĵط������µ���ľ�������������ա�
ǰ��������һ���ο��ڿ����ģ�"ʮ��������"�����ϻ���׺����ɽˮ��
¥̨�ڻ���������ʱ��Ժ�������Ǻ�Ժ��
LONG
        );
        set("exits", ([
                "west" : __DIR__"shilun",
                "north" : __DIR__"houyuan",
		"south" : __DIR__"zoulang",
        ]));
	set("objects", ([
                "/kungfu/class/xueshan/samu" : 1,
        ]));

	set("cost", 1);
        setup();
}
int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

        if (dir =="north" ) {
            if (present("samu huofo", environment(me))) 
            if (!myfam || myfam["family_name"] != "ѩɽ��"
	    && myfam["family_name"] != "Ѫ����")
                return notify_fail("��ľ���ס��˵���������Ǳ��¸�ɮ����֮�أ�ʩ����ء�\n");
        
	return 1;
    }
        return ::valid_leave(me, dir);
        set("no_clean_up", 0);
}
