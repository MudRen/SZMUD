// Code of ShenZhou
// Jay 7/11/96
inherit ROOM;


void create()
{
    int i;
        set("short", "�¶�");
        set("long", @LONG
������Ħ�����¶���������ȥ����ׯ������������С�㣬����ͷ��
Ŀѣ��
LONG
        );

        set("exits", ([
                "down" : __DIR__"middle",
		"north" : __DIR__"mty1",
        ]));

	set("cost", 1);
	set("outdoors", "city");
        setup();
        replace_program(ROOM);
}


