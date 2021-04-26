// Code of ShenZhou
// Room: /d/shaolin/gulou1.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸��
����������ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ���
�Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ���
�൱�ྻ������������ɮ�˴�ɨ��
LONG
	);

	set("exits", ([
		"up" : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));

	set("objects",([
		"kungfu/class/shaolin/jue-xin" : 1,
	]));
	set("cost", 2);
	setup();
}

void init()
{
	object me, ob;
	int i;

	me = this_player();

	if( !userp(me) ) return;

	if( (me->query("family/family_name") != "������"
	||  me->query("family/generation") > 36
	||  me->query_temp("win_times") < 3)
	&& me->query( "family/master_name") != "����" ) {
		if( objectp(ob = present("juexin", this_object())) )	
			destruct(ob);
		else {
			remove_call_out("make_juexin");
//			call_out("make_juexin", random(600));
			call_out("make_juexin", 1);
		}
	} else {
		if( !objectp(ob = present("juexin", this_object())) ) {
			remove_call_out("make_juexin");
//			call_out("make_juexin", random(600));
			call_out("make_juexin", 1);
		}
		else call_out("dest_juexin", random(600), ob);
	}	

	for( i=1; i<10; i++) {
		if( objectp(ob = present("juexin 2", this_object())) )	
			destruct(ob);
	}
}

int make_juexin()
{
	object ob;

	ob=new("/kungfu/class/shaolin/jue-xin");
	ob->move("/d/shaolin/gulou1");
	message_vision(HIW "\n���Ĵ�ʦ���˹������������£�����΢Ц�����ͷ����ʼ�붨��\n" NOR, ob); 
	call_out("dest_juexin", random(600), ob);
	return 1;
}

int dest_juexin(object ob)
{
	if (!ob) return 1;
	message_vision(HIW "\n���Ĵ�ʦվ�������˻��֣������뿪��\n" NOR, ob); 
	remove_call_out("make_juexin");
	//call_out("make_juexin", random(600));
	destruct(ob);
	return 1;
}


