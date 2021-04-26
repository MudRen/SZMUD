// Code of ShenZhou
inherit NPC;
#include <ansi.h>

string ask_me();

void create()
{
	set_name("ʩ��", ({ "shi lang","shi","lang" }));
        set_color("$YEL$");
	set("title","������");
	set("long",
		"ʩ����һԱ������ս��ˮ�����ո�ƽ��̨�壬���;����\n");
	set("gender", "����");
	set("age", 48);
	set("attitude", "peaceful");
	set("shen_type", 0);
	set("str", 30);
	set("int", 26);
	set("con", 28);
	set("dex", 26);
	set("max_qi", 1300);
	set("max_jing", 1300);
	set("neili", 1300);
	set("max_neili", 1300);
	set("jingli", 1300);
	set("max_jingli", 1300);
	set("jiali", 60);
	set("combat_exp", 160000);

	set_skill("force", 110);
	set_skill("dulong-dafa", 80);
	set_skill("dodge", 80);
	set_skill("lingshe-shenfa", 80);
	set_skill("strike", 80);
	set_skill("huagu-mianzhang", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);
	set_skill("san-sword",80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("sword","san-sword");
	prepare_skill("strike", "huagu-mianzhang");


      set("inquiry", ([
              "ΤС��" : (: ask_me :),
		"Τ��ү" : (: ask_me :),
		"֣�ɹ�" : "����ү��սӢ�£�������Ϳ�����ڳ�������������ӡ�\n",
		"����ү" : "����������Ǵ�����ϣ��ҳ��������ƹ��գ�\n",
		"����" : "��Ҳ�����ʵõ���\n",
		"����" : "������ţ�˭�˲�֪��\n",
		"̨��" : "�Ǿ����Ϸ�ƽ���ģ���������\n",
		"֣��ˬ" : "��С�ӱ���ǿ���˶��١�\n",
      ]));


	setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/armor/tiejia")->wear();

}

int accept_fight(object me)
{
        command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
        return 0;
}


int accept_kill(object me)
{
        command("say �󵨵��񣬾���ıɱ���٣�\n");
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}


string ask_me()
{
	mapping fam;
	object ob;

	if (this_player()->query_temp("shi-ling"))
		return("�һ��������أ����ҵ�������\n"); 
	ob = new(__DIR__"obj/lingpai");
	ob->move(this_player());
	this_player()->set_temp("shi-ling",1);
	command("ah");
	command("say ����Ҫȥ�����ء�");
	return "�ðɣ���֧��������ȥ���ҵ�ˮ�������ǲ���ҵ�����������ҡ�";
}
