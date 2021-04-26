// Code of ShenZhou

#include <ansi.h>
inherit NPC;
#include "/kungfu/class/shaolin/auto_perform.h";
int auto_perform();

string ask_me(object who);

void create()
{
	set_name("Բ���ʦ", ({ "yuanzhen dashi", "yuanzhen" }) );
	set("title", "�����ɵ���ʮ��������");
	set("gender", "����" );
	set("shen_type", -1);
	set("age", 70);
	set("str", 30);
	set("con", 30);
	set("dex", 30);
	set("int", 25);
	set("long",
		"����һ�������������ɮ��һ������տ�֮����\n" );

	set("combat_exp", 1800000);
	set("attitude", "peaceful");
	set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );

	set("inquiry", ([
		"����"   : (: ask_me :),
		"chengkun" : (: ask_me :),
	]) );

        set("max_qi", 3000);
        set("max_jing", 1500);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 100);
        set("class", "bonze");
        set_skill("force", 170);
        set_skill("cuff", 180);
        set_skill("whip", 180);
        set_skill("parry", 180);
        set_skill("dodge", 180);

        set_skill("buddhism", 150);
        set_skill("hunyuan-yiqi", 170);
        set_skill("jingang-quan", 180);
        set_skill("riyue-bian", 180);
        set_skill("shaolin-shenfa", 180);

        map_skill("force", "hunyuan-yiqi");
        map_skill("cuff",  "jingang-quan");
        map_skill("whip",  "riyue-bian");
        map_skill("parry", "riyue-bian");
        map_skill("dodge", "shaolin-shenfa");

        prepare_skill("cuff", "jingang-quan");

	setup();	
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}

string ask_me(object who)
{
	int i;
	object *ob;

	if( query("revealed") ) {
		if( is_killing(who) ) 
			return "���Ȼ֪�����ҵ���֣��������������\n";
		else {
			kill_ob(who);
			who->fight_ob(this_object());
			return "�Ҿ������꽭�����˳Ƶģ���Ԫ�����֣�������\n";
		}
	}

	if( (random(10) < 7) || is_fighting() )
		return "ƶɮʵ�ڶ�ʩ������֮��һ����֪��\n";

	set_temp("apply/armor", 100);
	set_temp("apply/dodge", 100);
//	set_temp("apply/damage",  100);

        set_name("����", ({ "cheng kun", "cheng", "kun" }) );
	set("nickname", HIY "��Ԫ������" NOR);

	message("vision",
		HIW"Բ������ͻȻ�ų������Ĺ�â����Цһ������Ȼ���ѿ��˳�����\n"
		"����Ҳ���������ˣ�������վ���������꣡\n" NOR,
		environment(), this_object() );

	set("pursuer", 1);
	set("attitude", "aggressive");
	set("vendetta/authority", 1);

	set("bellicosity", 10000);

//	set_leader(this_player());
	ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}

	set("revealed", 1);
	return "�Ҿ������꽭�����˳Ƶģ���Ԫ�����֣�������\n";
}

void unconcious()
{
        object obj, me;

        me = this_object();
        if (objectp(obj = me->query_temp("last_damage_from")))
                obj->set_temp("kill_chengkun",1);
        ::unconcious();
}
