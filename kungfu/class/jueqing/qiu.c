// NPC: /d/jueqing/npc/qiuqianchi.c
// Jiuer 08/18/2001

#include <ansi.h>

inherit NPC;

int auto_throw();
int ask_me();

void create()
{
	set_name("��ǧ��", ({ "qiu qianchi", "qiu" }));
	set("long",
"��λ������ͷ��ϡ�裬����ȫͺ�������������ƣ�Ȼ��˫Ŀ��������
������������Ƥ��Ҷ���壬��������ʯ�������������վã��·��������þ�����\n"
);	
	set("title" , "��������");
	set("gender", "Ů��");
	set("age", 45);
	set("per",20);
	set("con",30);
	set("int",30);
	set("str", 28);
	set("dex", 30);
    set("attitude", "peaceful");
	set("shen_type",-1);
	set("combat_exp", 900000);

    set("max_qi", 3000);
	set("qi",3000);
	set("jing",3000);
	set("max_jing",3000);
	set("max_jingli",3000);
	set("jingli",3000);
	set("neili", 4000); 
	set("max_neili", 4000);
	set("jiali", 100);

	set_skill("force",200);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	set_skill("strike",200);
	set_skill("throwing",200);
	set_skill("tie-zhang",230);

	map_skill("force","bixuan-gong");
	map_skill("dodge","shuishangpiao");
	map_skill("strike","tie-zhang");
	map_skill("parry","tie-zhang");
	
	prepare_skill("strike", "tie-zhang");
		
	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
			(: auto_throw :),
	}) );

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 100);
	
	set("inquiry", ([
		"name" : "�����в����գ������������������˳ơ�����������ǧ�ߡ��ı��ǡ�\n",
		"here" : "��֪������ʲô�ط�? \n",
		"С��" : "�Ǹ����ˡ�\n",
		"��������" : "�����ұ���Ů����\n",
		"���鵤" : "�����Ҿ�����������ഫ������黨֮���ĵ�ҩ��\n",
		"��ǧ��" : "�ߣ����ư����������ˮ��Ʈ���������Ҷ��硣\n",
		"��ǧ��" : "�����Ҵ�磬���书ƽƽ,ȴ��������֮����\n",
		"����ֹ" : (: ask_me :),
	]) );

	set_temp("tu",1);
	setup();
        
	carry_object("/clone/anqi/zaohu-ding")->set_amount(5);
}

void init()
{
	object ob = this_player();
	::init();	
	if (interactive(ob = this_player()) && !is_fighting()) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if (!ob || environment(ob) != environment())
		return;
	switch(random(2)) 
	{
	case 0 :
		say("��ǧ�߷���һ���Ц���е������������ǹ����ǹ���������������\n");
		break;
	case 1 :
		say("��ǧ��˵��������ʮ��ǰ�Ҿ���˵������������Ź����������ƣ�����Ҳ�ա���\n");
		break;
	}
}

int ask_me()
{
	object me = this_player();
	message("vision",
		HIY "��ǧ����Цһ���������������Ǹ����������ɷ��ѵ�����������ɱ�ҵ��𡣡�\n"
       "������ǧ����ɱ��" + me->name() +"\n"NOR, environment(), this_object() );
	kill_ob(this_player());
	return 1;
}

int accept_object(object me, object obj)
{
	object obn;

	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(obj) ) return 0;
	if ( !present(obj, me) ) return notify_fail("��û�����������\n");

	if (  (string)obj->query("id") != "tu")
		return notify_fail("ʲô��\n");
	
	if(this_object()->query("tu"))
	{
		command("bite");
		command("say ���㻹����ȥ�͵�ҩ����\n");
		return;
	}
	
	set("tu", 1);
	command("ah");
	message_vision("��ǧ��˵�����ҹ�Ů�����黨����\n
�ͷ���λ"+ RANK_D->query_respect(me)+"���������С����鵤��һö�������ȥ�������ɡ�\n
��Ů�������ࡻ�����ˣ����и����ˡ�\n" , me);
    message_vision("��ǧ�ߴӻ�������һö�����鵤�������㡣\n", me);
    
    obn=new("/clone/drug/jueqing-dan");
    obn->set_amount(1);
    obn->move(me);
	return 1;
}

#include "/clone/npc/auto_throw.h";

