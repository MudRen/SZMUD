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
		"east" : __DIR__"chalu7",
		"northeast" : __DIR__"chalu5",
		"southeast" : __DIR__"chalu4",
		"west" : __DIR__"chalu3",
		"northwest" : __DIR__"chalu"+(6+random(4)),
		"southwest" : __DIR__"chalu2",
	]));
	set("outdoors","xingxiu");
	set("cost", 10);
	setup();
	replace_program(ROOM);
}

