// Code of ShenZhou
// Room: /d/heimuya/mihang.c
// Date: fear 99/12/08

inherit ROOM;




void create()
{
        set("short", "����");
        set("long", @LONG
����Ŀռ䲻�󣬵��ϰ��źܶ��׸ף�װ�Ÿ��ָ�
�����ס��ϰ������������ͷ�����˯���������׵���
���Ǻܶࡣ�������ƽ�������ֵĶ������ˡ�
LONG
        );

        set("exits", ([
                "south" : __DIR__"eaststreet1",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}

