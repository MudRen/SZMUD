// Code of ShenZhou
// Room: /d/beijing/zjchengmen.c

inherit ROOM;

void create()
{
        set("short", "�Ͻ��ǳ���");
	set("long", @LONG
���Ǿ�����ʵ�ס�ĵط�����ͨ������������Ͳ��������������ˡ�
�ű�վ�Ŷ����������������������ׯ�����£�����һ�����ظС�
LONG
	);
        set("exits", ([
                "east" : __DIR__"wangfudajie",
]));
	set("no_clean_up", 0);
        set("fanhua", 2);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
