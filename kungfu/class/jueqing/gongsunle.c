// Filename:  gongsun lve ��������
// path:      /kungfu/class/jueqinggu/npc/gongsunle.c
// By jiuer-> 08/2001

#include <ansi.h>
inherit NPC;
void greeting(object);

void create()
{
	set_name("��������", ({ "gongsun lue", "gongsun", "lue" }));
	set("long",
		"�����Ǿ����ˮ��ׯׯ����Ů����\n\n"
		+"ֻ������ɫ���ﷺ�죬�����쳣��üĿ���ţ������峺���������СС���룬���ǽ�����\n\n");

	set("gender", "Ů��" );
	set("age", 17);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("inquiry", ([
		"name" : "�����ҿɲ�֪�������ҵ����������Ķ���Ů��ȡ�����֣��������ࡣ��\n",
		"here" : "��ׯ�С�ˮ��ɽׯ������Ƚ���������ȡ���\n",
		"ˮ��ɽׯ" : "��ɽׯ�ɺ����ţ������ҵ������ң����ﻹ���黨��\n",
		"����" : "�ҵ����ǹ���ֹ��\n",
		"����ֹ" : "�����ҵ�����\n",
		"��" : "����������˳ơ�����������ǧ�ߡ���\n",
		"��ǧ��" : "������������������ˣ�˵��������������ˮ��\n",
		"�黨"   : "�黨�Ĵ����ж����˶�������֮���ʱʹ���ɵ���ֻ�о��鵤���εúá�\n",
		"���鵤" : "�����Ҿ�����������ഫ������黨֮���ĵ�ҩ�������ղصĽ���\n",
		"�����" : "�����ȿɴ����ģ���֪�ж����˽�ȥ��û��������\n",
		"��Ů��" : "����Ů���������統���͸�С��������ġ�\n",
	]));

	set("combat_exp", 100000); 
	set("per", 28); 
	set("str", 22); 
	set("int", 28);
	set("con", 25);

	set("chat_chance",1);
	set("chat_msg", ({
			"���������ժ�������黨��������С�\n",
			"����վ���黨���£�������ͷ������������һ��̾Ϣ��һ������������������\n",
	}) );

	set("max_qi", 1000);
	set("max_jing", 1000);
	set("jiajin", 10);
	set("jiali", 10);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jingli",1000);
	set("eff_jingli",1000);
	set("max_jingli",1000);

	set_skill("force", 100); 
	set_skill("blade", 100);
	set_skill("dodge", 100); 
	set_skill("parry", 100);
	set_skill("sword", 100);

	set_temp("apply/attack", 100);
	set_temp("apply/defense", 100);
	set_temp("apply/damage", 100);
	setup(); 
	
	carry_object("/d/jueqing/npc/obj/greenrobe")->wear(); 
	carry_object("/d/jueqing/npc/obj/pihuwan")->wear(); 
	carry_object("/d/city/obj/changjian")->wield();
}

void init()
{
	object ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if(!ob || environment(ob) != environment())
		return;
	say("����˵��: �������䱸ɭ�ϣ�����ô�������ˣ������ȥ�ɣ���\n");
}

int accept_object(object me, object ob)
{
	object obn;

	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, me) ) return notify_fail("��û�����������\n");

	if (  (string)ob->query("id") != "longnu hua")
		return notify_fail("���಻��Ҫ���������\n");
	
	if(this_object()->query("longhua"))
	{
		command("say ���⻨���׶��˾����ˣ��㻹�ǿ�ȥ������ɡ���\n");
		command("drop hua");
		return 1;
	}
	set("longhua",1);       
	write( HIY "����˫��������Ů�����������£�\n
   �����磬���ǲ��ǻ��ǹ������డ��~~��~~��\n\n" NOR );

	message_vision( HIY "����Ĩ�˰����ᣬ������˼ЦЦ˵������λ"
	+RANK_D->query_respect(me)+"��Ц�ˡ�\n
��Ҳûʲô�������㣬�����Һ��������ݾ���ȣ��⼸���������ϡ���\n\n" NOR, me);

    message_vision("������������һ���ɰ���������ȡ��һ��ذ�׺�һ����Ƥ�ݸ���$N��\n", me);
	command("whisper "+me->query("id")+" �����ŵ�ͼ�ߣ����������ͼ��������");
	
	obn = new("/d/jueqing/npc/obj/tu");
	obn->set_amount(1);
	obn->move(me);
    obn = new("/d/jueqing/npc/obj/bishou");
	obn->set_amount(1);
	obn->move(me);
      return 1;
}