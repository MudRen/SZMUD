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
		"east" : __DIR__"chalu6",
		"northeast" : __DIR__"chalu3",
		"southeast" : __DIR__"chalu"+(1+random(4)),
		"west" : __DIR__"chalu9",
		"northwest" : __DIR__"chalu"+(1+random(4)),
		"southwest" : __DIR__"chalu"+(1+random(9)),
	]));
	set("outdoors","xingxiu");
	set("cost", 10);
	setup();
	replace_program(ROOM);
}

