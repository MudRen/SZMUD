//Room: /d/kaifeng/wroad2.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�����");
        set("long", @LONG
һ����ʯ�̳ɵĴ��ͨ���ϱ���·���������ﲻ����ֻ�����治
Զ���Ĺ�������һ����ª��̯�ӣ�̯��һ�ǵ������ڷ���ҡ���ţ���
��д�š�����ͤ������ȻҲΧ��һ���ˡ��������������ˣ�������
��������
LONG
        );

        set("exits", ([
                "west" : __DIR__"ximen",
                "south":__DIR__"wroad2s",
                "east":__DIR__"wroad1",
              ]));

        set("objects",([
               "d/taishan/npc/tangzi":1,
              ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}

