// Code of ShenZhou
//Ryu 6/22/97;
#include <ansi.h>;
inherit NPC;
string ask_me(object who);
int auto_perform();

void create()
{
	set_name("��ʦ��", ({ "he shiwo", "he", "shiwo" }));
	set("shen_type", -1);
	set("title", "ؤ���������");
	set("attitude", "peaceful");

	set("str", 30);
	set("con", 30);
	set("dex", 28);
	set("gender", "����");
	set("age", 35);
	set("long",
		"��������һ��������õĺ��£���ͷ�ҷ���һ��������ӷ�ף�͹͹�������ǰ̺ۡ�\n");
	set("combat_exp", 800000);
        set("max_qi", 1600);
        set("max_jing", 800);  
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);

        set_skill("force", 150);
	set_skill("longxiang-banruo", 150);
	set_skill("shenkongxing", 150);
	set_skill("staff", 150);
	set_skill("shexing-diaoshou", 150);
	set_skill("hand",150);
        set_skill("dodge", 150);
        set_skill("parry", 150);
	set_skill("stick", 300);
	set_skill("jingang-chu", 150);

	map_skill("force", "longxiang-banruo");
        map_skill("dodge", "shenkongxing");
        map_skill("hand", "shexing-diaoshou");
	map_skill("staff", "jingang-chu");

        prepare_skill("hand", "shexing-diaoshou");

	set("attitude", "friendly");
	set("inquiry", ([
		"����" : (: ask_me :),
		"�ɹ�����" : (: ask_me :),
	]));
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );	
	set("vendor_goods", ({
		__DIR__"obj/shaobing",
		__DIR__"obj/youtiao",
	}));

	setup();
	carry_object("/clone/weapon/tiezhang")->wield();
	carry_object("/d/gaibang/obj/budai")->set_amount(5);
	carry_object("/d/gaibang/obj/budai")->wear();
}

string ask_me(object who)
{
        int i;
	object cake;
	if (query("asked")) return ("�ٷϻ���\n");

        if( (random(10) < 5) || is_fighting() )
                return "�ҡ���֪����\n";

        message("vision",
		"��ʦ�ҵ������Ȼ֪�����ӵ����֣��ͻỵ�Ҵ��£��������ɣ�\n"
                "�������һ�����е�������Ȼ��ˣ����ӽ��췴�����ȥ������ƴ�ˡ���\n" ,
                environment(), this_object() );

        set_name("����", ({ "huodu", "huo"}));
	kill_ob(this_player());
	command("follow " + this_player()->query("id"));
	command("drop tiezhang");
	message_vision(HIM"�����������ͳ�һ��ߡ�ȣ�һ�ӣ����˿�����¶������һ�使�����ε�ĵ����\n"NOR, this_object());
        carry_object("/clone/unique/fan")->wield();
	carry_object("/d/gaibang/obj/yuzhu-zhang");
        return "���Ȼ֪�����ӵ����֣��ͻỵ�Ҵ��£��������ɣ�\n";
}

void unconcious()
{
	object ob = this_object();

        message_vision("\n$NͻȻ��һ����������սȦ�����ˣ�\n", ob);
	destruct(ob);
}
int auto_perform()
{
        object me = this_object();
        object weapon1, target = me->select_opponent();
        object weapon = me->query_temp("weapon");

        if ( !objectp(target)
          || !random( (int)me->query("combat_exp") * 2
                   / (int)target->query("combat_exp") + 1) ) return 0;

        if ( objectp(weapon) ) {
        if ( weapon->query("skill_type") == "stick" )
	if( objectp(weapon1 = target->query_temp("weapon")))
        command("break " + target->query("id"));

	command("shoot " + target->query("id"));
        }
        return 1;
}

