// Code of ShenZhou
// yayi.c  �ٸ�����
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("����", ({ "ya yi", "ya" }));
        set_color("$YEL$");
	set("gender", "����");
	set("age", 25);

	set("long", "һ���ߴ����͵ĺ��ӣ���Ϊ���ڹٸ����£������Ѿ�ĥ���ú��ޱ��顣\n");
	set("combat_exp", 7500);
	set("shen_type", 1);
        set_skill("unarmed", 30);
        set_skill("dodge", 30);
	setup();
	carry_object(__DIR__"obj/yayifu")->wear();
}
	
void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("killer")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
