// Code of ShenZhou
// item: /d/xingxiu/npc/obj/fire.c
// Siyan 6/5/96

inherit NPC;
int do_yao(string);
varargs void revive();

void init()
{
	object ob;
        mapping myfam;

        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
        && file_name(environment(this_object())) == "/d/xingxiu/xxcave" ) {
                myfam = (mapping)ob->query("family");
                if ((!myfam || myfam["family_name"] != "������") &&
                        (!wizardp(ob))) {
		this_object()->kill_ob(ob);	
		ob->start_busy(3);
                }
        }
        add_action("do_yao", "yao");
}

void create()
{
        set_name("����", ({"ju mang", "mang"}));
        set("race", "����");
        set("age", 100);
	set_weight(150000);
	set("long", "һ��ɫ�ʰ�쵵ľ�����\n");
	set("attitude", "peaceful");
	set("limbs", ({ "ͷ", "��", "��", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 20000);
	
        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 200);
        set_temp("apply/armor", 80);

	setup();
}

varargs void revive(int quiet)
{
	object me, env, *inv, mst;
	string str;
	int i, cnt;

	::revive();
	me = this_object();
	env = environment(me);
        //message_vision("$N��ͷ��\n", me);
	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if( living(inv[i]) ) {
			mst = inv[i];
			cnt++;
		}
        }
	if(cnt == 1) {
        	message_vision("$N����ͷ��$n�������㡣\n", me, mst);
		me->set_leader(mst);
	}
	else
        	message_vision("$N��������һ�ߣ��̳�һ��Сɽ��\n", me);
                //str += "  " + inv[i]->short() + "\n";
}

int do_yao(string victim)
{
	object me, ob, vc;
	me = this_object();
	ob = this_player();
	if(!(vc = find_living(victim))) {
		message_vision("$N����$n��ͷ��\n", ob, me);
		return 1;
	}
	if(me->query_leader()) {
		message_vision("$N����$n��ͷ����ָ��ָ" + vc->query("name") +
			"��\n", ob, me);
		remove_call_out("biting");
		call_out("biting",1,me,vc);
		//command("say hi " + vc->query("name"));
	}
	else
		message_vision("$N����$n��\n", ob, me);
	return 1;
}

void biting(object me, object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	me->kill_ob(ob);
}
