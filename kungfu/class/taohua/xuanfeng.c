// Code of ShenZhou
// .

inherit NPC;
#include <ansi.h>
int auto_perform();

void create()
{
	set_name("������", ({ "chen xuanfeng", "chen", "xuanfeng" }));
	set_weight(60000000);
	set("title", "�ڷ�˫ɷ");
	set("nickname", HIY"ͭʬ"NOR);
	set("long", 
"�����ǻ�ҩʦ�Ĵ���ӣ���Ũü���ۣ���������������׳����ֻ��\n"
"��ɫ΢΢���ơ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("str", 22);
	set("int", 23);
	set("con", 25);
	set("dex", 20);
	
	set("max_qi", 1500);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("combat_exp", 800000);

	set_skill("force", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
	set_skill("sword", 130);
        set_skill("qimen-dunjia", 130);
	set_skill("strike", 130);
	set_skill("luoying-shenjian", 130);
	set_skill("cuixin-zhang",140);
	set_skill("claw", 140);
	set_skill("yuxiao-jian", 130);
	set_skill("bitao-xuangong", 130);
	set_skill("luoying-shenfa", 140);
	set_skill("kick", 130);
	set_skill("xuanfeng-saoye", 130);
	set_skill("jiuyin-zhao", 140);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "jiuyin-zhao");
	map_skill("sword", "yuxiao-jian");
	map_skill("claw", "jiuyin-zhao");
	map_skill("dodge", "luoying-shenfa");
	map_skill("kick", "xuanfeng-saoye");
	map_skill("strike", "cuixin-zhang");
	
	prepare_skill("strike", "cuixin-zhang");
/*	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_perform :),
        }) );
*/
	create_family("�һ���", 2, "����");

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
}


//void unconcious()
void die()
{
        object obj, me;
        int i, flag;

	flag = 0;
	me = this_object();
        if (objectp(obj = me->query_temp("last_damage_from")))
		obj->set_temp("kill_xuanfeng",1);
	else
		return;
	
	if (obj->query_temp("kill_chaofeng")) {
		obj->set("kill_th_traitor",1);
		flag = 1;
	}

        if (flag) 
	message_vision(HIR"������Һ�һ����������������������ˣ�����\n"NOR, this_object());
	else 
	message_vision(HIR"������Һ�һ����������������ұ��𣡣���\n"NOR, this_object());
        
	::die();
}
