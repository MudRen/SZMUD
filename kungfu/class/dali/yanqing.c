// Code of ShenZhou
inherit NPC;

void create()
{
	set_name("������", ({ "duan yanqing", "duan", "yanqing" }));
	set_weight(10000000);
	set("nickname", "�����ӯ");
	set("long", 
"���������޳�������͹��������һ�ġ����״��أ�������ڡ�����ȳ��˫�ȣ����Ÿ����ƹ��ȡ�\n");
	set("gender", "����");
	set("age", 55);
	set("attitude", "aggressive");
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 2000);
	set("max_jing",1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 150);
	set("combat_exp", 1500000);

	set("apply/armor", 50);
	set_skill("force", 180);
	set_skill("dodge", 180);
	set_skill("parry", 180);
	set_skill("finger", 180);
	set_skill("kurong-changong", 180);
	set_skill("yiyang-zhi", 180);
	set_skill("duanjia-jian", 180);	
	set_skill("strike", 180);
	set_skill("staff", 180);
	set_skill("duanshi-shenfa", 180);
	map_skill("dodge", "duanshi-shenfa");
        map_skill("force", "kurong-changong");
        map_skill("finger", "yiyang-zhi");
	map_skill("staff", "duanjia-jian");
	map_skill("parry", "duanjia-jian");
	prepare_skill("finger", "yiyang-zhi");

	setup();
	carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/d/xixia/obj/robe")->wear();
}
void init()
{
        object ob;
//      ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
