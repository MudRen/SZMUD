// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "��ͤ");
        set("long", @LONG
����һ��·�ߵ�С��ͤ����ɽ·���˳��ڴ˴�ЪЪ�š�ͤ����
�м������Ӻͼ�֧���ʡ���Χ��һƬ���֡�
LONG
        );
        set("exits", ([
		"northwest" : __DIR__"jxnanmen",
	]));


        set("objects", ([
                        __DIR__"npc/xiang" : 1
	]));
	set("cost", 1);
	setup();
	set("outdoors","quanzhou");
        replace_program(ROOM);
}
