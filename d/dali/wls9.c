// Code of ShenZhou
// Room: /dali/wls9.c
// AceP
// The path from ChaDao to Wu Liang Shan :
// se; w; s; n; ne; w; sw; n; 9: #9, ne; sw; nw; e; s; w; sw; n; w;

inherit ROOM;

int do_say(string);
int do_drop(object);

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
���������ϴ����ڵ�����ɽ����������᫣���������������û�е�·��ֻ��
һЩ���˺Ͳ�ҩ���߳�����С�������������Ӻڣ�������·�����Ҿ�����������
�������Ժܴ�һ�ж���û���ˡ��������߽�������Ҳû��ȥ���㻹��С��Ϊ�á�
���ǣ���ս����ͷ��ֲ����ϵ��巽���ˣ�
LONG
	);

	set("exits", ([
		"southeast" : __FILE__,
		"northeast" : __DIR__"wls1",
		"southwest" : __FILE__,
		"northwest" : __FILE__,
		"south"     : __DIR__"wls8",
		"north"     : __DIR__"wls1",
		"west"      : __FILE__,
		"east"      : __DIR__"wls1",
	]));

	set("cost", 3);
	set("outdoors", "dali");
	setup();
}

void init()
{
	add_action("do_say", "say");
	add_action("do_drop", "drop");
}

int do_say(string arg)
{
	object me;
	me=this_player();

	if (arg=="���������շ���")
	{
		if (me->query("got_beiming")
			&& !me->query("ate_hama")
			&& !me->query_temp("tried")) {
			if (random(me->query("kar"))>20) {
				tell_object(me, "�㿪��������ʫ������һ�����񣬽���һ�������������\n");
				me->move(__DIR__"shucong");
				me->set_temp("tried",1);
				return 1;
			}
			me->set_temp("tried",1);
			return 0;
		}
		if (!query("opened")) {
			set("exits/northeast", __DIR__"wls10");
			set("opened",1);
			remove_call_out("closing");
			call_out("closing", 10);
		}
	}
	return 0;
}

void closing()
{
	set("exits/northeast", __DIR__"wls1");
}

int do_drop(object ob)
{
	write("�㲻�ܰ�����������������ݴ����Ҳ����ġ�\n");
	return 1;
}
