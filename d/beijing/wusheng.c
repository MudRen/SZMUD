//Cracked by Roath
// Room: wusheng ��ʤ�ھ�
// Ssy

inherit ROOM;

void create()
{
        set("short", "��ʤ�ھ�");
        set("long", @LONG
���Ǿ������������ϵ��ھ֣����ſ����Ҹ���һ��ʯʨ�ӣ�������צ����Ŀ
������������һ�����ң����顰��ʤ�ھ֡��ĸ�����ĺ��֣������������վ�
�Ƿ�����ڴ�������ͷ�����š�
LONG
        );

        set("exits", ([
                "west" : __DIR__"wangfudajie",
                "north" : __DIR__"biaoju",
        ]));

        set("objects", ([
                __DIR__"npc/biaotou" : 3,
        ]));

        set("cost", 0);
        setup();
        replace_program(ROOM);
}

