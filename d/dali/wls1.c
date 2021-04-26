// Code of ShenZhou
// Room: /d/dali/wls1.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// 1: se; w; s; n; ne; w; sw; n; #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_drop(object);
int do_find(string);

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
		"northeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"south"     : __FILE__,
		"north"     : __FILE__,
		"west"      : __FILE__,
		"east"      : __DIR__"chadao",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_drop", "drop");
	add_action("do_find", "find");
}

int do_drop(object ob)
{
	write("�㲻�ܰ�����������������ݴ����Ҳ����ġ�\n");
	return 1;
}

int do_find(string arg)
{
	object *inv;
	object me, ob;
	int i;
	me=this_player();

	if (arg=="miji" && me->query("got_beiming") && !me->query_temp("got_miji")) {
		tell_object(me,"�����������ҷ���һ���һ����Լ���ǰ��������ġ���ڤ�ؼ�����\n");
		ob=new(__DIR__"obj/beiming-miji");
		ob->move(me);
		me->set_temp("got_miji",1);
		return 1;
	}
	if (arg=="way" && me->query("got_beiming")) {
		inv=all_inventory(me);
		for(i=0; i<sizeof(inv); i++) 
			if (inv[i]->is_character())
			return notify_fail("���˻��Բ��ѣ��㻹�ǸϿ��ҵط�ҽ�����ɡ�\n"); 
		tell_object(me,"�㲦����������һ�󣬷�����һ��С·��\n");
		me->move(__DIR__"jb2");
		return 1;
	}
	return 0;
}
