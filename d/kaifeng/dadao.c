//Room: /d/kaifeng/dadao.c
//by bravo
inherit ROOM;
void create()
{
        set("short", "�ٵ�");
        set("long", @LONG
������һ����ʯ�ٵ��ϣ������Ѿ��ǿ��⾳���ˣ�·��ʱʱ����
������ɫ�����������������������䲻����·��վ��Щ�����λ��޵�
Ů�ӣ�����һ�������µ��Եø�����������ȥ�򶫼��ǿ��⸮�ˡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"ximen",
                "west":__DIR__"daqiao",
              ]));
        set("outdoors", "kaifeng");
        setup();
        replace_program(ROOM);
}
