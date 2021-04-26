//                ��׼��������ʾ��                                   |
// �κεĹ����ң������档�򵥶�ʵ�ڣ�������ҫ����  /u/naihe/naihe_room.c
// by naihe  2002-07-04

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",BLU"�嶥С��"NOR);
	set("long",@LONG
������ӿյ����ģ��Ŷ���ǽ�ϵ�һֻ������ƹⲻ��ҡҷ����ԭ�ȵ�����
��֪�Ӻη������ķ�Ҳƽ�������ˡ����°ڷŵ�һ��ľ����Ȼ����ص�����һЩ
�鼮���·������Ӻ���ͷ����ͷ�������ŵ�Ƕ��Сľ�������Ƭ��Ҳ�ƺ�������
ǰ�Ƿ��ˡ������ﲻ��������ĳ��ţ������������ǻ�����˼���ţ��о�ƽ����
ȴ����ǧ˿���Ƶ���ͷ��ӿ������
LONG
	);
	set("valid_startroom", 1);
	set("no_clean_up","1");  // ��仰��û���κ�����ģ�Ҫ�����·��䣬Ψ���ñ�ķ�����
	set("item_desc",([
            "photo":"����һ��Ŀ���������ͷ����д��Ƭ����ȴ������������˼����ʲô��\n",
	    "zhaopian":"����һ��Ŀ���������ͷ����д��Ƭ����ȴ������������˼����ʲô��\n",
	    "bed":"һ��Сľ�����ƺ��ܾ�û��˯���ˣ�ȴ�ƺ���ɢ����ĳ�����ĵ�������\n",
	    "muchuang":"һ��Сľ�����ƺ��ܾ�û��˯���ˣ�ȴ�ƺ���ɢ����ĳ�����ĵ�������\n",
	    "bulb":"ԭ������һ��װ�����ű�ʯ�ĵ��ݣ��ѹֻ���˳־�ɢ���Ź�â��\n",
	    "dengpao":"ԭ������һ��װ�����ű�ʯ�ĵ��ݣ��ѹֻ���˳־�ɢ���Ź�â��\n",
	    "quilt":"һ���ޱ������ŵ���������ء�\n",
	    "beizi":"һ���ޱ������ŵ���������ء�\n",
	    "book":"һЩ�鼮���������Ǳ������ƺ��Ǹ�����Ů�ӣ����ġ�����\n",
	    "shuji":"һЩ�鼮���������Ǳ������ƺ��Ǹ�����Ů�ӣ����ġ�����\n",
	    "yifu":"�����·���ûʲô�ر�֮����\n",
	    "cloth":"�����·���ûʲô�ر�֮����\n",
	    "pillow":"һ��С�����ϱ߾�����һ˿�����㷢��\n",
	    "zhentou":"һ��С�����ϱ߾�����һ˿�����㷢��\n",
	]));
	set("exits",([
	    "out":"/d/huashan/fengding",
//	    "dc":"/clone/misc/naihe/dc_dating",
//	    "west":"/u/spark/spark_room",
	]));

	setup();
	call_other("/clone/board/naihe_b","???");

}

void init()
{
	add_action("do_sleep","sleep");
	add_action("do_meeting","meeting");
	if(this_player()->query("id")=="naihe" || wizardp(this_player()))
	{
		add_action("do_note","note");
		add_action("do_armor","armor");
		add_action("do_gem","gem");
	}

	if(this_player()->query("id")!="naihe")
	{
		add_action("do_nomore","more");
		add_action("do_nomore","cat");
	}
}

int do_sleep()
{
	object me=this_player();
	int jing,jingli,neili,qi;

	if(me->query("id")=="naihe" && me->query("name")=="�κ�")
		message_vision(""MAG"$N�������򴲱ߣ�����ЪϢ��Ƭ�̡�"NOR"\n",me);

	if(me->query("id")=="spark" && me->query("name")=="��˸")
		message_vision(""MAG"$N�Ჽ���򴲱ߣ�����ЪϢ��Ƭ�̡�"NOR"\n",me);

	if(me->query("id")!="naihe" && me->query("id")!="spark")
	{
		write("�ѵ������ɱ��˵Ĵ���ȥ˯��̫����ò�˰ɡ�\n");
		message("vision",""CYN""+me->query("name")+"�ڴ���������ȥ���ƺ�������˯һ����\n"NOR,environment(me),me);
		return 1;
	}

	jing=me->query("max_jing");
	jingli=me->query("max_jingli");
	neili=me->query("max_neili");
	qi=me->query("max_qi");

	message_vision(""MAG"$NС����������þ������ȡ�"NOR"\n",me);

	me->set("jingli",jingli);
	me->set("jing",jing);
	me->set("neili",neili);
	me->set("qi",qi);

	return 1;
}



int do_gem()
{
	object me,ob;
	ob=new(__DIR__"obj/gem");
	me=this_player();

	message_vision(""CYN"$N�ڱ��Ӷ��������ͣ��ͳ���һ"+ob->query("unit")+ob->query("name")+"��"NOR"\n",me);
	ob->move(me);
	return 1;
}

int do_nomore()
{
	write(""BLU"���������һ���������ĵ�˵������������ô���������ء�����"NOR"\n");
	write("��һ���Ӵ�ס�ˣ���Ȼ�������Լ���Ҫ��ʲô��\n");
	return 1;
}

int do_note()
{
	object me=this_player();

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		new(__DIR__"obj/note_naihe")->move(me);
		message_vision(""BLU"$N��ǽ�������ģ�����ƾ�յ�����һ��С���ӣ�$N��æ��ס�����ù���Ī����"NOR"\n",this_player());
		return 1;
	}

	return 0;
}

int do_armor()
{
	object me,oba,obb,obc,obd,obe,obf;
	me=this_player();
	oba=new(__DIR__"obj/anyue-jian");
	obb=new(__DIR__"obj/ay-cloth");
	obc=new(__DIR__"obj/ay-pifeng");
	obd=new(__DIR__"obj/ay-kui");
	obe=new(__DIR__"obj/ay-ring");
	obf=present("cloth",me);

	if(me->query("id")=="naihe" || me->query("id")=="spark" || wizardp(me))
	{
		message_vision(""CYN"$N��ǽ�������ģ�ֻ�����м���שͷ���˽�ȥ��¶����һ��С����\n$N��С�����ó���һ����װ������������ǽ�ϣ�שͷ�ػ�ԭ����С������������"NOR"\n",me);

		if(!present("anyue jian",me)) oba->move(me);
		if(!present("anyue cloth",me)) obb->move(me);
		if(!present("anyue manteau",me)) obc->move(me);
		if(!present("anyue kui",me)) obd->move(me);
		if(!present("anyue ring",me)) obe->move(me);
		if(present("cloth",me)) destruct(obf);

		write("all armor ok.\n");
		return 1;
	}
	message_vision(""CYN"$N��ǽ���������ģ������ģ������Ҳ���С�������"NOR"\n",me);
	return 1;
}

int do_meeting()
{
	object me=this_player();
	string name=me->query("name");

	message("vision",name+"��˽�������������˽�ȥ��\n"NOR,environment(me),me);
	tell_object(me,"����˽�������������˽�ȥ��\n");
	me->move(__DIR__"naihe_meetingroom");
	message("vision",name+"���˹�����\n"NOR,environment(me),me);
	return 1;
}
