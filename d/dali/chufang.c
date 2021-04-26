// Code of ShenZhou
// chufang.c

inherit ROOM;

int serve();

void create()
{
	set("short", "�﷿");
	set("long", @LONG
�����ǹ�լ�Ļ﷿��רΪס������Ĺ�Ա���ṩ��ʳ(serve)��һ
Ⱥ���ž����Ĺ�Ա��Χ�����ӾͲͣ�Ʒ�������ز��Ĳ��ȡ���Ա����
������Բ������ƵسԺ�Ҫ�ˣ��������ʳ�����������
LONG
	);

	set("exits", ([
		"north" : __DIR__"diziarea.c",
	]));
	
	setup();
}

void init()
{
/*	object ob=this_player();

	if (userp(ob) && !wizardp(ob) && ob->query("family/family_name") != "����μ�") {
		message_vision("���������Ҷ����˽����������µ�����$N�㲻�Ǵ�����ˣ���ô�����������ˣ������ȥ��\n",ob);
		remove_call_out("kickout");
		call_out("kickout", 1, ob);
	}
*/
	add_action("do_serve", "serve");
}
/*
int kickout(object ob)
{
	if (!present(ob,find_object("/d/dali/chufang.c"))) {
		return 1;
	}
	message_vision("һȺ��ʿ��ӵ���ϰ�$N�ҹ����˳�ȥ��\n",ob);
	ob->move("/d/dali/taihejie5");
	message("vision","ֻ����ƹ����һ����"+ob->query("name")+"�������ﱻ���ҹ����˳�����\n", environment(ob), ob);
	ob->apply_condition("dalikiller",100);
	return 1;
}
*/
int do_serve()
{
	object ob,me;
	me=this_player();

	message_vision("$N�����ҪЩʳ��Ժȡ�\n", me);

	if (me->query("family/family_name") != "����μ�"
		&& !me->query("dali/employee"))
		return 1;

	if (!present("guoqiao mixian", environment(me))
		&& !present("guoqiao heiyu", environment(me))
		&& !present("ye er ba", environment(me))
		&& !present("guoqiao mixian", me)
		&& !present("guoqiao heiyu", me)
		&& !present("ye er ba", me))
	{
		switch(random(3)) {
		case 0:
			ob=new("/d/dali/obj/mixian");
			break;
		case 1:
			ob=new("/d/dali/obj/guoqiao");
			break;
		case 2:
			ob=new("/d/dali/obj/yeerba");
			break;
		}    
		ob->move(environment(me));
		message_vision("���Ӷ˳�"+ob->name()+"��$N�����������ԣ��������С���\n", me);
	}
	else message_vision("���Ӷ�$N˵�����㲻���ж������𣬳�����˵�ɡ�\n", me);
	
	if (!present("puer cha", environment(me))
		&& !present("qiguo ji", environment(me))
		&& !present("qiguo ji", me)
		&& !present("puer cha", me)) {
		switch(random(2)) {
		case 0:
			ob=new("/d/dali/obj/qiguoji");
			break;
		case 1:
			ob=new("/d/dali/obj/puercha");
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
