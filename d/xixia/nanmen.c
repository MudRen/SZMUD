// Code of ShenZhou
// Room: /d/xixia/nanmen.c

inherit ROOM;

void create()
{
        set("short", "��������");
        set("long", @LONG
�������ݵ��ϳ��ţ��������Ϸ��̵��м����������֡���ǽ�����ż��Źٸ�
��ʾ��һ����·����ͨ�����̲��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nandajie",
  "south" : __DIR__"hytan",
]));
        set("objects", ([
                __DIR__"npc/xiaowei": 1,
                __DIR__"npc/xxbing": 2,
]));

        set("no_clean_up", 0);
        set("outdoors", "xixia");

        setup();
}
int valid_leave(object me, string dir)
{
        if (dir =="north" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("xakiller") > 0)
                return notify_fail("���ı����еĳ�ǹ��ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
