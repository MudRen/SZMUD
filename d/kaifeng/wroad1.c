//Room: /d/kaifeng/wroad1.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����ǿ��������������������ǡ��򶫾Ϳ��Ե����⸮�ˡ�
ƽͷ�������ˣ�·�ϴ������ͷ������ү�ǡ������ٱ�������״���
�Ź������ˡ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"wroad2",
                "east":__DIR__"guangchang",
                
        ]));

        set("objects",([
                 __DIR__"npc/bing":1,
          ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}

