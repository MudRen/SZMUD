// Code of ShenZhou
// mozhen.c ĥ�뾮
// by Fang 8/26/96

inherit ROOM;

void create()
{
	set("short", "ĥ�뾮");
	set("long", @LONG
�ഫ���������ɽ�������վ�˼�飬ż��һ�ϸ���������ĥ����ĥ��
Ϊ�Σ�����ĥ�롣������������ĥ�룿���ƹ�����Ȼ�ɡ������ɴ�����
�����������ɡ�������ĥ�뾮������Ϊ�����ǰ��������һ������
������ĸͤ��ͤ�����о�(jing)��
LONG
	);
        set("outdoors", "wudang");
        set("resource/water", 1);
	set("exits", ([
		"west" : __DIR__"shanlu",
	]));
    set("item_desc", ([
            "jing" : "��ɫ���㡢�ڹ�¡��һ�ھ���\n",
    ]));
	set("cost", 2);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

