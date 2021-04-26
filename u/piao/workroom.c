//room:/u/piao/workroom.c
//piao 2001/09/15
#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_kill(string arg);
int do_zhengli(string arg);
int do_job(int stage);
void do_end();
void create()
{
	set("short","�ڰ׹�����");
	set("long",@LONG
����Ʈ�Ĺ����ң����ӵ��а���һ��̴ľ�칫����һ�������Σ��칫
���Ϸ���һ̨���ԡ����濿ǽ������һ���������ӣ����������Ʈ������
�õĸ�������֤�飻������������ܣ����Ϸ��űʼǡ�С˵��ʫ�ļ�֮��
�Ĺ��顣
LONG
	);
	set("no_fight",1);
	set("no_steal",1);
	set("valid_startroom",1);
/*
	set("objects",([
		__DIR__"xiaoyue":1,
		__DIR__"xianger":1,
	]));
*/
        
         set("exits",([
                "gm":"/d/gumu/dating",
                "down":"/d/wizard/wizard_room",
       		"quest":"/d/wizard/quest_r",
		"guide":"/d/wizard/guide_r",
	 ]));
        set("valid_startroom", 1);
        set("no_clean_up",0);
        setup();
        call_other("/clone/board/piao_b","???");
}


void init()
{	
	add_action("do_kill","kill");
	add_action("do_zhengli","zhengli");
	
}
int do_kill(string arg)
{	
	object me = this_player();
	tell_object(me,"���ң���æ���ġ�\n");
	return 1;

}


int do_zhengli(string arg)
{
	object me,ob;
	me = this_player();
	
	if (!me->query_temp("job"))
		return notify_fail("��ô����˼�ͼ������������ء�\n");
	if(!arg||arg!="room")
		return notify_fail("��Ҫ����ʲôѽ��\n");
	if(!(ob = present("laji dai", this_player())))
		return notify_fail("����ʲô������ѽ��\n");

	if((int)me->query("jingli")<20)
		return notify_fail("��̫���ˣ���Ϣһ�°ɡ�\n");
	if (me->query_busy()>0)
		return notify_fail("�㻹æ���ء�\n");	
		message_vision(CYN"$N�����������׷������Ҫ��ɵĹ�������\n"NOR,me);
		me->start_busy(2);
		remove_call_out("do_job");
		call_out("do_job",2,0,me);
		return 1;
}
int do_job(int stage)
{
	int bug;
	object me,gd,ob;
	me = this_player();
	
  	if (stage<0||!objectp(me)) return 1;
	bug = 0;
	switch (stage)
	{
		case 0: bug=1;
			message_vision(CYN"$N����ɨ�㣬��ʼ��ɨ�����ҵĵذ塣\n"NOR,me);
			break;
		case 1: bug=1;
			message_vision(CYN"$N��ˮͰ���ó�Ĩ����š�˼��£���ʼĨ�����Ӻ͵����ϵĻҳ���\n"NOR,me);
			break;
		case 2: bug=1;
			message_vision(CYN"$N��ʼ��������ϵ��鼮��\n"NOR,me);
			break;
		case 3: if(!random(2))  
			{
				bug = 1;
				message_vision(HIY"���ӣ�$N��æ��������������\n"NOR,me);
				gd=new("clone/money/gold");
				gd->move(me);
			}
			else
			{
				bug = 0;
				message_vision(HIY"�ۣ���룡$N��æ�ñ���һ��,������һֻ��룡\n"NOR,me);
			}
			break;		
		case 4: bug =1;
			message_vision(CYN"$N�ѵ��ϵ��ණ����װ�������������ڰѷ���������ˡ�\n"NOR,me);
			ob = present("laji dai",me);
			ob->set_name("������",({"lajidai"}));
			ob->set("long","һֻ��ɫ��������������װ�˲���������\n");
			break;
	}
	if (stage == 4)
	{
		me->start_busy(2);
		remove_call_out("do_end");
		call_out("do_end",2,0,me);
		return 1;
	}
	if (bug == 1) 
		stage++;
		call_out("do_job",10,stage,me);
		me->start_busy(10);
		return 1;
	
}
void do_end()
{
	object me;
	me = this_player();
	message_vision(CYN"$N�������������������԰���������������������ˡ�\n"NOR,me);
 	me->set_temp("zljob",4);
 	return;
}
