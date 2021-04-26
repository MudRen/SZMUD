// Code of ShenZhou
// 

#include <ansi.h>
inherit NPC;
string ask_midao();

void create()
{
	set_name("С��", ({"xiao zhao", "zhao"}));
	//set("nickname", "");
	set("long", 
		"����Ŀ����ĿС�����Ӻ����Ҳ��Ť�����������У������ɹ��Σ�\n"
		"��״�������ˡ���˫��֮��ϵ��һ��ϸ������˫������Ҳ����һ��������\n");

	set("age", 17 );
	set("gender", "Ů��");
	set("attitude", "heroism");

	set("str", 24);
	set("dex", 16);
	set("per", 34);
	set("shen_type", 0);

	set("max_qi", 500);
	set("max_jing", 500);
	set("neili", 500);
	set("max_neili", 500);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 0);


	set_skill("unarmed", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("blade", 50);
	set_skill("force", 50);

//	set_skill("mofu-wuzong", 0);

	map_skill("dodge", "");

        set("inquiry", ([
                "�ص�" : (:ask_midao:),
                //"�ص�" : (:do_midao :),

        ]) );

        set("chat_chance_combat", 10);
	setup();
	carry_object(__DIR__"obj/lian")->wield();
//	carry_object(__DIR__"obj/")->wear();
}
int init()
{
   ::init();
   add_action("do_cut", "cut");	
   add_action("do_cut", "la");	
}
int do_cut(string arg)
{	object weapon;
	object me = this_player();
	if ( !arg && arg != "lian" && arg != "chain" )
	     return notify_fail( "ʲô��\n");
	if ( !objectp(weapon = me->query_temp("weapon")))
	{  if (me->query("qi") > 500)
	   {	message_vision( "$N��סС��˫��ֻ����������˾����������������ӳ���ȴ�ǲ��ϡ�\n", me);
		message_vision("С�ѽе�����ѽ�����á���Խ��Խ�����ҿɸ��Ӳ���������");
		return 1;
	   }
	   else
	   {	message_vision( "$N˫����סС��˫��ֻ����������þ�һ����ֻ�����˵�һ��������ȴ�ǲ��ϡ�\n", me);
		message_vision("С��˵���������ӹŹֵý������Ǳ������У�Ҳ�������ˡ����ϵ�Կ����С�������");
		return 1;
	   }

	}
   	if ((string)weapon->query("skill_type") != "sword" && (string)weapon->query("skill_type") != "blade" )
	{	
	   message_vision("$N����" + weapon->name() + "�þ����£�ֻ�������һ�������������ǲ��ϡ�\n", me);
	   return 1;
	}
	if ( weapon->name() == "������" || weapon->name() == "���콣" || weapon->name() == "������")
	{
	   message_vision("$Nһ�����е�" + weapon->name() + "����С�����ϵ�������ȥ������Ӧ�ֱ������ˡ�\n", me);
	   me->set_temp("marks/��", 1);
	   return 1;
	}

	
}
int ask_midao()
{	
	object me = this_player();
	if ((int)me->query_temp("marks/��"))
	{  write("С��ҧ���´���΢һ�����������������ã��Ҵ���ȥ����\n");
	   me->set_temp("marks/��", 1);
	   me->delete_temp("marks/��");
	   return 1;
	}
	else
	{  write("С��ҡ��ҡͷ˵������֪������\n";
	   return 0;
	}
}
