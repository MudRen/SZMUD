// Code of ShenZhou
// Room: /d/dali/dinganfu5.c

inherit ROOM;

int serve();

void create()
{
	set("short", "�﷿");
	set("long", @LONG
�����ǹ�լ�Ļ﷿��רΪס������Ĺ�Ա���ṩ��ʳ(serve)��һȺ���ž�
���Ĺ�Ա��Χ�����ӾͲͣ�Ʒ�������ز��Ĳ��ȡ���Ա����������Բ������Ƶ�
�Ժ�Ҫ�ˣ��������ʳ�����������
LONG);
	set("exits", ([
		"north" : __DIR__"dinganfu2",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
}
void init()
{
	add_action("do_serve", "serve");
}
int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N�����ҪЩʳ��Ժȡ�\n", me);

	if (me->query("family/family_name") != "����μ�"
		&& !me->query("dali/employee")) return 1;

	if (!present("guoqiao mixian", environment(me))
		&& !present("guoqiao heiyu", environment(me))
		&& !present("ye er ba", environment(me))
		&& !present("guoqiao mixian", me)
		&& !present("guoqiao heiyu", me)
		&& !present("ye er ba", me))
	{
		switch(random(3))
		{
			case 0:
				ob=new(__DIR__"obj/mixian");
				break;
			case 1:
				ob=new(__DIR__"obj/guoqiao");
				break;
			case 2:
				ob=new(__DIR__"obj/yeerba");
				break;
		}    
		ob->move(environment(me));
		message_vision("���Ӷ˳�"+ob->name()+"��$N�����������ԣ��������С���\n", me);
	}
	else message_vision("���Ӷ�$N˵�����㲻���ж������𣬳�����˵�ɡ�\n", me);
	
	if (!present("puer cha", environment(me))
		&& !present("qiguo ji", environment(me))
		&& !present("qiguo ji", me)
		&& !present("puer cha", me))
	{
		switch(random(2))
		{
			case 0:
				ob=new(__DIR__"obj/qiguoji");
				break;
			case 1:
				ob=new(__DIR__"obj/puercha");
				break;
		}
		ob->move(environment(me));
		message_vision("���Ӷ˳�"+ob->name()+"��$N�����������ȣ��������С���\n", me);
	}
	else message_vision("���Ӷ�$N˵�����㲻���ж������𣿺�����˵�ɡ�\n", me);
	return 1;
}

int valid_leave(object me, string dir)
{
	if (present("guoqiao mixian", me)
		|| present("guoqiao heiyu", me)
		|| present("qiguo ji", me)
		|| present("ye er ba", me)
		|| present("puer cha", me))
		return notify_fail("����������˵���������ǳ������߰ɡ���\n");
	return ::valid_leave(me, dir);
}
