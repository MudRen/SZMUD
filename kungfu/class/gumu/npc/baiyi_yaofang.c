// longnv.c ������Ů
// by April 01/09/26

#include <ansi.h>
inherit NPC;
int ask_aoyao();

void create()
{
	object bj;

	set_name("������Ů", ({ "baiyi girl", "girl"}));
	set("long", 
		"������һϮ��ɴ��İ��£������������ס�\n");
	set("gender", "Ů��");
	set("age", 26);
	set("attitude", "peaceful");
	set("shen_type", 1);

	set("str", 20);
	set("int", 25);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 4000);
	set("max_jing", 5500);
	set("jiali", 200);
	set("neili", 6000);
	set("max_neili", 6000);
	set("jingli",4000);
	set("eff_jingli",4000);
	set("max_jingli",4000);

	set("combat_exp", 500000);
	set("score", 5000);

	set_skill("force", 150);
	set_skill("yunu-xinjing", 150);
	set_skill("cuff", 150);
	set_skill("meinu-quan", 150);
	set_skill("sword", 150);
	set_skill("yunu-jianfa", 150);
	set_skill("finger", 150);
	set_skill("suhan-zhi", 150);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("feiyan-gong", 150);
	set_skill("bee-training",150);
	set_skill("lovingness",150);
	set_skill("parry",150);
	set_skill("suxin-jue",150);
	set_skill("zuoyou-hubo",150);
	set_skill("throwing",150);
	set_skill("whip",150);
	set_skill("jueqing-bian",150);
	set_skill("finger",150);
	set_skill("suhan-zhi",150);

	map_skill("force", "yunu-xinjing");
	map_skill("dodge", "feiyan-gong");
	map_skill("cuff", "meinu-quan");
	map_skill("parry", "yunu-jianfa");
	map_skill("sword", "yunu-jianfa");

	prepare_skill("cuff", "meinu-quan");

	create_family("��Ĺ��", 5, "����");

    set("chat_chance_combat", 50);

	set("inquiry", ([
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
            "��ҩ" : (: ask_aoyao :),
        ]));

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/kungfu/class/gumu/obj/white_silk")->wear();
        
}

void init()
{
	object ob;

	::init();
	return;
}

int ask_aoyao()
{
        object me = this_player();
        message_vision(query("name")+"��$N���͵���\n",me);
        message_vision("���Ƚ����Ӵ�\[open lip\]��Ȼ����������ҩ��\[add **** in lu\]\n",me);
        message_vision("����������һЩ�����\[pour mi\]�������ҹ�Ĺʥҩ��ҩ�����ٿۺø���\[close lip\]\n",me);
        message_vision("��̿���ȼ\[burn coal\]����¯���������ˡ��Ϳ��԰�ҩ��\[aoyao\]��\n",me);
        message_vision("��ҩʱҪ��ʱ���ƻ�򣬻�Ҫ��ͣ���裬�����˵ġ�ҩ������֮��\n",me);
        message_vision("�ǵ������˻�\[mie huo\]��ȡҩ\[qu yao\]�����ⱻ���ˡ�\n",me);
        return 1;
}
