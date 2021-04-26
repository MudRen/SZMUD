// Code of ShenZhou
// laohu.c �ϻ�

inherit NPC_TRAINEE;

void create()
{
	set_name("����", ({ "bai xiong", "xiong", "bear" }) );
	set("race", "Ұ��");
	set("age", 25);
	set("long", "��ͷ����ܣ�ë����ޣ����ʹ���ţ���ƣ�������צ�������ɲ���\n");
	set("msg_fail", "$n��$N��������һ��");
	set("msg_succ", "$n����������������˰벽���ƺ���Щ����");
	set("msg_trained","$n�ͺ�����$N����ǰ��������");
	set("auto_follow",1);
	set("attitude", "aggressive");

	set("wildness", 12);
	set("ridable", 1);
	set("ability", 4);
	
	set("str", 60);	
	set("con", 60);
	set("dex", 30);	
	set("int", 10);

	set("combat_exp", 30000);

	set_temp("apply/attack", 50);
	set_temp("apply/damage", 70);
	set_temp("apply/armor",  50);

	set_weight(150000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"�����ڵ��ϴ��˸�����������˸���Ƿ��\n",
		"����΢΢�����Դ���˫Ŀ������������ע�������һ��һ����\n",
		"���������������˰�Ȧ����ʱ��ͷ��У�\n",
	}) );
	
	set("chat_msg_combat", ({
		"\n��������������������ƣ���Ҫ���䣡\n",
	}) );
		
	setup();
}

void die()
{
	message_vision("\n$N����Һ���һ����ſ�ڵ��ϲ����ˡ�\n", this_object());
	::die();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && ob->query_weight() >= 50000) {
		if(!this_object()->query_lord(ob)) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob);
		}
	}	

        add_action("do_look", "look");
}

int do_look(string arg)
{
        object *inv;
        int i;

        inv = all_inventory(this_object());

        if (!id(arg)) return 0;

        if (!sizeof(inv)) return 0;

        printf(this_object()->query("long") + 
        COMBAT_D->eff_status_msg((int)this_object()->query("eff_qi")* 100 / (int)this_object()->query("max_qi")) + "\n" 
        + "���������ţ�\n");
        for (i = 0; i < sizeof(inv); i++)
                printf("%s \n", inv[i]->short());
        return 1;
}

