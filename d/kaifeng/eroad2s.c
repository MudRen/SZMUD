//Room: /d/kaifeng/eroad2s.c
// by bravo
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
�����ڶ�����ϣ����ż�ʵ����ʯ����档����һ����ֱ�Ĵ�
�������߿���ͨ�������ţ����ϱ�ͨ���ϴ�֣����Ϸ�������������
��¥�ˡ�
LONG
        );

        set("exits", ([
                "north" : __DIR__"eroad2",
                "southwest":__DIR__"sroad2e",
                "southeast":__DIR__"tingyulou",
                ]));
         set("outdoors", "kaifeng");

        setup();
        replace_program(ROOM);
}
