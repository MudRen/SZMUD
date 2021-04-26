//Cracked by Roath
// puren.c ���͵�����
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
int ask_weapon();
int ask_armor();
void greeting(object);

void create()
{
	set_name("����", ({ "pu ren", "pu"}));
	set("long", "��\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "����");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 50000);
	set("score", 1000);

	set_skill("force", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("cuff", 70);
	set_skill("sword", 70);
	
	set("inquiry", ([
			"����"   :  (: ask_weapon :),
			"����"   :  (: ask_armor :),
			"��ԭ"   : 	(: ask_leave :),
			"����"   : 	"������������ɽ\n",
			
		]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	
	say("����΢΢һЦ˵������λ" + 
			RANK_D->query_respect(me) + "��ɽ·��Ұ·ʱҪС��Ұ�ޣ��ϻ��Ͷ��߼��˾�ҧ�ġ�\n");
	say("����˵���������Ͽ��е������Ķ���? ��������ʯ�����֦������������ǿ��Ĺ�������\n");
	say("����˵������������������װ���Լ�(wield item)�����û�������ȥ��(buy item)��\n");
	say("����˵���������������м�������Ҫ�Ļ��͸�����(ask pu about ����)��\n");
	say("����˵���������������Щ������������Ƥ��ţƤ��Ƥ���ģ������׵ȵȡ�\n");
	say("����˵������Щ������������ķ����������оͿ촩�ϰ�(wear item)��\n");
	say("����˵�����������Ҳ����һ������Ҫ������Ҫ��(ask pu about ����)��\n");

}
int ask_leave()
{	
	say("����ҡ��ҡͷ˵����û�е���ͬ�⣬��ɲ���˽���뵺��\n");
}
int ask_weapon()
{

}
int ask_armor()
{

}