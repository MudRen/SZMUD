// /d/xingxiu/beijiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����ӹȣ������ºͣ���ˮ���棬������ġ����С���ϣ��̼�
�������ٻ����ͣ���������������������ʮ�����֡������ǰ�������
�������������У������ھ���ʲ������������м�Ժ�䣬Ժ�ſ��п�
������
LONG
        );
        set("exits", ([ 
        "west" : __DIR__"store",
        "east" : __DIR__"house",
        "northwest" : __DIR__"saimachang",
        "south" : __DIR__"yili",
]));
        set("objects", ([
                __DIR__"npc/woman": 1,
                __DIR__"npc/shushi": 1
                 ]) );
		
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
