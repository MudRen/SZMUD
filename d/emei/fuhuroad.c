// Code of ShenZhou
// fuhuroad.c ����
// by Shan

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����ﶫ�¶����Ǳ����£�
�����ּ�������һ�����
LONG
        );
        set("exits", ([
                "northeast" : __DIR__"baoguo",
		"west" : __DIR__"fuhu",
        ]));

//	set("outdoors", "emei");

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
