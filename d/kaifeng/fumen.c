//Room: /d/kaifeng/fumen.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "���⸮��");
        set("long", @LONG
����ǿ��⸮�š�Ρ����ΰ�ĳ�ǽ�ϣ� "���⸮��" �ĸ�����
ʮ�����ۣ����ƻԻ͡������ױ��������ԡ�
LONG
        );

        set("exits", ([
                "north":__DIR__"kaifengfu",
                "south":__DIR__"guangchang",
                ]));
        set("objects", ([
                __DIR__"npc/bing" : 4,
                __DIR__"obj/dagu" : 1,
        ]));
        set("cost", 1);
        set("outdoors", "kaifeng");
        setup();
}
/*
int valid_leave(object me, string dir)
{
                
        if (!wizardp(me) && objectp(present("guan bing", environment(me))) && dir == "north")
                return notify_fail("�ٱ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
*/
