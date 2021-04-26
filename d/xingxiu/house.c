// Code by ShenZhou
// /d/xingxiu/house.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "������Ժ");
        set("long", @LONG
����һ�������ҵ�ͥԺ���ſڴ���������Ͷ��Ժ������˾���
�����졣Ժ�Ӷ����ǰ����Ŀ��������߾���С���֡�
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"beijiang",
        "east" : __DIR__"house1",
]));
        set("objects", ([
                __DIR__"npc/kid": 1,
                __DIR__"npc/bayi": 1 ]) );
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 1);
        setup();
//        replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (!wizardp(me) && objectp(present("hu laoye", environment(me))) && 
                dir == "east")
                return notify_fail("����ү˵: �ҰѰ���������ҵĿ������ˣ�˭Ҳ�����ȥ��\n");
        return ::valid_leave(me, dir);
}

