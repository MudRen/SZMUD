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
		"east" : __DIR__"chalu3",
		"northeast" : __DIR__"chalu4",
		"southeast" : __DIR__"chalu8",
		"west" : __DIR__"chalu5",
		"northwest" : __DIR__"chalu"+(1+random(4)),
		"southwest" : __DIR__"chalu6",
	]));
	set("outdoors","xingxiu");
	set("cost", 10);
	setup();
	replace_program(ROOM);
}

