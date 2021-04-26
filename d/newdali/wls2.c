// Code of ShenZhou
// Room: /d/dali/wls2.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; 2: w; s; n; ne; w; sw; n; #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_drop(object);

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
���������ϴ����ڵ�����ɽ����������᫣���������������û�е�·��ֻ��
һЩ���˺Ͳ�ҩ���߳�����С�������������Ӻڣ�������·�����Ҿ�����������
�������Ժܴ�һ�ж���û���ˡ��������߽�������Ҳû��ȥ���㻹��С��Ϊ�á�
���ǣ���ս����ͷ��ֲ����ϵ��巽���ˣ�
LONG );

	set("exits", ([
		"southeast" : __DIR__"wls2",
		"northeast" : __DIR__"wls2",
		"southwest" : __DIR__"wls2",
		"northwest" : __DIR__"wls1",
		"south"     : __DIR__"wls2",
		"north"     : __DIR__"wls1",
		"west"      : __DIR__"wls3",
		"east"      : __DIR__"wls2",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}

void init()
{
	object me;
	me=this_player();

	if (random(15)==0) {
		tell_object(me, "��ͻȻ�е�������Щ������ζ����ͷһ�����Ų�һ�����ġ�\n���ã��������ˣ�\n");
		me->unconcious();
		me->move(__DIR__"wls2");
	}

	add_action("do_drop", "drop");
}

int do_drop(object ob)
{
	write("�㲻�ܰ�����������������ݴ����Ҳ����ġ�\n");
	return 1;
}
