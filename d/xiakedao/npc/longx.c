//Cracked by Roath
// longx.c ���͵���
// Long, 6/13/97

#include <ansi.h>

inherit NPC;
object me;
string* commands = ({
	"north",
	"north",
	"northup",
	"climb tree", 
	"remove cloth",
	"wear coat",
	"jump fall",
	"east",
	"north",
});
string* places = ({
	"/d/xiakedao/shanlu1",
	"/d/xiakedao/shanlu2",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/pubu",
	"/d/xiakedao/yongdao1",
	"/d/xiakedao/yongdao3",
	"/d/xiakedao/dadong",
});
string* fname = ({
	" yi"," er", " san", " si", " wu", " liu", " qi", " ba", " jiu",
});

string* wait = ({
	" �����ڶ���������" + RANK_D->query_self(this_object()) + "���ɡ�",
	" �������Ƽݵ����Ͷ����ٷ����ɡ�", 	
});

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting();
void checking();
void check_follow(object, int);
void create()
{	int i;
	i = random(8) + 1;
	set_name("��" + chinese_number(i), ({ "long" + fname[i-1]}));
	set("long", "�������͵����������µ�һ�����ӡ����ϴ���ϴ�÷��׵Ľ��£�
ͷ�ϴ������ñ��һ����������������ῴҲ�����Ǹ��������ˡ�\n");
	set("nickname", "��·ʹ");
	set("gender", "����");
	set("age", random(30) + 20);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "����");	
	set("max_qi", 1500);
	set("eff_qi", 1500);
	set("qi", 1500);
	set("max_jing", 1500);
	set("eff_jing", 1500);
	set("jing", 1500);
	set("max_neili", 1500);
	set("eff_neili", 1500);
	set("neili", 1500);
	set("max_jingli", 1500);
	set("eff_jingli", 1500);
	set("jingli", 1500);
	set("combat_exp", 300000 + random(5) * 100000);
	set("score", 1000);
	
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);
	set_skill("taiji-shengong", 150);
	set_skill("liuxing-bu", 150);
	set_skill("wugou-jianfa", 150);
	set_skill("wuyu-zhangfa", 150);

      map_skill("force", "taiji-shengong");
	map_skill("sword", "wugou-jianfa");
	map_skill("parry", "wugou-jianfa");
	map_skill("dodge", "liuxing-bu");
	map_skill("strike", "wuyu-zhangfa");
	
	prepare_skill("strike", "wuyu-zhangfa");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object(__DIR__"obj/yellowrobe")->wear();

}
void init()
{
      me = this_player();
	::init();
      if( interactive(me) )
      {	//command("say " + query_temp("xkd/guest") + " -- " + me->query("id"));
		if (query_temp("xkd/guest") == me->query("id"))
		{	remove_call_out("greeting");
            	call_out("greeting", 0);
		}
	}
	//remove_call_out("checking");
	//call_out("checking", 5);
}

void greeting()
{	
	me = present(query_temp("xkd/guest"), environment(this_object()));
//	command("say " + me->query("id"));
	if (!(me->query_leader() == this_object()))
	{	command("hi " + query_temp("xkd/guest"));
		command("say " + RANK_D->query_self(this_object()) + query("name") + 
			"���֮���ڴ˹�ӭ��ݣ�" + RANK_D->query_respect(me) + "���������\n" +
			"    "+HBRED+HIW"(follow " + query("id") + ")"NOR);	
		remove_call_out("check_follow");
		call_out("check_follow", 20, me, 0);
		return;
	}
}
void check_follow(object me, int count)
{	int i;
	object long = this_object();
    	if( !(find_player(query_temp("xkd/guest"))))
	{	command("say ����Ҳ���ǵģ�һת�۾Ͳ�֪����ȥ�ˡ�");
		message_vision("$N˵��ת����ȥ�ˡ�\n", long);
		remove_call_out("check_follow");
		destruct(long);
		return;
	}
	if (me->query_leader() == this_object())
	{	remove_call_out("move_next");
		call_out("move_next", 1, me, 0);
	}
	else
	{	if ( count > 2 )
		{	message("vision", long->name() + "��֪���ı��˳���������" + me->name() + "���֣�����һ���㲻����\n", environment(me), ({me}));
			tell_object(me, long->name() + "��֪���ı��˳�������������ֱ��߱���Թ����������ҵģ������ܣ����ɡ�\n");
			me->move(environment(long));
			me->set_leader(long);
			remove_call_out("check_follow");
			call_out("check_follow", 1, me, count);
		}
		else
		{
			i = random(sizeof(wait));
			command("tell " + me->query("id") + wait[i]);
			count = count + 1;
			remove_call_out("check_follow");
			call_out("check_follow", 10, me, count);
		}
	}
	return;
}
void move_next(object me, int count)
{	object long = this_object();
    	if( !(objectp(me=find_player(query_temp("xkd/guest")))))
	{	command("say ����Ҳ���ǵģ�һת�۾Ͳ�֪����ȥ�ˡ�");
		message_vision("$N˵��ת����ȥ�ˡ�\n", this_object());
		remove_call_out("check_follow");
		destruct(this_object());
		return;
	}
	if (count >= sizeof(commands))
	{	command("say " + RANK_D->query_respect(me) + "���������Ժ򣬵���һ��㵽��");
		command("bye " + me->query("id"));
		me->set("xkd/hosted", 1);
		message_vision("$N˵����˻��֣�ת����ȥ�ˡ�\n", long);
		destruct(long);
		return;
	}
	command(commands[count]);
	if (!(present(me, environment(long))))
	{	message("vision", long->name() + "��֪���ı��˳���������" + me->name() + "���֣�����һ���㲻����\n", environment(me), ({me}));
		tell_object(me, long->name() + "��֪���ı��˳�������������ֱ��߱���Թ����������ҵģ������ܣ����ɡ�\n");
		//message_vision("$N��֪���ı��˳�������Թ�����������ҵģ������ܣ����ɡ�\n", long);
		me->move(places[count]);
		remove_call_out("move_next");
		call_out("move_next", 10, me, count);
	}
	count = count + 1;
	remove_call_out("move_next");
	call_out("move_next", 10, me, count);
	return;
}
