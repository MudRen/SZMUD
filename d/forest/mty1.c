// Code of ShenZhou
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "�¶�");
        set("long", @LONG
Ħ�����¶�����һ�����ʯ����ʯ֮��һ�������������ڴ�����
������һ��ɽ����Ħ���¶�����ï�ܣ�ʱֵ���ӳ��켾�ڣ�������
��Ҷ���к�ɫ���������ǵ�㣬ɷ�ǿ��ˡ�
LONG
        );

        set("exits", ([
                "east" : __DIR__"mtcave",
		"south" : __DIR__"mty",
		"up" : __DIR__"zaoshu",
        ]));
	set("objects", ([
                "/clone/npc/xie" : 1
        ]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


