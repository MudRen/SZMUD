// Code of ShenZhou
// ��·
// maco

inherit ROOM;

void create()
{
    int i;
	set("short", "��ʯ��·");
	set("long", @LONG
�˴��������Į������ط���Ȼ��ͬ����ػ�ɳ�л��Ŵִ�
ʯ�������ִ������������ף�ʮ�ֵ�������С�һ����ȥ��ɽ��
����ʮ����֮�࣬��֪��һ��������·��
LONG
	);

	set("exits", ([
		"east" : __DIR__"chalu4",
		"northeast" : __DIR__"chalu6",
		"southeast" : __DIR__"chalu5",
		"west" : __DIR__"chalu7",
		"northwest" : __DIR__"chalu11",
		"southwest" : __DIR__"chalu8",
	]));
	set("outdoors","xingxiu");
	set("cost", 10);
	setup();
	replace_program(ROOM);
}

