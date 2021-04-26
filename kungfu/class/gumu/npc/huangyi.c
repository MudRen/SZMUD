// huanggirl.c ������Ů
// by jiuer 11/01/2001

#include <ansi.h>
inherit NPC;

private string *homes_locations = ({
	"/d/gumu/milin0",
	"/d/gumu/gumu",
	"/d/gumu/chufang",
	"/d/gumu/huangshaling",
});

void create()
{
	object bj;

	set_name("������Ů", ({ "huangyi girl", "girl"}));
	set("long", 
		"������һϮ��ɴ��Ļ��£������������ס�\n");
	set("gender", "Ů��");
	set("age", 25);
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

	set("chat_chance",30);
	set("chat_msg", ({
		"������Ů�첽���˹��������������ܡ�\n",
			(: random_move :)
	}) );

	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/kungfu/class/gumu/obj/yellow_silk")->wear();
	carry_object("/kungfu/class/gumu/obj/miansha")->wear();
        
}

private void go_home()
{
        if( !living(this_object()) ) return;
        message_vision("$N�첽���˹�����\n$N�������뿪�ˡ�\n", this_object());
		this_object()->move(homes_locations[random(sizeof(homes_locations))]);
		message_vision("$N�첽���˹�����\n", this_object());
}

void init()
{
        if( strsrch(file_name(environment()), "/d/gumu/") == -1 ) {
                remove_call_out("go_home");
                call_out("go_home", 1);
                return;
		}
}
/*
void init()
{
	object ob;

	::init();
	return;
}
*/