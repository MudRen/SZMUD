// Code of ShenZhou
// .

inherit NPC;
#include <ansi.h>
int auto_perform();

void create()
{
        set_name("÷����", ({ "mei chaofeng", "mei", "chaofeng" }));
	set_weight(60000000);
        set("title", "�ڷ�˫ɷ");
        set("nickname", HIB"��ʬ"NOR);
        set("long",
"���ǻ�ҩʦ�Ķ�����÷���磬����ɫ�����Ϊ�þӺ����Ե���ڣ�\n"
"ģ��ȴ��Ϊ�����������һ��������Ⱦ�ͨ�޷���\n");
        set("gender", "Ů��");	
	set("age", 35);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("str", 20);
	set("int", 23);
	set("con", 20);
	set("dex", 25);
	
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 1800);
	set("max_neili", 1800);
	set("combat_exp", 800000);

	set_skill("force", 130);
	set_skill("dodge", 130);
	set_skill("parry", 130);
        set_skill("whip", 140);
	set_skill("claw", 140);
	set_skill("canglang-bian", 140);
	set_skill("bitao-xuangong", 130);
	set_skill("luoying-shenfa", 140);
	set_skill("jiuyin-zhao", 140);
	set_skill("strike", 140);
	set_skill("cuixin-zhang",140);

	map_skill("force", "bitao-xuangong");
	map_skill("parry", "jiuyin-zhao");
	map_skill("whip", "canglang-bian");
	map_skill("claw", "jiuyin-zhao");
	map_skill("dodge", "luoying-shenfa");
	map_skill("strike", "cuixin-zhang");

	prepare_skill("claw", "jiuyin-zhao");

/*	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: auto_perform :),
	}) );
*/
	create_family("�һ���", 2, "����");

	setup();
	carry_object("/d/xixia/obj/robe")->wear();
	if (clonep()) carry_object("/clone/unique/dulong-bian", 
				"/clone/weapon/changbian");
}


void die()
{
	object obj, me;
	int i, flag;

	flag = 0;
	me = this_object();
	if (objectp(obj = me->query_temp("last_damage_from")))
		obj->set_temp("kill_chaofeng",1);
	else 
		return;
        
	if (obj->query_temp("kill_xuanfeng")) {
		obj->set("kill_th_traitor",1);
		flag = 1;
	}
	
	if (flag) 
	message_vision(HIR"÷����ҽ�һ�������������ӣ����������ˣ�����\n"NOR, this_object());
	else 
	message_vision(HIR"÷����ҽ�һ�������������ӣ����ұ��𣡣���\n"NOR, this_object());

        ::die();
}
