// Code of ShenZhou
// /d/emei/fuhuroad2.c ����
// by Shan

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����������Ǳ����£�����
�ּ�������һ�����
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"fuhu",
		"westup" : __DIR__"jietuo",
        ]));

	set("cost", 3);
        setup();
	replace_program(ROOM);
}
