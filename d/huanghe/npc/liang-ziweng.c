// Code of ShenZhou
// liang-ziweng.c ������

inherit NPC;
int auto_throw();
void create()
{
	set_name("������", ({ "liang ziweng", "liang" }));
	set("nickname", "�����Ϲ�");
	set("long", 
"����������еȣ���ͷ�׷�����������ɫ����������ģ���һ\n"
"���𲼳��ۣ����ǵ����ס����ǳ���ɽ��ѧ��һ����ʦ��\n");
//	set("title", "");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 23);
	
	set("max_qi", 900);
	set("max_jing", 500);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 40);
	set("combat_exp", 300000);
	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: auto_throw :),
        }) );

	set_skill("force", 90);
	set_skill("ding-force", 100);
	set_skill("wuxingbu", 100);
	set_skill("yanqing-quan", 120);
	set_skill("dodge", 90);
	set_skill("parry", 85);
	set_skill("cuff", 85);
	set_skill("hammer", 100);
	set_skill("taoism",50);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff", "yanqing-quan");
	map_skill("parry", "yanqing-quan");

	prepare_skill("cuff", "yanqing-quan");

	setup();
	carry_object("/clone/weapon/yaochu2");
	carry_object("/clone/anqi/tougu-ding")->set_amount(7);
	carry_object("/clone/armor/gebu-changpao")->wear();
}
/*
void unconcious()
{
        command("say ���ֵܣ�����צ��̫Ӳ�����������");
        message_vision("\n$N������ǽ��һ�������������ֳ��İ����\n", this_object());
        destruct(this_object());
}
*/
#include "/clone/npc/auto_throw.h";
