// Code of ShenZhou
// Room: /d/dali/tusi2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Լ�����һЩ������������Ȳ֣����������������ж��׶�����޵�Χ
ǽ�����彨���ǹ�ģ�������������������ϵ�����Ъɽ������ʽ����������
ʮ�ߣ�����ʮ���壬����ʮ�ߡ���¥�������ټ���Сͷ�����ص㣬Ҳ�������ҡ�
LONG);
	set("exits", ([
		"west" : __DIR__"tusi3",
		"out" : __DIR__"tusi1",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
