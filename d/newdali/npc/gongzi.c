// Code of ShenZhou
inherit NPC;

void create()
{
        set_name("����", ({ "gongzi"}));
        set("long", 
"����һ��������ӣ����õ�Ҳ�������ٷ硢һ���˲ţ���ƫƫһ˫�۾�"
"ȴ��б����ˡ�\n");
	set("gender", "����");
        set("age", 20+random(10));
	set("attitude", "friendly");

	set("combat_exp", 7500);
        set_skill("unarmed", 35);
        set_skill("force", 35);
        set_skill("dodge", 40);
	set_skill("ding-unarmed", 30+random(10));
	map_skill("unarmed", "ding-unarmed");
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 40);
        set("shen_type", -1);
        setup();
	add_money("gold", 1);

}
void init()
{
        add_action("do_kill", "kill");
}
int do_kill(string arg)
{
        object ob;
        int i;

        if (!arg || arg != "gongzi") return command("kill ");
	
	if (present("e nu", environment(this_object()))){
	command("say ����ı�������ӣ�������������·�� ���Һ��ڣ�");
        message_vision("�������ҵĶ�ū��$N����������\n", this_player());

        for(i=0; i<2; i++) {
                if( objectp( ob = present("e nu " + (i+1), environment(this_object())) ) )
                                 ob->kill_ob(this_player());
                else    this_object()->kill_ob(this_player());
        }
	}

        return command("kill gongzi");
}














