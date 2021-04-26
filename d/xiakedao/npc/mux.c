//Cracked by Kafei
// mux.c ���͵��Դ�
// Long, 6/13/97

#include <ansi.h>

inherit NPC;
string* whattotell = ({
	" ���Ѿ�ǩ�����ˣ���ȥ��Ϣ��ɡ����������ĵ������������",
	" �������Ҹ����ɡ�",
	" �����Ǹ����û���������㡣", 
	" ǩ��ǩ����", 
	" ����ѽ�㡣", 
	" �ٲ�ǩ���ҿ�Ҫ���ˡ�", 
	" ����ǩ����ǩ�����Ҹ����ǳԡ�", 	
});

int ask_leave();
int ask_food();
int ask_daozhu();
void greeting(object);
void checking();
string* fname = ({
	"yi","er", "san", "si", "wu", "liu", "qi", "ba", "jiu",
});

void create()
{	int i = random(8)+1;
	
	set_name("ľ��" + chinese_number(i), ({ "mu lao" + fname[i-1], "mu"}));
	set("long", "
��������ݣ�ͷȴ��󣬿���ȥ����һ��ϸ��˶���һ�������ϡ���
�����们������һ�������ݣ��ŵ��㲻��Ц������\n");
	set("nickname", "�Ǽ�ʹ");
	set("gender", "����");
	set("age", random(50) + 30);
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
      object me = this_player();
      add_action("do_register", "register");
	::init();
      if( interactive(me) )
      {	remove_call_out("greeting");
            call_out("greeting", 1, me);
	}
//	remove_call_out("checking");
//	call_out("checking", 30);
}

void greeting(object me)
{	command("say �������͵��Ĺ����ң��������͵�����Ҫ�����ﱨ������\n" + 
	"    ������ֵ������⵱�ࡣ�뵽������Ǹ��ǰɣ��Ǽǵ�ָ�\n" +
 "    " + HBGRN+HIW"register �����������������ʵ�� email (������bbs email)��\n"NOR +
"		"+ BRED+HIW"(register xxxxx@yyyy.zzz)\n"NOR+
     CYN"    ǧ�����д��������Ը���");
	me->set_temp("xkd/sign", 1);
}
void checking()
{	object *players;
	object me = this_object();
	int count;
	int times;
	players = all_inventory(environment(me));
	for (count = 0 ; count <sizeof(players); count ++)
	{	if ((string)players[count]->query("race") == "����"  && players[count] != me )
		{	if (players[count]->query_temp("registered"))
			{	command("tell " + players[count]->query("id") + whattotell[0]);
			}
			else
			{
				times = (int)players[count]->query_temp("xkd/sign");
				//command("say " + (string)times + ", " + (string)sizeof(whattotell));
				if (times >= sizeof(whattotell)-1)
				{	times = 1;			}
				else
				{	times = times + 1;	}
				command("tell " + players[count]->query("id") + whattotell[times]);
				players[count]->set_temp("xkd/sign", times);
			}
		}
	}
	remove_call_out("checking");
	call_out("checking", 15);
	return;
}
int check_register(object ob)
{
        if (!ob->is_character())
                return notify_fail("������Ǵ����Ү��\n");
        if (!ob->query("id"))
                return notify_fail("��Ĵ�����ʲô��\n");
        if (!ob->query("name") || strsrch(ob->query("name"), "����") != -1)
                return notify_fail("�������������ʲô��\n");
        if (!ob->query("gender"))
                return notify_fail("����Ա���ʲô��\n");
        return 1;
}

int do_register(string arg)
{
	object ob;
	string pass;
	int bid;
        
                
      if (!check_register(this_player()))
      	return 0;

	if (!arg)
		return notify_fail("���ĵ����ʼ���ַ��ʲô��\n");
	bid = REGI_D->is_banned_email(arg);
	if (bid > 1)
		return notify_fail("��˵�ĵ����ʼ���ַ�ѱ�����ˡ�\n");
	if (bid > 0)
		return notify_fail("��������ȷ�ĵ����ʼ���ַ��\n");
	if (!(ob = this_player()->query_temp("link_ob")))
		return notify_fail("�����ʺų���Щ���⣬������ʦ��ȡ�\n");
      if (this_object()->query_temp("iambusy"))
              return notify_fail("�𼱱𼱣�һ��һ��������\n");

	this_object()->set_temp("iambusy", 1);
	ob->set("name", this_player()->query("name"));
	ob->save();
	REGI_D->register_char(this_player()->query("id"), arg);
//	this_player()->delete_temp("xkd/sign");
//	this_player()->set_temp("registered", 1);
	this_object()->delete_temp("iambusy");
	return 1;
}
