// Code of ShenZhou
// /d/emei/npc/monkey2.c ����
// Shan 6/26/96

inherit NPC;

void create()
{
        seteuid(getuid());

        set_name("����", ({ "monkey", "hou", "houzi" }) );
        set("race", "Ұ��");
        set("age", 8);
        set("long", "һֻ����ĺ��ӣ��۰Ͱ͵Ŀ����㣬�������Щ�Եġ�\n");
        set("attitude", "peaceful");

        set("limbs", ({ "ͷ��", "����",  "ǰ��", "����", "β��" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("thief", 0);

        set_skill("stealing", 30);
	set_skill("dodge", 20);

        set("combat_exp", 500);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/armor", 3);

        setup();

        set("chat_chance", 8);
        set("chat_msg", ({
                "һֻ���Ӻ�Ȼ�ܹ������������˸�Ҿ��\n",
		"һֻ����ߴߴ�������˹�����\n",
		"���ӱı��������ܿ��ˡ�\n",
                "����ҡҡβ���ܿ��ˡ�\n",
                (: random_move :)
        }) );
}

// inherit F_UNIQUE;

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if( !ob || environment(ob) != environment() 
                || ((fam = ob->query("family")) && fam["family_name"] == "����")
          ) return;

	switch( random(10) ) {
		case 0:
                       command("bow " + ob->query("id"));
		       break;
		case 1:
                       command("smirk " + ob->query("id"));
		       break;
		case 2:
                       command("jump " );
		       break;
		case 3:
                       command("steal jitui from " + ob->query("id"));	
                       command("eat jitui");
		       break;
		case 4:
                       command("steal jiudai from " + ob->query("id"));	
                       command("drink jiudai");
		       break;
                case 5:
                       command("trip " );
                       break;
                case 6:
                       command("steal hulu from " + ob->query("id"));  
                       command("drink hulu");
                       break;
                case 7:
                       command("steal tao from " + ob->query("id"));  
                       command("eat tao");
                       break;
                case 8:
                       command("fear ");
                       break;
                case 9:
                       command("giggle " );
                       break;
                case 10:
                       command("wave " );
                       command("steal bottle from " + ob->query("id"));  
                       command("drink bottle");
                       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("food_supply") && obj->value() >= 0) {
        	 command("bow "+ me->query("id"));
		command("bite ");
//		command("eat" + obj->query("id"));
	}
        else {
        	 command("shake");
	         command("give " + obj->query("id") + " to " + me->query("id"));
//		command("drop " + obj->query("id"));
               obj->move(this_player());
        }
	return 1;
}

